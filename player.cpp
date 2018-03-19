#include "Player.h"
#include <string>
#include <iostream>
using namespace std ;


Player::Player(string namePlayer,string colorPlayer, bool etat)
{
    color = colorPlayer;
    name = namePlayer ;
    if(etat)
    {
        activatePlayer() ;
    }
    else
    {
        desactivatePlayer() ;
    }
}

void Player::activatePlayer()
{
    actualPlayer  = true ;
}

void Player::desactivatePlayer()
{
    actualPlayer  = false ;
}

bool Player::getStatus()
{
    return actualPlayer ;
}

string Player::getName()
{
    return name ;
}





