#include "DB.h"
#include "SQLParser.h"
#include "SQLParserResult.h"
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
}

void DB::run()
{
	//select id,name, height from player where money>100 and gender='male';
	//SELECT id,name,money from table1,table2 where table1.height>160;
	string input;
	bool running = true;
	while (running) {
		cout << ">";
		getline(cin, input);
		SQLParserResult res;
		SQLParser::parse(input,&res);
		if (!res.isValid()) {
			cout << res.errorMsg() << endl;
		}
		for (auto stm : res.getStatements()) {
			running=stm->execute();
		}
	}
}

void DB::terminate()
{
	Dict::release();
}
