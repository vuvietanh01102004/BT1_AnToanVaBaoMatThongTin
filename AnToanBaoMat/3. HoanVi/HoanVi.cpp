#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Hàm mã hóa bằng phương pháp hoán vị
string encryptPermutation(const string& input, const vector<int>& sequence) {
    int columns = sequence.size();
    int rows = (input.length() + columns - 1) / columns;
    vector<vector<char>> grid(rows, vector<char>(columns, '_')); // dùng '_' làm ký tự đệm

    int pos = 0;
    for (int i = 0; i < rows && pos < input.length(); ++i) {
        for (int j = 0; j < columns && pos < input.length(); ++j) {
            grid[i][j] = input[pos++];
        }
    }

    string output;
    for (int k = 0; k < columns; ++k) {
        int col = sequence[k] - 1;
        for (int i = 0; i < rows; ++i) {
            output += grid[i][col];
        }
    }
    return output;
}

// Hàm giải mã bằng phương pháp hoán vị
string decryptPermutation(const string& cipher, const vector<int>& sequence) {
    int columns = sequence.size();
    int rows = (cipher.length() + columns - 1) / columns;
    vector<vector<char>> grid(rows, vector<char>(columns, '_'));

    int pos = 0;
    for (int k = 0; k < columns && pos < cipher.length(); ++k) {
        int col = sequence[k] - 1;
        for (int i = 0; i < rows && pos < cipher.length(); ++i) {
            grid[i][col] = cipher[pos++];
        }
    }

    string output;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            output += grid[i][j];
        }
    }

    // Xóa ký tự đệm cuối nếu có
    while (!output.empty() && output.back() == '_') {
        output.pop_back();
    }

    return output;
}

int main() {
    string message;
    cout << "Nhap van ban: ";
    getline(cin, message);

    int length;
    cout << "Nhap so luong khoa: ";
    cin >> length;

    vector<int> key(length);
    cout << "Nhap chuoi khoa (vi du: 2 4 1 3): ";
    for (int i = 0; i < length; ++i) {
        cin >> key[i];
    }

    int mode;
    cout << "Chon thao tac (1: Ma hoa, 2: Giai ma): ";
    cin >> mode;

    if (mode == 1) {
        cout << "Van ban da ma hoa: " << encryptPermutation(message, key) << endl;
    } else if (mode == 2) {
        cout << "Van ban da giai ma: " << decryptPermutation(message, key) << endl;
    } else {
        cout << "Lua chon khong hop le." << endl;
    }

    return 0;
}