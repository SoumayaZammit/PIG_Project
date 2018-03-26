#include "game.h"
#include "messagedisplay.h"
#include "player.h"
#include "token.h"
#include <iostream>

using namespace std;


Game::Game(string j1, string j2, QObject *parent): QObject(parent),player1(j1,"#ffffff",true),player2(j2,"#000000",false),message(j1,j2)
{
    roundCount = 0 ;
    tokenListe = new Token[6] ;
    victory = false ;
}


void Game::pilotage(int slot){
    bool existsalready = false;
    if(victory == false)
    {
        if (roundCount < 6)
        {
            for(int i = 0 ; i < roundCount ; i++)
            {
                if(slot == tokenListe[i].getPosition()) existsalready = true ;
            }
            if (existsalready == false)
            {
                placementStage(slot) ;
                tours_compt++ ;
            }
        }
        else
        {
            Game::deplacementStage(slot) ;
        }
        setVictory() ;
        changePos() ;
        changeBord() ;
        changeVis() ;
        changeTexte() ;
    }
}

void Game::placementStage(int slot) {  //gère la partie quand les 6 jetons ne sont pas encore mis sur la grille

     tokenListe[roundCount] = Token(roundCount % 2, slot) ;

}
void Game::deplacementStage(int slot) {//gère la phase de déplacement des jétons

    bool existsalready = false;
    bool occupiedalready = false ; //teste si la case est occupée ou pas

    for(int i = 0 ; i < 6 ; i++)
    {
       if(slot == tokenListe[i].getPosition() && roundCount % 2 == i % 2)
       {
           existsalready = true ;
           for(int j = 0 ; j < 6 ; j++)
           {
               if(tokenListe[j].getSelected() == true)
               {
                   tokenListe[j].setSelected(false) ;
               }
           }
           tokenListe[i].setSelected(true) ;
        }
    }
    if (existsalready == false)
    {
        for(int k = 0 ; k < 6 && k < roundCount ; k++)
        {
            if(slot == tokenListe[k].getPosition()) occupiedalready = true ;
        }
        if(occupiedalready == false)
        {
            for(int l = 0 ; l < 6 ; l++)
            {
                if(tokenListe[l].getSelected() == true)
                {
                    tokenListe[l].setPos(slot);
                    roundCount++ ;
                }
            }
        }
    }

}


QList<QString> Game::readPos() {  //liste des positions utilisées
    QList<QString> positions ;
    for(int i = 0 ; i < 9 ; i++)
    {
        positions << "#ffffff" ;
    }
    for(int j = 0 ; j < 6 && j < roundCount ; j++)
    {
        if(j % 2 == 0)
        {
            positions[tokenListe[j].getPosition()] = "#ffffff" ;
        }
        else
        {
            positions[tokenListe[j].getPosition()] = "#000000" ;
        }
    }
    return positions ;

}

QList<QString> Game:: readBord() {

    QList<QString> bordure ;
    for(int i = 0 ; i < 9 ; i++)
    {
        bordure << "#ffffff" ;
    }
    for(int j = 0 ; j < 6 && j < roundCount; j++)
    {
        if(j % 2 == 0)
        {
            bordure[tokenListe[j].getPosition()] = "#000000" ;
        }
        else
        {
            bordure[tokenListe[j].getPosition()] = "#cccccc" ;
        }
    }
    return bordure ;
}



 QList<bool> Game:: readVis() {

     QList<bool> visible ;
     for(int i = 0 ; i < 9 ; i++)
     {
         visible << false ;
     }
     for(int j = 0 ; j < 6 && j < roundCount ; j++)
     {
         visible[tokenListe[j].getPosition()] = true ;
     }
     return visible ;
 }

 int Game:: getTour() {

     return roundCount;
 }


 void Game:: setVictory() {
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
                 caseJ1[i] = tokenListe[j].getPosition() ;
             }
             else
             {
                 caseJ2[i] = tokenListe[j].getPosition() ;
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
     if (pPos[0] % 3 == pPos[1] % 3 && pPos[0] % 3 == pPos[2] % 3)
     {
         victory = true ;
     }
     else if (pPos[0] / 3 == pPos[1] / 3 && pPos[0] / 3 == pPos[2] / 3)
     {
         victory = true ;
     }
     else if (pPos[0] == 2 && pPos[1] == 4 && pPos[2] == 6)
     {
         victory = true ;
     }
     else if (pPos[0] == 0 && pPos[1] == 4 && pPos[2] == 8)
     {
         victory = true ;
     }

 }


 QString Game::currentText() {
 return message.getText(roundCount, victory) ;
 }

