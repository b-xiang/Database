#ifndef GLOBAL_H
#define GLOBAL_H

//������������
typedef signed char int8;
typedef unsigned char uint8;
typedef unsigned int uint;
typedef unsigned short uint16;
typedef short int16;
typedef uint uint32;
typedef int int32;
typedef long KeyType;
typedef long DataType;

//B+�����ֵ�ȫ�ֱ���
const int ORDER = 20;						// B+���Ľף��Ǹ��ڽ�����С����������
const int MINNUM_KEY = ORDER - 1;			// ��С��ֵ����
const int MAXNUM_KEY = 2 * ORDER - 1;		// ����ֵ����
const int MINNUM_CHILD = MINNUM_KEY + 1;	// ��С��������
const int MAXNUM_CHILD = MAXNUM_KEY + 1;	// �����������
const int MINNUM_LEAF = MINNUM_KEY;			// ��СҶ�ӽ���ֵ����
const int MAXNUM_LEAF = MAXNUM_KEY;			// ���Ҷ�ӽ���ֵ����


#define NULL 0

//block���ֵ�ȫ�ֱ���
#define BLOCK_SIZE 4096		//���СΪ4096�ֽ�
#define BLOCK_NUM 1048576	//һ���ļ��������1048576����

#define PCT_FREE_THRESHOLD 0.3f
#define PCT_USED_THRESHOLD 0.7f

enum BlockType {		//���ݿ�����
	index, table, dictionary
};

// socket �Ĳ���ȫ�ֱ���
#include <Winsock2.h>
const short server_my_port = 5055; // �˿ں�
const int max_thread_num = 10;  // ����߳���

struct F
{
	SOCKET sockConn;
};

#endif // !GLOBAL_H
