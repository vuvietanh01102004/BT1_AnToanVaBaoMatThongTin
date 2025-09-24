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
### Tên gọi
  + Tiếng Việt: Mã hoá Caesar (hoặc Hệ mã Caesar)
  + Tiếng Anh: Caesar Cipher hoặc Shift Cipher (mã dịch chuyển)
Trong tài liệu học thuật, thường thấy các tên:
  + Caesar Cipher → phổ biến nhất.
  + Shift Cipher → nhấn mạnh đặc điểm dịch chuyển bảng chữ cái.
  + Caesar Shift hoặc Caesar Code → cách gọi khác nhưng ít dùng hơn.
### Thuật toán mã hoá, thuật toán giải mã
* Thuật toán mã hoá (Encryption Algorithm):
- Input: Bản rõ 𝑃, khóa 𝑘.
- Output: Bản mã 𝐶.
- Các bước:
  + Bước 1: Với từng ký tự 𝑝𝑖 trong bản rõ:
    Chuyển sang số: 𝑝𝑖∈[0,25]
    Áp dụng công thức: ci​=(pi​+k)mod26
    Chuyển 𝑐𝑖 thành ký tự trong bảng chữ cái.
  + Bước 2: Ghép các ký tự 𝑐𝑖 → bản mã 𝐶.
* Thuật toán giải mã (Decryption Algorithm):
- 
    




  

