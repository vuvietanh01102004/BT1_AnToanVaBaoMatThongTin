#include <iostream>
#include <string>
using namespace std;

// Hàm mã hóa Vigenère
string encodeVigenere(const string& message, const string& pass) {
    string encoded;
    int keyLen = pass.length();

    for (size_t i = 0; i < message.length(); ++i) {
        char ch = message[i];
        if (isalpha(ch)) {
            bool isUpper = isupper(ch);
            char base = isUpper ? 'A' : 'a';
            int shift = tolower(pass[i % keyLen]) - 'a';
            char encryptedChar = ((ch - base + shift) % 26) + base;
            encoded += encryptedChar;
        } else {
            encoded += ch;
        }
    }

    return encoded;
}

// Hàm giải mã Vigenère
string decodeVigenere(const string& cipher, const string& pass) {
    string decoded;
    int keyLen = pass.length();

    for (size_t i = 0; i < cipher.length(); ++i) {
        char ch = cipher[i];
        if (isalpha(ch)) {
            bool isUpper = isupper(ch);
            char base = isUpper ? 'A' : 'a';
            int shift = tolower(pass[i % keyLen]) - 'a';
            char decryptedChar = ((ch - base - shift + 26) % 26) + base;
            decoded += decryptedChar;
        } else {
            decoded += ch;
        }
    }

    return decoded;
}

int main() {
    string inputText, secretKey;
    cout << "Nhap chuoi van ban: ";
    getline(cin, inputText);
    cout << "Nhap chuoi khoa: ";
    cin >> secretKey;

    int mode;
    cout << "Chon thao tac (1: Ma hoa, 2: Giai ma): ";
    cin >> mode;

    if (mode == 1) {
        string encrypted = encodeVigenere(inputText, secretKey);
        cout << "Van ban da ma hoa: " << encrypted << endl;
    } else if (mode == 2) {
        string decrypted = decodeVigenere(inputText, secretKey);
        cout << "Van ban da giai ma: " << decrypted << endl;
    } else {
        cout << "Lua chon khong hop le. Vui long chon 1 hoac 2." << endl;
    }

    return 0;
}