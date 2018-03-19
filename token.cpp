#include <string>
#include <iostream>
#include "token.h"
using namespace std ;



Token::Token()
{
    player = 0;
    pos = 0;

}

Token::Token(int nPlayer){
    if(player == 1 || player == 2) player = nPlayer ;
    status = false ;
}
Token::Token(int nPlayer, int position){
    if(player == 1 || player == 2) player = nPlayer ;
    if(pos>=0 && pos<=8) pos = position;
    status = false ;

}
void Token::setPos(int position){
    if(position>=0 && position<=8) pos = position;
    status = false ;
}
int Token::getPlayer(){
    return player;
}
bool Token::getStatus(){
    return pos;
}
void Token::setStauts(bool s){
    status = s;
}
