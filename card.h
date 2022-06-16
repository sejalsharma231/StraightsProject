#ifndef _CARD_H_
#define _CARD_H_
#include <iostream>
#include <string>

class Card {
     char suit;
     int value;
     char showValue;
public:
    Card(char suit, int value, char showValue);
    std::string printCard() const;
    Card &operator=(const Card &other);
    int getValue() const;
    char getSuit() const;
    char getShowValue() const;
};


#endif //STRAIGHTS_CARD_H
