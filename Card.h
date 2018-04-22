// Program name : Five Crowns Part 2
// Author : Daniel Jackson
// Date last updated : 4 / 14 / 2018
// Purpose : Create, print, shuffle and store a vector of Card and Hand objects

#pragma once
#include <string>
#include <iostream>

#ifndef Card_H
#define Card_H

class Card
{

	enum Face { THREE = 3, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, JOKER = 20 }; // enumeration for all card faces
	enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES, STARS, NOSUIT }; // enumeration for all card suits

	Face face; // card face of enumeration type Face
	Suit suit; // card suit of enumeration type Suit

	// allows classes deck and hand to access Card data
	friend class Deck;
	friend class Hand;
	// declares overloaded == and << operators as friends
	friend bool operator==(const Card& lhs, const Card& rhs);
	friend std::ostream& operator<<(std::ostream& os, const Card& obj);

	std::string getFace(Face face) const; // returns a string for a card face
	std::string getSuit(Suit suit) const; // returns a string for a card suit

public:
	std::string toString() const; // returns a string for a whole card
	void operator= (const Card &C); // overloaded assignment operator
	Card(Face face, Suit suit); // Constructor that initializes members face and suit
};

// declares overloaded == and << operators
inline bool operator==(const Card& lhs, const Card& rhs);
std::ostream& operator<<(std::ostream& os, const Card& obj);
#endif