#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <QString>
using namespace std ;

class Player
{
public:
    Player(string name, string color, bool state = false) ;
    void activatePlayer() ;
    void deactivatePlayer() ;
    bool getStatus() ;
    void setColor(QString color);
    QString getName() const;
    QString getColor() const;

private:
bool actualPlayer ;
QString name;
QString color;
};

#endif // PLAYER_Hpublic:
