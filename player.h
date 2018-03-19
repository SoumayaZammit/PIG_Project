#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std ;

class Player
{
public:
    Player(string name, string color, bool etat = false) ;
    void activatePlayer() ;
    void desactivatePlayer() ;
    bool getStatus() ;
    string getName() ;

private:
bool actualPlayer ;
string name ;
string color;
};

#endif // PLAYER_Hpublic:
