#include "translationTest.h"
#include <QTranslator>
#include <QtGui>
#include <iostream>
using namespace std;


TranslationTest:: TranslationTest(QObject *parent):QObject(parent) {
    translator1 = new QTranslator(this);
}

void TranslationTest::selectLanguage(QString language) {
    if(language == QString("Français")) {
        cout<< language.toStdString() << endl;
        translator1->load("t1_fr", ".");
        qApp->installTranslator(translator1);
        cout<< "translator installed" << endl;
    }else{
        qApp->removeTranslator(translator1);
    }
}



