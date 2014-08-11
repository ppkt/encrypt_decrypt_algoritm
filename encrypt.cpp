#include "encrypt.h"
#include <QRegExp>

Encrypt::Encrypt(QObject *parent) :
    QObject(parent),
    output(stdout),
    input(stdin)
{
}

// Function get simple text from input
bool Encrypt::getString()
{
    textToEncrypt = input.readLine();

    // Checking input text is correct
    if(!checkString(textToEncrypt)) {
        qDebug() << "Dozwolone są tylko litery i cyfry (bez polskich znakow).";
        return false;
    }

    if(textToEncrypt.isSimpleText())
        return true;

    return false;
}

// Function check text if content may be used
// if text is valid return false
bool Encrypt::checkString(QString text)
{
    QRegExp checker("^([A-Za-z0-9 ]+)$");
    return checker.exactMatch(text);
}

// Function encrypt text
bool Encrypt::encryptText()
{
    // Count litters in your text
    int charCount = textToEncrypt.count();

    for(int i = 0; i < charCount; i++) {
        char dec = {0};
        dec = textToEncrypt.at(i).toLatin1();

        // Check if ascii is space not encrypt
        if(dec != 32)
            encrypted.append(dec+5);
        else
            encrypted.append(dec);
    }

    // Correct encrypted text has these same counts
    if(encrypted.count() == textToEncrypt.count()) {
        qDebug() << trUtf8("Twój tekst:").toStdString().c_str() << textToEncrypt;
        qDebug() << "Zakodowano:" << encrypted;
        qDebug() << "-------------";
        return true;
    }

    return false;
}
