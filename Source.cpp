// Program name : Five Crowns Part 2
// Author : Daniel Jackson
// Date last updated : 4 / 14 / 2018
// Purpose : Create, print, shuffle and store a vector of Card and Hand objects

#include "Deck.h"
#include "Hand.h"

int main()
{
	srand(time(NULL)); // seeds rand for when the deck gets shuffled

	std::vector<Hand> hands; // vector of Hands, holds multiple card Hands

	Deck deck; // creates a new Deck object
	std::cout << "Deck created!\n";

	// shuffles and prints the deck
	deck.shuffleDeck();
	std::cout << "Deck shuffled!\n";
	deck.printDeck();

	// gets the number of players from the user
	std::string players = "";
	do
	{
		std::cout << "How many players do you want: ";
		std::cin >> players;
	} while (stoi(players) < 2 || stoi(players) > 7); // while the players are less than 2 or greater than 7

	// creates a hand for each player, then prints it
	for (int x = 0; x < stoi(players); x++)
	{
		Hand h(deck); // creates a hand from the deck
		hands.push_back(h); // adds the hand to the hands vector
		// prints the cards in the hand and the score of the hand
		std::cout << "Hand " << x + 1 << "\n";
		std::cout << h;
		std::cout << "Score: " << hands.at(x).getHandValue() << "\n";
	}

	// finds the lowest hand, and therefore the winner, of all the players
	Hand lowest = hands.at(0); // gives a starting "lowest" card
	int lowestPlayer = 0; // keeps track of the player number, which person the lowest hand belongs to
	for (int player = 1; player < hands.size(); player++) // iterates through the size of the Hands vector
	{
		if (hands.at(player) < lowest) // if the current card is less than the lowest card
		{
			lowest = hands.at(player); // make that card the new lowest
			lowestPlayer = player; // that player the new lowest
		}
	}

	std::cout << "Player " << lowestPlayer + 1 << " has the winning hand with a score of " << lowest.getHandValue() << "\n"; // prints the winning player and the player's score

	std::cin.get();
	std::cin.ignore();
	return 0;
}
