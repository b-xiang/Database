#include "DB.h"
//#define DEBUG
#define STAND_ALONE
//#define RELEASE


#ifdef DEBUG
#include "BlockMgr.h"
#include "vector"
#include "Block.h"
#include "sql/Expr.h"
#include <Windows.h>
#include <iostream>
#include "SQLParser.h"
#include "SQLParserResult.h"
#include "Dict.h"
#include "Timer.h"
using namespace std;
using namespace hsql;
int main() {
	system("clear.bat");
	system("pause");
}

#endif	//	DEBUG

#ifdef STAND_ALONE
#include <string>
#include <iostream>
#include <sstream>
#include "SQLParser.h"
using namespace hsql;
using namespace std;

int main() {
	system("clear.bat");

	char buff[1024];
	string s;
	while (true) {
		stringstream ss;
		SQLParserResult res;
		cout << ">";
		cin.getline(buff, 1024);
		s = string(buff);
		if (s == "q")
			break;
		SQLParser::parse(s, &res);
		if (!res.isValid()) {
			cout << res.errorMsg() << endl;
		}
		for (auto stm : res.getStatements()) {
			ss << stm->execute();
		}
		cout << ss.str();
	}
	return 0;
}
#endif // STAND_ALONE

#ifdef RELEASE
int main() {

	DB * db = DB::getInstance();

	db->init();
	db->run();
	db->terminate();

	DB::release();
	return 0;
}
#endif // RELEASE