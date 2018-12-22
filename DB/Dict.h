#ifndef DICT_H
#define DICT_H
/*-------------------------------------------------------------------------
*
* Dict.h
*	  此文件定义数据字典条目的相关类，以及对数据字典如何保存至文件中的
*	  相关函数。
*
*	考虑将数据字典的行的rowid放到一个文件中（此处考虑有点奇怪），后缀.copy
*
*
*-------------------------------------------------------------------------
*/

#include<iostream>
#include"sql\Expr.h"
using namespace std;

class Dict
{
private:
	//以下属性用于放五个数据字典文件的第一个块的块号（每个数据字典放在一个文件里），用于查找时的遍历
	string userblock1;
	string databaseblock1;
	string classblock1;
	string attributeblock1;
	string indexblock1;

public:
	static Dict* getInstance();
	static void release();
private:
	static Dict* instance;
	Dict() {}
	Dict(const Dict&) = delete;
	Dict& operator=(const Dict&) = delete;
public:

	void InitDictionary();					//创建所有数据字典表文件，整个程序只可以调用一次，该函数创建五个数据字典文件，
											//同时为其分配一个块，并记录第一个块的块号在文件"./data/firstblockid.bid"中

	void Init();							//数据字典初始化，初始化oid，将最新可以分配的oid加载到程序中

	int DeliverOid();							//分配一个oid
												//当生成一个数据库对象（用户、数据库、表、索引、属性）的时候，用该函数得到该对象的oid

	User*	CreateUser();					//创建一个数据库用户对象
	Database* CreateDatabase();				//创建数据库
	Class*	CreateClass();					//创建表、索引
	Attribute* CreateAttribute();			//创建属性对象
	Index*	CreateIndex();					//创建索引对象


	User*	GetUser(string username);		//从用户表中，根据username找到user对象
	Database*	GetDatabase(User* user, string dbname);	//从数据库表中，根据数据库名字and数据库所有者找到数据库
	Class*	GetClass(Database* tdatabase, string relationname);	//从class表中，根据数据库和relation的名字找到表、索引
	vector<Attribute*>	GetAttribute(Class* table);		//从attribute表中，根据表的oid，找到该表所有属性
	Attribute*	GetAttribute(int attritubeid);			//从attribute表中，根据属性oid找到属性
	vector<Attribute*>	GetAttribute(Index* index);		//从attribute表中，根据索引，找到该索引所有属性
	Index*	GetIndex(Class* tindex);					//从index表中，根据class中的索引的oid，找到索引对象


	void StoreUser(User* tuser);			//将user存入user表
	void StoreDatabase(Database* tdatabase);		//将database存入database表中
	void StoreClass(Class* tclass);			//将数据库对象（表，索引）存入class表中
	void StoreAttribute(Attribute* tattribute);		//将attribute存入attribute表中
	void StoreIndex(Index* tindex);			//将index存入index表中

};






/*------------------------------------
*
*class Oid用于表示数据库各个对象的编号
*从1递增，不会重复,当前值存放在数据字典
*表文件dict_oid.oid中的前四个字节。
*
*-------------------------------------
*/
class Oid {
public:
	static Oid* instance;
	static Oid* GetInstance();
	static void Release();

private:
	int curnum;		//current number (this number can be delivered)
	string filename;

	Oid(string tfilename);

public:
	int GetCurNum();	//得到当前可分配的oid
	void Load();		//从文件里拿出上次分配结束的id
	void Store();		//将本次分配完的oid放入文件
};



/*------------------------------------
*
*class User用于表示用户，共用的表，放
*在文件号为1号的文件中。
*
*-------------------------------------
*/

class User {
public:
	int userid;			//the oid of user

	string username;	//username
	string code;		//code of the account


	string fileid;			//user表的文件号为1

public:
	User();
	~User() {}

	int GetUserid();
	void SetUserid(int tuserid);

	string GetUsername();
	void SetUsername(string tusername);

	string GetCode();
	void SetCode(string tcode);

	void StoreToFile();		//将该对象存入user表文件中
};





/*------------------------------------
*
*class Database用于表示数据库，包括整个
*系统中所有数据库的定义信息，
*该表放在文件号为2号的文件中。
*
*-------------------------------------
*/

class Database {
public:
	int oid;			//oid of the database , receive from Oid

	string datname;		//name of database
	int ownerid;		//the oid of the user who create the database
	int datconnlimit;	//the max number of connector
	int curconnect;		//当前几个访问
	vector<int> datacl;		//access control	具有访问权限的userid


	string fileid;			//Database表的文件号为2，没有实际存储在文件中

public:
	Database();
	~Database() {}

	int GetOid();
	void SetOid(int toid);
	string GetDatName();
	void SetDatName(string tdatname);		//set database name
	int GetOwnerid();
	void SetOwnerid(int townerid);			//set database creater
	int GetDatconnlimit();
	void SetDatconnlimit(int tdatconnlimit);//set max number of connector
	void SetDatacl(vector<int> tdatacl);			//set access control


	bool IsAvailable(int userid);			//判断该userid是否有权限访问该数据库
	bool CanConnect();						//判断能否连接
	void Addconnect();						//增加一个连接数

	void StoreToFile();		//将该对象存入database表文件中
};



/*------------------------------------
*
*class Class用于表示数据库对象，包括整个
*系统中所有数据库的对象信息（表，索引等）
*该表放在文件号为3号的文件中。
*
*-------------------------------------
*/
class Class {
public:
	int oid;			//oid of the object , receive from Oid
	int databaseid;		//the oid of database which the relation belong to

	string relname;		//relation name
	string relfileid;		//the fileid of relation	文件的文件号
	string relblockid;		//the number of blocks relation occupy	该对象在哪个块中
	int reltuples;		//the number of tuples in relation	该对象有几个元组（统计信息）
	int hasindex;		//T means hasindex	有为1，无为0
	char relkind;		//kind of the object , r-relation i-index 该对象的类型（表还是索引）
	int relnatts;		//the number of attritubes	对象包含的属性个数
	int haspkey;		//T means having a primary key	有为1，无为0


	string fileid;			//Class表的文件号为3

public:
	Class();
	~Class() {}

	void AddTuples(int num = 1);			//增加num个元组，元组数目加num
	void DeleteTuples(int num = 1);		//删除num个元组，数目减num
	bool HasIndex();					//是否有索引
	void Setindex(bool t);					//设置索引
	bool HasPkey();						//是否定义主键
	void SetPkey(bool t);						//设置主键

	void StoreToFile();		//将该对象存入class表文件中
};

/*------------------------------------
*
*class Attribute用于表示属性，包括属性
*类型等，该表放在文件号为4的文件中
*
*-------------------------------------
*/
class Attribute {
public:
	int oid;			//属性的标号
	int relid;			//the oid of relation属性所属的表
	string name;		//name of the attritube属性名称
	hsql::ExprType type;		//属性类型
	int attnum;			//the order of attritube in a table
	int varcharlen;		//the length of verchar	变长数据的长度
	int notnull;		//属性是否非空，1非空，0可空
	int pkey;			//是否是主键，1是，0不是
	int colcard;		//the number of tuple which value is different	该属性有几个不同的元组



	string fileid;			//Attribute表的文件号为4

public:
	Attribute();
	~Attribute() {}

	int GetRelid();
	void SetRelid(int trelid);

	string GetAttritubeName();
	void SetAttritubeName(string name);

	hsql::ExprType GetType();
	void SetType(hsql::ExprType ttype);

	int GetAttnum();
	void SetAttnum(int tnum);

	int GetVarcharLength();
	void SetVarcharLength(int tlen);

	bool IsNotNull();
	void SetNotNull(bool t);

	bool IsPkey();
	void SetPkey(bool t);

	int GetColcard();
	void CalculateColcard();			//计算该属性有几个不同的元组

	void StoreToFile();					//将该对象存入Attribute表文件中
};



///*------------------------------------
//*
//*class Type用于表示类型，共用的表，放
//*在dict_type中。
//*
//*-------------------------------------
//*/
//
//class Type {
//public:
//	int oid;			//id of the type , receive from Oid
//	string name;		//the name of type
//	int typelen;		//the length of type
//	char splitsignal;	//split signal if it's a array
//
//public:
//	Type();
//	~Type();
//};


/*------------------------------------
*
*class Index用于表示索引，私用的表，放
*在文件号为5的文件中。
*
*-------------------------------------
*/
class Index {
public:
	int indexrelid;			//该索引在class表中的编号（oid）
	int indrelid;			//the oid of table create the index	创建该索引的表号
	int indnatts;			//the number of attritube	索引的属性个数
	string name;			//name of index索引名称
	char indtype;			//type of index, o唯一索引, p主索引, a其他
	vector<int> indkeys;				//the attritube id of index	索引的属性id


	string fileid;			//Index表的文件号为5

public:
	Index();
	~Index() {}

	int GetIndexrelid();
	void SetIndexrelid(int tid);

	int GetIndrelid();
	void SetIndrelid(int tid);

	int GetIndnatts();
	void SetIndnatts(int tnum);

	string GetName();
	void SetName(string tname);

	char GetIndtype();
	void SetIndetype(char type);

	vector<int> GetIndkeys();
	void SetIndkeys(vector<int> keys);

	void StoreToFile();					//将该对象存入index表文件中
};





#endif // !DICT_H