#ifndef GAME_H
#define GAME_H
#include <string>
#include <iostream>
#include <QObject>
#include "player.h"
#include "token.h"
using namespace std;

class Game: public QObject //Permet l'intéraction avec l'interface graphique
{
public:
    Q_OBJECT
public:
    explicit Game(string nom_Joueur1, string nom_Joueur2, QObject *parent = 0) ;
    Q_INVOKABLE void pilotage(int slot) ;
    void placementStage(int slot) ; //gère la parti quand les 6 jetons ne sont pas encore mis sur la grille
    void deplacementStag(int slot) ; //gère la phase de déplacement des jétons
    Q_INVOKABLE QList<QString> readPos() ; //liste des positions utilisées
    Q_INVOKABLE QList<QString> readBord() ;
    Q_INVOKABLE QList<bool> readVis() ;
    Q_PROPERTY(QList<QString> gameQML READ readPos NOTIFY changePos) ; //avec les mains : a chaque fois qu'on appelera depuis une fonction la signal "gameChanged", on appelera la fonction "readPos" (qui rend une Qliste actualisé des positions des jetons) et cette liste sera utilisé par l'interface sous le nom "gameQML"
    Q_PROPERTY(QList<QString> game2QML READ readBord NOTIFY changeBord) ;
    Q_PROPERTY(QList<bool> game3QML READ readVis NOTIFY changeVis) ;
    Q_INVOKABLE int getTour() ;
    Q_PROPERTY(QString currentText READ currentText NOTIFY changeTexte) ;
    void setVictory() ;
    bool isVictory(int *pPos) ;
    Q_INVOKABLE QString currentText() ;
signals:
    void changePos() ; //signal qui sert à communiquer avec le jeu
    void changeBord() ;
    void changeVis() ;
    void changeTexte() ;
public slots:
private:

    int tours_compt ; //compteur des coups déjà faits, afin de savoir dans quelle partie du jeu on est
    //zonetext message ; //objects avec les texts, joueurs et la liste dynamiques des jetons
    Player player1, player2 ;
    Token *tokenListe ;
    bool victory ;

};

#endif // GAME_H


