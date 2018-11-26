#include "DB.h"
int main() {
	
	DB * db = DB::getInstance();
	
	db->init();
	db->run();
	db->terminate();

	DB::release();
	return 0;
}