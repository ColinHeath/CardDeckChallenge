#include "Deck.h"
#include "gtest/gtest.h"
#include <set>

//Test to ensure that constructing the deck populates it with the right cards.
TEST(DeckTest, ConstructPresent)
{
	Deck deck;

	std::string suits[4] = {"Diamonds", "Hearts", "Clubs", "Spades"};
	
	for(size_t i = 0; i < 4; i++)
	{
		for(size_t j = 1; j <= 13; j++)
		{
			Card dealt = deck.deal();
			
			EXPECT_EQ(dealt.suit, suits[i]);
			EXPECT_EQ(dealt.value, j);
		}
	}
}

//Test for the behavior of dealing at the bottom of the deck.
TEST(DeckTest, DealLimit)
{
	Deck deck;

	for(size_t i = 0; i < 53; i++)
	{
		try
		{
			deck.deal();
		}
		catch(...)
		{
			EXPECT_EQ(i, 52);
		}
	}
}

TEST(DeckTest, HandLimit)
{
	Deck deck;

	std::vector<Card> userHand = deck.dealHand(53);

	EXPECT_EQ(userHand.size(), 52);
}

//Test to ensure that shuffling sufficiently changes the deck.
TEST(DeckTest, ShuffleChange)
{
	Deck deckOne;
	Deck deckTwo;

	deckTwo.shuffle();

	int identityCount = 0;

	for(int i = 0; i < 52; i++)
	{
		if(deckOne.deal() == deckTwo.deal()) identityCount++;
	}

	EXPECT_LT(identityCount, 20);
}

//Test to ensure that shuffling causes no repeated cards to appear.
TEST(DeckTest, ShuffleRepeat)
{
	Deck deck;

	deck.shuffle();

	std::vector<Card> deckHolder;

	for(int i = 0; i < 52; i++)
	{
		deckHolder.push_back(deck.deal());
	}

	for(size_t j = 0; j < 52; j++)
	{
		for(size_t k = j + 1; k < 52; k++)
		{
			EXPECT_NE(deckHolder[j], deckHolder[k]);
		}
	}
}