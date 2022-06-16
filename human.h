#ifndef _HUMAN_H_
#define _HUMAN_H_
#include "player.h"
#include "human.h"

class Human : public Player{
public:
    Human(std::string name);
   void makeMove(Table &x) override;
    ~Human() override;
};

#endif
