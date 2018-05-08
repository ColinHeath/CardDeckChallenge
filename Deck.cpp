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

Deck::~Deck(){}

//Shuffles the deck and resets the head to the 0th card in the deck.
//Another shuffling method, shuffleFromTop(), is included privately for
//future development in which partial decks should be shuffled.
void Deck::shuffle()
{
	this->topIndex = 0;
	this->shuffleFromTop();
}

//Deals out one card item. If 52 cards have already been dealt,
//will throw a std::out_of_range exception.
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

//Deals a vector hand of Card items. If more than 52 cards are requested,
//The deck will output 52 cards.
std::vector<Card> Deck::dealHand(int handSize)
{
	std::vector<Card> toReturn;

	for(int i = 0; i < handSize; i++)
	{
		try
		{
			toReturn.push_back(this->deal());
		}
		catch(std::out_of_range outOfRange)
		{
			break;
		}
	}

	return toReturn;
}

void Deck::shuffleFromTop()
{
	//Seed the cstdlib random generator with time(0) so that seeds are unlikely to repeat.
	std::srand(time(0));

	//Standard shuffling algorithm (Fisher-Yates/Durstenfeld), learned in class in fall.
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