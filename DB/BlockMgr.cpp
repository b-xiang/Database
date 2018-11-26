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
	delete b;
	b = nullptr;
}

bool BlockMgr::isFileFull(const char * fileid)
{
	return getFile(fileid)->blockNum >= BLOCK_NUM;
}

bool BlockMgr::isAbleToInput(const char * fileid, const char * blockid, Expr content)
{
	Block* blk = getBlock(fileid, blockid);
	return blk->isAbleToInput(content);
	delete blk;
}

bool BlockMgr::isAbleToInput(Block* block, Expr content)
{
	return block->isAbleToInput(content);
}

const char * BlockMgr::allocBlock(const char * fileid, BlockType bt)
{
	delete b;
	b = nullptr;
	file* curfile = getFile(fileid);
	curfile->blockNum++;
	const char * blkid = Conv64::to_64(curfile->blockNum).c_str();
	Block *blk = new Block(bt, curfile->fileid64, blkid);
	blk->writeToFile();
	delete blk;
	return blkid;
}

const char * BlockMgr::allocFile()
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

Block* BlockMgr::getBlock(const char * fileid, const char * blockid)
{
	Block*blk = new Block(fileid, blockid);
	blk->readFromFile();
	return blk;
}

file * BlockMgr::getFile(const char * fileid)
{
	for (auto item : files) {
		if (strcmp(item.fileid64, fileid) == 0)
			return &item;
	}
	return nullptr;
}
