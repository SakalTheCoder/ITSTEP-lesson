#include"Man.h"
Man::Man(){name = new char[20];}
Man::Man(const char*n, int Age) :Man() { Init(n, Age); }
Man::Man(const Man & m)
{
	name = m.name;
	age = m.age;
}

//constructor

void Man::Init(char*n, int Age) {
	if (n != NULL)
		name = n;
	age = Age;
}
void Man::Init(const char*n, int Age)
{
	if (n != NULL)
		strcpy_s(name,20, n);
	age = Age;
}
Man &Man::operator=(const Man &m)
{
	this->name = m.name;
	this->age = m.age;
	return *this;
}

