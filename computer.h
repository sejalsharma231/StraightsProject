#ifndef STRAIGHTS_COMPUTER_H
#define STRAIGHTS_COMPUTER_H
#include "player.h"


class Computer:public Player {
public:
    explicit Computer(std::string name);
    Computer(std::string name, std::vector<std::unique_ptr<Card>> hand, std::vector<std::unique_ptr<Card>> discards,
             int score, bool starter);
    void makeMove(Table &x) override;
    ~Computer() override;

};


#endif //STRAIGHTS_COMPUTER_H
