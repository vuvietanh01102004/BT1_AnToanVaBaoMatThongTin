#include <iostream>
#include <string>
using namespace std;

// Hàm mã hóa Caesar
string caesarEncrypt(string text, int key) {
    string result = "";

    for (char c : text) {
        if (isupper(c)) {
            result += char((c - 'A' + key) % 26 + 'A');
        } else if (islower(c)) {
            result += char((c - 'a' + key) % 26 + 'a');
        } else {
            result += c; // giữ nguyên ký tự không phải chữ cái
        }
    }

    return result;
}

int main() {
    string plaintext;
    int key;

    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, plaintext);

    cout << "Nhap khoa Caesar (1-25): ";
    cin >> key;

    string encrypted = caesarEncrypt(plaintext, key);
    cout << "Chuoi da ma hoa: " << encrypted << endl;

    return 0;
}