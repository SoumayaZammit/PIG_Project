#include "messagedisplay.h"


MessageDisplay:: MessageDisplay(string p1, string p2){
    player1 = p1;
    player2 = p2;
    actualPlayer(player1);
    start();
}
QString MessageDisplay::getText(int tours_game, bool issue){
    message.clear() ;
    if(issue == true)
    {
        winner(tours_game % 2) ;
    }
    else if (tours_game <= 5)
    {
        if (tours_game % 2 == 0) actualPlayer(player1) ;
        else actualPlayer(player2) ;
    }
    return message;
}


string MessageDisplay:: getInstructions() {
    return instructions;
}

void MessageDisplay:: actualPlayer(string player) {
    message.append(QString::fromStdString(player)) ;
    message.append(" c'est votre tour!") ;
}

void MessageDisplay:: winner(int player) {
    string winner ;
    if (player == 1)
    {
        winner = player1 ;
    }
    if (player == 2)
    {
         winner = player2 ;
    }
    message.append(QString::fromStdString(winner)) ;
    message.append(" gagne !") ;
}
void MessageDisplay:: start() {
    instructions = "Commencer par placer votre premier jeton!" ;
}

void MessageDisplay:: end() {
    instructions = "Fin de partie!" ;
}
