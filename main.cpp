#include <QCoreApplication>
#include "encrypt.h"
#include "decrypt.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Encrypt enc;
    Decrypt dec;

    bool good;
    do {
        good = enc.getString();
    }while(!good);

    if(enc.encryptText()) {
        if(!dec.decryptText(enc.encrypted))
            qDebug() << "Nie można odszyfrować!";
    }
    else
        qDebug() << "Nie można zakodować!";

    return 1;
}
