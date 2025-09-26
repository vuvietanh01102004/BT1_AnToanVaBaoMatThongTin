# Bài tập 1:
## TÌM HIỂU CÁC PHƯƠNG PHÁP MÃ HOÁ CỔ ĐIỂN
1. Caesar
2. Affine
3. Hoán vị
4. Vigenère
5. Playfair
### Với mỗi phương pháp, hãy tìm hiểu:
1. Tên gọi
2. Thuật toán mã hoá, thuật toán giải mã
3. Không gian khóa
4. Cách phá mã (mà không cần khoá)
5. Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript

# Bài làm
## Các phương pháp mã hoá cổ điển:
## 1. Caesar
## Tên gọi
  + Tiếng Việt: Mã hoá Caesar (hoặc Hệ mã Caesar)
  + Tiếng Anh: Caesar Cipher hoặc Shift Cipher (mã dịch chuyển)
## Thuật toán mã hoá, thuật toán giải mã
### Thuật toán mã hoá (Encryption Algorithm):
- Input: Bản rõ 𝑃, khóa 𝑘.
- Output: Bản mã 𝐶.
- Các bước:
  + Bước 1: Với từng ký tự 𝑝𝑖 trong bản rõ:
    Chuyển sang số: 𝑝𝑖∈[0,25]
    Áp dụng công thức: ci​=(pi​+k)mod26
    Chuyển 𝑐𝑖 thành ký tự trong bảng chữ cái.
  + Bước 2: Ghép các ký tự 𝑐𝑖 → bản mã 𝐶.
### Thuật toán giải mã (Decryption Algorithm):
- Input: Bản mã 𝐶, khóa 𝑘.
- Output: Bản rõ 𝑃.
- Các bước:
  + Bước 1: Với từng ký tự 𝑐𝑖 trong bản mã:
    Chuyển sang số: 𝑐𝑖∈[0,25]
    Áp dụng công thức: pi​=(ci​−k)mod26
    Chuyển 𝑝𝑖 thành ký tự trong bảng chữ cái.
  + Bước 2: Ghép các ký tự 𝑝𝑖 → bản rõ 𝑃.
## Không gian khoá
- Thường là bảng chữ cái Latin gồm 26 ký tự (A–Z).
- Khóa Caesar: Là số nguyên từ 1 đến 25 (dịch chuyển ký tự theo số này).
- Không gian khóa: Có 25 khóa hợp lệ.
## Cách phá mã (mà không cần khoá)
- Brute-force (thử tất cả khóa): phương pháp đơn giản nhất là thử tuần tự tất cả 25 giá trị khóa khả dĩ của Caesar, giải mã ciphertext với từng khóa rồi đọc kết quả. Vì không gian khóa rất nhỏ, người tấn công thường chỉ mất vài giây để tìm ra bản rõ có nghĩa.
- Phân tích tần suất chữ cái (frequency analysis): dựa vào đặc trưng phân bố chữ cái của ngôn ngữ (ví dụ E, T, A thường xuất hiện nhiều trong tiếng Anh). Ta đếm tần suất từng ký tự trong bản mã, suy ra ký tự phổ biến nhất tương ứng với ký tự phổ biến trong ngôn ngữ, từ đó xác định khóa ứng viên và giải mã.
- Điểm hóa thống kê (chi-square / scoring theo phân bố ngôn ngữ): với mỗi khóa ứng viên, giải mã và tính điểm phù hợp giữa phân bố chữ cái của kết quả và phân bố chuẩn của ngôn ngữ (ví dụ dùng chi-square hoặc log-likelihood). Khóa cho điểm tốt nhất thường cho bản rõ chính xác — cách này tự động và hiệu quả với văn bản trung-dài.
- Dùng digraph/trigraph (phân tích cặp/ba chữ cái): thay vì nhìn từng chữ cái đơn lẻ, ta đối chiếu tần suất cặp chữ cái (digram) và ba chữ cái (trigram) thông thường (ví dụ TH, HE, THE) trong kết quả giải mã theo từng khóa. Phương pháp này tăng độ chính xác khi phân tích tần suất đơn giản có thể bị nhiễu.
- Dùng công cụ/tập thư viện tự động (automatic toolkits): tận dụng các công cụ và thư viện có sẵn (script, website hoặc phần mềm giải mã) thực hiện brute-force, scoring, và kiểm tra từ điển tự động. Đây là cách nhanh nhất khi không muốn làm thủ công và cần xử lý nhiều ciphertext.
## Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
### Giải mã bằng code C++
``` cpp
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
```

**Kết quả**
- MÃ HOÁ
<img width="962" height="433" alt="image" src="https://github.com/user-attachments/assets/9bbc0257-c0ed-4427-bfee-a0aa4ed5aaab" />

- GIẢI MÃ
<img width="876" height="433" alt="image" src="https://github.com/user-attachments/assets/1e561dc4-092f-4510-b8f1-0ff27dd56fe7" />

### Giải mã bằng html+css+javascript
- MÃ HOÁ
<img width="929" height="750" alt="image" src="https://github.com/user-attachments/assets/24161ede-b26a-49fa-a3cb-850b9876635c" />

- GIẢI MÃ
<img width="960" height="730" alt="image" src="https://github.com/user-attachments/assets/b3e5c5c0-23a2-42e2-af25-8e25a634d674" />

## 2. Affine
## Tên gọi: 
Tên gọi đầy đủ của phương pháp mã hóa affine là "Affine Cipher" hay trong tiếng Việt thường gọi là "Phương pháp mã hóa tuyến tính" hoặc "Mã hóa Affine".
## Thuật toán mã hoá, thuật toán giải mã
### Thuật toán mã hoá
- Công thức mã hoá: E(x) = (a \cdot x + b) \mod m
- Trong đó:
  + x: vị trí của ký tự trong bảng chữ cái (A = 0, B = 1, ..., Z = 25)
  + a: hệ số nhân (phải nguyên tố cùng với m)
  + b: hệ số dịch chuyển
  + m: số lượng ký tự trong bảng chữ cái (thường là 26)
### Thuật toán giải mã
- Công thức giải mã: D(y) = a^{-1} \cdot (y - b) \mod m
- Trong đó:
  + y: vị trí của ký tự đã mã hóa
  + a^{-1}: số sao cho a \cdot a^{-1} \equiv 1 \mod m
  + b: hệ số dịch chuyển như ở bước mã hóa
## Không gian khoá
- a phải thỏa mãn: gcd(a, m) = 1
  + Với m = 26, các giá trị a hợp lệ là: a \in \{1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25\} -> Có 12 giá trị thỏa mãn điều kiện.
- b \in \{0, 1, 2, ..., 25\} -> Có 26 giá trị có thể chọn.

==> Tổng số khóa hợp lệ: \text{Không gian khóa} = 12 \times 26 = 312 \text{ cặp khóa } (a, b)
## Cách phá mã (mà không cần khoá)
- Thử tất cả các cặp khóa (Brute-force): Có 312 cặp khóa hợp lệ (a, b) với a nguyên tố cùng 26, thử từng cặp để giải mã và chọn văn bản rõ nghĩa nhất.
- Phân tích tần suất: Dựa vào tần suất xuất hiện của các chữ cái (ví dụ: E, A, T phổ biến trong tiếng Anh), ước lượng vị trí ban đầu của ký tự rồi suy ra a và b, Dùng công thức giải mã để khôi phục văn bản.
## Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
### Giải mã bằng code C++
``` cpp
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
```

**Kết quả**
- MÃ HOÁ
<img width="773" height="337" alt="image" src="https://github.com/user-attachments/assets/964bcc48-a3ce-42da-8948-8eced68a3341" />

- GIẢI MÃ
<img width="773" height="352" alt="image" src="https://github.com/user-attachments/assets/34e2f52f-d152-4fdc-afa8-01c56ad6232f" />

### Giải mã bằng html+css+javascript
- MÃ HOÁ
<img width="886" height="781" alt="image" src="https://github.com/user-attachments/assets/ad661087-052f-441f-9949-081e59807ff4" />

- GIẢI MÃ
<img width="850" height="780" alt="image" src="https://github.com/user-attachments/assets/940b8f47-093a-4e57-9ebe-62f00ce35b7d" />

## 3. Hoán vị
## Tên gọi: 
- "Transposition Cipher" — hay trong tiếng Việt thường gọi là "Mã hóa hoán vị" hoặc "Phương pháp hoán vị ký tự".
- Một ví dụ phổ biến là Rail Fence Cipher hoặc Columnar Transposition Cipher.
## Thuật toán mã hoá, thuật toán giải mã
### Thuật toán mã hoá
- Chọn kích thước khối k và một hoán vị perm = [p0,p1,...,p(k-1)] (mỗi pi ∈ {0..k-1} duy nhất).
- Chia bản rõ thành khối độ dài k (pad ký tự X nếu cần).
- Mỗi khối block (length k): bản mã khối cblock[i] = block[perm[i]].
### Thuật toán giải hoá
- Cần hoán vị nghịch inv sao cho inv[perm[i]] = i. Sau đó block[i] = cblock[inv[i]].
## Không gian khoá
- Là tập hợp tất cả các hoán vị có thể của các cột trong bảng mã hóa. Mỗi hoán vị tương ứng với một khóa duy nhất.
- Giả sử dùng khóa có độ dài n (tức là chia văn bản thành n cột), thì số lượng hoán vị có thể của các cột là: \text{Không gian khóa} = n!
## Cách phá mã (mà không cần khoá)
- Phân tích cấu trúc và độ dài:
  + Đếm độ dài bản mã → giả sử độ dài là L
  + Ước lượng độ dài khóa (số cột) → thử các giá trị n sao cho n là ước của L
- Thử tất cả các hoán vị có thể (Brute-force):
  + Với mỗi độ dài khóa n, có n! hoán vị cột có thể
  + Thử từng hoán vị để giải mã bản mã
  + Kiểm tra kết quả có phải văn bản rõ nghĩa không (dùng từ điển, kiểm tra ngữ pháp…)
- Phân tích ngữ nghĩa và từ vựng:
  + Tần suất từ: kiểm tra xem kết quả có chứa từ phổ biến như “the”, “and”, “là”, “của”…
  + Kiểm tra ngữ pháp: nếu văn bản có cấu trúc câu hợp lý → có thể là bản gốc
  + Dùng từ điển tiếng Việt hoặc tiếng Anh để kiểm tra từ hợp lệ
  + Dùng AI hoặc thuật toán thống kê để đánh giá độ “tự nhiên” của văn bản
## Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
### Giải mã bằng code C++
``` cpp
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
```

**Kết quả**
- MÃ HOÁ
<img width="751" height="361" alt="image" src="https://github.com/user-attachments/assets/87e66b0c-0923-4250-9eb8-b5d5e595710e" />

- GIẢI MÃ
<img width="730" height="372" alt="image" src="https://github.com/user-attachments/assets/92ddd775-1a38-44f5-acaf-1119f651d880" />

### Giải mã bằng html+css+javascript
- MÃ HOÁ
<img width="866" height="699" alt="image" src="https://github.com/user-attachments/assets/ac85840a-86c0-4618-bdaf-017533a8a5a1" />

- GIẢI MÃ
<img width="849" height="695" alt="image" src="https://github.com/user-attachments/assets/1dcd905b-77ec-4342-b37c-5a1869bc87cb" />

## 4. Vigenère
## Tên gọi:
- Tên gọi đầy đủ của phương pháp mã hóa này là "Vigenère Cipher", trong tiếng Việt thường gọi là "Mã hóa Vigenère" hoặc "Phương pháp mã hóa đa bảng chữ cái".
## Thuật toán mã hoá, thuật toán giải mã
### Thuật toán mã hoá
- Chuẩn hóa văn bản và khóa:
  + Chỉ dùng chữ cái (A–Z hoặc a–z)
  + Nếu khóa ngắn hơn văn bản, lặp lại khóa cho đến khi đủ độ dài
- Mã hóa từng ký tự:
 + Với mỗi ký tự P_i trong văn bản và K_i trong khóa: C_i = (P_i + K_i) \mod 26
 + Trong đó:
   + P_i: vị trí của ký tự trong bảng chữ cái (A = 0, B = 1, ..., Z = 25)
   + K_i: vị trí của ký tự khóa tương ứng
   + C_i: vị trí của ký tự mã hóa
- Ghép các ký tự mã hóa lại thành bản mã
### Thuật toán giải hoá
- Chuẩn hóa bản mã và khóa như bước mã hóa
- Giải mã từng ký tự:
  + Với mỗi ký tự C_i trong bản mã và K_i trong khóa: P_i = (C_i - K_i + 26) \mod 26
  + Trong đó:
    + C_i: vị trí của ký tự mã hóa
    + K_i: vị trí của ký tự khóa
    + P_i: vị trí của ký tự gốc
- Ghép các ký tự lại để khôi phục văn bản gốc
## Không gian khoá
- Khóa là một chuỗi ký tự (chỉ cần độ dài ≥ 1).
- Nếu bảng chữ cái có 26 ký tự, thì số lượng khóa = 26^m (m = độ dài khóa).
## Cách phá mã (mà không cần khoá)
### Ước lượng độ dài khóa (Key Length Estimation)
- Phương pháp Kasiski Examination:
  + Tìm các chuỗi lặp lại trong bản mã (ví dụ: “ABC” xuất hiện nhiều lần)
  + Ghi lại khoảng cách giữa các lần xuất hiện
  + Tìm ước số chung lớn nhất của các khoảng cách → có thể là độ dài khóa
- Phương pháp Friedman Test:
  + Dựa trên chỉ số trùng khớp (Index of Coincidence) để ước lượng độ dài khóa
  + Văn bản mã hóa bằng Vigenère có chỉ số trùng khớp thấp hơn văn bản tiếng Việt/Anh bình thường
### Tách bản mã thành các nhóm theo độ dài khóa
- Tách bản mã thành n nhóm ký tự, mỗi nhóm gồm các ký tự được mã hóa bằng cùng một ký tự khóa
- Ví dụ: nếu bản mã là FMCXY... và khóa dài 3 → nhóm 1 gồm ký tự ở vị trí 0, 3, 6,...; nhóm 2 gồm vị trí 1, 4, 7,...
### Phân tích tần suất từng nhóm (Frequency Analysis)
### Giải mã bằng khóa đã suy ra
## Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
### Giải mã bằng code C++
``` cpp
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
```

**Kết quả**
- MÃ HOÁ
<img width="772" height="347" alt="image" src="https://github.com/user-attachments/assets/1e143ffb-5d66-439c-a6c9-f991ccf83478" />

- GIẢI MÃ
<img width="759" height="364" alt="image" src="https://github.com/user-attachments/assets/ca72b7d7-30a4-4631-8bfd-3382f918d9f7" />

### Giải mã bằng html+css+javascript
- MÃ HOÁ
<img width="887" height="723" alt="image" src="https://github.com/user-attachments/assets/8a68f944-0e20-4715-bc31-271576e3d7db" />

- GIẢI MÃ
<img width="860" height="700" alt="image" src="https://github.com/user-attachments/assets/a5fdad9f-8659-4c08-a8b0-5536480d59da" />

## 5. Playfair
## Tên gọi:
- Được gọi là "Mã hóa Playfair" hoặc "Phương pháp mã hóa cặp chữ cái Playfair".
- Đây là một phương pháp mã hóa cổ điển được phát minh bởi Charles Wheatstone vào năm 1854, nhưng được đặt tên theo Lord Playfair, người đã phổ biến nó.
## Thuật toán mã hoá, thuật toán giải mã
### Thuật toán mã hoá
- Tạo bảng chữ cái 5×5 từ khóa:
  + Loại bỏ ký tự trùng lặp trong khóa
  + Ghép phần còn lại của bảng chữ cái (thường gộp I và J lại)
- Chuẩn hóa văn bản gốc:
  + Loại bỏ ký tự không phải chữ cái
  + Gộp I và J lại (nếu cần)
  + Chia thành các cặp ký tự (digraph)
  + Nếu hai ký tự trong cặp giống nhau → chèn X vào giữa
  + Nếu văn bản có số ký tự lẻ → thêm X cuối
- Mã hóa từng cặp ký tự theo quy tắc:
  + Cùng hàng: thay mỗi ký tự bằng ký tự bên phải (vòng tròn nếu ở cuối hàng)
  + Cùng cột: thay mỗi ký tự bằng ký tự bên dưới (vòng tròn nếu ở cuối cột)
  + Khác hàng, khác cột: thay mỗi ký tự bằng ký tự nằm ở giao điểm hàng của nó và cột của ký tự kia
### Thuật toán giải hoá
- Sử dụng cùng bảng chữ cái như khi mã hóa
- Chia bản mã thành các cặp ký tự
- Giải mã từng cặp theo quy tắc ngược:
  + Cùng hàng: thay mỗi ký tự bằng ký tự bên trái
  + Cùng cột: thay mỗi ký tự bằng ký tự bên trên
  + Khác hàng, khác cột: thay mỗi ký tự bằng ký tự nằm ở giao điểm hàng của nó và cột của ký tự kia
- Ghép các cặp lại thành văn bản gốc
- Loại bỏ ký tự X chèn thêm nếu cần (nếu không phải ký tự gốc)
## Không gian khoá
Playfair Cipher sử dụng bảng chữ cái 5×5 gồm 25 ký tự (thường gộp I và J lại). Mỗi khóa là một hoán vị của 25 ký tự này -> Số lượng bảng khác nhau = số hoán vị của 25 ký tự: \text{Không gian khóa} = 25! = 15,511,210,043,330,985,984,000,000
## Cách phá mã (mà không cần khoá)
- Phân tích tần suất digraph (cặp ký tự):
  + Đếm tần suất các cặp ký tự trong bản mã
  + So sánh với bảng tần suất digraph phổ biến
  + Suy đoán các cặp ký tự gốc → từ đó suy ra vị trí trong bảng Playfair → khôi phục bảng
- Suy luận bảng chữ cái 5×5
  + Tìm ra bảng chữ cái đã dùng để mã hóa
  + Vì bảng là hoán vị của 25 chữ cái (gộp I/J), có thể thử các bảng khả thi
- Thử và kiểm tra ngữ nghĩa
  + Giải mã bản mã bằng bảng đó
  + Kiểm tra xem văn bản có hợp lý không (có từ đúng, ngữ pháp đúng)
  + Nếu chưa đúng → tinh chỉnh bảng → lặp lại
- Kỹ thuật nâng cao (nếu có máy tính):
  + Genetic Algorithm: dùng thuật toán tiến hóa để tìm bảng tối ưu
  + Hill Climbing / Simulated Annealing: tối ưu bảng dựa trên điểm số ngữ nghĩa
  + Bigram scoring: đánh giá chất lượng giải mã dựa trên tần suất cặp chữ
## Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
### Giải mã bằng code C++
``` cpp
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
```

**Kết quả**
- MÃ HOÁ
<img width="740" height="342" alt="image" src="https://github.com/user-attachments/assets/2feb1c00-b690-45fd-8625-df7ab5e6f617" />

- GIẢI MÃ
<img width="824" height="398" alt="image" src="https://github.com/user-attachments/assets/e896cdcd-ac33-4b0d-be3e-fd06e262ab4e" />

### Giải mã bằng html+css+javascript
- MÃ HOÁ
<img width="1021" height="715" alt="image" src="https://github.com/user-attachments/assets/109d17c8-8a1f-4344-91f4-a195de88b5fe" />

- GIẢI MÃ
<img width="994" height="705" alt="image" src="https://github.com/user-attachments/assets/f6692212-c74f-4a32-be6a-e14e1ae8d3ae" />























  

