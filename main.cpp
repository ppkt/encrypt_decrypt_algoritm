#include <QCoreApplication>
#include "encrypt.h"
#include "decrypt.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Encrypt enc;
    Decrypt dec;
    QTextStream cout(stdout);

    cout << "Podaj tekst do zaszyfrowania" << endl;
    bool good;
    do {
        good = enc.getString();
    }while(!good);

    if(enc.encryptText()) {
        if(!dec.decryptText(enc.getEncrypted()))
            cout << "Nie można odszyfrować!" << endl;
    }
    else
        cout << "Nie można zakodować!" << endl;

    return 1;
}
