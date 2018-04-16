#include "messagedisplay.h"
#include <iostream>

MessageDisplay:: MessageDisplay(string p1, string p2, int language){
    player1 = p1;
    player2 = p2;
    std::cout << player1 << player2 << std::endl;
    actualPlayer(player1, language);
    start();
}
QString MessageDisplay::getText(int roundCount, bool issue, int language){
    message.clear() ;
    if(issue == true)
    {
        winner(roundCount % 2, language) ;
    }
    else
    {
        if (roundCount % 2 == 0) actualPlayer(player1, language) ;
        else actualPlayer(player2, language) ;
    }
    return message;
}


QString MessageDisplay:: getInstructions(int roundCount, bool issue, int language) {
    cout << "getInstructions language: " << language << endl;
    instructions.clear();
    if(!language){
        if(issue == true){
            instructions.append(QString::fromStdString("Game Over!"));
        }else if(roundCount >= 0 && roundCount <= 5){
            instructions.append(QString::fromStdString("Place your token"));
        }else{
            instructions.append(QString::fromStdString("Move your token by clicking on it \nthen by clicking on an empty slot"));
        }
    }else{
        if(issue == true){
            instructions.append(QString::fromStdString("Fin de la partie!"));
        }else if(roundCount >= 0 && roundCount <= 5){
            instructions.append(QString::fromStdString("Placer votre jeton"));
        }else{
            instructions.append(QString::fromStdString("Déplacer votre jeton en cliquant dessus \npuis en cliquant sur une case vide."));
        }
    }
    return instructions;
}

void MessageDisplay:: actualPlayer(string player, int language) {
    if(!language){
        message.append(QString::fromStdString(player)) ;
        message.append(" it's your turn!") ;
    }else{
        if(player == "Player 1"){
            message.append("Joueur 1") ;
            message.append(" à vous de jouer!") ;
        }else{
            message.append("Joueur 2") ;
            message.append(" à vous de jouer!") ;
        }
    }

}

void MessageDisplay:: winner(int player, int language) {
    string winner ;

    std::cout << "player = " << player<< std::endl;
     if(!language){
        if (player == 1)
        {
            winner = "Player 1 WINS!";
        }
        if (player == 0)
        {
            winner = "Player 2 WINS!";
        }
     }
     else{
         if (player == 1)
         {
             winner = "Joueur 1 GAGNE!";
         }
         if (player == 0)
         {
             winner = "Joueur 2 GAGNE!";
         }
     }
     message.append(QString::fromStdString(winner));
}
void MessageDisplay:: start() {
    instructions.append(QString::fromStdString("Start by placing your token!")) ;
}

void MessageDisplay:: end() {
    instructions.append(QString::fromStdString("Game over!")) ;
}
