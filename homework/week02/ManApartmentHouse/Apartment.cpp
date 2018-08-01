#include"Apartment.h"
Apt::Apt()
{
	count = 0;
	max = 5;
	men = new Man[max];
}
Apt::Apt(int size)
{
	count = 0;
	max = size;
	men = new Man[max];
}

//constructor

bool Apt::AddMan(char *name,int age)
{
	if (count  < max - 1)
	{
		men[count].Init(name, age);
		count++;
		return 1;
	}
	return 0;
}
bool Apt::RemoveMan()
{
	if (count >= 1)
	{
		count--;
		return 1;
	}
	return 0;
}
bool Apt::RemoveMan(char * name)
{
	int x = Search(name);
	if (x > 0)
	{
		for (int i=0,j=0;i<count;i++,j++)
		{
			if (i != x)
				men[j] = men[i];
			else
				i++;
		}
		count--;
		return 1;
	}
	else
		return 0;
}
void Apt::ShowMan()
{	
	if (count == 0)
		cout << "No man lives here" << endl;
	for (int i = 0; i < count; i++)
		cout << "\t" << i + 1 << " - " << (men + i)->GetName() << " , Age = " << (men + i)->GetAge() << endl;
}
int Apt::Search(char *name)
{
	for (int i = 0; i < count; i++)
		if (strcmp((men + i)->GetName(), name) == 0)
			return i;
	return -1;
}
