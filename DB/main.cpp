#include "DB.h"
#define DEBUG


#ifndef DEBUG
int main() {
	DB * db = DB::getInstance();

	db->init();
	db->run();
	db->terminate();

	DB::release();
	return 0;
}
#else
#include "BlockMgr.h"
#include "vector"
#include "Block.h"
#include "sql/Expr.h"
#include <Windows.h>
#include <iostream>
#include "SQLParser.h"
#include "SQLParserResult.h"
#include "Timer.h"
using namespace std;
using namespace hsql;
int main() {
	system("clear.bat");
	/*vector<Expr*> src;
	vector<string> rowid;
	vector<Expr*> res;
	for (int i = 0; i < 10000; i++) {
		src.push_back(Expr::makeLiteral((int64_t)i));
		src.push_back(Expr::makeLiteral("hello world"));
		src.push_back(Expr::makeLiteral(3.14*i));
	}
	rowid = BlockMgr::getInstance()->multiplePut(src);
	res = BlockMgr::getInstance()->multipleGet(rowid);
	for (auto r : res) {
		
	}*/
	cout<<Timer::getCurTime();
	system("pause");
}
#endif // !DEBUG
