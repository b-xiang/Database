#include "RWmutex.h"




RWmutex* RWmutex::ptr = nullptr;

RWmutex::RWmutex()
{
}




RWmutex * RWmutex::getInstence()
{
	if (ptr == nullptr) {
		ptr = new RWmutex;
	}
	return ptr;
}

void RWmutex::addMutex(string table_name)
{
	
	mutex_map.insert(pair<string, shared_mutex*>(table_name, new shared_mutex));
}

void RWmutex::dropMutex(string table_name)
{
	mutex_map.erase(table_name);
}

void RWmutex::w_lock(string table_name)
{
	mutex_map.find(table_name)->second->lock();
}

void RWmutex::w_unlock(string table_name)
{
	mutex_map.find(table_name)->second->unlock();
}

void RWmutex::r_lock(string table_name)
{
	mutex_map.find(table_name)->second->lock_shared();
}

void RWmutex::r_unlock(string table_name)
{
	mutex_map.find(table_name)->second->unlock_shared();
}
