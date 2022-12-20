//filename: WordleImp.cpp
//author: Veronica Bone
//created: 5/9/22
//revised: 5/18/22

//implementation file for header files

#include "user.h"
#include "game.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>
#include <vector>


using namespace std;

//default constructor setting all Stats to 0 

User::User()
{
	cout<<"Enter your username, or create a new one: ";
	cin>> this->username;
	this->oneGuess=0;
	this->twoGuess=0;
	this->threeGuess=0;
	this->fourGuess=0;
	this->fiveGuess=0;
	this->sixGuess=0;
	this->gamesPlayed=0;
	this->percentWon=0;
	this->streak=0;
	this->maxStreak=0;
}

//open the stat database file

void User:: openFile()
{
	string filename="userInfo.txt";
	this->infoFile.open(filename.c_str(), fstream::in |fstream::out |fstream::app); 
	if (!this->infoFile)
		cout<<"Error";
}

//close the stat database file
void User::closeFile()
{
	this->infoFile.close();
}

//search for a user in the database
void User::searchForUser ()
{
	openFile();
	string name;
	bool found = false;
	while(getline(this->infoFile, name) && found==false)
		{
			if (name==this->username)	
			{	
				found=true;
				cout<<this->username <<endl;
				break;
			}
			else
				found=false;
		}
	
	if (found ==true)
	{
		readInStats();
		closeFile();
		closeFile();
}
		
	if (found == false)
	{
		closeFile();
	}
}

//add a user to the database, if they are not already included
void User::addUser()
{
	openFile();
	
	this->infoFile << endl <<endl <<this->username
	<< "\nGamesPlayed:" <<this->gamesPlayed <<endl 
	<<"percentWon:"<<this->percentWon <<endl
	<<"Streak:" <<this->streak<<endl <<"MaxStreak:" 
	<<this->maxStreak<<endl<<"1guess:"<<this->oneGuess <<endl <<"2guesses:" 
	<<this->twoGuess <<endl<<"3guesses:"<<this->threeGuess <<endl 
	<<"4guesses:" <<this->fourGuess<< endl <<"5guesses:"
	<<this->fiveGuess<<endl <<"6guesses:"<<this->sixGuess;
	
	closeFile();	
}


//read in the stats from a returning user
void User::readInStats()
{
	char c=':';  //char right before the data to read into stat variables
	vector<int> nums;  
	char temp;
	int num;
	int len =-1;
	int multiplier =1;
	
	//to go through the file by char, to stop at the : character
	while(this->infoFile.get(temp) && temp!=c)
		temp=temp;
		
	//reading the file character by character, converting the char into an int,
	// and storing the int in a vector
	while(this->infoFile.get(temp) && temp!='\n')
	{
		num=temp-'0';
		nums.push_back(num);
		len++;
			
	}
	
	//converting the vector of ints into a multi digit number, a way to 
	//concatinate ints
	for (len; len>=0; len--)
	{ 
		this->gamesPlayed+= (nums[len] * multiplier);
		multiplier*=10;
	}
	
	//clearing vaiables before reading in the next data
	len =-1;
	multiplier =1;
	nums.clear();
		
	//repeating this process for each private stat member
	while(this->infoFile.get(temp) && temp!=c)
	temp=temp;
	while(this->infoFile.get(temp) && temp!='\n')
	{
		num=temp-'0';
		nums.push_back(num);
		len++;
			
	}
	for (len; len>=0; len--)
	{ 
		this->percentWon+= (nums[len] * multiplier);
		multiplier*=10;
	}
	len =-1;
	multiplier =1;
	nums.clear();

	while(this->infoFile.get(temp) && temp!=c)
	temp=temp;
	while(this->infoFile.get(temp) && temp!='\n')
	{
		num=temp-'0';
		nums.push_back(num);
		len++;
			
	}
	for (len; len>=0; len--)
	{ 
		this->streak+= (nums[len] * multiplier);
		multiplier*=10;
	}
	len =-1;
	multiplier =1;
	nums.clear();
	
	while(this->infoFile.get(temp) && temp!=c)
	temp=temp;
	while(this->infoFile.get(temp) && temp!='\n')
	{
		num=temp-'0';
		nums.push_back(num);
		len++;
			
	}
	for (len; len>=0; len--)
	{ 
		this->maxStreak+= (nums[len] * multiplier);
		multiplier*=10;
	}
	len =-1;
	multiplier =1;
	nums.clear();

	while(this->infoFile.get(temp) && temp!=c)
	temp=temp;
	while(this->infoFile.get(temp) && temp!='\n')
	{
		num=temp-'0';
		nums.push_back(num);
		len++;
			
	}
	for (len; len>=0; len--)
	{ 
		this->oneGuess+= (nums[len] * multiplier);
		multiplier*=10;
	}
	len =-1;
	multiplier =1;
	nums.clear();
	
	
	while(this->infoFile.get(temp) && temp!=c)
	temp=temp;
	while(this->infoFile.get(temp) && temp!='\n')
	{
		num=temp-'0';
		nums.push_back(num);
		len++;
			
	}
	for (len; len>=0; len--)
	{ 
		this->twoGuess+= (nums[len] * multiplier);
		multiplier*=10;
	}
	len =-1;
	multiplier =1;
	nums.clear();
	
	while(this->infoFile.get(temp) && temp!=c)
	temp=temp;
	while(this->infoFile.get(temp) && temp!='\n')
	{
		num=temp-'0';
		nums.push_back(num);
		len++;
			
	}
	for (len; len>=0; len--)
	{ 
		this->threeGuess+= (nums[len] * multiplier);
		multiplier*=10;
	}
	len =-1;
	multiplier =1;
	nums.clear();
	
	while(this->infoFile.get(temp) && temp!=c)
	temp=temp;
	while(this->infoFile.get(temp) && temp!='\n')
	{
		num=temp-'0';
		nums.push_back(num);
		len++;
			
	}
	for (len; len>=0; len--)
	{ 
		this->fourGuess+= (nums[len] * multiplier);
		multiplier*=10;
	}
	len =-1;
	multiplier =1;
	nums.clear();
	
		while(this->infoFile.get(temp) && temp!=c)
	temp=temp;
	while(this->infoFile.get(temp) && temp!='\n')
	{
		num=temp-'0';
		nums.push_back(num);
		len++;
			
	}
	for (len; len>=0; len--)
	{ 
		this->fiveGuess+= (nums[len] * multiplier);
		multiplier*=10;
	}
	len =-1;
	multiplier =1;
	nums.clear();
	
	while(this->infoFile.get(temp) && temp!=c)
	temp=temp;
	while(this->infoFile.get(temp) && temp!='\n')
	{
		num=temp-'0';
		nums.push_back(num);
		len++;
			
	}
	for (len; len>=0; len--)
	{ 
		this->sixGuess+= (nums[len] * multiplier);
		multiplier*=10;
	}
	len =-1;
	multiplier =1;
	nums.clear();
	}
	
	
//taking the number of guesses and incrementing the variables
void User::howManyGuesses(int num)
{
	if (num==1)
		this->oneGuess+=1;
	if (num==2)
		this->twoGuess+=1;
	if (num==3)
		this->threeGuess+=1;
	if (num==4)
		this->fourGuess+=1;
	if (num==5)
		this->fiveGuess+=1;
	if (num==6)
		this->sixGuess+=1;
	
}


//incrementing the gamesPlayed variable
void User::incrementGamesPlayed()
{
	this->gamesPlayed+=1;
}


//incrementing the gamesWon variable
void User::incrementGamesWon()
{
	this->gamesWon+=1;
}


//calculating the percent won after a new game
void User::calculatePercentWon ()
{
	this->percentWon = ((this->gamesWon / this->gamesPlayed) *100);
}


//incrementing the streak
void User::incrementStreak ()
{
	this->streak+=1;
}

//comparing the current streak to past streaks to determine the maxStreak
void User::determineMaxStreak ()
{
	if (this->streak>this->maxStreak)
		this->maxStreak = this->streak;
}

//printing the stats after a game
void User::printStats()
{
	cout << endl <<endl <<this->username
	<< "\nGamesPlayed:" <<this->gamesPlayed <<endl <<"percentWon:"
	<<this->percentWon <<endl	<<"Streak:" <<this->streak<<endl 
	<<"MaxStreak:" <<this->maxStreak<<endl
	<<"1guess: ";
	for (int i=1; i<= this->oneGuess; i++)
		cout<< "|";
	cout<<endl <<"2guess: ";
	for (int i=1; i<= this->twoGuess; i++)
		cout<< "|";
	cout<<endl <<"3guess: ";
	for (int i=1; i<= this->threeGuess; i++)
		cout<< "|";
	cout<<endl <<"4guess: ";
	for (int i=1; i<= this->fourGuess; i++)
		cout<< "|";
	cout<<endl <<"5guess: ";
	for (int i=1; i<= this->fiveGuess; i++)
		cout<< "|";
	cout<<endl <<"6guess: ";
	for (int i=1; i<= this->sixGuess; i++)
		cout<< "|";
}



//default constructor
Game::Game ()
{
	this->numOfGuesses=1;
	this->maxGuesses=7;
	this->won=false;
}

//to print instructions
void Game::printInstructions()
{
	cout << "\n----HOW TO PLAY----";
	cout<<"\nGuess the WORDLE in six tries.\n"
	<< "Each guess must be a valid five-letter word. Press Enter to submit.\n"
	<< "After each guess, the board will change to show how close your guess was to the word.\n"
	<< "\n\nA few examples...\n"
	<< "If you enter 'weary', the letters that show in green are in the correct space.\n";
	char green='a';
	cout<<"We";
	greenText(green) ;
	cout<< "ry\n\n";
	
	cout<<"If you enter 'hello', the letters that are in the word, but in the wrong spot will be yellow.\n";
	char yellow='e';
	cout <<"h";
	yellowText(yellow);
	cout<<"llo\n\n";
	
	cout<<"Whatever letter that is not in the word at all will be red.\n";
	char red = 'w';
	redText(red);
	cout<<"ate";
	red='r';
	redText (red);	
	cout<<endl <<endl;

}	

//to turn text red if a character is not in the word
void Game::redText(char r)
{
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 4);
	cout<<r;
	SetConsoleTextAttribute(color,15);
}

//to turn text green if a character is in the correct place in a word
void Game::greenText(char g)
{
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 2);
	cout<<g;
	SetConsoleTextAttribute(color,15);
}

//to turn text yellow if it is in the word, but not in the correct spot
void Game::yellowText (char y)
{
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 6);
	cout<<y;
	SetConsoleTextAttribute(color,15);
}


//opens a dictionary of 5 letter words and assigns a random one to the 
//Wordle word of the game
void Game::findRandomWord()
{
	string word;
	char chword [5];
	string filename="5letterWords.txt";
	this->dictionary.open(filename.c_str()); 
	srand(time(0));
	int random = rand()%5757;
	for (int i=1; i<=random; i++)
		getline (dictionary, word);
	
	for (int index=0; index<5 ;index++)
		this->wordleWord[index] = word[index];
	this->wordleWord[5]='\0';
	this->dictionary.close();
}


//prompts the user for guesses, gives the user 6 tries to guess the right word
void Game:: getUserWords()
{	
	bool correct= true;
	char userGuess[5];
	string word;
	bool inDictionary=false;
	
	cout<< "Time to enter your guesses...\n\n";
 	
	for (this->numOfGuesses=1; this->numOfGuesses<this->maxGuesses;
	this->numOfGuesses++)
 	{
		cout <<"Guess #" <<this->numOfGuesses <<":   ";
 		cin>>this->userGuess; 
			
			
 		cout<< "            ";
 		compareWords();
 		correct=true;
 		for (int i=0; i<5; i++)
 		{
 			if (this->userGuess[i]!=this->wordleWord[i])
 				correct=false;
 		}
		 if (correct==true)
		 {
		 	cout<<"You won in " <<this->numOfGuesses <<" guesses.\n\n";
		 	this->won=true;
		 	break;			 	
 	} 	 
}
	if (correct==false)
		cout<<"You lost\n\n";
}

//compares the wordle word to the user guess
void Game:: compareWords()
{
	bool inWord = false;
	
	for (int i=0; i<5; i++)
	{
		if (this->userGuess[i]==this->wordleWord[i])
			greenText(this->userGuess[i]);
		
		else{
			for(int j=0; j<5; j++)
			{
				if(this->userGuess[i]==wordleWord[j])
					inWord=true;
				else
					inWord=false;
		}
		if (inWord)
			yellowText(this->userGuess[i]);
		else
			redText (this->userGuess[i]);
	}
}
	cout<<endl;
}


		


