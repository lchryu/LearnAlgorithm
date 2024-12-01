import random
import os

# Tạo các thư mục input và output nếu chưa tồn tại
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Hàm để tính phân tích thừa số nguyên tố
def prime_factorization(n):
    factors = []
    # Bắt đầu với 2
    while n % 2 == 0:
        factors.append(2)
        n //= 2
    # Xử lý các số lẻ
    for i in range(3, int(n**0.5) + 1, 2):
        while n % i == 0:
            factors.append(i)
            n //= i
    # Nếu n vẫn lớn hơn 2, nó là một số nguyên tố
    if n > 2:
        factors.append(n)
    return factors

# Sinh một test case duy nhất
def generate_test_case(test_number):
    n = random.randint(2, 10**12)  # Sinh ngẫu nhiên n trong khoảng 2 đến 10^12
    input_data = str(n)
    
    factors = prime_factorization(n)
    output_data = " ".join(map(str, factors))
    
    # Định dạng số thứ tự file với ba chữ số (ví dụ: 000, 001,... 049)
    formatted_number = f"{test_number:03}"
    
    # Ghi dữ liệu đầu vào vào file input/inputXXX.txt
    input_filename = f'input/input{formatted_number}.txt'
    with open(input_filename, 'w') as input_file:
        input_file.write(input_data + "\n")
    
    # Ghi kết quả mong đợi vào file output/outputXXX.txt
    output_filename = f'output/output{formatted_number}.txt'
    with open(output_filename, 'w') as output_file:
        output_file.write(output_data + "\n")

# Sinh 50 test case và cập nhật trên terminal
for i in range(50):  # Bắt đầu từ 0 đến 49
    generate_test_case(i)
    os.system('cls' if os.name == 'nt' else 'clear')  # Xóa màn hình
    print(f"{i + 1}/50 test cases generated.")

print("50 test cases have been written to input/input000.txt - input/input049.txt and output/output000.txt - output/output049.txt.")
