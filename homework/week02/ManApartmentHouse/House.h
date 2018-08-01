#pragma once
#include"Apartment.h"
class House
{
	Apt *apt;
	int AptCount;
public:
	House();
	void AddApt();
	bool AddMan(char *name,int age);
	bool AddManAt(char *name,int age ,int index);
	bool RemoveMan();
	bool RemoveMan(char*name);
	bool RemoveApt();
	bool RemoveApt(int index);
	
	void DisplayAt(int index);
	void DisplayAll();
	int GetAptCount();
};
