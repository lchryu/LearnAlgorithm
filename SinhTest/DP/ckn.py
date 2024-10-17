import os
import random

# Hàm tính số Stirling loại 2
def stirling_number(n, k):
    dp = [[0 for _ in range(k+1)] for _ in range(n+1)]
    dp[0][0] = 1
    
    for i in range(1, n+1):
        for j in range(1, k+1):
            dp[i][j] = dp[i-1][j-1] + j * dp[i-1][j]
    
    return dp[n][k]

# Hàm sinh test case
def generate_test_case(test_number, max_n=25, max_t=100):
    # Số lượng test case ngẫu nhiên trong khoảng 1 đến max_t
    t = random.randint(1, max_t)
    
    # Định dạng số test case với 3 chữ số
    formatted_number = f"{test_number:03}"
    
    # Tạo đường dẫn file input và output sử dụng os.path.join để tương thích hệ điều hành
    input_file_path = os.path.join('input', f'input{formatted_number}.txt')
    output_file_path = os.path.join('output', f'output{formatted_number}.txt')
    
    with open(input_file_path, 'w') as input_file, open(output_file_path, 'w') as output_file:
        # Ghi số lượng test case
        input_file.write(f"{t}\n")
        
        for _ in range(t):
            # Sinh ngẫu nhiên n và k sao cho 1 <= k <= n <= max_n
            n = random.randint(1, max_n)
            k = random.randint(1, n)
            
            # Tính số cách chia n lớp thành k nhóm
            result = stirling_number(n, k)
            
            # Ghi vào file input
            input_file.write(f"{n} {k}\n")
            
            # Ghi kết quả tương ứng vào file output
            output_file.write(f"{result}\n")

# Hàm sinh nhiều test case
def generate_multiple_test_cases(num_cases, max_t=100):
    # Tạo các thư mục nếu chưa tồn tại
    os.makedirs('input', exist_ok=True)
    os.makedirs('output', exist_ok=True)

    for i in range(1, num_cases + 1):  # Bắt đầu từ 1 để tránh input000.txt
        generate_test_case(i, max_t=max_t)
        print(f"Bộ test {i:03} đã được tạo.")

    print(f"{num_cases} bộ test đã được sinh thành công.")

# Sinh 50 bộ test, với mỗi bộ test chứa tối đa 100 test case nhỏ
if __name__ == "__main__":
    generate_multiple_test_cases(50, max_t=100)
