
#include "card.h"

Card::Card(char suit, int value, char showValue) :suit{suit}, value{value},showValue(showValue){}

std::string Card::printCard() const {
    std::string cardInfo;
    cardInfo += showValue;
    cardInfo += suit;
    return cardInfo;
}

Card &Card::operator=(const Card &other) {
    if(this == &other){
        return *this;
    }
    suit = other.suit;
    showValue = other.showValue;
    value = other.value;
    return *this;
}

int Card::getValue() const {
    return value;
}

char Card::getShowValue() const {
    return showValue;
}

char Card::getSuit() const {
    return suit;
}








