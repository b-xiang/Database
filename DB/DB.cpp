#include "DB.h"
#include "SQLParser.h"
#include "SQLParserResult.h"
#include "serversocket.h"
#include "BufferMgr.h"
#include "IdxMgr.h"
#include "Dict.h"
#include <string>
#include <iostream>

using namespace std;
using namespace hsql;


DB* DB::instance = nullptr;

DB * DB::getInstance()
{
	if (instance == nullptr)
		instance = new DB();
	return instance;
}

void DB::release()
{
	if(instance!=nullptr)
		delete instance;
	instance = nullptr;
}

void DB::init()
{
	s= new ServerSocket;
}

void DB::run()
{
	s->run();
}

void DB::terminate()
{
	s->release();
	delete s;
	BufferMgr::release();
	IdxMgr::release();
	Dict::release();
	Dict::release();
}