#ifndef DB_H
#define DB_H

class DB
{
public:
	static DB* getInstance();
	static void release();
private:
	static DB* instance;
	DB() {}
	DB(const DB&) = delete;
	DB& operator=(const DB&) = delete;
public:
	void init();
	void run();
	void terminate();
};

#endif // !DB_H