#ifndef MESSAGEDISPLAY_H
#define MESSAGEDISPLAY_H
#include <string>
#include <QObject>
using namespace std ;

class MessageDisplay
{
public:
    MessageDisplay(string player1, string player2);
    Q_INVOKABLE QString getText(int tours_Jeu, bool issue) ;
    Q_INVOKABLE QString getInstructions(int round, bool issue) ;
    void actualPlayer(string player) ;
    void winner(int winner) ;
    void start() ;
    void dephasage() ;
    void end() ;

private:
    QString message, instructions ;
    string player1, player2 ;
};

#endif // MESSAGEDISPLAY_H
