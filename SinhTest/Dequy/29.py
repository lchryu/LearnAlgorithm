import random
import os

# Tạo các thư mục input và output nếu chưa tồn tại
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Hàm tính f(n) dựa trên định nghĩa đệ quy có nhớ (memoization)
def f(n, memo):
    if n in memo:
        return memo[n]
    
    if n == 0:
        memo[0] = 0
    elif n == 1:
        memo[1] = 1
    elif n == 2:
        memo[2] = 2
    elif n % 3 == 0:
        memo[n] = f(2 * (n // 3), memo)
    elif n % 3 == 1:
        memo[n] = f(2 * (n // 3), memo) + f(2 * (n // 3) + 1, memo)
    elif n % 3 == 2:
        memo[n] = (f(2 * (n // 3), memo) + f(2 * (n // 3) + 1, memo) 
                   + f(2 * (n // 3) + 2, memo))
    
    return memo[n]

# Hàm sinh ngẫu nhiên test case cho bài toán
def generate_test_case(test_number):
    T = random.randint(1, 10)  # Số lượng test case ngẫu nhiên cho mỗi file
    input_data = []
    output_data = []
    memo = {}

    for _ in range(T):
        n = random.randint(0, 2 * 10**9)
        result = f(n, memo)
        input_data.append(str(n))
        output_data.append(str(result))
    
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
