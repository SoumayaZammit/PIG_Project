#ifndef MESSAGEDISPLAY_H
#define MESSAGEDISPLAY_H
#include <string>
#include <QObject>
using namespace std ;

class MessageDisplay
{
public:
    MessageDisplay(string player1, string player2, int language);
    Q_INVOKABLE QString getText(int tours_Jeu, bool issue, int language) ;
    Q_INVOKABLE QString getInstructions(int round, bool issue, int language) ;
    void actualPlayer(string player, int langage) ;
    void winner(int winner, int language) ;
    void start() ;
    void dephasage() ;
    void end() ;

private:
    QString message, instructions ;
    string player1, player2 ;
};

#endif // MESSAGEDISPLAY_H
