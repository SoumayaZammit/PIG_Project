#include "messagedisplay.h"
#include <iostream>

MessageDisplay:: MessageDisplay(string p1, string p2){
    player1 = p1;
    player2 = p2;
    std::cout << player1 << player2 << std::endl;
    actualPlayer(player1);
    start();
}
QString MessageDisplay::getText(int roundCount, bool issue){
    message.clear() ;
    if(issue == true)
    {
        winner(roundCount % 2) ;
    }
    else
    {
        if (roundCount % 2 == 0) actualPlayer(player1) ;
        else actualPlayer(player2) ;
    }
    return message;
}


QString MessageDisplay:: getInstructions(int roundCount, bool issue) {
    instructions.clear();
    if(issue == true){
        instructions.append(QString::fromStdString("Game Over!"));
    }else if(roundCount > 0 && roundCount <= 5){
        instructions.append(QString::fromStdString("Place your token"));
    }else{
        instructions.append(QString::fromStdString("Move your token by clicking on it \nthen by clicking on an empty slot"));
    }
    return instructions;
}

void MessageDisplay:: actualPlayer(string player) {
    message.append(QString::fromStdString(player)) ;
    message.append(" it's your turn!") ;
}

void MessageDisplay:: winner(int player) {
    string winner ;

    std::cout << "player = " << player<< std::endl;
    if (player == 1)
    {
        winner = player1 ;
    }
    if (player == 0)
    {
         winner = player2 ;
    }
    message.append(QString::fromStdString(winner)) ;
    message.append(" WINS!") ;
}
void MessageDisplay:: start() {
    instructions.append(QString::fromStdString("Start by placing your token!")) ;
}

void MessageDisplay:: end() {
    instructions.append(QString::fromStdString("Game over!")) ;
}
