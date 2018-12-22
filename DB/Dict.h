#ifndef DICT_H
#define DICT_H
/*-------------------------------------------------------------------------
*
* Dict.h
*	  ���ļ����������ֵ���Ŀ������࣬�Լ��������ֵ���α������ļ��е�
*	  ��غ�����
*
*	���ǽ������ֵ���е�rowid�ŵ�һ���ļ��У��˴������е���֣�����׺.copy
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
	//�����������ڷ���������ֵ��ļ��ĵ�һ����Ŀ�ţ�ÿ�������ֵ����һ���ļ�������ڲ���ʱ�ı���
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

	void InitDictionary();					//�������������ֵ���ļ�����������ֻ���Ե���һ�Σ��ú���������������ֵ��ļ���
											//ͬʱΪ�����һ���飬����¼��һ����Ŀ�����ļ�"./data/firstblockid.bid"��

	void Init();							//�����ֵ��ʼ������ʼ��oid�������¿��Է����oid���ص�������

	int DeliverOid();							//����һ��oid
												//������һ�����ݿ�����û������ݿ⡢�����������ԣ���ʱ���øú����õ��ö����oid

	User*	CreateUser();					//����һ�����ݿ��û�����
	Database* CreateDatabase();				//�������ݿ�
	Class*	CreateClass();					//����������
	Attribute* CreateAttribute();			//�������Զ���
	Index*	CreateIndex();					//������������


	User*	GetUser(string username);		//���û����У�����username�ҵ�user����
	Database*	GetDatabase(User* user, string dbname);	//�����ݿ���У��������ݿ�����and���ݿ��������ҵ����ݿ�
	Class*	GetClass(Database* tdatabase, string relationname);	//��class���У��������ݿ��relation�������ҵ�������
	vector<Attribute*>	GetAttribute(Class* table);		//��attribute���У����ݱ��oid���ҵ��ñ���������
	Attribute*	GetAttribute(int attritubeid);			//��attribute���У���������oid�ҵ�����
	vector<Attribute*>	GetAttribute(Index* index);		//��attribute���У������������ҵ���������������
	Index*	GetIndex(Class* tindex);					//��index���У�����class�е�������oid���ҵ���������


	void StoreUser(User* tuser);			//��user����user��
	void StoreDatabase(Database* tdatabase);		//��database����database����
	void StoreClass(Class* tclass);			//�����ݿ���󣨱�����������class����
	void StoreAttribute(Attribute* tattribute);		//��attribute����attribute����
	void StoreIndex(Index* tindex);			//��index����index����

};






/*------------------------------------
*
*class Oid���ڱ�ʾ���ݿ��������ı��
*��1�����������ظ�,��ǰֵ����������ֵ�
*���ļ�dict_oid.oid�е�ǰ�ĸ��ֽڡ�
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
	int GetCurNum();	//�õ���ǰ�ɷ����oid
	void Load();		//���ļ����ó��ϴη��������id
	void Store();		//�����η������oid�����ļ�
};



/*------------------------------------
*
*class User���ڱ�ʾ�û������õı���
*���ļ���Ϊ1�ŵ��ļ��С�
*
*-------------------------------------
*/

class User {
public:
	int userid;			//the oid of user

	string username;	//username
	string code;		//code of the account


	string fileid;			//user����ļ���Ϊ1

public:
	User();
	~User() {}

	int GetUserid();
	void SetUserid(int tuserid);

	string GetUsername();
	void SetUsername(string tusername);

	string GetCode();
	void SetCode(string tcode);

	void StoreToFile();		//���ö������user���ļ���
};





/*------------------------------------
*
*class Database���ڱ�ʾ���ݿ⣬��������
*ϵͳ���������ݿ�Ķ�����Ϣ��
*�ñ�����ļ���Ϊ2�ŵ��ļ��С�
*
*-------------------------------------
*/

class Database {
public:
	int oid;			//oid of the database , receive from Oid

	string datname;		//name of database
	int ownerid;		//the oid of the user who create the database
	int datconnlimit;	//the max number of connector
	int curconnect;		//��ǰ��������
	vector<int> datacl;		//access control	���з���Ȩ�޵�userid


	string fileid;			//Database����ļ���Ϊ2��û��ʵ�ʴ洢���ļ���

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


	bool IsAvailable(int userid);			//�жϸ�userid�Ƿ���Ȩ�޷��ʸ����ݿ�
	bool CanConnect();						//�ж��ܷ�����
	void Addconnect();						//����һ��������

	void StoreToFile();		//���ö������database���ļ���
};



/*------------------------------------
*
*class Class���ڱ�ʾ���ݿ���󣬰�������
*ϵͳ���������ݿ�Ķ�����Ϣ���������ȣ�
*�ñ�����ļ���Ϊ3�ŵ��ļ��С�
*
*-------------------------------------
*/
class Class {
public:
	int oid;			//oid of the object , receive from Oid
	int databaseid;		//the oid of database which the relation belong to

	string relname;		//relation name
	string relfileid;		//the fileid of relation	�ļ����ļ���
	string relblockid;		//the number of blocks relation occupy	�ö������ĸ�����
	int reltuples;		//the number of tuples in relation	�ö����м���Ԫ�飨ͳ����Ϣ��
	int hasindex;		//T means hasindex	��Ϊ1����Ϊ0
	char relkind;		//kind of the object , r-relation i-index �ö�������ͣ�����������
	int relnatts;		//the number of attritubes	������������Ը���
	int haspkey;		//T means having a primary key	��Ϊ1����Ϊ0


	string fileid;			//Class����ļ���Ϊ3

public:
	Class();
	~Class() {}

	void AddTuples(int num = 1);			//����num��Ԫ�飬Ԫ����Ŀ��num
	void DeleteTuples(int num = 1);		//ɾ��num��Ԫ�飬��Ŀ��num
	bool HasIndex();					//�Ƿ�������
	void Setindex(bool t);					//��������
	bool HasPkey();						//�Ƿ�������
	void SetPkey(bool t);						//��������

	void StoreToFile();		//���ö������class���ļ���
};

/*------------------------------------
*
*class Attribute���ڱ�ʾ���ԣ���������
*���͵ȣ��ñ�����ļ���Ϊ4���ļ���
*
*-------------------------------------
*/
class Attribute {
public:
	int oid;			//���Եı��
	int relid;			//the oid of relation���������ı�
	string name;		//name of the attritube��������
	hsql::ExprType type;		//��������
	int attnum;			//the order of attritube in a table
	int varcharlen;		//the length of verchar	�䳤���ݵĳ���
	int notnull;		//�����Ƿ�ǿգ�1�ǿգ�0�ɿ�
	int pkey;			//�Ƿ���������1�ǣ�0����
	int colcard;		//the number of tuple which value is different	�������м�����ͬ��Ԫ��



	string fileid;			//Attribute����ļ���Ϊ4

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
	void CalculateColcard();			//����������м�����ͬ��Ԫ��

	void StoreToFile();					//���ö������Attribute���ļ���
};



///*------------------------------------
//*
//*class Type���ڱ�ʾ���ͣ����õı���
//*��dict_type�С�
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
*class Index���ڱ�ʾ������˽�õı���
*���ļ���Ϊ5���ļ��С�
*
*-------------------------------------
*/
class Index {
public:
	int indexrelid;			//��������class���еı�ţ�oid��
	int indrelid;			//the oid of table create the index	�����������ı��
	int indnatts;			//the number of attritube	���������Ը���
	string name;			//name of index��������
	char indtype;			//type of index, oΨһ����, p������, a����
	vector<int> indkeys;				//the attritube id of index	����������id


	string fileid;			//Index����ļ���Ϊ5

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

	void StoreToFile();					//���ö������index���ļ���
};





#endif // !DICT_H