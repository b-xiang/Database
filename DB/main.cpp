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
using namespace std;
int main() {
	system("clear.bat");
	vector<string> fid;
	vector<string> blkid;
	vector<string> rowid;
	BlockMgr* blkmgr = BlockMgr::getInstance();
	fid.push_back(blkmgr->allocFile());
	blkid.push_back(blkmgr->allocBlock(fid[0], table));
	blkid.push_back(blkmgr->allocBlock(fid[0], table));
	blkid.push_back(blkmgr->allocBlock(fid[0], table));
	fid.push_back(blkmgr->allocFile());
	blkid.push_back(blkmgr->allocBlock(fid[1], index));
	blkid.push_back(blkmgr->allocBlock(fid[1], dictionary));

	for (int i = 0; i < 50; i++) {
		Block* blk = blkmgr->getBlock(fid[0], blkid[0]);
		Expr* e=Expr::makeLiteral((int64_t)i + 32);
		rowid.push_back(blk->generateRowID());
		blk->put(e);
		Expr *e1=Expr::makeLiteral("hello world");
		rowid.push_back(blk->generateRowID());
		blk->put(e1);
		Expr* e2=Expr::makeLiteral(2.31+i);
		rowid.push_back(blk->generateRowID());
		blk->put(e2);
		blk->writeToFile();
		delete e;
		delete e1;
		delete e2;
		delete blk;
	}
	for (int i = 0; i < 150; i++) {
		Block* blk= blkmgr->getBlock(fid[0], blkid[0]);
		Expr* e = blk->get(rowid[i].c_str());
		if (e->type == kExprLiteralFloat) {
			cout << e->fval << endl;
		}
		else if (e->type == kExprLiteralInt) {
			cout << e->ival << endl;
		}
		else if (e->type == kExprLiteralString) {
			cout << e->name << endl;
		}
		delete e;
		delete blk;
	}

	//select id,name, height from player where money>100 and gender='male';
	//SELECT id,name,money from table1,table2 where table1.height>160;
	//insert into stu (id,height,name) values (1,2.2,'sad');
	string input;
	while (true) {
		cout << ">";
		getline(cin, input);
		SQLParserResult res;
		SQLParser::parse(input, &res);
		if (!res.isValid()) {
			cout << res.errorMsg() << endl;
		}
		for (auto stm : res.getStatements()) {
			stm->execute();
		}
	}
}
#endif // !DEBUG
