#include "IdxMgr.h"

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
}
