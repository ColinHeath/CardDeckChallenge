#include <string>

struct Card
{
	public:
		std::string suit;
		std::string value;
};

class Deck
{
	public:
		Deck();
		~Deck();
		void shuffle();
		Card deal();
		std::vector<Card> dealHand(int handSize);
	private:
		void shuffleFromTop();

		Card internalDeck[52];
		int topIndex;
}