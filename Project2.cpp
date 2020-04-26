// Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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



int main()
{
	string word;
	char charas;
	int enemies;
	double val;
	
	double levelComplete[10] = { 90.9, 23.2, 45.2, 100.0, 56.0, 0.0, 65.5, 0.0, 10.0, 32.0 };
	double newArray[sizeof(levelComplete)];
	double XP = 32.7;
	int doubloons = 7001;
	string characterName = "Leroy Jenkins";
	string villainName = "Thanos";
	vector<string> weapons;
	char difficultyLevel = 'H';
	int numOfLives = 2;
	double distanceTraveled = 356.98;
	int enemiesSlain = 1500;
	word=encodingStrings(1, characterName);
	cout << word << endl;
	charas = encodingChars(1, difficultyLevel);
	cout << charas << endl;
	enemies=encodingInts(5672, enemiesSlain);
	cout << enemies << endl;
	cout << encodingInts(5672, enemies) << endl;
	val = encodingDoubles(3824, XP);
	cout << val << endl;
	cout << encodingDoubles(3824, val) << endl;
	//cout << encodingDoubleArray(3452, levelComplete)<<endl;
	encodingDoubleArray(3453, levelComplete,newArray);
	
	
	
	
}


double encodingDoubles(int key, double var)
{
	int castedVar =var* 100;
	double newVar = castedVar^ key;
	newVar = newVar / 100;
	return newVar;
}

void encodingDoubleArray(int key,double doublearray[],double newArray[])
{
	int castedArrayVal;
	for (int i = 0; i < 10; i++)
	{
		castedArrayVal = encodingDoubles(key, doublearray[i]);
		newArray[i] = castedArrayVal;
		cout << newArray[i]<<" ";
		
	}
	return;
	

}
int encodingInts(int key,int value)
{
	int newValue=value^ key;
	
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



