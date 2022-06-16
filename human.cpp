
#include "human.h"

Human::Human(std::string name) {
    this->score=0;
    this->starter=false;
    this->name=std::move(name);
    this->type="h";
}

void validCard(std::string card){
    //checking if the argument is in the correct format of a card
    if(!(card[0]=='1' || card[0]=='2'|| card[0]=='3'|| card[0]=='4'|| card[0]=='5'|| card[0]=='6'|| card[0]=='7'
         || card[0]=='8'|| card[0]=='9'|| card[0]=='T'|| card[0]=='J'|| card[0]=='Q'|| card[0]=='K' || card[0]=='A')){
        throw std::invalid_argument("Invalid rank");
    }else if (card.size()<2) {
        throw std::invalid_argument("Failed to obtain a suit");
    }else if (!(card[1]=='H' || card[1]=='D'||card[1]=='C'||card[1]=='S')){
        throw std::invalid_argument("Invalid suit");
    }

}
void Human::makeMove(Table &x) {
    std::vector<std::string> legalCards = legalPlays(x);
std::string cmd;

    std::cin.exceptions(std::ios::eofbit | std::ios::failbit);
    while (std::cin >> cmd) {
        if (cmd == "play") {
            try {
                //checking if next argument exists
                while (std::cin.peek() == 32) {
                    std::cin.ignore(1);
                }
                if (std::cin.peek() == 10) {
                    throw std::invalid_argument("Failed to obtain a rank\nThis is not a legal play.");
                }

                std::string card;
                std::cin >> card;
                try {
                    //seeing if card is valid
                    validCard(card);
                } catch (std::invalid_argument &e) {
                    std::cerr << e.what() << std::endl;
                }
                //card is in correct form so now we are checking if it is in their legal plays
                bool found = false;
                for (auto &i: legalCards) {
                    if (i == card) { found = true; }
                }
                if (!found) {
                    throw std::invalid_argument("This is not a legal play.");
                }
                //entered card can be played so now we look for the card in the hand and use the play function
                int n = 0;
                for (auto &i : hand) {
                    if (i->printCard() == card) {
                        play(std::move(i), x);
                        hand.erase(hand.begin() + n);
                        break;
                    }
                    n++;
                }
                break;
            } catch (std::invalid_argument &e) {
                std::cerr << e.what() << std::endl;
            }
        } else if (cmd == "discard") {
            try {
                if (!legalCards.empty()) {
                    throw std::invalid_argument("You have a legal play. You may not discard.");
                }

                while (std::cin.peek() == 32) {
                    std::cin.ignore(1);
                }
                if (std::cin.peek() == 10) {
                    throw std::invalid_argument("Failed to obtain a rank\nThis is not a legal discard.");
                }
                std::string card;
                std::cin >> card;
                try {
                    //seeing if card is valid
                    validCard(card);
                } catch (std::invalid_argument &e) {
                    std::cerr << e.what() << std::endl;

                }
                //card is correct now we check if they its in their hand
                bool found = false;
                for (auto &i: hand) {
                    if (i->printCard() == card) { found = true; }
                }
                if (!found) {
                    throw std::invalid_argument("This is not a legal discard.");
                }
                int n=0;
                for (auto &i : hand) {
                    if (i->printCard() == card) {
                       discard(std::move(i));
                        hand.erase(hand.begin() + n);
                        break;
                    }
                    n++;
                }
                break;
            } catch (std::invalid_argument &e) {
                std::cerr << e.what() << std::endl;
            }
        }else if(cmd == "deck") {
            throw std::invalid_argument("deck");
        }else if(cmd == "quit") {
            throw std::invalid_argument("quit");
        }else if(cmd == "ragequit") {
            throw std::invalid_argument("ragequit");
        }else{
            throw std::invalid_argument("invalid command");
        }
    }
}

Human::~Human() = default;











