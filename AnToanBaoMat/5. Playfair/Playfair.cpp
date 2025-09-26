#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

// Tạo bảng chữ cái 5x5 từ khóa
string makeMatrix(const string& rawKey) {
    string key = rawKey + "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // Gộp J vào I
    vector<bool> used(26, false);
    string matrix = "";

    for (size_t i = 0; i < key.size(); ++i) {
        char ch = toupper(key[i]);
        if (!isalpha(ch)) continue;
        if (ch == 'J') ch = 'I';
        int idx = ch - 'A';
        if (!used[idx]) {
            used[idx] = true;
            matrix += ch;
        }
    }

    return matrix.substr(0, 25);
}

// Tìm vị trí ký tự trong bảng
pair<int, int> getPos(char c, const string& matrix) {
    if (c == 'J') c = 'I';
    int index = matrix.find(c);
    return make_pair(index / 5, index % 5);
}

// Chuẩn hóa văn bản đầu vào
string preprocess(const string& text) {
    string cleaned = "";
    for (size_t i = 0; i < text.size(); ++i) {
        char ch = toupper(text[i]);
        if (isalpha(ch)) {
            if (ch == 'J') ch = 'I';
            cleaned += ch;
        }
    }

    string result = "";
    for (size_t i = 0; i < cleaned.size(); ++i) {
        result += cleaned[i];
        if (i + 1 < cleaned.size() && cleaned[i] == cleaned[i + 1]) {
            result += 'X';
        }
    }

    if (result.size() % 2 != 0) result += 'X';
    return result;
}

// Mã hóa văn bản
string encryptPlayfair(const string& text, const string& key) {
    string matrix = makeMatrix(key);
    string prepared = preprocess(text);
    string cipher = "";

    for (size_t i = 0; i + 1 < prepared.size(); i += 2) {
        char a = prepared[i];
        char b = prepared[i + 1];
        pair<int, int> pa = getPos(a, matrix);
        pair<int, int> pb = getPos(b, matrix);
        int ra = pa.first, ca = pa.second;
        int rb = pb.first, cb = pb.second;

        if (ra == rb) {
            cipher += matrix[ra * 5 + (ca + 1) % 5];
            cipher += matrix[rb * 5 + (cb + 1) % 5];
        } else if (ca == cb) {
            cipher += matrix[((ra + 1) % 5) * 5 + ca];
            cipher += matrix[((rb + 1) % 5) * 5 + cb];
        } else {
            cipher += matrix[ra * 5 + cb];
            cipher += matrix[rb * 5 + ca];
        }
    }

    return cipher;
}

// Giải mã văn bản
string decryptPlayfair(const string& cipher, const string& key) {
    string matrix = makeMatrix(key);
    string plain = "";

    for (size_t i = 0; i + 1 < cipher.size(); i += 2) {
        char a = cipher[i];
        char b = cipher[i + 1];
        pair<int, int> pa = getPos(a, matrix);
        pair<int, int> pb = getPos(b, matrix);
        int ra = pa.first, ca = pa.second;
        int rb = pb.first, cb = pb.second;

        if (ra == rb) {
            plain += matrix[ra * 5 + (ca + 4) % 5];
            plain += matrix[rb * 5 + (cb + 4) % 5];
        } else if (ca == cb) {
            plain += matrix[((ra + 4) % 5) * 5 + ca];
            plain += matrix[((rb + 4) % 5) * 5 + cb];
        } else {
            plain += matrix[ra * 5 + cb];
            plain += matrix[rb * 5 + ca];
        }
    }

    return plain;
}

int main() {
    string text, key;
    cout << "Nhap van ban: ";
    getline(cin, text);
    cout << "Nhap khoa: ";
    getline(cin, key);

    int choice;
    cout << "Chon chuc nang (1: Ma hoa, 2: Giai ma): ";
    cin >> choice;

    if (choice == 1) {
        cout << "Ban ma hoa: " << encryptPlayfair(text, key) << endl;
    } else if (choice == 2) {
        cout << "Ban giai ma: " << decryptPlayfair(text, key) << endl;
    } else {
        cout << "Lua chon khong hop le!" << endl;
    }

    return 0;
}