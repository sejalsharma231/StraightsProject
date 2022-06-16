
#include "computer.h"
#include <utility>

Computer::Computer(std::string name){
    this->score=0;
    this->starter=false;
    this->name=std::move(name);
    this->type="c";
}
Computer::Computer(std::string name,std::vector<std::unique_ptr<Card>> hand,std::vector<std::unique_ptr<Card>> discards,int score, bool starter){
    this->type="c";
    this->name=std::move(name);
    this->discards=std::move(discards);
    this->hand=std::move(hand);
    this->score=score;
    this->starter=starter;
}

void Computer::makeMove(Table &x) {
    std::vector<std::string> legalCards = legalPlays(x);
    if(!legalCards.empty()){
        int n=0;
        for (auto &i : hand) {
            if (i->printCard() == legalCards[0]) {
                play(std::move(i), x);
                hand.erase(hand.begin() + n);
                break;
            }
            n++;
        }
    }else{
        discard(std::move(hand[0]));
        hand.erase(hand.begin());
    }
}

Computer::~Computer() = default;







