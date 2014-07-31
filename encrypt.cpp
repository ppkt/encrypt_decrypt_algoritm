#include "encrypt.h"

Encrypt::Encrypt(QObject *parent) :
    QObject(parent)
{
}

// Function get simple text from input
bool Encrypt::getString()
{
    QTextStream input(stdin);
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
    for(int i = 0; i < text.count(); i++) {
        int ascii = text.at(i).toLatin1();

        if(ascii != 32) // if asii != space
            if(!(ascii >= 65 && ascii <= 90))   // A-Z
                if(!(ascii >= 97 && ascii <= 122))  // a-z
                    if(!(ascii >= 48 && ascii <= 57))   // 0-9
                        return false;

    }
    return true;
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
        qDebug() << "Twój tekst:" << textToEncrypt;
        qDebug() << "Zakodowano:" << encrypted;
        qDebug() << "-------------";
        return true;
    }

    return false;
}
