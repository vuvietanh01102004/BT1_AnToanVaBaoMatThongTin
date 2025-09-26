#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Hàm chuẩn hóa modulo 26
int mod26(int n) {
    return (n % 26 + 26) % 26;
}

// Tìm nghịch đảo modular của a theo modulo 26
int inverseA(int a) {
    for (int i = 1; i < 26; ++i) {
        if ((a * i) % 26 == 1) return i;
    }
    return -1;
}

// Hàm mã hóa Affine
string encryptAffine(const string& input, int a, int b) {
    string output;
    for (char ch : input) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            int x = ch - base;
            int y = mod26(a * x + b);
            output += char(y + base);
        } else {
            output += ch;
        }
    }
    return output;
}

// Hàm giải mã Affine
string decryptAffine(const string& input, int a, int b) {
    string output;
    int a_inv = inverseA(a);
    if (a_inv == -1) return "Khong the giai ma vi a khong co nghich dao modulo 26.";

    for (char ch : input) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            int y = ch - base;
            int x = mod26(a_inv * (y - b));
            output += char(x + base);
        } else {
            output += ch;
        }
    }
    return output;
}

int main() {
    string text;
    int a, b, option;

    cout << "Nhap chuoi: ";
    getline(cin, text);

    cout << "Nhap khoa a b (cach nhau boi dau cach): ";
    cin >> a >> b;

    cout << "Chon chuc nang (1: Ma hoa, 2: Giai ma): ";
    cin >> option;

    if (option == 1) {
        cout << "Ban ma hoa: " << encryptAffine(text, a, b) << endl;
    } else if (option == 2) {
        cout << "Ban giai ma: " << decryptAffine(text, a, b) << endl;
    } else {
        cout << "Lua chon khong hop le!" << endl;
    }

    return 0;
}