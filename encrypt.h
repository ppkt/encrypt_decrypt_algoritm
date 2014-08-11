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
    QString getEncrypted() const { return this->encrypted; }
signals:

public slots:

private:
    QTextStream cout;
    QTextStream cin;
    QString encrypted;


};

#endif // ENCRYPT_H
