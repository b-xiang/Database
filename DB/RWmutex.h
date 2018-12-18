#pragma once

#include<map>
#include<shared_mutex>
#include<string>
using namespace std;



class RWmutex
{
public:
	static RWmutex* getInstence();
	void addMutex(string table_name);
	void dropMutex(string table_name);
	void w_lock(string table_name);
	void w_unlock(string table_name);
	void r_lock(string table_name);
	void r_unlock(string table_name);

private:
	// map  <string name,shared_mutex mut>
	map<string, shared_mutex*> mutex_map;

	RWmutex();
	static RWmutex* ptr;

};

