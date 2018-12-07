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
	for (auto tbl : tbls) {
		for (auto col : tbl->cols) {
			delete col->root;
			delete col;
		}
		delete tbl;
	}
}

bool IdxMgr::hasIdx(Expr * columnRef)
{
	for (auto tbl : tbls) 
		if (tbl->tableRef == columnRef->table) 
			for (auto col : tbl->cols) 
				if (col->colRef == columnRef->name)
					return true;
	return false;
}

void IdxMgr::createIdx(Expr * columnRef)
{
	if (hasIdx(columnRef))
		return;
	for (auto tbl : tbls)
		if (tbl->tableRef == columnRef->table) {
			tbl->cols.push_back(new col_idx(columnRef->name, new BPlusTree));
			return;
		}
	tbl_idx* idx=new tbl_idx(columnRef->table);
	idx->cols.push_back(new col_idx(columnRef->name, new BPlusTree));
	tbls.push_back(idx);
}

BPlusTree * IdxMgr::getBPT(Expr * columnRef)
{
	if(!hasIdx(columnRef))
		return nullptr;
	for (auto tbl : tbls)
		if (tbl->tableRef == columnRef->table)
			for (auto col : tbl->cols)
				if (col->colRef == columnRef->name)
					return col->root;
}
