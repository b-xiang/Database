#include "Dict.h"
#include<iostream>
#include<fstream>
#include <direct.h>
#include <map>
#include <io.h>
#include"BlockMgr.h"
#include"sql\Expr.h"
#include "Block.h"
#include"Block.h"

using namespace std;

Dict* Dict::instance = nullptr;
string Dict::curSchema;
map<int, pair <RoidType, string>> Dict::roidmap;

Dict * Dict::getInstance()
{
	if (instance == nullptr) {
		instance = new Dict;
		instance->Init();
	}
	return instance;
}

void Dict::release()
{
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}
	storemap();
}

void Dict::InitDictionary()
{
	BlockMgr* blkmgr = BlockMgr::getInstance();
	_mkdir("data");
	ofstream fout("./data/dict_oid.oid", ios::out);	//创建oid文件
	fout << 1;
	fout.close();
	fout.clear();



	file file_user = *blkmgr->getFile(blkmgr->allocFile());
	file file_database = *blkmgr->getFile(blkmgr->allocFile());
	file file_class = *blkmgr->getFile(blkmgr->allocFile());
	file file_attribute = *blkmgr->getFile(blkmgr->allocFile());
	file file_index = *blkmgr->getFile(blkmgr->allocFile());


	string block1;
	string fileid = file_user.fileid64;
	string str = "./data/data_" + fileid + ".db";		//创建user表文件
	fout.open(str, ios::out);
	fout.close();
	fout.clear();
	block1 = BlockMgr::getInstance()->allocBlock(fileid);	//为文件分配第一个块

/**/
	fout.open("./data/firstblockid.bid", ios::out | ios::app);			//创建一个文件，放所有的第一块块号，				##这个有待商榷
	fout << block1 << "\n";									//将第一个块号写入
	fout.close();
	fout.clear();
	/**/

	fileid = file_database.fileid64;
	str = "./data/data_" + fileid + ".db";			//创建database表文件
	fout.open(str, ios::out);
	fout.close();
	fout.clear();
	block1 = BlockMgr::getInstance()->allocBlock(fileid);	//为文件分配第一个块

	/**/
	fout.open("./data/firstblockid.bid", ios::out | ios::app);			//创建一个文件，放所有database的rowid，				##这个有待商榷
	fout << block1 << "\n";									//将第一个块号写入
	fout.close();
	fout.clear();
	/**/

	fileid = file_class.fileid64;
	str = "./data/data_" + fileid + ".db";			//创建class表文件
	fout.open(str, ios::out);
	fout.close();
	fout.clear();
	block1 = BlockMgr::getInstance()->allocBlock(fileid);	//为文件分配第一个块

	/**/
	fout.open("./data/firstblockid.bid", ios::out | ios::app);			//创建一个文件，放所有class的rowid，				##这个有待商榷
	fout << block1 << "\n";									//将第一个块号写入
	fout.close();
	fout.clear();
	/**/

	fileid = file_attribute.fileid64;
	str = "./data/data_" + fileid + ".db";			//创建attribute表文件
	fout.open(str, ios::out);
	fout.close();
	fout.clear();
	block1 = BlockMgr::getInstance()->allocBlock(fileid);	//为文件分配第一个块

	/**/
	fout.open("./data/firstblockid.bid", ios::out | ios::app);			//创建一个文件，放所有attribute的rowid，				##这个有待商榷
	fout << block1 << "\n";									//将第一个块号写入
	fout.close();
	fout.clear();
	/**/

	fileid = file_index.fileid64;
	str = "./data/data_" + fileid + ".db";			//创建index表文件
	fout.open(str, ios::out);
	fout.close();
	fout.clear();
	block1 = BlockMgr::getInstance()->allocBlock(fileid);	//为文件分配第一个块

	/**/
	fout.open("./data/firstblockid.bid", ios::out | ios::app);			//创建一个文件，放所有index的rowid，				##这个有待商榷
	fout << block1 << "\n";									//将第一个块号写入
	fout.close();
	fout.clear();
	/**/
}

void Dict::Init()
{
	_mkdir("data");
	int isExist = _access("./data/dict_oid.oid", 0);
	if (isExist == -1) {
		InitDictionary();
		User* user = CreateUser();
		user->SetUserid(DeliverOid());
		user->SetUsername("default");
		user->SetCode("default");
		StoreUser(user);
	}

	Initmap();
	Oid::GetInstance();						//新建oid计数
	

	//将各个文件第一块的块号放到类中
	ifstream fin("./data/firstblockid.bid", ios::in);

	getline(fin, userblock1);

	getline(fin, databaseblock1);

	getline(fin, classblock1);

	getline(fin, attributeblock1);

	getline(fin, indexblock1);

	fin.close();
	fin.clear();
}

void Dict::Initmap()
{
	ifstream fin("./data/dict.roid", ios::in);			//打开保存rowid的文件
	string line;
	while (getline(fin, line)) {
		if (line != "") {
			Expr*expr = Block::decodeExprArray(line);
			roidmap[(*(expr->exprList))[0]->ival]=make_pair((RoidType)(*(expr->exprList))[1]->ival,(*(expr->exprList))[2]->name);
		}
	}
}

void Dict::storemap()
{
	ofstream fout("./data/dict.roid", ios::out);			//打开保存rowid的文件
	for (auto item : roidmap) {
		vector<Expr*> exprs;
		Expr* oidExpr = Expr::makeLiteral((int64_t)item.first);
		Expr* roidTypeExpr = Expr::makeLiteral((int64_t)item.second.first);
		Expr* ridExpr = Expr::makeLiteral(item.second.second.c_str());
		exprs.push_back(oidExpr);
		exprs.push_back(roidTypeExpr);
		exprs.push_back(ridExpr);
		Expr* resExpr = Expr::makeArray(&exprs);
		string resstr = Block::encodeExprArray(resExpr);
		fout << resstr << endl;
	}
	fout.close();
	fout.clear();
}

int Dict::DeliverOid() {
	return Oid::GetInstance()->GetCurNum();	//获得当前的oid
}

User*	Dict::CreateUser() {
	return new User;
}

Database* Dict::CreateDatabase() {
	return new Database;
}

Class*	Dict::CreateClass() {
	return new Class;
}

Attribute* Dict::CreateAttribute() {
	return new Attribute;
}

Index*	Dict::CreateIndex() {
	return new Index;
}


User*	Dict::GetUser(string username) {
	User* targetuser = CreateUser();			//创建一个空的User用于装结果
	string tempusername;						//用于装读出的username
	vector<string> rowidList;
	for (auto item : roidmap) {
		if (item.second.first == UserRoid)
			rowidList.push_back(item.second.second);
	}
	vector<Expr*>tempexpr = BlockMgr::getInstance()->multipleGet(rowidList);
	vector<Expr*>::iterator iter;
	for (iter = tempexpr.begin(); iter != tempexpr.end(); iter++) {
		tempusername = (*((*iter)->exprList))[1]->name;
		if (tempusername == username) {		//找到
			targetuser->SetUserid((*((*iter)->exprList))[0]->ival);
			targetuser->SetUsername(username);
			targetuser->SetCode((*((*iter)->exprList))[2]->name);
			return targetuser;
		}
	}
	return nullptr;			//如果都遍历完了还没找到，那么不存在这一项
}


Database*	Dict::GetDatabase(User* user, string dbname) {
	Database* targetdatabase = CreateDatabase();			//创建一个空的User用于装结果

	int userid = user->GetUserid();

	int tempuserid;
	string tempdaname;

	vector<string> rowidList;
	for (auto item : roidmap) {
		if (item.second.first == DatabaseRoid)
			rowidList.push_back(item.second.second);
	}
	vector<Expr*>tempexpr = BlockMgr::getInstance()->multipleGet(rowidList);

	vector<Expr*>::iterator iter;
	for (iter = tempexpr.begin(); iter != tempexpr.end(); iter++) {
		tempuserid = (*((*iter)->exprList))[2]->ival;
		tempdaname = (*((*iter)->exprList))[1]->name;

		if (tempdaname == dbname && tempuserid == userid) {		//找到
			targetdatabase->oid = ((*((*iter)->exprList))[0]->ival);
			targetdatabase->datname = dbname;
			targetdatabase->ownerid = ((*((*iter)->exprList))[2]->ival);
			targetdatabase->datconnlimit = ((*((*iter)->exprList))[3]->ival);
			targetdatabase->curconnect = ((*((*iter)->exprList))[4]->ival);
			vector<Expr*> gg = *((*((*iter)->exprList))[5]->exprList);
			vector<Expr*>::iterator it;
			for (it = gg.begin(); it != gg.end(); it++) {
				targetdatabase->datacl.push_back((*it)->ival);
			}

			return targetdatabase;
		}
	}

	return nullptr;			//如果都遍历完了还没找到，那么不存在这一项
}


vector<Database*> Dict::getDatabases(User* user)
{
	vector<Database*> res;
	Database* targetdatabase = CreateDatabase();			//创建一个空的User用于装结果

	int userid = user->GetUserid();

	int tempuserid;
	string tempdaname;

	vector<string> rowidList;
	for (auto item : roidmap) {
		if (item.second.first == DatabaseRoid)
			rowidList.push_back(item.second.second);
	}
	vector<Expr*>tempexpr = BlockMgr::getInstance()->multipleGet(rowidList);

	vector<Expr*>::iterator iter;
	for (iter = tempexpr.begin(); iter != tempexpr.end(); iter++) {
		tempuserid = (*((*iter)->exprList))[2]->ival;
		tempdaname = (*((*iter)->exprList))[1]->name;

		if (tempuserid == userid) {		//找到
			targetdatabase->oid = ((*((*iter)->exprList))[0]->ival);
			targetdatabase->datname = ((*((*iter)->exprList))[1]->name);
			targetdatabase->ownerid = ((*((*iter)->exprList))[2]->ival);
			targetdatabase->datconnlimit = ((*((*iter)->exprList))[3]->ival);
			targetdatabase->curconnect = ((*((*iter)->exprList))[4]->ival);
			vector<Expr*> gg = *((*((*iter)->exprList))[5]->exprList);
			vector<Expr*>::iterator it;
			for (it = gg.begin(); it != gg.end(); it++) {
				targetdatabase->datacl.push_back((*it)->ival);
			}
			res.push_back(new Database(*targetdatabase));
		}
	}

	delete targetdatabase;
	return res;
}


Class*	Dict::GetClass(Database* tdatabase, string relationname) {
	Class* targetclass = CreateClass();			//创建一个空的Class用于装结果

	int databaseid = tdatabase->GetOid();

	int temp_databaseid;
	string temp_relationname;

		
	vector<string> rowidList;
	for (auto item : roidmap) {
		if (item.second.first == ClassRoid)
			rowidList.push_back(item.second.second);
	}
	vector<Expr*>tempexpr = BlockMgr::getInstance()->multipleGet(rowidList);

	vector<Expr*>::iterator iter;
	for (iter = tempexpr.begin(); iter != tempexpr.end(); iter++) {
		temp_databaseid = (*((*iter)->exprList))[1]->ival;

		temp_relationname = (*((*iter)->exprList))[2]->name;

		if (temp_databaseid == databaseid && temp_relationname == relationname) {		//找到

			targetclass->oid = ((*((*iter)->exprList))[0]->ival);

			targetclass->databaseid = ((*((*iter)->exprList))[1]->ival);

			targetclass->relname = ((*((*iter)->exprList))[2]->name);

			targetclass->relfileid = ((*((*iter)->exprList))[3]->name);

			targetclass->relblockid = ((*((*iter)->exprList))[4]->name);

			targetclass->reltuples = ((*((*iter)->exprList))[5]->ival);

			targetclass->hasindex = ((*((*iter)->exprList))[6]->ival);

			targetclass->relkind = *((*((*iter)->exprList))[7]->name);

			targetclass->relnatts = ((*((*iter)->exprList))[8]->ival);

			targetclass->haspkey = ((*((*iter)->exprList))[9]->ival);
			return targetclass;
		}
	}

	return nullptr;			//如果都遍历完了还没找到，那么不存在这一项

}

vector<Class*> Dict::getClasses(Database * tdatabase)
{
	vector<Class*> res;
	Class* targetclass = CreateClass();			//创建一个空的Class用于装结果

	int databaseid = tdatabase->GetOid();

	int temp_databaseid;
	string temp_relationname;


	vector<string> rowidList;
	for (auto item : roidmap) {
		if (item.second.first == ClassRoid)
			rowidList.push_back(item.second.second);
	}
	vector<Expr*>tempexpr = BlockMgr::getInstance()->multipleGet(rowidList);
	vector<Expr*>::iterator iter;
	for (iter = tempexpr.begin(); iter != tempexpr.end(); iter++) {
		temp_databaseid = (*((*iter)->exprList))[1]->ival;

		temp_relationname = (*((*iter)->exprList))[2]->name;

		if (temp_databaseid == databaseid) {		//找到

			targetclass->oid = ((*((*iter)->exprList))[0]->ival);

			targetclass->databaseid = ((*((*iter)->exprList))[1]->ival);

			targetclass->relname = ((*((*iter)->exprList))[2]->name);

			targetclass->relfileid = ((*((*iter)->exprList))[3]->name);

			targetclass->relblockid = ((*((*iter)->exprList))[4]->name);

			targetclass->reltuples = ((*((*iter)->exprList))[5]->ival);

			targetclass->hasindex = ((*((*iter)->exprList))[6]->ival);

			targetclass->relkind = *((*((*iter)->exprList))[7]->name);

			targetclass->relnatts = ((*((*iter)->exprList))[8]->ival);

			targetclass->haspkey = ((*((*iter)->exprList))[9]->ival);
			res.push_back(targetclass);
		}
	}

	return res;

}


vector<Attribute*>	Dict::GetAttribute(Class* table) {
	vector<Attribute*> allarrtibute;			//定义返回值

	int relid = table->oid;						//表的编号
	int totalnum = table->relnatts;				//表总共有几个属性

	int i = 0;		//找到几个属性
	int temp_relid;			//属性所属的表的id

	Attribute* tempattritube = CreateAttribute();
	delete tempattritube;

	vector<string> rowidList;
	for(auto item:roidmap){
		if (item.second.first == AttributeRoid)
			rowidList.push_back(item.second.second);
	}
	vector<Expr*>tempexpr = BlockMgr::getInstance()->multipleGet(rowidList);

	vector<Expr*>::iterator iter;
	for (iter = tempexpr.begin(); iter != tempexpr.end(); iter++) {
		temp_relid = (*((*iter)->exprList))[1]->ival;

		if (temp_relid == relid) {		//找到

			Attribute* targetattribute = CreateAttribute();			//创建一个空的Attribute用于装结果

			targetattribute->oid = ((*((*iter)->exprList))[0]->ival);

			targetattribute->relid = ((*((*iter)->exprList))[1]->ival);

			targetattribute->name = ((*((*iter)->exprList))[2]->name);

			targetattribute->type = (ExprType)((*((*iter)->exprList))[3]->ival);

			targetattribute->attnum = ((*((*iter)->exprList))[4]->ival);

			targetattribute->varcharlen = ((*((*iter)->exprList))[5]->ival);

			targetattribute->notnull = ((*((*iter)->exprList))[6]->ival);

			targetattribute->pkey = ((*((*iter)->exprList))[7]->ival);

			targetattribute->colcard = ((*((*iter)->exprList))[8]->ival);

			allarrtibute.push_back(targetattribute);

			i++;

			if (i == totalnum) {
				return allarrtibute;
			}
		}
	}

	return allarrtibute;			//没找到或者没找全都返回

}



Attribute*	Dict::GetAttribute(int attritubeid) {
	Attribute* targetattribute = CreateAttribute();			//创建一个空的Attribute用于装结果

	int temp_attributeid;						//用于装读出的attributeid

	vector<string> rowidList;
	for (auto item : roidmap) {
		if (item.second.first == AttributeRoid)
			rowidList.push_back(item.second.second);
	}
	vector<Expr*>tempexpr = BlockMgr::getInstance()->multipleGet(rowidList);
	vector<Expr*>::iterator iter;
	for (iter = tempexpr.begin(); iter != tempexpr.end(); iter++) {

		temp_attributeid = (*((*iter)->exprList))[0]->ival;

		if (temp_attributeid == attritubeid) {		//找到

			targetattribute->oid = ((*((*iter)->exprList))[0]->ival);

			targetattribute->relid = ((*((*iter)->exprList))[1]->ival);

			targetattribute->name = ((*((*iter)->exprList))[2]->name);

			targetattribute->type = ((*((*iter)->exprList))[3]->type);

			targetattribute->attnum = ((*((*iter)->exprList))[4]->ival);

			targetattribute->varcharlen = ((*((*iter)->exprList))[5]->ival);

			targetattribute->notnull = ((*((*iter)->exprList))[6]->ival);

			targetattribute->pkey = ((*((*iter)->exprList))[7]->ival);

			targetattribute->colcard = ((*((*iter)->exprList))[8]->ival);

			return targetattribute;
		}
	}
	return nullptr;			//如果都遍历完了还没找到，那么不存在这一项
}



vector<Attribute*>	Dict::GetAttribute(Index* index) {
	vector<Attribute*> allarrtibute;			//定义返回值

	vector<int>::iterator iter;
	for (iter = index->indkeys.begin(); iter != index->indkeys.end(); iter++) {		//按照attribute对应的所有属性id取出所有属性
		allarrtibute.push_back(GetAttribute(*iter));
	}

	return allarrtibute;

}


Index*	Dict::GetIndex(Class* tindex) {
	Index* targetindex = CreateIndex();			//创建一个空的Index用于装结果

	int indexrelid = tindex->oid;				//数据库对象（索引）对应的oid
	int temp_indexrelid;						//用于装读出的indexrelid
	string tempblockid = indexblock1;			//遍历文件用的块


	//遍历所有块，同时在文件中找到对应项目，并且判断indexrelid是否相等
	do {
		Block* tempblock = BlockMgr::getInstance()->getBlock(targetindex->fileid, tempblockid);

		vector<Expr*> tempexpr = tempblock->get(0, tempblock->GetRecordnum()-1);
		vector<Expr*>::iterator iter;
		for (iter = tempexpr.begin(); iter != tempexpr.end(); iter++) {

			temp_indexrelid = (*((*iter)->exprList))[0]->ival;

			if (temp_indexrelid == indexrelid) {		//找到

				targetindex->indexrelid = ((*((*iter)->exprList))[0]->ival);

				targetindex->indrelid = ((*((*iter)->exprList))[1]->ival);

				targetindex->indnatts = ((*((*iter)->exprList))[2]->ival);

				targetindex->name = ((*((*iter)->exprList))[3]->name);

				targetindex->indtype = *((*((*iter)->exprList))[4]->name);

				vector<Expr*> gg = *((*((*iter)->exprList))[5]->exprList);
				vector<Expr*>::iterator it;
				for (it = gg.begin(); it != gg.end(); it++) {
					targetindex->indkeys.push_back((*it)->ival);
				}

				return targetindex;
			}
		}

		tempblockid = tempblock->GetNextblockid();

	} while (tempblockid != "");						//如果下一个块的块号是空的话，表示所有文件都遍历完了

	return nullptr;			//如果都遍历完了还没找到，那么不存在这一项
}


void Dict::StoreUser(User* tuser) {
	tuser->StoreToFile();
}

void Dict::StoreDatabase(Database* tdatabase) {
	tdatabase->StoreToFile();
}

void Dict::StoreClass(Class* tclass) {
	tclass->StoreToFile();
}

void Dict::StoreAttribute(Attribute* tattribute) {
	tattribute->StoreToFile();
}

void Dict::StoreIndex(Index* tindex) {
	tindex->StoreToFile();
}

void Dict::UpdateUser(User * tuser)
{
	tuser->updateFile();
}

void Dict::UpdateDatabase(Database * tdatabase)
{
	tdatabase->updateFile();
}

void Dict::UpdateClass(Class * tclass)
{
	tclass->updateFile();
}

void Dict::UpdateAttribute(Attribute * tattribute)
{
	tattribute->updateFile();
}


string Dict::getRowid(int oid)
{
	return roidmap[oid].second;
}



/*-------------------------------------------------*/
Oid* Oid::instance = nullptr;

Oid::Oid(string tfilename) {
	filename = tfilename;
}

Oid * Oid::GetInstance()
{
	if (instance == nullptr) {
		instance = new Oid("./data/dict_oid.oid");
		instance->Load();
	}
	return instance;
}

void Oid::Release()
{
	if (instance != nullptr) {
		instance->Store();
		delete instance;
		instance = nullptr;
	}
}

int Oid::GetCurNum()
{
	return curnum++;
}

void Oid::Load()
{
	ifstream fin(filename, ios::in);
	fin >> curnum;
	fin.close();
}

void Oid::Store()
{
	ofstream fout(filename, ios::out);
	fout << curnum;
	fout.close();
}
/*-------------------------------------------------*/


/*-------------------------------------------------*/
User::User() {
	userid = 0;
	username = "";
	code = "";
	file file_user = file(0);
	fileid = file_user.fileid64;
}

int User::GetUserid() {
	return userid;
}

void User::SetUserid(int tuserid) {
	userid = tuserid;
}

string User::GetUsername() {
	return username;
}

void User::SetUsername(string tusername) {
	username = tusername;
}

string User::GetCode() {
	return code;
}

void User::SetCode(string tcode) {
	code = tcode;
}

void User::updateFile()
{
	//生成要放入的数据final
	Expr* expr_userid = Expr::makeLiteral((int64_t)userid);		//		##此处有问题
	Expr* expr_username = Expr::makeLiteral(username.data());
	Expr* expr_code = Expr::makeLiteral(code.data());
	vector<Expr*> exprlist;
	exprlist.push_back(expr_userid);
	exprlist.push_back(expr_username);
	exprlist.push_back(expr_code);
	Expr* final = Expr::makeArray(&exprlist);

	BlockMgr::getInstance()->update(Dict::getRowid(GetUserid()).c_str(),final);

}

void User::StoreToFile() {
	//Block* targetblock = BlockMgr::getInstance()->getBlock(fileid, userblock1);		//取得文件中第一个块

	//生成要放入的数据final
	Expr* expr_userid = Expr::makeLiteral((int64_t)userid);		//		##此处有问题
	Expr* expr_username = Expr::makeLiteral(username.data());
	Expr* expr_code = Expr::makeLiteral(code.data());
	vector<Expr*> exprlist;
	exprlist.push_back(expr_userid);
	exprlist.push_back(expr_username);
	exprlist.push_back(expr_code);
	Expr* final = Expr::makeArray(&exprlist);

	string rowid;
	Block* targetblock = BlockMgr::getInstance()->getLastAvailableBlock(fileid);		//取得file的最后一个可用的块
	rowid = targetblock->put(final);									//将数据放入可以放入的块
	targetblock->updateBuffer();

	Dict::roidmap[userid] =make_pair(UserRoid, rowid);
}



/*-------------------------------------------------*/


/*-------------------------------------------------*/
Database::Database()
{
	datconnlimit = 1;		//默认最大并发访问1个用户
	curconnect = 0;			//当前0个访问
	file file_database = file(1);
	fileid = file_database.fileid64;
}

int Database::GetOid() {
	return oid;
}

void Database::SetOid(int toid) {
	oid = toid;
}

string Database::GetDatName() {
	return datname;
}

void Database::SetDatName(string tdatname)
{
	datname = tdatname;
}

int Database::GetOwnerid() {
	return ownerid;
}

void Database::SetOwnerid(int townerid)
{
	ownerid = townerid;
}

int Database::GetDatconnlimit()
{
	return datconnlimit;
}

void Database::SetDatconnlimit(int tdatconnlimit)
{
	datconnlimit = tdatconnlimit;
}

void Database::SetDatacl(vector<int> tdatacl) {
	datacl = tdatacl;
}

bool Database::IsAvailable(int userid) {
	vector<int>::iterator iter;
	for (iter = datacl.begin(); iter != datacl.end(); iter++)
	{
		if ((*iter) == userid) {
			return true;			//该user有权限
		}
	}
	return false;
}

bool Database::CanConnect()
{
	if (curconnect < datconnlimit) {
		return true;			//小于最大连接数，可以连接
	}
}

void Database::Addconnect() {
	curconnect++;
}


void Database::updateFile()
{
	Expr* expr_oid = Expr::makeLiteral((int64_t)oid);
	Expr* expr_datname = Expr::makeLiteral(datname.data());
	Expr* expr_ownerid = Expr::makeLiteral((int64_t)ownerid);
	Expr* expr_datconnlimit = Expr::makeLiteral((int64_t)datconnlimit);
	Expr* expr_curconnect = Expr::makeLiteral((int64_t)curconnect);
	vector<Expr*> acl;
	vector<int>::iterator iter;
	for (iter = datacl.begin(); iter != datacl.end(); iter++)
	{
		acl.push_back(Expr::makeLiteral((int64_t)(*iter)));
	}
	Expr* expr_datacl = Expr::makeArray(&acl);

	//生成最终要放入的final
	vector<Expr*> exprlist;
	exprlist.push_back(expr_oid);
	exprlist.push_back(expr_datname);
	exprlist.push_back(expr_ownerid);
	exprlist.push_back(expr_datconnlimit);
	exprlist.push_back(expr_curconnect);
	exprlist.push_back(expr_datacl);
	Expr* final = Expr::makeArray(&exprlist);
	BlockMgr::getInstance()->update(Dict::getRowid(oid).c_str(), final);
}

void Database::StoreToFile() {
	//生成各条要放入的数据
	Expr* expr_oid = Expr::makeLiteral((int64_t)oid);
	Expr* expr_datname = Expr::makeLiteral(datname.data());
	Expr* expr_ownerid = Expr::makeLiteral((int64_t)ownerid);
	Expr* expr_datconnlimit = Expr::makeLiteral((int64_t)datconnlimit);
	Expr* expr_curconnect = Expr::makeLiteral((int64_t)curconnect);
	vector<Expr*> acl;
	vector<int>::iterator iter;
	for (iter = datacl.begin(); iter != datacl.end(); iter++)
	{
		acl.push_back(Expr::makeLiteral((int64_t)(*iter)));
	}
	Expr* expr_datacl = Expr::makeArray(&acl);

	//生成最终要放入的final
	vector<Expr*> exprlist;
	exprlist.push_back(expr_oid);
	exprlist.push_back(expr_datname);
	exprlist.push_back(expr_ownerid);
	exprlist.push_back(expr_datconnlimit);
	exprlist.push_back(expr_curconnect);
	exprlist.push_back(expr_datacl);
	Expr* final = Expr::makeArray(&exprlist);


	//放入块中
	string rowid;
	Block* targetblock = BlockMgr::getInstance()->getLastAvailableBlock(fileid);		//取得file的最后一个可用的块
	targetblock->setBlockType(dictionary);
	rowid = targetblock->put(final);									//将数据放入可以放入的块

	targetblock->updateBuffer();

	Dict::roidmap[oid] =make_pair(DatabaseRoid, rowid);
}

/*-------------------------------------------------*/

/*-------------------------------------------------*/
Class::Class()
{
	reltuples = 0;
	hasindex = 0;
	relnatts = 0;
	haspkey = 0;
	file file_class = file(2);
	fileid = file_class.fileid64;
}

void Class::AddTuples(int num)
{
	reltuples = reltuples + num;
}

void Class::DeleteTuples(int num) {
	reltuples = reltuples - num;
}

bool Class::HasIndex() {
	if (hasindex == 1) {
		return true;
	}
	else {
		return false;
	}
}

void Class::Setindex(bool t) {
	if (t == true)
		hasindex = 1;
	else
		hasindex = 0;
}

bool Class::HasPkey() {
	if (haspkey == 1) {
		return true;
	}
	else {
		return false;
	}
}

void Class::SetPkey(bool t) {
	if (t == true)
		haspkey = 1;
	else
		haspkey = 0;
}

void Class::updateFile()
{
	Expr* expr_oid = Expr::makeLiteral((int64_t)oid);
	Expr* expr_databaseid = Expr::makeLiteral((int64_t)databaseid);
	Expr* expr_relname = Expr::makeLiteral(relname.data());
	Expr* expr_relfileid = Expr::makeLiteral(relfileid.data());
	Expr* expr_relblockid = Expr::makeLiteral(relblockid.data());
	Expr* expr_reltuples = Expr::makeLiteral((int64_t)reltuples);
	Expr* expr_hasindex = Expr::makeLiteral((int64_t)hasindex);
	Expr* expr_relkind = Expr::makeLiteral(&relkind);
	Expr* expr_relnatts = Expr::makeLiteral((int64_t)relnatts);
	Expr* expr_haspkey = Expr::makeLiteral((int64_t)haspkey);

	//生成最终要放入的final
	vector<Expr*> exprlist;
	exprlist.push_back(expr_oid);
	exprlist.push_back(expr_databaseid);
	exprlist.push_back(expr_relname);
	exprlist.push_back(expr_relfileid);
	exprlist.push_back(expr_relblockid);
	exprlist.push_back(expr_reltuples);
	exprlist.push_back(expr_hasindex);
	exprlist.push_back(expr_relkind);
	exprlist.push_back(expr_relnatts);
	exprlist.push_back(expr_haspkey);
	Expr* final = Expr::makeArray(&exprlist);
	BlockMgr::getInstance()->update(Dict::getRowid(oid).c_str(), final);
}

void Class::StoreToFile() {
	//生成各条要放入的数据
	Expr* expr_oid = Expr::makeLiteral((int64_t)oid);
	Expr* expr_databaseid = Expr::makeLiteral((int64_t)databaseid);
	Expr* expr_relname = Expr::makeLiteral(relname.data());
	Expr* expr_relfileid = Expr::makeLiteral(relfileid.data());
	Expr* expr_relblockid = Expr::makeLiteral(relblockid.data());
	Expr* expr_reltuples = Expr::makeLiteral((int64_t)reltuples);
	Expr* expr_hasindex = Expr::makeLiteral((int64_t)hasindex);
	Expr* expr_relkind = Expr::makeLiteral(&relkind);
	Expr* expr_relnatts = Expr::makeLiteral((int64_t)relnatts);
	Expr* expr_haspkey = Expr::makeLiteral((int64_t)haspkey);

	//生成最终要放入的final
	vector<Expr*> exprlist;
	exprlist.push_back(expr_oid);
	exprlist.push_back(expr_databaseid);
	exprlist.push_back(expr_relname);
	exprlist.push_back(expr_relfileid);
	exprlist.push_back(expr_relblockid);
	exprlist.push_back(expr_reltuples);
	exprlist.push_back(expr_hasindex);
	exprlist.push_back(expr_relkind);
	exprlist.push_back(expr_relnatts);
	exprlist.push_back(expr_haspkey);
	Expr* final = Expr::makeArray(&exprlist);

	//放入块中
	string rowid;
	Block* targetblock = BlockMgr::getInstance()->getLastAvailableBlock(fileid);		//取得file的最后一个可用的块
	rowid = targetblock->put(final);									//将数据放入可以放入的块
	targetblock->updateBuffer();

	Dict::roidmap[oid] = make_pair(ClassRoid,rowid);
}


/*-------------------------------------------------*/

/*-------------------------------------------------*/
Attribute::Attribute() {
	varcharlen = 10;
	notnull = 0;
	pkey = 0;
	colcard = 0;
	file file_attribute = file(3);
	fileid = file_attribute.fileid64;
}

int Attribute::GetRelid() {
	return relid;
}

void Attribute::SetRelid(int trelid) {
	relid = trelid;
}

string Attribute::GetAttritubeName() {
	return name;
}

void Attribute::SetAttritubeName(string name) {
	this->name = name;
}

ExprType Attribute::GetType() {
	return type;
}

void Attribute::SetType(ExprType ttype) {
	type = ttype;
}

int Attribute::GetAttnum() {
	return attnum;
}

void Attribute::SetAttnum(int tnum) {
	attnum = tnum;
}

int Attribute::GetVarcharLength() {
	return varcharlen;
}

void Attribute::SetVarcharLength(int tlen) {
	varcharlen = tlen;
}

bool Attribute::IsNotNull() {
	if (notnull == 1) {
		return true;
	}
	else {
		return false;
	}
}

void Attribute::SetNotNull(bool t) {
	if (t == true)
		notnull = 1;
	else
		notnull = 0;
}

bool Attribute::IsPkey() {
	if (pkey == 1) {
		return true;
	}
	else {
		return false;
	}
}

void Attribute::SetPkey(bool t) {
	if (t == true)
		pkey = 1;
	else
		pkey = 0;
}

int Attribute::GetColcard() {
	return colcard;
}

void Attribute::CalculateColcard() {
	//此处需要调用统计方法，统计该属性的不同元组个数
}

void Attribute::updateFile()
{
	Expr* expr_oid = Expr::makeLiteral((int64_t)oid);
	Expr* expr_relid = Expr::makeLiteral((int64_t)relid);
	Expr* expr_name = Expr::makeLiteral(name.data());
	Expr* expr_type = Expr::makeLiteral((int64_t)type);
	Expr* expr_attnum = Expr::makeLiteral((int64_t)attnum);
	Expr* expr_varcharlen = Expr::makeLiteral((int64_t)varcharlen);
	Expr* expr_notnull = Expr::makeLiteral((int64_t)notnull);
	Expr* expr_pkey = Expr::makeLiteral((int64_t)pkey);
	Expr* expr_colcard = Expr::makeLiteral((int64_t)colcard);

	//生成最终要放入的final
	vector<Expr*> exprlist;
	exprlist.push_back(expr_oid);
	exprlist.push_back(expr_relid);
	exprlist.push_back(expr_name);
	exprlist.push_back(expr_type);
	exprlist.push_back(expr_attnum);
	exprlist.push_back(expr_varcharlen);
	exprlist.push_back(expr_notnull);
	exprlist.push_back(expr_pkey);
	exprlist.push_back(expr_colcard);
	Expr* final = Expr::makeArray(&exprlist);

	BlockMgr::getInstance()->update(Dict::getRowid(oid).c_str(), final);
}

void Attribute::StoreToFile() {
	//生成各条要放入的数据
	
	Expr* expr_oid = Expr::makeLiteral((int64_t)oid);
	Expr* expr_relid = Expr::makeLiteral((int64_t)relid);
	Expr* expr_name = Expr::makeLiteral(name.data());
	Expr* expr_type = Expr::makeLiteral((int64_t)type);
	Expr* expr_attnum = Expr::makeLiteral((int64_t)attnum);
	Expr* expr_varcharlen = Expr::makeLiteral((int64_t)varcharlen);
	Expr* expr_notnull = Expr::makeLiteral((int64_t)notnull);
	Expr* expr_pkey = Expr::makeLiteral((int64_t)pkey);
	Expr* expr_colcard = Expr::makeLiteral((int64_t)colcard);

	//生成最终要放入的final
	vector<Expr*> exprlist;
	exprlist.push_back(expr_oid);
	exprlist.push_back(expr_relid);
	exprlist.push_back(expr_name);
	exprlist.push_back(expr_type);
	exprlist.push_back(expr_attnum);
	exprlist.push_back(expr_varcharlen);
	exprlist.push_back(expr_notnull);
	exprlist.push_back(expr_pkey);
	exprlist.push_back(expr_colcard);
	Expr* final = Expr::makeArray(&exprlist);


	//放入块中
	string rowid;
	Block* targetblock = BlockMgr::getInstance()->getLastAvailableBlock(fileid);		//取得file的最后一个可用的块
	rowid =targetblock->put(final);									//将数据放入可以放入的块
	targetblock->updateBuffer();

	Dict::roidmap[oid] = make_pair(AttributeRoid,rowid);
}


/*-------------------------------------------------*/

/*-------------------------------------------------*/
Index::Index() {
	indtype = 'a';
	file file_index = file(4);
	fileid = file_index.fileid64;
}

int Index::GetIndexrelid() {
	return indexrelid;
}

void Index::SetIndexrelid(int tid)
{
	indexrelid = tid;
}

int Index::GetIndrelid() {
	return indrelid;
}

void Index::SetIndrelid(int tid) {
	indrelid = tid;
}

int Index::GetIndnatts() {
	return indnatts;
}

void Index::SetIndnatts(int tnum) {
	indnatts = tnum;
}

string Index::GetName() {
	return name;
}

void Index::SetName(string tname) {
	name = tname;
}

char Index::GetIndtype() {
	return indtype;
}

void Index::SetIndetype(char type) {
	indtype = type;
}

vector<int> Index::GetIndkeys() {
	return indkeys;
}

void Index::SetIndkeys(vector<int> keys) {
	indkeys = keys;
}

void Index::StoreToFile() {
	//生成各条要放入的数据
	Expr* expr_indexrelid = Expr::makeLiteral((int64_t)indexrelid);
	Expr* expr_indrelid = Expr::makeLiteral((int64_t)indrelid);
	Expr* expr_indnatts = Expr::makeLiteral((int64_t)indnatts);
	Expr* expr_name = Expr::makeLiteral(name.data());
	Expr* expr_indtype = Expr::makeLiteral(&indtype);
	vector<Expr*> acl;
	vector<int>::iterator iter;
	for (iter = indkeys.begin(); iter != indkeys.end(); iter++)
	{
		acl.push_back(Expr::makeLiteral((int64_t)(*iter)));
	}
	Expr* expr_indkeys = Expr::makeArray(&acl);

	//生成最终要放入的final
	vector<Expr*> exprlist;
	exprlist.push_back(expr_indexrelid);
	exprlist.push_back(expr_indrelid);
	exprlist.push_back(expr_indnatts);
	exprlist.push_back(expr_name);
	exprlist.push_back(expr_indtype);
	exprlist.push_back(expr_indkeys);
	Expr* final = Expr::makeArray(&exprlist);

	//放入块中
	string rowid;
	Block* targetblock = BlockMgr::getInstance()->getLastAvailableBlock(fileid);		//取得file的最后一个可用的块
	rowid = targetblock->put(final);									//将数据放入可以放入的块
	targetblock->updateBuffer();

}

/*-------------------------------------------------*/

