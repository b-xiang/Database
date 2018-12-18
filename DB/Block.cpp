#include "Block.h"
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>
#include <io.h>
#include <assert.h>
#include <direct.h>
#include "Convertor.h"
#include "Base64.h"
using namespace std;

Block::Block(string _fileid, string _blockid, BlockType _type)
{
	memset(buffer, 0, sizeof(buffer));
	blockType = _type;
	strcpy(databaseObjectID, Conv64::to_64(_type, 6).c_str());
	strcpy(fileid, _fileid.c_str());
	strcpy(blockid, _blockid.c_str());
	pctfree = 0;
	pctused = 0;
	recordnum = 0;
	metaEnd = 0;
	bodyBegin = BLOCK_SIZE;
}

Block::~Block()
{
}

bool Block::isAbleToInput(Expr* content)
{
	if (isFull())
		return false;
	return true;
	/////////////////////////////////////////////
}

bool Block::put(Expr* content)
{
	putStrategy* str=nullptr;
	if (content->type == kExprLiteralInt) 
		str = new putIntStrategy;
	else if (content->type == kExprLiteralFloat)
		str = new putFloatStrategy;
	else if (content->type == kExprLiteralString)
		str = new putStringStrategy;
	assert(str);
	bool res = str->put(this, content);
	delete str;
	return res;
}

Expr* Block::get(const char * rowid)
{
	string s(rowid);
	string doi = s.substr(0, 6);
	string fid = s.substr(6, 3);
	string bid = s.substr(9, 6);
	string rid = s.substr(15, 3);
	if (strcmp(doi.c_str(), databaseObjectID) != 0 || strcmp(fid.c_str(), fileid) != 0 || strcmp(bid.c_str(), blockid) != 0)
		throw "*** Error! Row ID does not match!";
	return get(atoi(Conv64::to_10(rid).c_str()));
}

vector<Expr*> Block::get(const char * fromrowid, const char * torowid)
{
	string fs(fromrowid);
	string fdoi = fs.substr(0, 6);
	string ffid = fs.substr(6, 3);
	string fbid = fs.substr(9, 6);
	string frid = fs.substr(15, 3);
	string ts(torowid);
	string tdoi = ts.substr(0, 6);
	string tfid = ts.substr(6, 3);
	string tbid = ts.substr(9, 6);
	string trid = ts.substr(15, 3);
	if (strcmp(fdoi.c_str(), databaseObjectID) != 0 || strcmp(ffid.c_str(), fileid) != 0 || strcmp(fbid.c_str(), blockid) != 0 || strcmp(tdoi.c_str(), databaseObjectID) != 0 || strcmp(tfid.c_str(), fileid) != 0 || strcmp(tbid.c_str(), blockid) != 0)
		throw "*** Error! Row ID does not match!";
	return get(atoi(Conv64::to_10(frid).c_str()), atoi(Conv64::to_10(trid).c_str()));
}

vector<Expr*> Block::getFromXToEnd(const char * fromrowid)
{
	string s(fromrowid);
	string doi = s.substr(0, 6);
	string fid = s.substr(6, 3);
	string bid = s.substr(9, 6);
	string rid = s.substr(15, 3);
	if (strcmp(doi.c_str(), databaseObjectID) != 0 || strcmp(fid.c_str(), fileid) != 0 || strcmp(bid.c_str(), blockid) != 0)
		throw "*** Error! Row ID does not match!";
	return get(atoi(Conv64::to_10(rid).c_str()), recordnum - 1);
}

vector<Expr*> Block::getFromFrontToX(const char * torowid)
{
	string s(torowid);
	string doi = s.substr(0, 6);
	string fid = s.substr(6, 3);
	string bid = s.substr(9, 6);
	string rid = s.substr(15, 3);
	if (strcmp(doi.c_str(), databaseObjectID) != 0 || strcmp(fid.c_str(), fileid) != 0 || strcmp(bid.c_str(), blockid) != 0)
		throw "*** Error! Row ID does not match!";
	return get(0, atoi(Conv64::to_10(rid).c_str()));
}

string Block::generateRowID()
{
	stringstream ss;
	ss << databaseObjectID << fileid << blockid << Conv64::to_64(recordnum,3);
	return ss.str();
}

bool Block::writeToFile()
{
	_mkdir("data");
	int isExist = _access(getFileName().c_str(), 0);
	if (isExist==-1) {
		ofstream o(getFileName(), ios::out);
		o.close();
	}
	fstream nodeFile(getFileName(), ios::binary | ios::out | ios::in);
	if (!nodeFile)
		return false;
	updateBuffer();
	nodeFile.seekp(BLOCK_SIZE*atoi(Conv64::to_10(blockid).c_str()));
	nodeFile.write(buffer, BLOCK_SIZE);
	nodeFile.close();
	return true;
}

bool Block::readFromFile()
{
	fstream nodeFile(getFileName(), ios::binary | ios::in);
	if (!nodeFile)
		return false;
	nodeFile.seekg(BLOCK_SIZE*atoi(Conv64::to_10(blockid).c_str()));
	nodeFile.read(buffer, BLOCK_SIZE);
	nodeFile.close();
	return true;
}

void Block::writeToBuffer(int begin, char * text)
{
	strcpy(buffer + begin, text);
}

int Block::getMetaEnd()
{
	return metaEnd;
}

void Block::setMetaEnd(int _metaEnd)
{
	metaEnd = _metaEnd;
}

int Block::getBodyBegin()
{
	return bodyBegin;
}

void Block::setBodyBgein(int _bodyBegin)
{
	bodyBegin = _bodyBegin;
}


void Block::updateBuffer()
{
	char buff[BLOCK_SIZE];
	memset(buff, 0, sizeof(buff));
	metaEnd = 0;
	memcpy(buffer + metaEnd, databaseObjectID, sizeof(databaseObjectID));
	metaEnd += sizeof(databaseObjectID) - 1;
	memcpy(buffer + metaEnd, fileid, sizeof(fileid));
	metaEnd += sizeof(fileid) - 1;
	memcpy(buffer + metaEnd, blockid, sizeof(blockid));
	metaEnd += sizeof(blockid);

	strcpy(buff,Conv64::to_64(recordnum).c_str());
	strcpy(buffer + metaEnd, buff);
	metaEnd += strlen(buff) + 1;
	
	for (int i = 0; i < recordnum; i++) {
		strcpy(buff, Conv64::to_64(recordpos[i]).c_str());
		strcpy(buffer + metaEnd, buff);
		metaEnd += strlen(buff) + 1;
	}
	for (int i = 0; i < recordnum; i++) {
		strcpy(buff, Conv64::to_64(dataType[i]).c_str());
		strcpy(buffer + metaEnd, buff);
		metaEnd += strlen(buff) + 1;
	}

	strcpy(buff, Conv64::to_64(bodyBegin).c_str());
	strcpy(buffer + metaEnd, buff);
	metaEnd += strlen(buff) + 1;

	pctfree = (bodyBegin - metaEnd - 2 * sizeof(float) + 0.0f) / BLOCK_SIZE;
	pctused = (metaEnd + (BLOCK_SIZE - bodyBegin) + 2 * sizeof(float)) / BLOCK_SIZE;
	memcpy(buffer + metaEnd, &pctfree, sizeof(pctfree));
	metaEnd += sizeof(pctfree);
	memcpy(buffer + metaEnd, &pctused, sizeof(fileid));
	metaEnd += sizeof(pctused);
}

void Block::updateVar()
{
	long location = 0;
	char buff[BLOCK_SIZE];
	memset(buff, 0, sizeof(buff));
	strcpy(buff, buffer+location);
	location += strlen(buff)+1;
	string s(buff);
	strcpy(databaseObjectID, s.substr(0, 6).c_str());
	strcpy(fileid, s.substr(6, 3).c_str());
	strcpy(blockid, s.substr(9, 6).c_str());

	strcpy(buff, buffer + location);
	location += strlen(buff)+1;
	recordnum = atoi(Conv64::to_10(buff).c_str());

	for (int i = 0; i < recordnum; i++) {
		strcpy(buff, buffer + location);
		location += strlen(buff) + 1;
		recordpos.push_back(atoi(Conv64::to_10(buff).c_str()));
	}
	for (int i = 0; i < recordnum; i++) {
		strcpy(buff, buffer + location);
		location += strlen(buff) + 1;
		dataType.push_back((ExprType)atoi(Conv64::to_10(buff).c_str()));
	}

	strcpy(buff, buffer + location);
	location += strlen(buff) + 1;
	bodyBegin = atoi(Conv64::to_10(buff).c_str());

	memcpy(&pctfree, buffer + location, sizeof(pctfree));
	location += sizeof(pctfree);
	memcpy(&pctused, buffer + location, sizeof(fileid));
	location += sizeof(pctused);
}

bool Block::isFull()
{
	if (pctfree < PCT_FREE_THRESHOLD || pctused>PCT_USED_THRESHOLD)
		return true;
	return false;
}

const char * Block::getFileid()
{
	return fileid;
}

const char * Block::getBlockid()
{
	return blockid;
}

string Block::getFileName()
{
	stringstream ss;
	ss << "./data/data_" << fileid << ".db";
	return ss.str();
}

Expr* Block::get(int idx)
{
	ExprType type = dataType[idx];
	getStrategy*str = getGetStrategy(type);
	Expr * res = str->get(this, idx);
	delete str;
	return res;
}

vector<Expr*> Block::get(int fromidx, int toidx)
{
	vector<Expr*> res;
	getStrategy* str[4];
	str[0] = getGetStrategy(kExprLiteralInt);
	str[1] = getGetStrategy(kExprLiteralFloat);
	str[2] = getGetStrategy(kExprLiteralString);
	str[3] = getGetStrategy(kExprArray);

	for (int i = fromidx; i <= toidx; i++) {
		ExprType type = dataType[i];
		if (type == kExprLiteralInt)
			res.push_back(str[0]->get(this, i));
		else if (type == kExprLiteralFloat)
			res.push_back(str[1]->get(this, i));
		else if (type == kExprLiteralString)
			res.push_back(str[2]->get(this, i));
		else if (type == kExprArray)
			res.push_back(str[3]->get(this, i));
	}
	for (int i = 0; i < 4; i++) delete str[i];
	
	return res;
}

bool Block::putIntStrategy::put(Block *blk, Expr* e)
{
	string content = Conv64::to_64(e->ival);
	blk->bodyBegin=blk->bodyBegin - content.length() - 1;	//-1是为了给base64型的数据加一位\0
	strcpy(blk->buffer + blk->bodyBegin, content.c_str());
	blk->recordnum++;
	blk->dataType.push_back(e->type);
	blk->recordpos.push_back(blk->bodyBegin);
	blk->updateBuffer();
	return true;
}

bool Block::putFloatStrategy::put(Block *blk, Expr* e)
{
	blk->bodyBegin = blk->bodyBegin - sizeof(double);
	memcpy(blk->buffer + blk->bodyBegin, &e->fval, sizeof(double));
	blk->recordnum++;
	blk->dataType.push_back(e->type);
	blk->recordpos.push_back(blk->bodyBegin);
	blk->updateBuffer();
	return true;
}

bool Block::putStringStrategy::put(Block *blk, Expr* e)
{
	char buff[BLOCK_SIZE];
	memset(buff, 0, sizeof(buff));
	b64_encode(e->name, strlen(e->name), buff);
	blk->bodyBegin = blk->bodyBegin - strlen(buff) - 1;
	strcpy(blk->buffer + blk->bodyBegin, buff);
	blk->recordnum++;
	blk->dataType.push_back(e->type);
	blk->recordpos.push_back(blk->bodyBegin);
	blk->updateBuffer();
	return true;
}

bool Block::putArrayStrategy::put(Block * blk, Expr * e)
{
	putStrategy* str=nullptr;
	for (auto item : *e->exprList) {
		delete str;
		str = nullptr;
		str = Block::getPutStrategy(item->type);
		str->put(blk, e);
	}
	return true;
}


Expr* Block::getStringStrategy::get(Block * blk, int idx)
{
	char buff[BLOCK_SIZE];
	char decode[BLOCK_SIZE];
	memset(buff, 0, sizeof(buff));
	memset(decode, 0, sizeof(decode));
	int from=blk->recordpos[idx];
	strcpy(buff, blk->buffer + from);
	b64_decode(buff, strlen(buff), decode);
	Expr* e = Expr::makeLiteral(decode);
	return e;
}

Expr* Block::getFloatStrategy::get(Block * blk, int idx)
{
	double res;
	int from = blk->recordpos[idx];
	memcpy(&res, blk->buffer + from, sizeof(res));
	Expr* e=Expr::makeLiteral(res);
	return e;
}

Expr* Block::getIntStrategy::get(Block * blk, int idx)
{
	char buff[BLOCK_SIZE];
	char decode[BLOCK_SIZE];
	memset(buff, 0, sizeof(buff));
	memset(decode, 0, sizeof(decode));
	int from = blk->recordpos[idx];
	strcpy(buff, blk->buffer + from);
	strcpy(decode,Conv64::to_10(buff).c_str());
	Expr* e=Expr::makeLiteral((int64_t)atoi(decode));
	return e;
}

Expr * Block::getArrayStrategy::get(Block * blk, int idx)
{
	vector<Expr*>* vec = new vector<Expr*>;
	int n = 0;//需要从数据字典中获取
	for (int i = 0; i < n; i++) {
		getStrategy* str = getGetStrategy(blk->dataType[idx + i]);
		vec->push_back(str->get(blk,idx+i));
	}
	return Expr::makeArray(vec);
}