//Static Animals
//Demonstrates static member variables and functions
//Author is Moses Arocha

#include <iostream>
#include <string>

using namespace std;

class Animals
{
public:
    static int s_Total;     //static member variable declaration
                            //total number of Animals objects in existence
    
    Animals(int hunger, int mood, int health);
    static int GetTotal();  //static member function prototype
	int GetHunger();
	int GetMood();
	int GetHealth();
	void SetHealth(int health);
	void SetHunger(int hunger);
	void SetMood(int mood);
    
private:
    int m_Hunger;
    int m_Mood;
    int m_Health;
};

int Animals::s_Total = 0;   //static member variable initialization

Animals::Animals(int hunger, int mood, int health): 
    m_Hunger(hunger),
    m_Mood(mood),
    m_Health(health)
{
    cout << "A New Aminal Has Been Added To The Safari!" << endl;
    ++s_Total;
}

int Animals::GetTotal()     //static member function definition
{
    return s_Total;
}

void Animals::SetHunger(int hunger)
{
	if (hunger < 0)
	{
		cout << " You Cannot Set An Animal's Hunger To A Negative Number.\n\n";
	}
	else
	{
		m_Hunger = hunger;
	}
}

int Animals::GetHunger()
{
	return m_Hunger;
}

void Animals::SetMood(int mood)
{
	if (mood < 0)
	{
		cout << " You Cannot Set An Animal's Hunger To A Negative Number.\n\n";
	}
	else
	{
		m_Mood = mood;
	}
}

int Animals::GetMood()
{
	return m_Mood;
}

void Animals::SetHealth(int health)
{
	if (health < 0)
	{
		cout << " You Cannot Set An Animal's Hunger To A Negative Number.\n\n";
	}
	else
	{
		m_Health = health;
	}
}

int Animals::GetHealth()
{
	return m_Health;
}


int main()
{
	string userInput;
	int hunger;
	int mood;
	int hunger2;
	int mood2;
	int hunger3;
	int mood3;
	int health;


	cout << " Welcome To The Game Safari, The Game Where You Learn About An Animal.\n";
	cout << "\n\t What Animal Would You Like To Learn About? ";
	getline(cin, userInput);

	cout << "\n Great! A New Shippment Has Just Arrived From Western Africa.\n"
             << " It Seems To Be A Rather Large Box. \n\n";

	Animals anim1(1,2,9), anim2(4,5,9), anim3(7,8,9);

	cout << " " << Animals::s_Total << " New Animals Have Been Added! \n\n";
	cout << " All Three Animals Are " << userInput << " Like You Requested.\n";
	cout << " Let Us Define The Characteristics Of Them.\n"
		 << " Look Over Here. The First Animal's Name Tag Says Charlize.\n";
		 
	cout << " Let's Define Charlize's Characteristics.\n"
		 << " What Is Her Hunger Level? [1-10] " ;
	cin >> hunger;
	anim1.SetHunger(hunger);
	cout << " Great! Now, Let Us Define Her Stress Level? [1-10] ";
	cin >> mood;
	anim1.SetMood(mood); // sets the animals mood to the number given

	cout << " Awesome, Well She Is Young, So Her Health Will Be? [1-10] ";
	cin >> health;
	anim1.SetHealth(health);
	anim2.SetHealth(health);
	anim3.SetHealth(health);

	cout << "\n\n Alright, Now To The Second. His Name Is Moses! \n";
	cout << " He Seems To Be The Happiest Of The " << userInput << ".\n";
	cout << " Let's Define Moses' Characteristics.\n"
		 << " What Is His Hunger Level? [1-10] ";
	cin >> hunger2;
	anim2.SetHunger(hunger2);

	cout << " Great! Now, Let Us Define His Stress Level? [1-10] ";
	cin >> mood2;
	anim2.SetMood(mood2);

	cout << "\n\n Now, The Last of The " << userInput << ", His Name Is Oracle.\n";
	cout << " Let's Define Oracle's Characteristics!\n"
		 << " What Is His Hunger Level? [1-10] ";
	cin >> hunger3;
	anim3.SetHealth(hunger3);

	cout << " What Is His Stress level? [1-10] ";
	cin >> mood3;
	anim3.SetMood(mood3);

	cout << "\n\n\n Here At The Safari, The Total Amount Of " << userInput << " Is " << Animals::GetTotal() << ".\n\n";
	cout << " Charlize's Hunger Level Is " << anim1.GetHunger() << " With Her Stress Level At " << anim1.GetMood()
		 << ".\n Her Overall Health Is A " << anim1.GetHealth() << " Out Of 10.\n\n";

	cout << " Moses' Hunger Level Is " << anim2.GetHunger() << " With His Stress Level At " << anim2.GetMood()
		<< ".\n His Overall Health Is A " << anim2.GetHealth() << " Out Of 10.\n\n";

	cout << " Oracle's Hunger Level Is " << anim3.GetHunger() << " With His Stress Level At " << anim3.GetMood()
		 << ".\n His Overall Health Is A " << anim3.GetHealth() << " OUt Of 10.\n\n";

	cout << " It Seems Your " << userInput << " Are Pretty Happy. Come Back Whenever You Like!\n\n\t\t\t Take Care!\n\n\n";

    return 0;
}
