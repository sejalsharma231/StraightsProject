//
// Created by sejal sharma on 2020-12-05.
//

#include "player.h"


void Player::addHand(std::unique_ptr<Card> p) {
    hand.emplace_back(std::move(p));
}


void Player::makeStarter() {
    starter=true;
}
bool Player::isStarter() const {
    return starter;
}

bool Player::emptyHanded() {
    return (hand.empty());
}

void Player::printHand() {
    std::cout<<"Your hand: ";
    for(auto & i : hand){
        std::cout << i->printCard();
        if(i !=hand[hand.size()-1]) {
            std::cout<<" ";
        }
    }
    std::cout<<"\n";
}
void Player::printDiscards() {
    std::cout<<name<<"'s discards:";
    for(auto & i : discards){
        std::cout << " "<<i->printCard();
    }
    std::cout<<"\n";
}

void Player::play(std::unique_ptr<Card> p, Table &x) {
    std::cout<<name<< " plays "<< p->printCard()<<"\n";
    if(p->getSuit()=='C'){
        int insert=0;
        int value=p->getValue();
        if(!(x.clubs.empty())&&value>x.clubs[x.clubs.size()-1]->getValue()){
           insert=x.clubs.size();
        }else {
            for (int i = 0; i < x.clubs.size(); i++) {
                if (i != 0 && value < x.clubs[i]->getValue() && value > x.clubs[i - 1]->getValue() && value) {
                    insert = i;
                }
            }
        }x.clubs.emplace(x.clubs.begin() + insert, std::move(p));

    }else if(p->getSuit()=='D'){
        int insert=0;
        int value=p->getValue();
        if(!(x.diamonds.empty())&&value>x.diamonds[x.diamonds.size()-1]->getValue()){
            insert=x.diamonds.size();
        }else {
            for (int i = 0; i < x.diamonds.size(); i++) {
                if (i != 0 && value < x.diamonds[i]->getValue() && value > x.diamonds[i - 1]->getValue() && value) {
                    insert = i;
                }
            }
        }x.diamonds.emplace(x.diamonds.begin() + insert, std::move(p));
    }else if(p->getSuit()=='H'){
        int insert=0;
        int value=p->getValue();
        if(!(x.hearts.empty())&&value>x.hearts[x.hearts.size()-1]->getValue()){
            insert=x.hearts.size();
        }else {
            for (int i = 0; i < x.hearts.size(); i++) {
                if (i != 0 && value < x.hearts[i]->getValue() && value > x.hearts[i - 1]->getValue() && value) {
                    insert = i;
                }
            }
        }x.hearts.emplace(x.hearts.begin() + insert, std::move(p));
    }else{
        int insert=0;
        int value=p->getValue();
        if(!(x.spade.empty())&&value>x.spade[x.spade.size()-1]->getValue()){
            insert=x.spade.size();
        }else {
            for (int i = 0; i < x.spade.size(); i++) {
                if (i != 0 && value < x.spade[i]->getValue() && value > x.spade[i - 1]->getValue() && value) {
                    insert = i;
                }
            }
        }x.spade.emplace(x.spade.begin() + insert, std::move(p));
    }
}

void Player::discard(std::unique_ptr<Card> p) {
    std::cout<<name<< " discards "<< p->printCard()<<"\n";
    discards.emplace_back(std::move(p));
}

std::vector<std::string> Player::legalPlays(Table &x) {
    std::vector<std::string>legalCards;
    if (starter && hand.size()==13){
        int n = 0;
        for (auto &i : hand ) {
            if(i->printCard()=="7S") {
                legalCards.emplace_back(i->printCard());
            }
            n++;
        }
    }else {
        for (auto &i : hand) {
            if (i->getValue() == 7) {
                legalCards.emplace_back(i->printCard());
            } else if (i->getSuit() == 'S') {
                for (auto &s : x.spade) {
                    if (s->getValue() == (i->getValue() - 1) || s->getValue() == (i->getValue() + 1)) {
                        legalCards.emplace_back(i->printCard());
                    }
                }
            } else if (i->getSuit() == 'C') {
                for (auto &s : x.clubs) {
                    if (s->getValue() == (i->getValue() - 1) || s->getValue() == (i->getValue() + 1)) {
                        legalCards.emplace_back(i->printCard());
                    }
                }
            } else if (i->getSuit() == 'D') {
                for (auto &s : x.diamonds) {
                    if (s->getValue() == (i->getValue() - 1) || s->getValue() == (i->getValue() + 1)) {
                        legalCards.emplace_back(i->printCard());
                    }
                }
            } else if (i->getSuit() == 'H') {
                for (auto &s : x.hearts) {
                    if (s->getValue() == (i->getValue() - 1) || s->getValue() == (i->getValue() + 1)) {
                        legalCards.emplace_back(i->printCard());
                    }
                }
            }
        }
    }
    return legalCards;
}



int Player::discardValue() {
    int value=0;
    for (auto &i : discards) {
        value+= i->getValue();
    }
    return value;
}
void Player::recalculateScore() {
        score += discardValue();

}
int Player::getScore() const {
    return score ;

}

void Player::printNewScore() {
    std::cout<<name<<"'s score: "<<score<<" + "<<discardValue()<<" = ";
    recalculateScore();
    std::cout<<score<<"\n";
}

std::string Player::getType() {
    return type;
}

std::string Player::getName() {
    return name;
}

void Player::newRound() {
    for (auto &i : hand) {
        i.reset();
        hand.erase(hand.begin());
    }
    for (auto &i : discards) {
        i.reset();
        discards.erase(discards.begin());
    }
    starter=false;

}

std::vector<std::unique_ptr<Card>> Player::getDiscards() {
    return std::move(discards);
}

std::vector<std::unique_ptr<Card>> Player::getHand() {
    return std::move(hand);
}

Player::~Player() = default;


















