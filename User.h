//filename: User.h
//name: Veronica Bone
//created: 5/9/22
//revised: 5/18/22

#ifndef USER_H  //GUARD
#define USER_H

#include <fstream>
#include "game.h"


using namespace std;


class User
{
	private:
		string username; 
		fstream infoFile;
		int oneGuess;
		int twoGuess;
		int threeGuess;
		int fourGuess;
		int fiveGuess;
		int sixGuess;
		int gamesPlayed;
		int gamesWon;
		int percentWon;
		int streak;
		int maxStreak;
		
	public:	
		User ();
		void openFile();
		void closeFile();
		void searchForUser ();
		void addUser ();
		void readInStats();
		void howManyGuesses(int);
		void incrementGamesPlayed();
		void incrementGamesWon();
		void calculatePercentWon ();
		void incrementStreak ();
		void determineMaxStreak ();
		void printStats();
};
#endif

