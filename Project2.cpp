#include <iostream>
#include <stdio.h>
#include <vector>
#include <array>
using namespace std;
string encodingStrings(int key, string name);
char encodingChars(int key, char character);
int encodingInts(int key, int value);
double encodingDoubles(int key, double var);
void encodingDoubleArray(int key, double doublearray[], double newArray[]);
void encoder(double XP, int doubloons, string characterName, string villainName, char combatRating, char npcStanding, int numOfLives, double distanceTraveled, int enemiesSlain);



int main()
{
	double levelComplete[10] = { 90.9, 23.2, 45.2, 100, 56.3, 0, 65.5, 0, 10.7, 32.4 };
	double enc_Arr[10];
	double XP = 32.7;
	int doubloons = 7001;
	string characterName = "Leroy Jenkins";
	string villainName = "Thanos";
	char combatRating = 'B';
	char npcStanding = 'F';
	int numOfLives = 2;
	double distanceTraveled = 356.98;
	int enemiesSlain = 1500;

	cout << "Levels Completeness: " << endl;
	encodingDoubleArray(5672, levelComplete, enc_Arr);
	encoder(XP, doubloons, characterName, villainName, combatRating, npcStanding, numOfLives, distanceTraveled, enemiesSlain);
	
}

void encoder(double XP, int doubloons, string characterName, string villainName, char combatRating, char npcStanding, int numOfLives, double distanceTraveled, int enemiesSlain) {
	
	//encode XP
	double enc_XP = encodingDoubles(5672, XP);

	//encode doubloons
	double enc_doubloons = encodingInts(5672, doubloons);

	//encode character name
	string enc_charName = encodingStrings(13, characterName);

	//encode villian name
	string enc_Villian = encodingStrings(13, villainName);

	//encode combat rating Standing
	char enc_combatRating = encodingChars(13, combatRating);

	// encode NPC Standing
	char enc_npcStanding = encodingChars(13, npcStanding);

	//encode number of lives
	int enc_numOfLives = encodingInts(5672, numOfLives);

	//encode distance Traveled
	double enc_distance = encodingDoubles(5672, distanceTraveled);

	//encode enemies slainr
	int enc_slain = encodingInts(5672, enemiesSlain);

	//Printing for testing purposes:
	cout << "\nXP: " << enc_XP << endl;
	cout << "doubloons: " <<  enc_doubloons << endl;
	cout << "Character Name: " << enc_charName << endl;
	cout << "Villian: " << enc_Villian << endl;
	cout << "Combat Rating; " << enc_combatRating << endl;
	cout << "npcStanding: " << enc_npcStanding << endl;
	cout << "Number of Lives: " << enc_numOfLives << endl;
	cout << "Distance Traveled: " << enc_distance << endl;
	cout << "Enemies Slain: " << enc_slain << endl;
}

double encodingDoubles(int key, double var)
{
	int castedVar = var * 100;
	double newVar = castedVar ^ key;
	newVar = newVar / 100;
	return newVar;
}

void encodingDoubleArray(int key, double doublearray[], double newArray[])
{
	double castedArrayVal;
	for (int i = 0; i < 10; i++)
	{
		castedArrayVal = encodingDoubles(key, doublearray[i]);
		newArray[i] = castedArrayVal;
		//Printing for testing
		cout << newArray[i]<<" ";
	}
	return;	
}

int encodingInts(int key, int value)
{
	int newValue = value ^ key;
	return newValue;
}

string encodingStrings(int key, string name)
{
	string newName = name;
	char letters[52] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','X','Y','Z' };
	for (int i = 0; i < int(name.length()); i++)
	{
		for (int k = 0; k < 52; k++)
		{
			if (name.at(i) == letters[k])
			{
				newName.at(i) = letters[((k + key) % 52)];
				break;
			}
		}
	}
	return newName;
}

char encodingChars(int key, char character)
{
	char newChar = character;
	char letters[52] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','X','Y','Z' };

	for (int k = 0; k < 52; k++)
	{
		if (character == letters[k])
		{
			newChar = letters[((k + key) % 52)];
			break;
		}
	}
	return newChar;
}
