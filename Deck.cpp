// Program name : Five Crowns Part 2
// Author : Daniel Jackson
// Date last updated : 4 / 14 / 2018
// Purpose : Create, print, shuffle and store a vector of Card and Hand objects

#include "Deck.h"




void Deck::createDeck() // creates the card deck
{
	int Hand = 2;
	for (int y = 0; y < Hand; y++) // repeats each suit twice
	{
		for (Card::Suit suit = Card::CLUBS; suit <= Card::STARS; suit = Card::Suit(suit + 1)) // loops through all the suits
		{
			for (Card::Face face = Card::THREE; face <= Card::KING; face = Card::Face(face + 1)) // loops through all the decks
			{
				Card card(face, suit); // creates a card object
				deck.push_back(card); // pushed the card onto the Deck
			}
		}
	}
	const int numJokers = 6;
	for (int Hand = 0; Hand < numJokers; Hand++) // pushes the Jokers onto the deck
	{
		Card card(Card::JOKER, Card::NOSUIT);
		deck.push_back(card);
	}
}

void Deck::shuffleDeck() // shuffles the Deck vector
{
	for (auto i : deck)
	{
		int rndValue = rand() % deck.size(); // sets a pseudo random index between 0 and the last card in the Deck
		Card tmpCard = i; // sets the current Card to a temporary Card
		i = deck[rndValue]; // sets the current Card to the value in the pseudo random indeHand
		deck[rndValue] = tmpCard; // sets the Card at the pseudo random address to the current card, effectively swapping each card
	}
}

void Deck::printDeck() // prints out each Card in the Deck
{
	int num = 0;
	for (auto i : deck)
	{
		std::cout << i << '\n';
		num++;
	}
	std::cout << "Cards in deck: " << num << '\n';
}

Card Deck::dealCard() // deals one card from the deck
{
	Card card = deck.back(); // assigns the back card of the deck vector to a card.
	deck.pop_back(); // removes the back card of the deck vector
	return card; // returns the card from the back of the deck
}

Deck::Deck() // constructor
{
	createDeck(); // creates a deck when called
}
