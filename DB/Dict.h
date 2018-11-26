#ifndef DICT_H
#define DICT_H
 
class Dict
{
public:
	static Dict* getInstance();
	static void release();
private:
	static Dict* instance;
	Dict() {}
	Dict(const Dict&) = delete;
	Dict& operator=(const Dict&) = delete;
public:
	

};

#endif // !DICT_H