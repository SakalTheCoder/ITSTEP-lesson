#pragma once
#include"Man.h"
class Apt {
	Man *men;
	int max, count;
public:
	Apt();
	Apt(int size);

	
	void ShowMan();
	
	bool AddMan(char*name, int age);
	bool RemoveMan();
	bool RemoveMan(char *name);

	int Search(char *name);
	int GetMax() { return max; }
	int GetCount() { return count; }

};