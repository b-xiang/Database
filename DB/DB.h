#ifndef DB_H
#define DB_H

class ServerSocket;
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
private:
	ServerSocket* s;
};

#endif // !DB_H