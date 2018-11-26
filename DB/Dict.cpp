#include "Dict.h"

Dict* Dict::instance = nullptr;

Dict * Dict::getInstance()
{
	if (instance = nullptr)
		instance = new Dict;
	return instance;
}

void Dict::release()
{
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}
}
