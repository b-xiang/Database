#include "IdxMgr.h"
#include "BPlus_tree.h"

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

BPlusTree * IdxMgr::getBPT(int attrOid)
{
	return idx[attrOid];
}
