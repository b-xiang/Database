#include "IdxMgr.h"
#include "BPlus_tree.h"
#include <string>
using namespace hsql;
using namespace std;

IdxMgr* IdxMgr::instance = nullptr;

IdxMgr * IdxMgr::getInstance()
{
	if (instance == nullptr)
		instance = new IdxMgr;
	return instance;
}

void IdxMgr::release()
{
	delete instance;
	instance = nullptr;
}

IdxMgr::~IdxMgr()
{
	for (auto i : idx) {
		delete i.second;
	}
}

bool IdxMgr::hasIdx(int attrOid)
{
	return idx[attrOid] != nullptr;
}

void IdxMgr::createIdx(int attrOid)
{
	if (hasIdx(attrOid))
		return;
	idx[attrOid] = new BPlusTree;
}

void IdxMgr::addRecord(int attrOid, Expr * expr, string rid)
{
	BPlusTree* bpt = getBPT(attrOid);
	BPTKeyType key = generateKey(expr);
	bpt->insert(key, rid);
}

void IdxMgr::removeRecord(int attrOid, hsql::Expr * expr)
{
	BPlusTree* bpt = getBPT(attrOid);
	BPTKeyType key = generateKey(expr);
	bpt->remove(key);
}

vector<BPTDataType> IdxMgr::getRowids(int attrOid, vector<Expr*> expr)
{
	vector<BPTDataType> res;
	BPlusTree* bpt = getBPT(attrOid);
	for (auto e : expr) {
		auto r = bpt->select(generateKey(e), generateKey(e));
		res.insert(res.begin(),r.begin(),r.end());
	}
	return res;
}

vector<BPTDataType> IdxMgr::getRowids(int attrOid)
{
	BPlusTree* bpt = getBPT(attrOid);
	return bpt->getAllValues();
}

vector<BPTDataType> IdxMgr::getRowids(int attrOid, hsql::Expr * expr, COMPARE_OPERATOR cmp)
{
	BPlusTree* bpt = getBPT(attrOid);
	return bpt->select(generateKey(expr), cmp);
}

BPlusTree * IdxMgr::getBPT(int attrOid)
{
	return idx[attrOid];
}

BPTKeyType IdxMgr::generateKey(hsql::Expr * expr)
{
	BPTKeyType key;
	if (expr->type == kExprLiteralInt) {
		key = expr->ival;
	}
	else if (expr->type == kExprLiteralFloat) {
		key = expr->fval;
	}
	else if (expr->type == kExprLiteralString) {
		BPTKeyType res = 0;
		BPTKeyType mask = 1;
		for (unsigned int i = 0; i < strlen(expr->name); i++) {
			res += (expr->name[i] - '0')*mask;
			mask /= 100;
		}
		key = res;
	}
	return key;
}
