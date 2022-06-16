
#include "deck.h"
#include "card.h"

Deck::Deck(int seed): seed{seed}{
    char suit;
    for (int j = 0; j<4; j++){
        switch(j) {
            case 0:suit = 'C'; break;
            case 1:suit = 'D'; break;
            case 2:suit = 'H'; break;
            case 3:suit = 'S'; break;
        }
        for(int s=1; s<14; s++){
            switch(s){
                case 1: //Card tmp =Card(suit, s, 'A' );
                    theDeck.emplace_back(suit, s, 'A' ); break;
                case 10:// Card tmp =Card(suit, s, 'T' );
                    theDeck.emplace_back(suit, s, 'T' ); break;
                case 11:theDeck.emplace_back(suit, s, 'J' ); break;
                case 12:theDeck.emplace_back(suit, s, 'Q' ); break;
                case 13:theDeck.emplace_back(suit, s, 'K' ); break;
                default:theDeck.emplace_back(suit, s, std::to_string(s)[0] ); break;
            }
        }
    }
}

std::string Deck::printDeck() {
    std::string deckInfo;
    for(int i=1; i<53; i++){
        if((i%13)==0){
            deckInfo+=theDeck[i-1].printCard();
            deckInfo+= "\n";
        }else{
            deckInfo+=theDeck[i-1].printCard();
            deckInfo+=" ";
        }
    }
    return deckInfo;
}

void Deck::shuffle() {
    std::shuffle(theDeck.begin(), theDeck.end(), std::default_random_engine(seed));
}

Card Deck::getCard(int pos) {
    return theDeck[pos];
}

