import random
import os

# Tạo các thư mục input và output nếu chưa tồn tại
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Hàm đệ quy có nhớ để tính số Fibonacci thứ n
def fibonacci_memo(n, memo):
    if n in memo:
        return memo[n]
    if n < 2:
        return n
    memo[n] = fibonacci_memo(n - 1, memo) + fibonacci_memo(n - 2, memo)
    return memo[n]

# Hàm sinh ngẫu nhiên test case cho bài toán
def generate_test_case(test_number):
    T = random.randint(1, 10)  # Số lượng test case ngẫu nhiên cho mỗi file
    input_data = []
    output_data = []
    memo = {}
    
    for _ in range(T):
        n = random.randint(0, 90)
        fib_n = fibonacci_memo(n, memo)
        input_data.append(str(n))
        output_data.append(str(fib_n))
    
    # Định dạng số thứ tự file với ba chữ số (ví dụ: 000, 001,... 099)
    formatted_number = f"{test_number:03}"
    
    # Ghi dữ liệu đầu vào vào file input/inputXXX.txt
    input_filename = f'input/input{formatted_number}.txt'
    with open(input_filename, 'w') as input_file:
        input_file.write(f"{T}\n" + "\n".join(input_data) + "\n")
    
    # Ghi kết quả mong đợi vào file output/outputXXX.txt
    output_filename = f'output/output{formatted_number}.txt'
    with open(output_filename, 'w') as output_file:
        output_file.write("\n".join(output_data) + "\n")

# Sinh 100 test case và cập nhật trên terminal
for i in range(100):  # Bắt đầu từ 0 đến 99
    generate_test_case(i)
    os.system('cls' if os.name == 'nt' else 'clear')  # Xóa màn hình
    print(f"{i + 1}/100 test cases generated.")

print("100 test cases have been written to input/input000.txt - input/input099.txt and output/output000.txt - output/output099.txt.")
