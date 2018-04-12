#include "Player.h"
#include <string>
#include <QString>
#include <iostream>
using namespace std ;


Player::Player(string namePlayer,string colorPlayer, bool state)
{
    name.clear();
    color.clear();
    name.append(QString::fromStdString(namePlayer));
    color.append(QString::fromStdString(colorPlayer));

    if(state)
    {
        activatePlayer() ;
    }
    else
    {
        deactivatePlayer() ;
    }
}

void Player::activatePlayer()
{
    actualPlayer  = true ;
}

void Player::deactivatePlayer()
{
    actualPlayer  = false ;
}

bool Player::getStatus()
{
    return actualPlayer ;
}

QString Player::getName() const
{
    return name ;
}

QString Player::getColor() const
{
    return color ;
}

void Player::setColor(QString playerColor)
{
    color = playerColor;
}





