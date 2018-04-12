#ifndef TRANSLATIONTEST_H
#define TRANSLATIONTEST_H
#include <QTranslator>
#include <QtGui>

class TranslationTest : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString emptyString READ getEmptyString NOTIFY languageChanged)

public:
    explicit TranslationTest(QObject *parent=0);

    QString getEmptyString();
    void selectLanguage(QString language);

signals:
    void languageChanged();

private:
    QTranslator *translator1;
};
#endif // TRANSLATIONTEST_H

