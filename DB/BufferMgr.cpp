#include"BufferMgr.h"
#include "Block.h"
#include<stdlib.h>
#include<iostream>
using namespace std;
BufferMgr* BufferMgr::instance = nullptr;

BufferMgr * BufferMgr::getInstance()
{
	if (instance == nullptr) {
		instance = new BufferMgr;
	}	
	return instance;
}

void BufferMgr::release()
{
	delete instance;
	instance = nullptr;
}

BufferMgr::~BufferMgr()
{
}
void BufferMgr::initialBuffer() {
	string s = "-1";
	BufferBlock* curblk = NULL;
	for (int i = 0; i < DATA_BUFFER_BLOCK_NUM; i++) {
		if (head == NULL) {
			head = new BufferBlock();
			head->blk = new Block(s,s);
			head->next = NULL;
			curblk = head;
		}
		else {
			curblk->next=new BufferBlock();
			curblk->next->blk = new Block(s, s);
			curblk->next->next = NULL;
			curblk = curblk->next;
		}
	}
}
Block* BufferMgr::findBlockById(string fileid, string blockid) {
	string s = "-1";
	if (head == NULL)
		initialBuffer();
	BufferBlock* m = head;
	BufferBlock* n = NULL;
	while (m != NULL) {
		//如果找到
		if ((strcmp(m->blk->getFileid(),fileid.c_str()) == 0) && (strcmp(m->blk->getBlockid(), blockid.c_str()) == 0)) {
			if (m != head) {//如果不在队首
				n->next = m->next;
				m->next = head;
				head = m;
			}
			return head->blk;//根据LRU已经把要操作的块放到了头部
		}
		n = m;
		m = m->next;
	}
	//跳出循环说明缓冲区中没找到
	m = head;
	if (m->next != NULL) {//lru 将内存队列中的最后一个块放在队首
		while (m->next->next != NULL) {
			m = m->next;
		}
		m->next->next = head;
		head = m->next;
		m->next = NULL;
	}
	if ((strcmp(head->blk->getFileid(), s.c_str()) != 0) && (strcmp(head->blk->getBlockid(), s.c_str()) != 0)) {
		head->blk->updateBuffer();
		head->blk->writeToFile();
	}
	head->blk = new Block(fileid, blockid);
	head->blk->readFromFile();
	head->blk->updateVar();
	return head->blk;
}
void BufferMgr::print() {
	BufferBlock* m = head;
	while (m != NULL) {
		cout << m->blk->getFileid() << "  " << m->blk->getBlockid() << endl;
		m = m->next;
	}
}
void BufferMgr::deleteBufferBlock(string fileid, string blockid) {
	string s = "-1";
	BufferBlock* m = head;
	BufferBlock* n = NULL;
	while (m != NULL) {
		if ((strcmp(m->blk->getFileid(), fileid.c_str()) == 0) && (strcmp(m->blk->getBlockid(), blockid.c_str()) == 0))
			break;
		n = m;
		m = m->next;
	}
	if (head == m) {
		head = m->next;
		delete m;
		m = head;
		while (m->next != NULL) {
			m = m->next;
		}
		m->next = new BufferBlock();
		m->next->next = NULL;
		m->next->blk = new Block(s, s);
	}
	else if (m->next == NULL) {
		n->next = NULL;
		delete m;
		m = head;
		while (m->next != NULL) {
			m = m->next;
		}
		m->next = new BufferBlock();
		m->next->next = NULL;
		m->next->blk = new Block(s, s);
	}
	else {
		n->next = m->next;
		delete m;
		m = head;
		while (m->next != NULL) {
			m = m->next;
		}
		m->next = new BufferBlock();
		m->next->next = NULL;
		m->next->blk = new Block(s, s);
	}
}
