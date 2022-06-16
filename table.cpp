//
// Created by sejal sharma on 2020-12-06.
//

#include "table.h"

void Table::emptyTable(){
    for (auto &i : spade) {
        i.reset();
        spade.erase(spade.begin());
    }
    for (auto &i : diamonds) {
        i.reset();
        diamonds.erase(diamonds.begin());
    }
    for (auto &i : hearts) {
        i.reset();
        hearts.erase(hearts.begin());
    }
    for (auto &i : clubs) {
        i.reset();
        clubs.erase(clubs.begin());
    }
}

void Table::printTable() {
    std::cout<<"Cards on the table:\n";
    //print clubs
    std::cout<<"Clubs:";
    for(auto & i : clubs){
        std::cout<<" "<<i->getShowValue();
    }std::cout<<"\n";
    //print diamonds
    std::cout<<"Diamonds:";
    for(auto & i : diamonds){
        std::cout<<" "<<i->getShowValue();
    }std::cout<<"\n";
    //print hearts
    std::cout<<"Hearts:";
    for(auto & i : hearts){
        std::cout<<" "<<i->getShowValue();
    }std::cout<<"\n";
    //print spades
    std::cout<<"Spades:";
    for(auto & i : spade){
        std::cout<<" "<<i->getShowValue();
    }std::cout<<"\n";
}
