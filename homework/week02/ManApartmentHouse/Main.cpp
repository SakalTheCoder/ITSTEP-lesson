#include"UselessFunc.h"
void cls();						//clears screen
void ClsCinFlag();				//clears Error Cin Flag  cause using getline after cin>>int is risky
void AskInput(char *,int &);	//Ask user for name and age input
void TestInput(int &opt);
int main()
{
	House H;
	int opt;
	do {
		
		cout << "1 - Add a Man\
				\n2 - Add a Man at specific Apartment\
				\n3 - Remove a Man\
				\n4 - Remove Man by name\
				\n5 - Add an Apartment\
				\n6 - Remove an Apartment\
				\n7 - Remove a specific Apartment by position\
				\n8 - Display Men in an Apartment\
				\n9 - Display everything\n\n";
		OptInput(opt);
		cls();
		switch (opt)
		{
			
			case 1:
			{
				int age;
				char *name = new char[20];
				AskInput(name,age);

				if (H.AddMan(name, age))
					cout << "!!! - Man added successfully - !!!" << endl;
				else 
					cout << "!!! - Man not added pls re-input - !!!" << endl;

				eofunc();
				break;
			}
			case 2:
			{
				int age;
				int pos;
				char *name = new char[20];

				cout << "Input the Position of Apartment : "; cin >> pos;
				TestInput(pos);
				AskInput(name, age);

				if (H.AddManAt(name, age,pos-1))
					cout << "!!! - Man added successfully - !!!" << endl;
				else
					cout << "!!! - Man not added pls re-input - !!!" << endl;

				eofunc();
				break;
			}
			case 3:
			{
				if (H.RemoveMan())
					cout << "!!! - Man removed - !!!" << endl;
				else
					cout << "!!!- Man NOT removed - !!!" << endl;

				eofunc();
				break;
			}
			case 4:
			{
				char*name = new char[20];
				cout << "Input Name : "; cin.getline(name, 20);

				if (H.RemoveMan(name))
					cout << "!!! - Man removed - !!!" << endl;
				else
					cout << "!!!- Man NOT removed - !!!" << endl;

				eofunc();
				break;
			}
			case 5:
			{
				H.AddApt();
				cout << "!!! - Apartment added - !!!" << endl;
				eofunc();
				break;
			}
			case 6:
			{
				if (H.RemoveApt())
					cout << "!!! - Last apartment removed - !!!" << endl;
				else
					cout << "!!! - Apartment deletion failed - !!!" << endl;
				eofunc();
				break;
			}
			case 7:
			{
				int pos;
				cout << "Input the Position of Apartment : "; cin >> pos;
				TestInput(opt);

				if (H.RemoveApt(pos-1))
					cout << "!!! - Last apartment removed - !!!" << endl;
				else
					cout << "!!! - Apartment deletion failed - !!!" << endl;

				eofunc();
				break;
			}
			case 8:
			{ 
				int pos;
				cout << "Input the Position of Apartment : "; cin >> pos;
				TestInput(pos);
				H.DisplayAt(pos - 1);
				eofunc();
				break;
			}
			case 9:
				H.DisplayAll();
				eofunc();
				break;
			default:
				return 0;
		}

	} while (1);
	system("pause");
	return 0;
}



