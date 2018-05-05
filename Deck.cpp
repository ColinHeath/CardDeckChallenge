#include "Deck.h"
#include <cstdlib>

bool Card::operator>(const Card rhs) const
{
	return (this->value > rhs.value);
}

bool Card::operator<(const Card rhs) const
{
	return (this->value < rhs.value);
}

bool Card::operator==(const Card rhs) const
{
	return ((this->suit == rhs.suit) && (this->value == rhs.value));
}

bool Card::operator!=(const Card rhs) const
{
	return !((*this) == rhs);
}

Deck::Deck()
:topIndex(0)
{
	//Temporary lookup array to make population easier.
	std::string suits[4] = {"Diamonds", "Hearts", "Clubs", "Spades"};
	
	//Populate Internal Deck with Card Structs
	for(size_t i = 0; i < 4; i++)
	{
		for(int j = 0; j < 13; j++)
		{
			Card toAdd;
			
			toAdd.suit = suits[i];
			toAdd.value = j + 1;

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
	if(topIndex < 52)
	{
		return this->internalDeck[topIndex++];
	}
	else
	{
		std::out_of_range outOfRange("End of Deck has been Reached");
		throw outOfRange;
	}
}

std::vector<Card> Deck::dealHand(int handSize)
{
	std::vector<Card> toReturn;

	for(int i = 0; i < handSize; i++)
	{
		toReturn.push_back(this->deal());
	}

	return toReturn;
}

void Deck::shuffleFromTop()
{
	//Seed the cstdlib random generator pseudorandomly with time.
	std::srand(time(0));

	int j;
	Card temp;
	for(int i = 51; i > this->topIndex; i--)
	{
		j = (std::rand() % (i + 1));
		temp = (this->internalDeck)[j];
		(this->internalDeck)[j] = (this->internalDeck)[i];
		(this->internalDeck)[i] = temp;
	}
}