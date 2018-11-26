#ifndef GLOBAL_H
#define GLOBAL_H

typedef signed char int8;
typedef unsigned char uint8;
typedef unsigned int uint;
typedef unsigned short uint16;
typedef short int16;
typedef uint uint32;
typedef int int32;
typedef long KeyType;
typedef long DataType;

const int ORDER = 20;						// B+树的阶（非根内结点的最小子树个数）
const int MINNUM_KEY = ORDER - 1;			// 最小键值个数
const int MAXNUM_KEY = 2 * ORDER - 1;		// 最大键值个数
const int MINNUM_CHILD = MINNUM_KEY + 1;	// 最小子树个数
const int MAXNUM_CHILD = MAXNUM_KEY + 1;	// 最大子树个数
const int MINNUM_LEAF = MINNUM_KEY;			// 最小叶子结点键值个数
const int MAXNUM_LEAF = MAXNUM_KEY;			// 最大叶子结点键值个数

#define NULL 0

#define BLOCK_SIZE 4096		//块大小为4096字节
#define BLOCK_NUM 1024	//一个文件中最多有1048576个块

#define PCT_FREE_THRESHOLD 0.3f
#define PCT_USED_THRESHOLD 0.7f

enum DataFieldType {	//数据域类型
	Float,
	FixedChar,
	VarChar,
	Int,
	Null,
	Date
};
enum BlockType {		//数据块类型
	index, table, dictionary
};

#endif // !GLOBAL_H
