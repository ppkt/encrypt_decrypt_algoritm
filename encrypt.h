#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <QObject>
#include <QTextStream>
#include <QDebug>

class Encrypt : public QObject
{
    Q_OBJECT

    QString textToEncrypt;
    bool checkString(QString text);

public:
    explicit Encrypt(QObject *parent = 0);

    bool getString();
    bool encryptText();
    QString encrypted;

signals:

public slots:

};

#endif // ENCRYPT_H
