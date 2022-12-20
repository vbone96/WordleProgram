//filename: User.h
//name: Veronica Bone
//created: 5/9/22
//revised: 5/18/22

#ifndef GAME_H  //GUARD
#define GAME_H

#include <fstream>

using namespace std;


class Game
{
	private:
		char wordleWord[5];
		char userGuess[5];
		int numOfGuesses;
		int maxGuesses;
		bool won;
		ifstream dictionary;
		
	public:	
		Game ();
		
		void printInstructions ();
		void redText(char);
		void greenText(char);
		void yellowText (char);
		void findRandomWord ();
		void getUserWords();
		bool getWon(){return won;};
		int getNumOfGuesses(){return numOfGuesses;};
		void compareWords();
		
};
#endif

