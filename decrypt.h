#ifndef DECRYPT_H
#define DECRYPT_H

#include <QObject>
#include <QDebug>
#include <QTextStream>


class Decrypt : public QObject
{
    Q_OBJECT
public:
    explicit Decrypt(QObject *parent = 0);
    bool decryptText(QString encrypted);

signals:

public slots:

private:
    QTextStream cout;
};

#endif // DECRYPT_H
