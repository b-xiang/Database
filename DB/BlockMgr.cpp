#include "BlockMgr.h"
#include "Block.h"

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
	return blk->isAbleToInput(content);
	delete blk;
}

bool BlockMgr::isAbleToInput(Block* block, Expr* content)
{
	return block->isAbleToInput(content);
}

string BlockMgr::allocBlock(string fileid, BlockType bt)
{
	file* curfile = getFile(fileid);
	string blkid = Conv64::to_64(curfile->blockNum,6);
	Block *blk = new Block(bt, curfile->fileid64, blkid.c_str());
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
	file newfile=file(maxid + 1);
	files.push_back(newfile);
	return files[files.size()-1].fileid64;
}

Block * BlockMgr::getBlock(string fileid, string blockid)
{
	Block*blk = new Block(fileid, blockid);
	return blk;
}

file * BlockMgr::getFile(string fileid)
{
	for (int i = 0; i < files.size();i++) {
		if (strcmp(files[i].fileid64, fileid.c_str()) == 0)
			return &files[i];
	}
	return nullptr;
}
