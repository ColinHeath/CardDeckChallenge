# CardDeckChallenge

- **Name**: Colin Heath
- **Email**: colinjhe@usc.edu

**Summary**
The files in this repository provide definitions for a Card struct and Deck class.

The Card struct contains two members, string suit and int value. It supports standard comparison and assignment operators (<, >, ==, !=, =). Aces are worth 1.

The Deck class automatically populates itself with 52 unshuffled cards. It supports shuffling via the shuffle() method, dealing one card via the deal() method, and dealing multiple cards in a vector via the dealHand(int handSize) method.

When using the class and struct in other work, it is important to keep in mind that
the types of Card's data members are string and integer, so the value of a card cannot be compared against the string "Jack".

Additionally, there is a makefile provided for compiling automated tests of the Deck class. The makefile produces an executable, deckTest, which will run a series of short tests to ensure that the Deck class functions as intended.