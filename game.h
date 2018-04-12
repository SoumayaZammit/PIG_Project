#ifndef GAME_H
#define GAME_H
#include <string>
#include <iostream>
#include <QObject>
#include "player.h"
#include "token.h"
#include "messagedisplay.h"
#include "translationtest.h"


using namespace std;

class Game: public QObject //Permet l'intéraction avec l'interface graphique
{
public:
    Q_OBJECT
public:
    explicit Game(string nom_Joueur1, string nom_Joueur2, QObject *parent = 0) ;
    Q_INVOKABLE void play(int slot) ;
    void placementStage(int slot) ; //gère la parti quand les 6 jetons ne sont pas encore mis sur la grille
    void moveStage(int slot) ; //gère la phase de déplacement des jétons
    Q_INVOKABLE void setPlayerColor(int player, QString color) ;
    Q_INVOKABLE QList<QString> readPos() const; //liste des positions utilisées
    Q_PROPERTY(QList<QString> gameQML READ readPos NOTIFY changePos); //avec les mains : a chaque fois qu'on appelera depuis une fonction la signal "gameChanged", on appelera la fonction "readPos" (qui rend une Qliste actualisé des positions des jetons) et cette liste sera utilisé par l'interface sous le nom "gameQML"
    Q_INVOKABLE int getTour();
    Q_PROPERTY(QString currentText READ currentText NOTIFY changeText) ;
    Q_PROPERTY(QString currentInstructions READ currentInstructions NOTIFY changeInstruction) ;
    void setVictory();
    bool isVictory(int *pPos) ;
    bool isMoveAllowed(int currentPosition, int newPosition);
    Q_INVOKABLE QString currentText() ;
    Q_INVOKABLE QString currentInstructions() ;
    Q_INVOKABLE void language(int l);
signals: //signal qui sert à communiquer avec le jeu
    void changePos() ; //changer position
    void changeText() ;
    void changeInstruction() ;
public slots:
private:
    Player player1, player2 ;
    Token *tokenList ;
    MessageDisplay message; //objects avec les texts, joueurs et la liste dynamiques des jetons
    bool victory ;
    int roundCount; //compteur des coups déjà faits, afin de savoir dans quelle partie du jeu on est
    TranslationTest* myObj;
};

#endif // GAME_H


