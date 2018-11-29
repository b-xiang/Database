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
using namespace std;
int main() {
	vector<string> fid;
	vector<string> blkid;
	BlockMgr* blkmgr = BlockMgr::getInstance();
	fid.push_back(blkmgr->allocFile());
	blkid.push_back(blkmgr->allocBlock(fid[0], table));
	blkid.push_back(blkmgr->allocBlock(fid[0], table));
	blkid.push_back(blkmgr->allocBlock(fid[0], table));
	fid.push_back(blkmgr->allocFile());
	blkid.push_back(blkmgr->allocBlock(fid[1], index));
	blkid.push_back(blkmgr->allocBlock(fid[1], dictionary));
}
#endif // !DEBUG
