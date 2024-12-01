import os
import random

# Tạo thư mục nếu chưa có
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Sinh test case
def generate_test_case(test_number):
    # Sinh giá trị ngẫu nhiên cho n trong giới hạn cho phép
    n = random.randint(0, 10**18)
    
    # Sinh output dựa trên n
    if n == 0:
        result = 1
    elif n % 4 == 1:
        result = 8
    elif n % 4 == 2:
        result = 4
    elif n % 4 == 3:
        result = 2
    else:
        result = 6
    
    input_data = f"{n}\n"
    output_data = f"{result}\n"

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
