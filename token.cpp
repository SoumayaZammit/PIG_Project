#include <string>
#include <iostream>
#include "token.h"
using namespace std ;



Token::Token()
{
    player = 0;
    pos = 0;
    status = false;

}

Token::Token(int nPlayer){
    if(nPlayer == 1 || nPlayer == 2) player = nPlayer ;
    status = false ;
}
Token::Token(int nPlayer, int position){
    if (nPlayer == 1 || nPlayer == 2){
       player = nPlayer;
    }
    if(position>=0 && position<=8) pos = position;
    status = false ;

}
void Token::setPos(int position){
    if(position>=0 && position<=8) pos = position;
    status = false ;
}
int Token::getPosition(){
    if(pos>=0 && pos<=8) return pos;
    return 0;
}
int Token::getPlayer(){
    return player;
}
bool Token::getSelected(){
    return status;
}
void Token::setSelected(bool s){
    status = s;
}
