#include "House.h"
House::House()
{
	AptCount = 0;
	apt = new Apt;
}

void House::AddApt()
{
	Apt *temp = new Apt[AptCount+1];
	for (int i = 0; i < AptCount; i++)
		temp[i] = apt[i];
	delete[]apt;
	apt = temp;
	AptCount++;
}
bool House::AddMan(char*name,int age)
{
	
	for (int i = 0; i < AptCount; i++)
	{
		if ((apt + i)->AddMan(name, age))
			return 1;
	}
	cout << "\nApartment might be non-existance or full consider adding a new one\
			 \ncurrent apartment : " << AptCount << endl;
	return 0;
}
bool House::AddManAt(char*name, int age, int index)
{
	if (index < 0 || index >= AptCount)
	{
		cout << "\nApartment At Position : [" << index + 1 << "] does not exist.\
				 \nconsider creating a new apartment or set man to another\n\n";
		return 0;
	}
	else
	{
		if ((apt + index)->AddMan(name, age))
			return 1;
		else
			return 0;
	}
		
}
bool House::RemoveMan()
{
	for (int i = 0; i < AptCount; i++)
	{
		if ((apt + i)->RemoveMan())
			return 1;
	}
	cout << "There is no man left to remove. " << endl;
	return 0;

}
bool House::RemoveMan(char*name)
{
	for (int i = 0; i < AptCount; i++)
	{
		if ((apt + i)->RemoveMan(name))
			return 1;
	}
	cout << "Man not found. " << endl;
	return 0;

}
bool House::RemoveApt()
{
	if (AptCount > 0)
	{
		Apt *temp = new Apt[--AptCount];
		for (int i = 0; i < AptCount; i++)
			temp[i] = apt[i];
		delete[]apt;
		apt = temp;
		return 1;
	}
	else 
		return 0;
}
bool House::RemoveApt(int index)
{
	if (index >= 0 && index < AptCount)
	{
		int i;
		Apt *temp = new Apt[--AptCount];
		for (int j = i = 0; i < AptCount; i++, j++)
		{ 
			if (i != index)
				temp[i] = apt[j];
			else
				j++;
		}
		delete[]apt;
		apt = temp;
		return 1;
	}
	else 
		return 0;
}
void House::DisplayAt(int index)
{
	if (index < AptCount && index >= 0)
	{
		cout << " - Apartment " << index + 1 << " : " << endl;
		(apt + index)->ShowMan();
	}
	else
		cout << "!!! - Apartment not found - !!!";
}
void House::DisplayAll()
{
	cout << AptCount << endl;
	for (int i = 0; i < AptCount; i++)
	{
		cout << "Apartment - " << i + 1 << endl;
		(apt + i)->ShowMan();
	}
}
int House::GetAptCount()
{
	return AptCount;
}
