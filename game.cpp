#include "game.h"

Game::Game(string j1, string j2, QObject *parent): QObject(parent),J1(j1,true),Joueur2(j2,false),message(j1,j2)
{
    tours_compt = 0 ;
    pieceListe = new piece[6] ;
    victoire_jeu = false ;
}
