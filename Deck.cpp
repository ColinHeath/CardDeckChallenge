#include "Deck.h"
#include <cstdlib>

Deck::Deck()
:topIndex(0)
{
	//Temporary lookup arrays to make population easier.
	std::string suits[4] = {"Diamonds", "Hearts", "Clubs", "Spades"};
	std::string values[13] = 
		{"Ace". "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	
	//Populate Internal Deck with Card Structs
	for(size_t i = 0; i < 4; i++)
	{
		for(size_t j = 0; j < 13; j++)
		{
			Card toAdd;
			
			toAdd.suit = suits[i];
			toAdd.value = values[j];

			this->internalDeck[(13*i) + j] = toAdd;
		}
	}
}

Deck::~Deck()
{

}

void Deck::shuffle()
{
	this->topIndex = 0;
	this->shuffleFromTop();
}

Card Deck::deal()
{
	return this->internalDeck[topIndex++];
}

std::vector<Card> Deck::dealHand(int handSize)
{
	std::vector<Card> toReturn;

	for(size_t i = 0; i < handSize; i++)
	{
		toReturn.push_back(this->deal());
	}

	return toReturn;
}

void Deck::shuffleFromTop()
{
	//Seed the cstdlib random generator pseudorandomly with time.
	std::srand(std::time(0));

	int j;
	int temp;
	for(int i = 51; i > this->topIndex; i--)
	{
		j = (std::rand() % (i + 1));
		temp = cards[j];
		cards[j] = cards[i];
		cards[i] = temp;
	}
}