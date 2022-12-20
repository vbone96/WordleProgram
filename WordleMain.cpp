// filename: main.cpp
// author: Veronica Bone
// created: 5/9/2022
// revised: 5/182022

#include <iostream>
#include "user.h" //header file
#include "game.h"

using namespace std;

int main()
{
	char playAgain;
	User p;
	Game g;

	//do while loop to keep playing game until user decides to quit
	do{
	g.printInstructions();
	g.findRandomWord();
	cout<<endl <<endl;
	g.getUserWords();
	
	p.searchForUser();
	p.incrementGamesPlayed();
	if (g.getWon() ==true)
	{	
		p.incrementStreak();
		p.incrementGamesWon();
	}
	p.determineMaxStreak();
	p.howManyGuesses(g.getNumOfGuesses());
	p.printStats();
	
	cout<< "\n\nPlay again? Y/N:";
	cin>>playAgain;
	
} while (playAgain=='Y');
	p.addUser();		
}
