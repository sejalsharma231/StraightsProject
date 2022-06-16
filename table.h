//
// Created by sejal sharma on 2020-12-06.
//

#ifndef _TABLE_H_
#define _TABLE_H_

#include "card.h"
#include <iostream>
#include <vector>
#include <memory>

class Table {
    std::vector<std::unique_ptr<Card> > diamonds;
    std::vector<std::unique_ptr<Card> > hearts;
    std::vector<std::unique_ptr<Card> > clubs;
    std::vector<std::unique_ptr<Card> > spade;

public:
    void printTable();
    void emptyTable();
    friend class Computer;
    friend class Human;
    friend class Player;

};
#endif //STRAIGHTS_TABLE_H
