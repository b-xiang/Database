#include "BlockMgr.h"
#include "Block.h"
#include "BufferMgr.h"

BlockMgr* BlockMgr::instance = nullptr;

BlockMgr * BlockMgr::getInstance()
{
	if (instance == nullptr)
		instance = new BlockMgr;
	return instance;
}

void BlockMgr::release()
{
	delete instance;
	instance = nullptr;
}

BlockMgr::~BlockMgr()
{
}

bool BlockMgr::isFileFull(string fileid)
{
	return getFile(fileid)->blockNum >= BLOCK_NUM;
}

bool BlockMgr::isAbleToInput(string fileid, string blockid, Expr* content)
{
	Block* blk = getBlock(fileid, blockid);
	bool res = blk->isAbleToInput(content);
	delete blk;
	return res;
}

bool BlockMgr::isAbleToInput(Block* block, Expr* content)
{
	return block->isAbleToInput(content);
}

string BlockMgr::allocBlock(string fileid, BlockType bt)
{
	file* curfile = getFile(fileid);
	string blkid = Conv64::to_64(curfile->blockNum, 6);
	Block *blk = new Block(curfile->fileid64, blkid.c_str(), bt);
	blk->writeToFile();
	delete blk;
	curfile->blockNum++;
	return blkid;
}

string BlockMgr::allocFile()
{
	int maxid = -1;
	for (auto item : files) {
		if (item.fileid > maxid)
			maxid = item.fileid;
	}
	file newfile = file(maxid + 1);
	files.push_back(newfile);
	return files[files.size() - 1].fileid64;
}

Block * BlockMgr::getBlock(string fileid, string blockid)
{
	BufferMgr*mgr=BufferMgr::getInstance();
	return mgr->findBlockById(fileid, blockid);
}

file* BlockMgr::getFile(string fileid)
{
	for (int i = 0; i < files.size(); i++) {
		if (strcmp(files[i].fileid64, fileid.c_str()) == 0)
			return &files[i];
	}
}


vector<string> BlockMgr::multiplePut(vector<Expr*> records)
{
	vector<string> res;

	file* curfile = getLastAvailableFile();
	if (curfile == nullptr) {
		allocFile();
		curfile = getLastAvailableFile();
	}
	Block* curblk = getLastAvailableBlock(curfile->fileid64);
	if (curblk == nullptr) {
		allocBlock(curfile->fileid64);
		curblk = getLastAvailableBlock(curfile->fileid64);
	}

	for (auto r : records) {
		if (isFileFull(curfile->fileid64) && curblk->isFull()) {
			allocFile();
			curfile = getLastAvailableFile();
			releaseBlk(curblk);
			curblk = nullptr;
			curblk = getLastAvailableBlock(curfile->fileid64);
		}
		if (curblk->isFull()) {
			allocBlock(curfile->fileid64);
			releaseBlk(curblk);
			curblk = nullptr;
			curblk = getLastAvailableBlock(curfile->fileid64);
		}
		if (curblk->isAbleToInput(r)) {
			res.push_back(curblk->generateRowID());
			curblk->put(r);
		}
		else {
			if (isFileFull(curfile->fileid64)) {
				allocFile();
				curfile = getLastAvailableFile();
				releaseBlk(curblk);
				curblk = nullptr;
				curblk = getLastAvailableBlock(curfile->fileid64);
			}
			else {
				allocBlock(curfile->fileid64);
				releaseBlk(curblk);
				curblk = nullptr;
				curblk = getLastAvailableBlock(curfile->fileid64);
			}
			curblk->put(r);
		}
	}
	releaseBlk(curblk);
	return res;
}

vector<Expr*> BlockMgr::multipleGet(vector<string> rowids)
{
	vector<Expr*> res;
	string hisdoi, hisfid, hisbid, hisrid;
	file* curfile;
	Block* curblk = nullptr;
	for (auto id : rowids) {
		string s(id);
		string doi = s.substr(0, 6);
		string fid = s.substr(6, 3);
		string bid = s.substr(9, 6);
		string rid = s.substr(15, 3);
		if (doi != hisdoi)
			hisdoi = doi;
		if (fid != hisfid) {
			hisfid = fid;
			curfile = getFile(fid);
		}
		if (bid != hisbid) {
			hisbid = bid;
			releaseBlk(curblk);
			curblk = nullptr;
			curblk = getBlock(curfile->fileid64, bid);
		}
		res.push_back(curblk->get(id.c_str()));
	}
	return res;
}

file* BlockMgr::getLastAvailableFile()
{
	if (files.size() == 0)
		return nullptr;
	file* curfile = &files[files.size() - 1];
	if (!isFileFull(curfile->fileid64))
		return curfile;
	else
		return nullptr;
}

Block * BlockMgr::getLastAvailableBlock(string fileid)
{
	file* curfile = getFile(fileid);
	if (curfile->blockNum == 0)
		allocBlock(fileid);

	Block * curblk = BufferMgr::getInstance()->findBlockById(fileid, Conv64::to_64(curfile->blockNum - 1, 6));
	if (curblk->isFull()) {
		string blockid = allocBlock(fileid, curblk->getBlockType());
		curblk->setNextBlockid(blockid);
		curblk = BufferMgr::getInstance()->findBlockById(fileid, blockid);
	}
	return curblk;
}

void BlockMgr::releaseBlk(Block * blk)
{
	if (blk == nullptr)
		return;
	blk->writeToFile();
	delete blk;
}
