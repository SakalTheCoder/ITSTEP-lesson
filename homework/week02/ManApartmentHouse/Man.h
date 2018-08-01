#pragma once
#include<iostream>
#include<string>
using namespace std;
class Man {
	char *name; 
	int age;
public:
	Man();
	Man(const Man &m);
	Man(const char*n, int Age);

	Man &operator=(const Man &m);

	void Init(char*n,int Age);
	void Init(const char*n, int Age);
	
	char*GetName() { return this -> name; }
	int GetAge() { return this->age; }
};