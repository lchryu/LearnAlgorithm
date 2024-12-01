import random
import os

# Tạo các thư mục input và output nếu chưa tồn tại
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Sieve of Eratosthenes để tìm tất cả các số nguyên tố đến MAX
def sieve_of_eratosthenes(max_n):
    prime = [True] * (max_n + 1)
    prime[0] = prime[1] = False
    p = 2
    while p * p <= max_n:
        if prime[p]:
            for i in range(p * p, max_n + 1, p):
                prime[i] = False
        p += 1
    primes = [i for i in range(2, max_n + 1) if prime[i]]
    return primes

MAX = 10**7
primes = sieve_of_eratosthenes(MAX)

# Sinh một test case duy nhất
def generate_test_case(test_number):
    n = random.randint(2, MAX)  # Sinh ngẫu nhiên n trong khoảng 2 đến 10^7
    input_data = str(n)
    
    output_primes = " ".join(str(p) for p in primes if p < n)
    
    # Định dạng số thứ tự file với ba chữ số (ví dụ: 000, 001,... 049)
    formatted_number = f"{test_number:03}"
    
    # Ghi dữ liệu đầu vào vào file input/inputXXX.txt
    input_filename = f'input/input{formatted_number}.txt'
    with open(input_filename, 'w') as input_file:
        input_file.write(input_data + "\n")
    
    # Ghi kết quả mong đợi vào file output/outputXXX.txt
    output_filename = f'output/output{formatted_number}.txt'
    with open(output_filename, 'w') as output_file:
        output_file.write(output_primes + "\n")

# Sinh 50 test case và cập nhật trên terminal
for i in range(50):  # Bắt đầu từ 0 đến 49
    generate_test_case(i)
    os.system('cls' if os.name == 'nt' else 'clear')  # Xóa màn hình
    print(f"{i + 1}/50 test cases generated.")

print("50 test cases have been written to input/input000.txt - input/input049.txt and output/output000.txt - output/output049.txt.")
