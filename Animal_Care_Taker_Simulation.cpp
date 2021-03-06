//Animals Caretaker
//Simulates caring for a virtual pet
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

//returns the current attributes
WORD GetConsoleTextAttribute (HANDLE hCon)
{
  CONSOLE_SCREEN_BUFFER_INFO con_info;
  GetConsoleScreenBufferInfo(hCon, &con_info);
  return con_info.wAttributes;
}

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
const int saved_colors = GetConsoleTextAttribute(hConsole);

int choice = 1;

//Creation of The Class Animals
class Animals
{
public:
	//Lists the default variable values, so they could be redefined in the following function
	Animals(int hunger = 5, int boredom = 5, int health = 100, int stress = 10, int sleep = 7, int intelligence= 20);
	void Story(int Random); // the hidden function
	void Eat(int food = 20);
	void Interact(int fun = 20);
	void Speak(int Random);
	void Nap(); // also known as sleep in some codes
	void Train(int iq = 5);
	void Welcome();
	void Kill();
	int GetHunger();
	int GetBoredom();
	int GetHealth();
	int GetStress();
	int GetSleep();
	int GetIntelligence();

private:
	int m_Hunger;
	int m_Boredom;
	int m_Health;
	int m_Stress;
	int m_Sleep;
	int m_Intelligence;

	int GetMood(int Random = 6);
	void PassTime(int time = 1);
};

//Identifying attributes as they pair
Animals::Animals(int hunger, int boredom, int health, int stress, int sleep, int intelligence):
	m_Hunger(hunger),
	m_Boredom(boredom),
	m_Health(health),
	m_Stress(stress),
	m_Sleep(sleep),
	m_Intelligence(intelligence)
{}

//interger function to receive GetMood in main
 int Animals::GetMood(int Random)
{
	srand(static_cast<unsigned int>(time(0)));  //seed random number generator
	 Random = rand() % 20 + 1;         // random number between 1 and 10
	 return (Random);
}

//interger function to receive GetHunger in main
int Animals::GetHunger()
{
	return (m_Hunger);
}

//integer function to receive GetBoredom in main
int Animals::GetBoredom()
{
	return (m_Boredom);
}

//integer function to receive GetHealth in main
int Animals::GetHealth()
{
	return (m_Health);
}

//integer function to receive GetStress in main
int Animals::GetStress()
{
	return (m_Stress);
}

//integer function to receive GetSleep in main
int Animals::GetSleep()
{
	return (m_Sleep);
}

//integer function to receive GetIntelligence in main
int Animals::GetIntelligence()
{
	return (m_Intelligence);
}

//function that allows for the passing of time (includes all but intelligence)
void Animals::PassTime(int time)
{
	m_Hunger += time;
	m_Boredom += time;
	m_Stress += time;
	m_Sleep += time;
	m_Health -= time;
}

// function that kills the critter
void Animals::Kill()
{
	if (m_Hunger == 10)
	{
		cout << "\n You Have Lost The Game. Charlize Died. GoodBye." << endl;
		choice = 0;
	}
	else if (m_Boredom == 10)
	{
		cout << "\n You Have Lost The Game. Charlize Ran Away. GoodBye." << endl;
		choice = 0;
	}
	else if (m_Stress == 20)
	{
		cout << "\n You Have Lost The Game. Charlize Died. GoodBye." << endl;
		choice = 0;
	}
	else if (m_Sleep == 15)
	{
		cout << "\n You have Lost The Game. Charlize Died. Goodbye." << endl;
		choice = 0;
	}
	else if (m_Health == 0)
	{
		cout << "\n You Have Lost The Game. Charlize Died. Goodbye." << endl;
		choice = 0;
	}
}

// A hidden feature only found by using the case number 630
 void Animals::Story(int Random)
{
	string RandomWeather;
	int Weather;
	string Continue;
	string Walk;

	srand(static_cast<unsigned int>(time(0)));  //seed random number generator

	 Weather = rand() % 5 + 1;         // random number between 1 and 10

	 //if statement that defines weather for THIS FUNCTION ONLY!
	 if (Weather == 1)
	 {
		 RandomWeather = "Cloudy";
	 }
	 else if (Weather == 2)
	 {
		 RandomWeather = "Sunny";
	 }
	 else if (Weather == 3)
	 {
		 RandomWeather = "Snowy";
	 }
	 else if (Weather == 4)
	 {
		 RandomWeather = "Rainy";
	 }
	 else if (Weather == 5)
	 {
		 RandomWeather = "Windy";
	 }
	 else
	 {
		 RandomWeather = "Stormy";
	 }

	// if statements that define mood of animal for this function ONLY!
	int mood = GetMood(Random);
	string WordMood;

	if (mood > 15)
	{
        	WordMood = "Happy";
	}
	
	else if (mood > 10)
	{
        	WordMood = "Tired";
	}
	
         else if (mood > 5)
	{
		WordMood = "Stressed";
	}
	
         else
	{
        	WordMood = "Excited";
	}
	
	//Beginning of what users will see with display
	cin.ignore();
	Sleep(150);

	//beginning of cout, uses getline, getline does not matter
	cout << "\n\n Hello! \n\n I Am The Former Care Taker Of The Elephants At The Safari.\n"
		 << " Good Luck. They Are A Hassle. Everyday They Need Two Baths,\n"
		 << " To Be Fed 35 Pounds Of Food Each, And 9 Hours Of Sleep.\n\n"
		 << " I Hope You Are Up For The Challenge. Do You Want To Continue? [Y/N] ";
	
	getline(cin, Continue); //getline does not matter for continuation

	cout << "\n\n Well Anyways, The Game Will Continue! Hurry!\n";

	Sleep(1550);

	//place where variable string WordMood comes into place
	cout << "\n Here! Take This! It's A Tranquilizer. Approach Charlize Slowly!\n"
	     << " She Seems Very " << WordMood << " Oh No!...\n\n ";
	Sleep(1550);
	cout << " Shoot Her With It Already!\n"
	     << "\t Press Enter To Shoot Charlize.\n";
	
	cin.ignore();
	cin.get();

	cout << "\n\t Okay Great. She Is Safe Now, Please Pet Her.\n"
	     << "\t\t Press Enter To Pet Charlize.\n";
	cin.ignore();
	cin.get();

	// Passing of time
	PassTime();

	Sleep(150);
	cout << "\n Amazing. Simply Amazing.\n\n Sounds Like She Is Happy, Take Her For A Walk...\n"
	     << "\n As You Take Charlize For A Walk, She Gets Scared...\n"
	     << " A Mouse Was On The Road. She Ran Away, Chase Her!\n\n\t\t Please Push Enter To Chase.";
	
	//Must push enter 6 times, for loop for getting a value (enter key)
	for (int i = 0; i < 3; ++i)
	{
		cin.ignore();
		cin.get();
	}

	cout << "\n Oh Thank Goodness, You Caught Her! Please, Walk Her Back.\n"
	     << "\n As You Walked Her Back To The Zoo, She Gets Tired.\n"
	     << "\n She Decides To Sit Down. Please, Take Her Back To The Zoo Now.\n"
	     << " Please Type Walk To Walk Back To The Zoo. ";
	cin >> Walk; // walk also does not mattter, this is why there is not getline

	PassTime(); // passes time further

	//continuation of the game
	cout << "\n\n As You Enter The Zoo, She Begins To Speak To You..\n\n";
	Sleep(5550);


	cout << "\t 'Hey, I'm Charlize.' - Charlize The Animals\n"
	     << " Scared You Run Away And Never Come Back.\n\n";
	Sleep(1550);


	cout << " To This Day You Wonder What Ever Happend To Charlize...\n\n"
	     << " Today Is The Day You Are Going To Visit Her, After 15 Years.\n"
	     << " Nervous, You Stumble Through The Zoo Towards Her Cage...\n\n";
	Sleep(1550);

	//Last bit, requires users to push enter to continue so break doesn't inact in main
	cout << " It's Not The Same As You Remember, You Wish You Hadn't Left.\n"
	     << " As You Walk To Her Cage, She Instantly Recongizes You.\n"
	     << " As She Strolls Towards You A Smile Spreads Across Your Face,\n"
	     << " You Waited Years For This To Happen, You Have Missed Her...\n"
	     << "\n\n To Be Continued...";
	Sleep(15000);

	PassTime();

}

void Animals::Eat(int food)
{
	char Feed;

	// if statement so hunger never increases above ten, or decreases below zero
	m_Hunger = m_Hunger - 2;
	if (m_Hunger < 0)
	{
		m_Hunger = 0;
	}
	
	else if (m_Hunger > 10)
	{
		m_Hunger = 10;
	}

	cout << "\n\n As You Walk Over To Charlize, She Seems Hungry. So You Give Her Some Food.\n"
	     << " She Thanks You By Letting You Touch Her Trunk.\n"
	     << " Would You Like To Feed Her Again? [Y/N] ";
	cin >> Feed;

	//toupper must be a char variable, dont change to string
	Feed = toupper(Feed);

	if (Feed == 'Y')
	{
		SetConsoleTextAttribute(hConsole, saved_colors); // returns colors back to black and white background
		cout << "\n Great Charlize Has Been Fed! She Loves You More Now.\n";
		m_Hunger = m_Hunger - 2; // removes two from the variable m_Hunger that is private
	}
	else
	{
		cout << "\n She Gave You A Dirty Look. This Is Not A Good Sign.\n";
	}

	cin.ignore();
	cin.get();

	PassTime();

}

void Animals::Speak(int Random)
{
	int MoodNum = GetMood(Random);
	string mood;
	string discuss;

	// an if statement that states that m_Health cannot go over 100, or decrease below 0
	m_Health = m_Health + 10;
	
	if (m_Health < 0)
	{
		m_Health = 0;
	}
	
	else if (m_Health > 100)
	{
		m_Health = 100;
	}

	// an if statement that defines from the random function to define mood for this FUNCTION ONLY
	if (MoodNum > 15)
	{
        	mood = "Fustrated";
	}
	
	else if (MoodNum > 10)
	{
        	mood = "Happy";
	}
	
        else if (MoodNum > 5)
	{
        	mood = "Depressed";
	}
	
        else
	{
		mood = "Cheerful";
	}

	// beginning of what users will see
	Sleep(550);
	cout << "\n\n I Am Charlize, I Have An Interesting Life! ";
	cout << " I Am Very " << mood; cin.ignore(); // added cin.ignore() because getline skips if not placed
	cout << ". \n Thankfully, I Have A Caring CareTaker, Who Always Talks To Me.\n";
	cout << " What Do You Want To Talk About?? Oh, How About Peanuts!\n";
	cout << "\n Please Insert What You Would Like To Discuss: ";
	getline(cin, discuss);

	// user-written functions placed here, length depends on task committed
	if (discuss.length() < 5)
	{
		cout << "\n I Would Love To Talk About That!\n";
	}
	
	else
	{
		cout << "\n Ehh, Alright I Guess. K.\n";
	}

	//walks out, possibly add more to this place, but not required
	cout << "\n\t I Am So Excited About Talking. I Love To Talk, I Love You!\n "
		 << "\t I Have Had A Great Day. Oh Wait, Nayley Is Calling Me...\n";
	cout << " \n\t Well I Have To Leave Now, So Goodbye!\n\n";
		 
	cin.get();

	PassTime(); // further passes time

}

void Animals::Interact(int fun)
{
	string game;

	cout << "\n\n Yay! Let's Play A Game!\n\n";
	// statement that boredom is subtracted along with stress
	m_Boredom -= fun;
	m_Stress -= 4; // the only mention of removing stress 

	// if statement that declares that m_Boredom cannot drop below 0 or rise over 10
	if (m_Boredom < 0)
		{
			m_Boredom = 0;
		}
	else if (m_Boredom > 10)
		{
			m_Boredom = 10;
		}

	if (m_Stress < 0)
		{
			m_Stress = 0;
		}
	else if (m_Stress > 20)
		{
			m_Stress = 20;
		}

	cin.ignore();

	cout << " Oooh, What Game Would You Like To Play!?!\n"
		 << " Choose A Game You Would Like To Play: Hide And Seek or Fetch \n\t\t";
	getline (cin, game);

	// if statement, user written functions, no exact match, its a catch all
	if (game.length() < 4)
	{
		cout << "\n\n\t Yes! Let's Play!" << endl;
	}
	else
	{
		cout << "\n\n\t Oh My Gosh Yes! Let's Play!" << endl;
	}

	cout << "\n You Play With Charlize For A Few Hours. She Loves You.\n Which Is Great, Because Before, She Hated You. HAHA.\n\n";

	//may need cin.ignore(); if attempted > 1
	cin.get();

	PassTime(); // further pushes time

}

void Animals::Nap()
{
	// the only subtraction of sleep
	m_Sleep = m_Sleep - 5;

	// if statement that if m_Sleep reaches 0 it will stay, it cannot go over 15
	if (m_Sleep < 0)
	{
		m_Sleep = 0;
	}
	else if (m_Sleep > 15)
	{
		m_Sleep = 15;
	}

	int hours = 0; // used so user knows when to stop pushing enter

	cout << "\n\n It Seems That Charlize Has Fallen Asleep.\n"
		 << " In Order For The Game To Continue, She Must Sleep.\n"
		 << " Press Enter For Her To Sleep Safely.\n\n";

	//for loop to allow user to allow animal to sleep
	for (int i = 0; i < 16; ++i)
		{
			++hours;
			cin.get();
			cout << "\t" << hours <<" Hours Has Gone By...\n";
		}

	cout << "\n\n Amazingly, She Has Awoken! Great!\n";
	cout << " Everyday, She Needs 16 Hours Of Sleep, So Make Sure You Come Back!\n";
	cout << " If You Don't She Will Cry And Run Away!\n";
	Sleep(600);

	PassTime(); // further passes time, so numbers will not add up. It will subtract then add
}

void Animals::Train(int iq)
{
	vector<string> Tricks; // vector created for tricks only
	vector<string> Words; // vector created for words only ^ no interaction at all

	string choice;
	string trick;
	string word;
	char repeat = 'Y';

	cin.ignore(); // cin.ignore(); is needed so the getline can be redefined
	cout << "\n\n What Would You Like To Teach Charlize? [Tricks Or Words]\n\t";
	getline(cin, choice); // input does not truly detact choice, its a catch all

	while (repeat == 'Y' || repeat == 'y') // uses char with the word repeat (Y)
	{
		if (choice.length() > 5) // user-wrtitten and defined, its a catch all
		{
			cin.ignore();
			cout << "\n Please Enter A Trick You Would Like To Teach Charlize:\n\t";
			getline(cin, trick);
			m_Intelligence += iq; // only place it increases iq
			Tricks.push_back(trick);
		}
		
		else
		{
			cin.ignore();
			cout << "\n Please Enter A Word You Would Like To Teach Charlize:\n\t";
			getline(cin, word);
			m_Intelligence += iq; // only place it increases iq
			Words.push_back(word);
		}

		

		cout << "\n\n Would You Like To Teach Charlize More Things?! [Y/N] ";
		cin >> repeat; // repeat equals y unlesss told other wise

		

		PassTime(); // further pushes time

	}
	
	// must be outside while loop
	cout << "\n\n Amazing! Charlize Has Learned So Much! Come Back Again.\n\n";
	
	Sleep(1000);
		
}

void Animals::Welcome()
{
	string type; // used for user to choose which type of caretaker
	int level = 1; // used for users to choose what level they want to play at

	cout << " From Moses Arocha, \n To Matthew,\n\n Greetings! \n\n I Hope You Are Having A Wonderful Day. I Am Glad To See You Back.\n"
	     << " I Know, It's Been A While. Well, To Begin, This Is Charlize.\n"
	     << " Here You Will Be The CareTaker. What Type Of CareTaker Would You Like To Be?\n";
	cout << "\n Please Insert One Of The Three Below: [Nice, Magical, Evil] ";
	getline(cin, type); // string does define which choice, else created

	if (type == "NICE" || type == "Nice" || type == "nice")
	{
		cout << "\n\t Great! You Will Be A Nice CareTaker!\n";
	}
	
	else if (type.length() > 4)
	{
		cout << "\n\t I Hope Everything Turns Out Well...\n";
	}
	
	else if (type == "EVIL" || type == "evil" || type == "Evil")
	{
		cout << "\n\t This Does Not Seem Like A Great Sign...\n";
	}
	
	else // catch all for this function
	{
		cout << "\n\t You Chose Wrong. You Get To Be Nice!\n";
	}

	Sleep(1550);

	cout << "\n\n What Level Of Difficulty Do You Wish To Play The Game?\n\n";
	cout << " 1 - Easy\n";
	cout << " 2 - Medium\n";
	cout << " 3 - Veteran\n";

	cout << "\n\t\tWhat Would You Like To Do? : ";
	cin >> level;

		if ((!cin) || ((cin !=0) && (level != 1) && (level != 2) && (level != 3) ))
		{
			level = 0;
			cout << "\n You Have Lost The Game Already, Great. \n";
			cin.ignore();
			cin.get();
		}

		switch (level) // level is defined in the previous line from user-input
		{
		case 1:
			cout << "\n\n Great, The Rules Of The Game Are Simple. DO NOT KILL CHARLIZE!\n"
				 << " Everyday The Statics Will Increase, Once They Reach The Max, \n\t\t Charlize Will Die.\n\n";
			cout << "\n\t The Statics of Charlize Can Be Found Below.\n";

			/* here is the section where Get's are used to grab private variables and make them
			   viewable to the user, the class the user edits and defines does not exist, this
			   does not alther the class, just presents the info*/
			cout << "\n Boredom Level Is A " << GetBoredom() << " Out Of 10." << endl;
			cout << "\n Health Level Is A " << GetHealth() << " Out Of 100." << endl;
			cout << "\n Hunger Level Is A " << GetHunger() <<  " Out of 10. " << endl;
			cout << "\n Intelligence Level Is A " << GetIntelligence() << " Out of 200. " <<endl;
			cout << "\n Sleep Level Is A " << GetSleep() << " Out of 15." << endl;
			cout << "\n Stress Level Is A " << GetStress() << " Out of 20.\n\n\n";
			
			cout << "\n\n\t\t Please Read The Above. Please Wait...\n\n";
			break; // from break, it sends straight to the main

		case 2:
			cout << "\n\n Amazing! Moving Up In The World. The Rules Of The Game Are Simple.\n"
			     << " Everyday, You Must Feed Charlize, Bath Her, And Let Her Sleep. It Is\n"
			     << " It Is Recommended To Let Her Sleep And Relax.\n"
			     << " Everyday The Statics Will Increase, Once They Reach The Max,\n\t\t Charlize Will Die.\n\n";
			PassTime();

			cout << "\n Boredom Level Is A " << GetBoredom() << " Out Of 10." << endl;
			cout << "\n Health Level Is A " << GetHealth() << " Out Of 100." << endl;
			cout << "\n Hunger Level Is A " << GetHunger() <<  " Out of 10. " << endl;
			cout << "\n Intelligence Level Is A " << GetIntelligence() << " Out of 200. " <<endl;
			cout << "\n Sleep Level Is A " << GetSleep() << " Out of 15." << endl;
			cout << "\n Stress Level Is A " << GetStress() << " Out of 20.\n\n\n";
			
			cout << "\n\n\t\t Please Read The Above. Please Wait...\n\n";
			break; // from break, it sends straight to the main

		case 3:
			cout << "\n\n\t\t You Are A Veteran. Great. Good Luck.\n";
			PassTime(); // harder the level, the harder the game is made in the beginning
			PassTime();
			PassTime();
			PassTime();
			cout << "\n Boredom Level Is A " << GetBoredom() << " Out Of 10." << endl;
			cout << "\n Health Level Is A " << GetHealth() << " Out Of 100." << endl;
			cout << "\n Hunger Level Is A " << GetHunger() <<  " Out of 10. " << endl;
			cout << "\n Intelligence Level Is A " << GetIntelligence() << " Out of 200. " <<endl;
			cout << "\n Sleep Level Is A " << GetSleep() << " Out of 15." << endl;
			cout << "\n Stress Level Is A " << GetStress() << " Out of 20.\n\n\n";
			
			cout << "\n\n\t\t Please Read The Above. Please Wait...\n\n";
			break; // from break, it sends straight to the main

		default:
			SetConsoleTextAttribute(hConsole, 0x0C); // the color of red
			cout << "\n Wow, Genius, Wrong Input. " << level << " is not proper.\n\n";
			SetConsoleTextAttribute(hConsole, saved_colors); // returns the colors to black and white
		}
}

int main(int Random, string RandomWeather)
{
	int fail = 1;
	
	Animals crit; // creation of the class section crit from the class Animals, where user edits
	
	string animalCaring;

	SetConsoleTextAttribute(hConsole, 0x08); // the color dark grey
	//SetConsoleTextAttribute(hConsole, 0xF0); // the background color dark blue
	crit.Welcome(); // keeps color from above
	SetConsoleTextAttribute(hConsole, saved_colors); // returns it to black and white

	SetConsoleTextAttribute(hConsole, 0x0E);// The color of bright yellow
	Sleep(5567);

	cin.ignore(); // A MANDATORY line needed for get to be processed
	cout << "\n\n  Welcome To The Safari Game! The Game Where You Care For An Animal!\n\n";
	cout << "\n What Species Of An Animal Would You Like To Care For? : ";
	getline (cin, animalCaring);

		while(choice !=0) // as soon as choice equals zero it will release
		{
			

				SetConsoleTextAttribute(hConsole, 0x04); // the color dark red
				cout << "\n\n Sounds Great! Well Here Are Your Choices! Choose Wisely!\n\n";
				cout << "\n\t 0 - Exit\n";
				cout << "\t 1 - Let Your " << animalCaring << "  Sleep.\n";
				cout << "\t 2 - Let Your " << animalCaring << "  Eat.\n";
				cout << "\t 3 - Let Your " << animalCaring << "  Learn.\n";
				cout << "\t 4 - Let Your " << animalCaring << "  Speak.\n";
				cout << "\t 5 - Let Your " << animalCaring << "  Play!\n";

				SetConsoleTextAttribute(hConsole, 0x07); // the color dark blue
				cout << "\n\t\tWhat Would You Like To Do? : ";
				cin >> choice;

				
				if ((!cin) || ((cin !=0) &&
					(choice != 1) && (choice != 2) &&
				    (choice != 3) && (choice != 4) &&
				    (choice != 5) && (choice != 6) &&
					(choice != 630) ))
				{
					choice = 0;
					cout << "\n You Have Lost The Game Already, Great. \n";
					cin.ignore();
					cin.get();
				}

		crit.Kill();
							
		switch (choice) // same variable as while loop
		{
		case 0:
			SetConsoleTextAttribute(hConsole, 0x08); //  the color dark grey
			/* here the class section crit is created from the class Animals, 
				this is where the user will edit the information, so here is the modified
				information that will be provided to the user*/
			cout << "\n\n\t The Statics of Charlize Can Be Found Below.\n";
			cout << "\n Boredom Level Is A " << crit.GetBoredom() << " Out Of 10." << endl;
			cout << "\n Health Level Is A " << crit.GetHealth() << " Out Of 100." << endl;
			cout << "\n Hunger Level Is A " << crit.GetHunger() <<  " Out of 10. " << endl;
			cout << "\n Intelligence Level Is A " << crit.GetIntelligence() << " Out of 200. " <<endl;
			cout << "\n Sleep Level Is A " << crit.GetSleep() << " Out of 15." << endl;
			cout << "\n Stress Level Is A " << crit.GetStress() << " Out of 20.\n\n\n";
			cout << "\n\n Whatever, You Killed Charlize! Come Again!\n";
			cout << "\n\n The Secret Code is 630\n\n";

			cin.ignore();
			cin.get(); // necessary for user to see the secret code
			system("cls");
			SetConsoleTextAttribute(hConsole, saved_colors); // returns to the colors black and white
			break;
		
		case 1:
			SetConsoleTextAttribute(hConsole, 0x0B); // the color cyan
			crit.Nap();
			system("cls");
			SetConsoleTextAttribute(hConsole, saved_colors); // returns to the colors black and white
			break;

		case 2:
			SetConsoleTextAttribute(hConsole, 0x05); // the color dark magenta
			crit.Eat();
			system("cls");
			SetConsoleTextAttribute(hConsole, saved_colors); // returns to the colors of black and white
			break;

		case 3:
			SetConsoleTextAttribute(hConsole, 0x02); // the color dark green
			crit.Train();
			system("cls");
			SetConsoleTextAttribute(hConsole, saved_colors); // returns the colors to black and white
			break;

		case 4: 
			SetConsoleTextAttribute(hConsole, 0x08); // the color of gray
			crit.Speak(Random);
			system("cls");
			SetConsoleTextAttribute(hConsole, saved_colors); // returns the colors to black and white
			break;

		case 5:
			SetConsoleTextAttribute(hConsole, 0x06); // changes the colors to dark yellow
			crit.Interact();
			system("cls");
			SetConsoleTextAttribute(hConsole, saved_colors); // returns the colors to black and white
			break;

		case 6:
			SetConsoleTextAttribute(hConsole, 0x0A); // changes colors to green

			cout << "\n\n\t The Statics of Charlize Can Be Found Below.\n";
			cout << "\n Boredom Level Is A " << crit.GetBoredom() << " Out Of 10." << endl;
			cout << "\n Health Level Is A " << crit.GetHealth() << " Out Of 100." << endl;
			cout << "\n Hunger Level Is A " << crit.GetHunger() <<  " Out of 10. " << endl;
			cout << "\n Intelligence Level Is A " << crit.GetIntelligence() << " Out of 200. " <<endl;
			cout << "\n Sleep Level Is A " << crit.GetSleep() << " Out of 15." << endl;
			cout << "\n Stress Level Is A " << crit.GetStress() << " Out of 20.\n\n\n";

			SetConsoleTextAttribute(hConsole, saved_colors); // returns the colors to black and white
			break;

		case 630:
			SetConsoleTextAttribute(hConsole, 0x0D); // the color magenta is used
			crit.Story(Random);
			system("cls");
			SetConsoleTextAttribute(hConsole, saved_colors); // returns colors to black and white
			break;

		default:
			SetConsoleTextAttribute(hConsole, 0x0C); // the color of red
			cout << "\n Wow, Genius, Wrong Input. " << choice << " is not proper.\n\n";
			SetConsoleTextAttribute(hConsole, saved_colors); // returns the colors to black and white
		}

	} 

	return 0;
}
