#include "decrypt.h"
#include <QFile>

Decrypt::Decrypt(QObject *parent) :
    QObject(parent),
    output(stdout)
{
}

// Function decrypt text
bool Decrypt::decryptText(QString encrypted)
{
    // Count litters in encrypted text
    int textCount = encrypted.count();
    QString decrypted;

    for(int i = 0; i < textCount; i++) {
        char enc = {0};
        enc = encrypted.at(i).toLatin1();

        // Check if ascii is space not decrypt
        if(enc != 32)
            decrypted.append(enc-5);
        else
            decrypted.append(enc);

    }

    // Correct decrypted text has these same counts
    if(decrypted.count() == encrypted.count()) {
        this->output << "Zakodowany:" << encrypted << endl;
        this->output << "Odkodowany:" << decrypted << endl;
        this->output << "-------------" << endl;
        return true;
    }

    return false;
}
