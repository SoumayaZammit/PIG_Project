#ifndef TRANSLATIONTEST_H
#define TRANSLATIONTEST_H
#include <QTranslator>
#include <QtGui>

class TranslationTest : public QObject
{
    Q_OBJECT

public:
    explicit TranslationTest(QObject *parent=0);

    void selectLanguage(QString language);

private:
    QTranslator *translator1;
};
#endif // TRANSLATIONTEST_H

