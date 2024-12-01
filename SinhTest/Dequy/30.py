import random
import os

# Tạo các thư mục input và output nếu chưa tồn tại
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Hàm tính g(n) dựa trên định nghĩa đệ quy có nhớ (memoization)
def g(n, memo):
    if n in memo:
        return memo[n]
    
    if n == 1:
        return 1
    if n == 3:
        return 3
    
    if n % 2 == 0:
        memo[n] = g(n // 2, memo)
    elif (n - 1) % 4 == 0:
        memo[n] = 2 * g(2 * (n // 4) + 1, memo) - g(n // 4, memo)
    elif (n - 3) % 4 == 0:
        memo[n] = 3 * g(2 * (n // 4) + 1, memo) - 2 * g(n // 4, memo)
    
    return memo[n]

# Hàm sinh ngẫu nhiên test case cho bài toán
def generate_test_case(test_number):
    T = random.randint(1, 10)  # Số lượng test case ngẫu nhiên cho mỗi file
    input_data = []
    output_data = []
    memo = {}

    for _ in range(T):
        n = random.randint(1, 2 * 10**9)
        result = g(n, memo)
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
