CXX = g++
CPPFLAGS = -Wall -g -std=c++11
GTEST_LL = -I /usr/include/gtest/ -l gtest -l gtest_main -pthread

all: clean test

test: Deck.o
	$(CXX) $(CPPFLAGS) test.cpp Deck.o $(GTEST_LL) -o deckTest

Deck.o: 
	$(CXX) $(CPPFLAGS) -c Deck.cpp -o Deck.o

clean: cleanDeck cleanTest

cleanDeck:
	-@rm -rf ./Deck.o

cleanTest:
	-@rm -rf ./deckTest