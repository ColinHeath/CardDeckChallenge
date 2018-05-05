#include <string>
#include <vector>
#include <stdexcept>

struct Card
{
	public:
		std::string suit;
		int value;

		bool operator>(const Card rhs) const;
		bool operator<(const Card rhs) const;
		bool operator==(const Card rhs) const;
		bool operator!=(const Card rhs) const;
		void print() const;
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
};