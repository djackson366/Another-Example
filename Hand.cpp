// Program name : Five Crowns Part 2
// Author : Daniel Jackson
// Date last updated : 4 / 14 / 2018
// Purpose : Create, print, shuffle and store a vector of Card and Hand objects

#include "Hand.h"




void Hand::addCard(Card card) // adds a card to the Hand vector
{
	hand.push_back(card);
}

void Hand::setHandValue() // generates a hand value by adding the values of the faces of each card in the hand
{
	for (auto i : hand)
	{
		handValue += i.face;
	}
}

int Hand::getHandValue() // returns the hand value
{
	return handValue;
}

int Hand::numCards() // returns the number of cards in the hand
{
	return hand.size();
}

Hand::Hand(Deck & deck) // constructor generates a hand when called
{
	for (int i = 0; i < cardsInHand; i++) // loops through the cards required for one hand
	{
		addCard(deck.dealCard()); // adds a card to the hand while removing that same card from the deck
	}
	setHandValue(); // sets the value of the newly created hand
}

bool operator==(const Hand& lhs, const Hand& rhs) // compares one Hand value to another for equivalence
{
	return &lhs.handValue == &rhs.handValue;
}

bool operator< (const Hand& lhs, const Hand& rhs) // compares one Hand value to another for inequality
{
	return lhs.handValue < rhs.handValue;
}

std::ostream& operator<<(std::ostream& os, const Hand & obj) // prints all the Cards in one hand
{
	for (auto i : obj.hand) // loops through hand
	{
		std::cout << "	" << i << '\n'; // prints the object
	}
	return os;
}

void Hand::operator= (const Hand &H) // assigns one card to another by making the cards in the deck equal and the hand values equal
{
	for (int x = 0; x < numCards(); x++) // loops through the number of cards in a hand
	{
		hand.at(x) = H.hand.at(x); // assigns the cards from the right hand of the = to the left
	}
	handValue = H.handValue; // gives the deck the same handValue
}