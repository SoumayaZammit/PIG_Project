#include "game.h"
#include "messagedisplay.h"
#include "player.h"
#include "token.h"
#include "translationtest.h"
#include <iostream>
#include <QtGui>


using namespace std;

Game::Game(string j1, string j2, QObject *parent): QObject(parent),player1(j1,"#000000",true),player2(j2,"#aaaaaa",false),message(j1,j2)
{
    roundCount = 0 ;
    tokenList = new Token[6] ;
    victory = false ;
    myObj = new TranslationTest();

}


void Game::play(int slot){
    bool existsalready = false;
    if(victory == false)
    {
        if (roundCount < 6)
        {
            for(int i = 0 ; i < roundCount ; i++)
            {
                if(slot == tokenList[i].getPosition()) existsalready = true ;
            }
            if (existsalready == false)
            {
                placementStage(slot);
                roundCount++ ;
            }
        }
        else
        {
            Game::moveStage(slot) ;
        }
        setVictory() ;
        changePos() ;
        changeText() ;
        changeInstruction();
    }
}

void Game::placementStage(int slot) {  //gère la partie quand les 6 jetons ne sont pas encore mis sur la grille

     tokenList[roundCount] = Token(roundCount % 2+1, slot) ;
}
void Game::moveStage(int slot) {//gère la phase de déplacement des jetons
    std::cout << "tokenList = [";
    for(int i = 0 ; i < 6 ; i++){
        std::cout << "{position: " << tokenList[i].getPosition() << ", player: " << tokenList[i].getPlayer() << ", isSelected: " << tokenList[i].getSelected() << "},";
    }
    std::cout << "]" << std::endl;
    bool existsalready = false;
    bool occupiedalready = false ; //teste si la case est occupée ou pas
    for(int i = 0 ; i < 6 ; i++)
    {
       if(slot == tokenList[i].getPosition() && roundCount % 2 == i % 2)
       {
           existsalready = true ;
           for(int j = 0 ; j < 6 ; j++)
           {
               if(tokenList[j].getSelected() == true)
               {

                   tokenList[j].setSelected(false) ;
               }
           }
           tokenList[i].setSelected(true) ;
        }
    }
    if (existsalready == false)
    {
        for(int k = 0 ; k < 6 && k < roundCount ; k++)
        {
            if(slot == tokenList[k].getPosition()){
                occupiedalready = true ;
            }
        }
        if(occupiedalready == false)
        {
            for(int l = 0 ; l < 6 ; l++)
            {
                if((tokenList[l].getSelected() == true) && isMoveAllowed(tokenList[l].getPosition(), slot))
                {
                    tokenList[l].setPos(slot);
                    roundCount++ ;
                }
            }
        }
    }

}

bool Game::isMoveAllowed(int currentPosition, int newPosition){
    bool isAllowed = false;
    std::cout << "isAllowed= " << isAllowed << std::endl;
    std::cout << "currentPosition= " << currentPosition << ", newPosition= " << newPosition << std::endl;
    switch(currentPosition) {
        case 0 : {
            std::cout << "case" << 0 <<std::endl;
            if (newPosition == 6 || newPosition == 8 || newPosition == 7)
            {
                isAllowed = true;
            }
            break;
        }
        case 1 : {
            std::cout << "case" << 1 <<std::endl;
            if (newPosition == 2 || newPosition == 4 || newPosition == 7)
            {
                isAllowed = true;
            }
            break;
        }
        case 2 : {
            std::cout << "case" << 2 <<std::endl;
            if (newPosition == 1 || newPosition == 3 || newPosition == 7)
            {
                isAllowed = true;
            }
            break;
        }
        case 3 : {
            std::cout << "case" << 3 <<std::endl;
            if (newPosition == 2 || newPosition == 8 || newPosition == 7)
            {
                isAllowed = true;
            }
            break;
        }
        case 4 : {
            std::cout << "case" << 4 <<std::endl;
            if (newPosition == 1 || newPosition == 5 || newPosition == 7)
            {
                isAllowed = true;
            }
            break;
        }
        case 5 : {
            std::cout << "case" << 5 <<std::endl;
            if (newPosition == 4 || newPosition == 6 || newPosition == 7)
            {
                isAllowed = true;
            }
            break;
        }
        case 6 : {
            std::cout << "case" << 6 <<std::endl;
            if (newPosition == 0 || newPosition == 5 || newPosition == 7)
            {
                isAllowed = true;
            }
            break;
        }
        case 7 : {
            std::cout << "case" << 7 <<std::endl;
            if (newPosition != 7)
            {
                isAllowed = true;
            }
            break;
        }
        case 8 : {
            std::cout << "case" << 8 <<std::endl;
            if (newPosition == 0 || newPosition == 3 || newPosition == 7)
            {
                isAllowed = true;
            }
            break;
        }
    }
    std::cout << "isAllowed= " << isAllowed << std::endl;
    return isAllowed;
}

QList<QString> Game::readPos() const {  //liste des positions utilisées
    QList<QString> positions ;
    for(int i = 0 ; i < 9 ; i++)
    {
        positions << "#ffffff" ;
    }
    for(int j = 0 ; j < 6 && j < roundCount ; j++)
    {
        if(j % 2 == 0)
        {
            positions[tokenList[j].getPosition()] = player1.getColor() ;
        }
        else
        {
            positions[tokenList[j].getPosition()] = player2.getColor() ;
        }
    }
    return positions ;

}

 int Game:: getTour() {

     return roundCount;
 }


 void Game:: setVictory(){
     int i ;
     int* caseJ1 = new int[3] ;
     int* caseJ2 = new int[3] ;

     if(roundCount >= 5)
     {
         for(int j = 0 ; j < 6 && j < roundCount ; j++)
         {
             i = j / 2 ;
             if(j % 2 == 0)
             {
                 caseJ1[i] = tokenList[j].getPosition() ;
             }
             else
             {
                 caseJ2[i] = tokenList[j].getPosition() ;
             }
         }
         if (roundCount % 2 == 1) isVictory(caseJ1) ;
         else isVictory(caseJ2) ;
         delete[] caseJ1 ;
         delete[] caseJ2;
     }
 }


 bool Game::isVictory(int *pPos) { //test si l'un de deux joueurs a gagné
     int a ;
     if (pPos[0] > pPos[1])
     {
         a = pPos[0] ;
         pPos[0] = pPos[1] ;
         pPos[1] = a ;
     }
     if (pPos[1] > pPos[2])
     {
         a = pPos[2] ;
         pPos[2] = pPos[1] ;
         pPos[1] = a ;
     }
     if (pPos[0] > pPos[1])
     {
         a = pPos[0] ;
         pPos[0] = pPos[1] ;
         pPos[1] = a ;
     }

     if (pPos[0] == 0 && pPos[1] == 5 && pPos[2] == 6){
         victory = true ;
     }else if (pPos[0] == 4 && pPos[1] == 7 && pPos[2] == 8){
         victory = true ;
     }else if (pPos[0] == 1 && pPos[1] == 2 && pPos[2] == 3){
         victory = true ;
     }else if (pPos[0] == 0 && pPos[1] == 3 && pPos[2] == 8){
         victory = true ;
     }else if (pPos[0] == 2 && pPos[1] == 6 && pPos[2] == 7){
         victory = true ;
     }else if (pPos[0] == 1 && pPos[1] == 4 && pPos[2] == 5){
         victory = true ;
     }else if (pPos[0] == 0 && pPos[1] == 1 && pPos[2] == 7){
         victory = true ;
     }else if (pPos[0] == 0 && pPos[1] == 5 && pPos[2] == 6){
         victory = true ;
     }else if (pPos[0] == 0 && pPos[1] == 1 && pPos[2] == 7){
         victory = true ;
     }else if (pPos[0] == 3 && pPos[1] == 5 && pPos[2] == 7){
         victory = true ;
     }

     std::cout << "isVictory? = " << victory << std::endl;
return victory;
 }


 QString Game::currentText() {
    return message.getText(roundCount, victory) ;
 }


 QString Game::currentInstructions() {
    return message.getInstructions(roundCount, victory) ;
 }

 void Game::setPlayerColor(int player, QString color){
     std::cout << "player: " << player << ", color: " << color.toStdString() << std::endl;
     if(player == 1){
         player1.setColor(color);
     }else if(player == 2){
         player2.setColor(color);
     }


 }

 void Game::language(int l){
     cout<<l<<endl;
    if (l==0)
     myObj->selectLanguage(QString("English"));
    else
     myObj->selectLanguage(QString("Français"));
 }
