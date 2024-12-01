import random
import os

# Tạo các thư mục input và output nếu chưa tồn tại
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Hàm sinh test case
def generate_test_case(test_number):
    m = random.randint(2, 100)  # Số dòng của ma trận
    n = random.randint(2, 100)  # Số cột của ma trận
    k = random.randint(1, n)    # Cột cần sắp xếp (1-based index)

    matrix = [[random.randint(-10000, 10000) for _ in range(n)] for _ in range(m)]

    # Ghi dữ liệu đầu vào vào file
    formatted_number = f"{test_number:03}"
    input_filename = f'input/input{formatted_number}.txt'
    with open(input_filename, 'w') as input_file:
        input_file.write(f"{m} {n} {k}\n")
        for row in matrix:
            input_file.write(" ".join(map(str, row)) + "\n")
    
    # Sắp xếp cột thứ k theo logic của C++ code
    column = [matrix[i][k-1] for i in range(m)]  # Lấy cột thứ k
    column.sort()  # Sắp xếp cột này theo thứ tự tăng dần
    for i in range(m):
        matrix[i][k-1] = column[i]  # Gán giá trị đã sắp xếp lại cho cột

    # Ghi kết quả đầu ra vào file
    output_filename = f'output/output{formatted_number}.txt'
    with open(output_filename, 'w') as output_file:
        for row in matrix:
            output_file.write(" ".join(map(str, row)) + "\n")

# Sinh 50 test case
for i in range(50):
    generate_test_case(i)
    print(f"Generated test case {i + 1}/50.")

print("50 test cases have been written to input and output directories.")
