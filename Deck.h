// Program name : Five Crowns Part 2
// Author : Daniel Jackson
// Date last updated : 4 / 14 / 2018
// Purpose : Create, print, shuffle and store a vector of Card and Hand objects

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include "time.h"
#include "Card.h"

#ifndef Deck_H
#define Deck_H

class Deck
{
	std::vector<Card> deck; // Holds Card objects
	void createDeck(); // populates the vector

public:
	void shuffleDeck(); // sorts the vector
	void printDeck(); // prints the vector
	Card dealCard(); // pops a card from deck vector

	Deck();
};
#endif