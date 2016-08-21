//Friend Elephant
//Demonstrates friend functions and operator overloading
//Author is Moses Arocha

#include <iostream>
#include <windows.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

WORD GetConsoleTextAttribute (HANDLE hCon)
{
  CONSOLE_SCREEN_BUFFER_INFO con_info;
  GetConsoleScreenBufferInfo(hCon, &con_info);
  return con_info.wAttributes;
}

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
const int saved_colors = GetConsoleTextAttribute(hConsole);


class Elephant
{
    //make following global functions friends of the Elephant class
    friend void Peek(const Elephant& aElephant);
    friend ostream& operator<<(ostream& os, const Elephant& aElephant);	
    
public:
    Elephant(const string& Name, string& Hobbies, int& Age, int& Height, int& Weight);

private:
    string m_Name;
	string m_Hobbies;
	int m_Age;
	int m_Height;
	int m_Weight;
};

Elephant::Elephant(const string& Name, string& Hobbies, int& Age, int& Height, int& Weight):
    m_Name(Name),
	m_Hobbies(Hobbies),
	m_Age(Age),
	m_Height(Height),
	m_Weight(Weight)
{}

void Peek(const Elephant& aElephant);
ostream& operator<<(ostream& os, const Elephant& aElephant);


/// The Beginning of the main
int main()
{
	string ElephantName;
	string ElephantHobbies;
	int ElephantAge;
	int ElephantHeight;
	int ElephantWeight;

	
	
  SetConsoleTextAttribute(hConsole, 0x08); // Sets The Color To Gray

	cout << "\t\t Welcome To The Wonderful Safari!\n "
		 << "  We Are Glad You Are Here. You're Here To See The Elephants Right?\n"
		 << "\n\t\tPlease Wait As Game Loads....\n\n\n" << endl;
	Sleep(3000);
	
	cout << "\n Sounds Great! Here Is The First Elephant. She Appears To Be A Pregnant Female."
		 << "\n What Do You Want To Name Her?: ";
	getline(cin, ElephantName);

	cout << "\n\n What A Wonderful Name! Hey? Why Don't We Play A Little Game?\n\n";
	cout << "\n (Push Enter To Continue)\n\n";
	cin.ignore();
	cout << "\t Whoever Can Correctly Guess The Hobbies, Age, Height,\n\t and Weight Of Her Can Keep Her.\n";
	cout << "\n\t Do You Want To Play? Yes! Alright Great!\n\n";

	cout << " What Is " << ElephantName << "'s Hobby? ";
	getline(cin, ElephantHobbies);

	cout << " What Is " << ElephantName << "'s Age? ";

	while(!(cin >> ElephantAge))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max_digits10, '\n');
			cout << " This Is An Invalid Input: ";
		}

	cin.ignore();
	cout << " What Is " << ElephantName << "'s Height? (In Feet): ";

		while(!(cin >> ElephantHeight))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max_digits10, '\n');
			cout << " This Is An Invalid Input: ";
		}

   cin.ignore();
	cout << " What Is " << ElephantName << "'s Weight? (In Lbs): ";

		while(!(cin >> ElephantWeight))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max_digits10, '\n');
			cout << " This Is An Invalid Input: ";
		}

Elephant eleph(ElephantName, ElephantHobbies, ElephantAge, ElephantHeight, ElephantWeight);

    cout << "\n Calling Peek() to access eleph's private data member:\n m_Name, m_Hobbies, m_Age, m_Height, m_Weight \n";
	Peek(eleph);
    
    cout << "\nSending eleph object to cout with the << operator:\n";
    cout << eleph;
    
    return 0;
}

//global friend function which can access all of a Elephant object's members
void Peek(const Elephant& aElephant)
{
    cout << aElephant.m_Name << ", \n";
	cout << aElephant.m_Hobbies << ", \n";
	cout << aElephant.m_Age << ", \n";
	cout << aElephant.m_Height << ", \n";
	cout << aElephant.m_Weight << " \n";
}

//global friend function which can access all of Elephant object's members
//overloads the << operator so you can send a Elephant object to cout
ostream& operator<<(ostream& os, const Elephant& aElephant)
{
    os << "Elephant's Object - \n";
    os << "m_Name: " << aElephant.m_Name << endl;
	os << "m_Hobbies:" << aElephant.m_Hobbies << endl;
	os << "m_Age:" << aElephant.m_Age << endl;
	os << "m_Height:" << aElephant.m_Height << endl;
	os << "m_Weight:" << aElephant.m_Weight << endl;
    return os;
}
