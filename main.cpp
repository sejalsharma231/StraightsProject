#include <iostream>
#include "player.h"
#include "human.h"
#include "game.h"
#include "deck.h"
#include "computer.h"

int main(int argc, char **argv) {

   int seed =0;
    std::string cmd;
    //check if seed is provided by user
    if (argc > 1) {
         try{
            seed = std::stoi(argv[1]);
        }catch(std::exception &err){
            std::cerr << "Invalid seed, using default seed!" << std::endl;
            }
    }

    //ask for players
    std::vector<Player *> players;
    int added=0;

    std::string playerName;
    while(added<4){
        try{
        switch(added) {
            case 0:playerName="Player1"; break;
            case 1:playerName="Player2"; break;
            case 2:playerName="Player3"; break;
            case 3:playerName="Player4"; break;
        }
        std::cout<<"Is "<<playerName<<" a human (h) or computer (c)?\n";

        std::cin >> cmd;

        if(cmd=="h"){
            players.emplace_back(new Human(playerName));
        }else if(cmd=="c"){
            players.emplace_back(new Computer(playerName));
        }else {
            throw std::invalid_argument("Enter a valid player type!");
        }
        added+=1;
        }catch (std::invalid_argument &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    //start game
    Game game =  Game(players[0],players[1],players[2],players[3],seed);
    while(!game.gameOver()){
        game.newRound();
        int current = 0;
        for(int i=0; i<4;i++){
            if(players[i]->isStarter()){
                current = i; break;
            }
        }
        std::cout<<"It's "<< players[current]->getName()<<" turn to play.\n";
        while(!game.roundOver()){
            if(players[current]->getType()=="h"){
                game.playInfo(players[current]);
            }
            while(true){
                try {
                    game.makeMove(players[current]);
                    break;
                }catch (std::invalid_argument &e) {
                    std::string error =e.what();
                    if(error=="invalid command") {
                        std::cerr << e.what() << std::endl;
                    }else if(error=="deck"){
                        game.printDeck();
                    }else if(error=="quit"){
                        game.endRound();
                        game.printWinner();
                        return 0;
                    }
                    else if(error=="ragequit"){
                        std::cout<< players[current]->getName()<< " ragequits. A computer will now take over."<<std::endl;
                        Player *temp=new Computer(players[current]->getName(),std::move(players[current]->getHand()),std::move(players[current]->getDiscards()),players[current]->getScore(),players[current]->isStarter());
                        delete players[current];
                        players[current]=game.rageQuit(temp);
                        players[current]=temp;
                        game.makeMove(players[current]);
                        break;
                    }
                }
            }
            if(current==3){
                current=0;
            }else{
                current ++;
            }
        }
        game.endRound();
    }
    game.printWinner();
}
