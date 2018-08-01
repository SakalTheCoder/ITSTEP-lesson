#include "UselessFunc.h"
void cls() {
	system("cls");
}
void ClsCinFlag()	//to clear cin flag
{
	cin.clear();
	cin.ignore(1000, '\n');
}
void AskInput(char*name, int &age)//too lazy to write it again and again
{

	cout << "Input Name : ";	cin.getline(name, 20);
	cout << "input age : ";		cin >> age;
	TestInput(age);
}
void OptInput(int &opt)		//test the user option selection Input
{
	cout << "Input an option : ";
	cin >> opt;
	ClsCinFlag();
	if (opt < 1 || opt > 10)
	{
		cout << "\n Input ERROR \n\n" << endl;
		OptInput(opt);
	}
}
void eofunc()	//use at end of every case in switch
{
	cout <<"\n";
	system("pause");
	cls();
}
void TestInput(int &Int)	//test if user inputted char [should be use at most int input]
{
	if (cin.fail() || Int<0)
	{
		cls();
		ClsCinFlag();
		cout << "\n!!! - Input failed - !!!\n\n;" << endl;
		cout << "Please Re-input : ";
		cin >> Int;		//putting ClsCinFlg after cin>>Int will yeild Error (it clear the cin flag so function becomes useless)
		TestInput(Int); //test if user failed again
	}
	else {
		ClsCinFlag();
	}
}
