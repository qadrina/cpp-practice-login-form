#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main() 
{
	int choice;
	cout << "\t\t\t___________________________\n\n\n";
	cout << "\t\t\t Welcome to the login page \n\n\n";
	cout << "\t\t\t _________ Menu _________ \n\n";
	cout << "  \n\n";
	cout << "\t| Press 1 to LOGIN                    |" << endl;
	cout << "\t| Press 2 to REGISTER                 |" << endl;
	cout << "\t| Press 3 if you forgot your PASSWORD |" << endl;
	cout << "\t| Press 4 to EXIT                     |" << endl;
	cout << "\n\t\t\t Please enter your choice: ";
	
	cin >> choice;
	cout << endl;
	
	switch(choice)
	{
		case 1:
			login();
			break;
			
		case 2:
			registration();
			break;
		
		case 3:
			forgot();
			break;
		
		case 4:
			cout << "\t\t\t Thank you. \n\n";
			break;
			
		default:
			system("cls");
			cout << "\t\t\t Please select from the options above \n" << endl;
			main();
	}
	
}

void login() 
{
	int count;
	string userId, password, id, pass;
	system("cls");
	
	cout << "\t\t\t Please enter USERNAME and PASSWORD " << endl;
	cout << "\t\t\t USERNAME : ";
	cin >> userId;
	cout << "\t\t\t PASSWORD : ";
	cin >> password;
	
	ifstream input("records.txt");
	
	while(input >> id >> pass)
	{
		if(id == userId && pass == password)
		{
			count = 1;
			system("cls");
		}
	}
	input.close();
	
	if(count == 1)
	{
		cout << userId << "\n Successfully logged in! \n";
		main();
	}
	else
	{
		cout << "\n LOGIN ERROR \n Please check your username and password!";
		main();
	}
}

void registration()
{
	//r is to register
	string ruserId, rpassword, rid, rpass;
	system("cls");
	
	cout << "\t\t\t Enter USERNAME : ";
	cin >> ruserId;
	cout << "\t\t\t Enter PASSWORD : ";
	cin >> rpassword;
	
	ofstream f1("records.txt", ios::app);
	f1 << ruserId << ' ' << rpassword << endl;
	system("cls");
	
	cout << "\n\t\t\t Registration successful \n";
	main();
}

void forgot()
{
	int option;
	system("cls");
	
	cout << "\t\t\t Select the option below \n";
	cout << "Press 1 to search your ID by USERNAME " << endl;
	cout << "Press 2 to go back to the MAIN MENU " << endl;
	cout << "\t\t\t Enter your choice : ";
	cin >> option;
	
	switch(option)
	{
		case 1:
		{
			int count = 0;
			// s is to show
			string suserId, sid, spass;
			cout << "\n\t\t\t Enter the username which you remembered : ";
			cin >> suserId;
			
			ifstream f2("records.txt");
			while(f2 >> sid >> spass)
			{
				if(sid == suserId)
				{
					count = 1;
				}
			}
			f2.close();
			
			if(count==1)
			{
				cout << "\n\n Your account is found! \n";
				cout << "\n\n Your password is : " << spass << "\n";
				main();
			}
			else
			{
				cout << "\n\t Sorry, could not find your account. \n";
				main();
			}
			break;
		}
		
		case 2:
			{
				main();
			}
		
		default:
			cout << "\t\t\t Wrong choice. Please try again." << endl;
			forgot();
	}
}
