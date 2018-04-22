// Program name : Five Crowns Part 2
// Author : Daniel Jackson
// Date last updated : 4 / 14 / 2018
// Purpose : Create, print, shuffle and store a vector of Card and Hand objects

#pragma once
#include <vector>
#include "Deck.h"
#ifndef Hand_H
#define Hand_H

class Hand
{
	std::vector<Card> hand; // a vector of cards
	int handValue; // stores the value of the hand
	int numCards(); // returns the number of cards in the hand
	const int cardsInHand = 9; // the max number of cards a hand can hold
	void addCard(Card card); // adds a card to the deck
	void setHandValue(); // generates a hand value
	// gives the overloaded operators access to private hand members
	friend bool operator==(const Hand& lhs, const Hand& rhs); // compares two hands for equality
	friend bool operator< (const Hand& lhs, const Hand& rhs); // compares two hands to see if one is less than
	friend std::ostream& operator<<(std::ostream& os, const Hand& obj); // prints one hand
public:
	void operator= (const Hand &H); // assigns one hand to another
	int getHandValue(); // returns the value of the hand
	Hand(Deck &deck); // Hand constructor take a reference to a deck
};

bool operator==(const Hand& lhs, const Hand& rhs); // compares two hands for equality
bool operator< (const Hand& lhs, const Hand& rhs); // compares two hands to see if one is less than
std::ostream& operator<<(std::ostream& os, const Hand& obj); // prints one hand

#endif