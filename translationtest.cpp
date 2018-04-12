#include "translationTest.h"
#include <QTranslator>
#include <QtGui>


TranslationTest:: TranslationTest(QObject *parent):QObject(parent) {
    translator1 = new QTranslator(this);
}

QString TranslationTest::getEmptyString() {
    return "";
}

void TranslationTest::selectLanguage(QString language) {
    if(language == QString("fr")) {
        translator1->load("t1_fr", ".");
        qApp->installTranslator(translator1);
    }

    emit languageChanged();
}



