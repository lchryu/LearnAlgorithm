import os
import random
import math

MOD = 1000000007

# Hàm kiểm tra số nguyên tố
def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

# Hàm tính số ước của N!
def count_divisors_of_factorial(n):
    divisors = 1
    for i in range(2, n + 1):
        if is_prime(i):
            count = 0
            power = i
            while power <= n:
                count += n // power
                power *= i
            divisors *= (count + 1)
            divisors %= MOD
    return divisors

# Tạo thư mục nếu chưa có
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Sinh test case
def generate_test_case(test_number):
    # Sinh giá trị ngẫu nhiên cho n trong giới hạn cho phép
    n = random.randint(1, 100000)
    
    input_data = f"{n}\n"
    output_data = f"{count_divisors_of_factorial(n)}\n"

    # Ghi dữ liệu vào tệp
    formatted_number = f"{test_number:03}"
    
    # Tạo tệp input
    with open(f'input/input{formatted_number}.txt', 'w') as input_file:
        input_file.write(input_data)
    
    # Tạo tệp output
    with open(f'output/output{formatted_number}.txt', 'w') as output_file:
        output_file.write(output_data)

# Sinh 50 test cases
for i in range(50):
    generate_test_case(i)

print("50 test cases have been generated.")
