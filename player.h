
#ifndef STRAIGHTS_PLAYER_H
#define STRAIGHTS_PLAYER_H

#include <iostream>
#include <vector>
#include "card.h"
#include "table.h"

class Player{
protected:
    int score;
    bool starter;
    std::string name;
    std::string type;
    std::vector<std::unique_ptr<Card>> discards;
    std::vector<std::unique_ptr<Card>> hand;
    int discardValue();
    void recalculateScore();
public:
    virtual void makeMove(Table& x)=0;
    void addHand(std::unique_ptr<Card> p);
    void play (std::unique_ptr<Card> p, Table &x);
    void discard (std::unique_ptr<Card> p);
    bool emptyHanded();
    void printHand();
    std::vector<std::string> legalPlays(Table &x);
    void printDiscards();
    void printNewScore();
    void newRound();
    //getters and setters
    std::vector<std::unique_ptr<Card>> getDiscards();
    std::vector<std::unique_ptr<Card>> getHand();
    int getScore() const;
    bool isStarter() const;
    void makeStarter();
    std::string getType();
    std::string getName();
    //destructor
    virtual ~Player();
};



#endif //STRAIGHTS_PLAYER_H
