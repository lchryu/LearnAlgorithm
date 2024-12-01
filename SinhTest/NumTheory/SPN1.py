import random
import os

# Tạo các thư mục input và output nếu chưa tồn tại
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Hàm Sieve of Eratosthenes để tìm tất cả các số nguyên tố lên đến MAX_LIMIT
def sieve_of_eratosthenes(max_n):
    prime = [True] * (max_n + 1)
    p = 2
    while (p * p <= max_n):
        if prime[p]:
            for i in range(p * p, max_n + 1, p):
                prime[i] = False
        p += 1
    
    prime[0] = prime[1] = False  # 0 và 1 không phải là số nguyên tố
    
    primes = [i for i in range(max_n + 1) if prime[i]]
    return primes

# Tính toán số nguyên tố cần thiết để đáp ứng tất cả các giá trị n có thể có
MAX_PRIMES_REQUIRED = 100000000  # Giá trị tối đa của n trong các test case

# To approximate the maximum value of nth prime, we use n*log(n)
# for the 100 millionth prime, this would give us a value that is around 2 billion.
approx_limit = 2000000000

# This approximation is based on the prime number theorem.
primes = sieve_of_eratosthenes(approx_limit)  # Approximate upper limit

# Hàm sinh ngẫu nhiên test case
def generate_test_case(test_number):
    n = random.randint(1, 100000000)  # Sinh ngẫu nhiên n trong khoảng 1 đến 100000000
    input_data = str(n)
    output_data = " ".join(map(str, primes[:n]))
    
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
