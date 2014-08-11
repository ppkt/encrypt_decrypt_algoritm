#include <QCoreApplication>
#include "encrypt.h"
#include "decrypt.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Encrypt enc;
    Decrypt dec;
    QTextStream output(stdout);

    output << "Podaj tekst do zaszyfrowania" << endl;
    bool good;
    do {
        good = enc.getString();
    }while(!good);

    if(enc.encryptText()) {
        if(!dec.decryptText(enc.getEncrypted()))
            output << "Nie można odszyfrować!" << endl;
    }
    else
        output << "Nie można zakodować!" << endl;

    return 1;
}
