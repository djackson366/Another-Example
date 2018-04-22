// Program name : Five Crowns Part 2
// Author : Daniel Jackson
// Date last updated : 4 / 14 / 2018
// Purpose : Create, print, shuffle and store a vector of Card and Hand objects

#include "Card.h"



std::string Card::getFace(Face face) const// returns a string based on the Face enumeration
{
	switch (face)
	{
	case THREE: return "Three";
	case FOUR: return "Four";
	case FIVE: return "Five";
	case SIX: return "Six";
	case SEVEN: return "Seven";
	case EIGHT: return "Eight";
	case NINE: return "Nine";
	case TEN: return "Ten";
	case JACK: return "Jack";
	case QUEEN: return "Queen";
	case KING: return "King";
	case JOKER: return "Joker";
	default: return "";
	};
}

std::string Card::getSuit(Suit suit) const // returns a string based on the Suit enumeration
{
	switch (suit)
	{
	case CLUBS: return "Clubs";
	case DIAMONDS: return "Diamonds";
	case HEARTS: return "Hearts";
	case SPADES: return "Spades";
	case STARS: return "Stars";
	default: return "Nothing";
	};
}

std::string Card::toString() const// builds and returns a string of the whole Card
{
	if (face != JOKER) // because a joker has no suit, we do not need to print its suit
	{
		return getFace(face) + " of " + getSuit(suit);
	}
	else
	{
		return getFace(face); // prints the Joker
	}
}

void Card::operator=(const Card & C) // assigns one card to another
{
	face = C.face;
	suit = C.suit;
}

Card::Card(Face face, Suit suit) // constructor
{
	this->face = face; // initialize face and suit
	this->suit = suit;
}

inline bool operator==(const Card& lhs, const Card& rhs) // compares one card face to another
{
	return &lhs.face == &rhs.face;
}

std::ostream& operator<<(std::ostream& os, const Card& obj) // prints one card
{
	std::cout << obj.toString();
	return os;
}