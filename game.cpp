
#include "game.h"
#include "deck.h"
#include "player.h"
#include "table.h"
#include "computer.h"

Game::Game(Player *p1, Player *p2, Player *p3, Player *p4, int seed): p1{p1},p2{p2},p3{p3},p4{p4}{
    this->deck= new Deck(seed);
    this->table= new Table();
}

void Game::newRound() {
    deck->shuffle();
    p1->newRound();
    p2->newRound();
    p3->newRound();
    p4->newRound();
    table->emptyTable();
    for (int i = 0; i < 52; i++) {
        auto s = std::make_unique<Card>(deck->getCard(i));

        if (i < 13) {
            if (s->getValue() == 7 && s->getSuit() == 'S') {
                p1->makeStarter();
            }
            p1->addHand(std::move(s));
        } else if (i < 26) {
            if (s->getValue() == 7 && s->getSuit() == 'S') {
                p2->makeStarter();
            }
            p2->addHand(std::move(s));
        } else if (i < 39) {
            if (s->getValue() == 7 && s->getSuit() == 'S') {
                p3->makeStarter();
            }
            p3->addHand(std::move(s));
        } else {
            if (s->getValue() == 7 && s->getSuit() == 'S') {
                p4->makeStarter();
            }
            p4->addHand(std::move(s));

        }
    }

    std::cout<<"A new round begins.";
}

void Game::makeMove(Player *currentPlayer) {
    currentPlayer->makeMove(*table);
}

bool Game::roundOver() {
    if(p1->isStarter()){
       return p4->emptyHanded();
    }
    if(p2->isStarter()){
        return p1->emptyHanded();
    }
    if(p3->isStarter()){
        return p2->emptyHanded();
    }
        return p3->emptyHanded();

}

void Game::printDeck() {
    std::cout<<deck->printDeck();
}

void Game::playInfo(Player *currentPlayer) {
    table->printTable();
    currentPlayer->printHand();
    std::cout << "Legal plays:";
    std::vector<std::string> legalCards = currentPlayer->legalPlays(*table);
    for (auto &i: legalCards) {
        std::cout << " " << i;
    }std::cout << "\n";
}

void Game::endRound() {
    p1->printDiscards();
    p1->printNewScore();
    p2->printDiscards();
    p2->printNewScore();
    p3->printDiscards();
    p3->printNewScore();
    p4->printDiscards();
    p4->printNewScore();
}

bool Game::gameOver() {
    return(p1->getScore()>79||p2->getScore()>79||p3->getScore()>79||p4->getScore()>79);
}

Player * Game::rageQuit(Player *currentPlayer) {
    if(currentPlayer->getName()=="Player1"){
        p1=currentPlayer;
        return p1;
    }else if(currentPlayer->getName()=="Player2"){
        p2=currentPlayer;
        return p2;
    }else if(currentPlayer->getName()=="Player3"){
        p3=currentPlayer;
        return p3;
    }else{
        p4=currentPlayer;
        return p4;
    }

}

Game::~Game() {
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete deck;
    delete table;
}

void Game::printWinner() {
    int lowestScore=p1->getScore();
    if(p2->getScore()<lowestScore){
        lowestScore=p2->getScore();
    }
    if(p3->getScore()<lowestScore){
        lowestScore=p3->getScore();
    }
    if(p4->getScore()<lowestScore){
        lowestScore=p4->getScore();
    }
    if(lowestScore==p1->getScore()){
        std::cout<<p1->getName()<<" wins!"<<std::endl;
    }
    if(lowestScore==p2->getScore()){
        std::cout<<p2->getName()<<" wins!"<<std::endl;
    }
    if(lowestScore==p3->getScore()){
        std::cout<<p3->getName()<<" wins!"<<std::endl;
    }
    if(lowestScore==p4->getScore()){
        std::cout<<p4->getName()<<" wins!"<<std::endl;
    }
}


