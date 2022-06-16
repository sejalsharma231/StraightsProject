
#ifndef STRAIGHTS_DECK_H
#define STRAIGHTS_DECK_H
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <random>
#include <chrono>

class Card;

class Deck {
    std::vector<Card > theDeck;
    int seed;
public:
    explicit Deck(int seed );
    void shuffle();
    std::string printDeck();
    Card getCard(int pos);
};



#endif //STRAIGHTS_DECK_H
