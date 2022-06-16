
#ifndef _GAME_H_
#define _GAME_H_
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>

class Deck;
class Player;
class Card;
class Table;

class Game {
    Table *table = nullptr;
    Deck *deck = nullptr;
    Player *p1;
    Player *p2;
    Player *p3;
    Player *p4;
public:
    Game(Player *p1, Player *p2, Player *p3, Player *p4, int seed=0);

    //shuffle cards and distribute them to all the players
    void newRound();
    void makeMove(Player *currentPlayer);
    bool roundOver();
    void printDeck();
    void playInfo(Player *currentPlayer);
    void endRound();
    bool gameOver();
    void printWinner();
    Player* rageQuit(Player *currentPlayer);
   ~Game();
};


#endif //STRAIGHTS_GAME_H
