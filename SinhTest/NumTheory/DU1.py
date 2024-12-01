import random
import os

# Tạo các thư mục input và output nếu chưa tồn tại
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Hàm để tính số ước dựa trên phân tích thừa số nguyên tố
def count_divisors(n):
    divisors_count = 1
    count = 0
    
    # Bắt đầu với 2
    while n % 2 == 0:
        n //= 2
        count += 1
    if count > 0:
        divisors_count *= (count + 1)
    
    # Xử lý các số lẻ từ 3 trở đi
    for i in range(3, int(n**0.5) + 1, 2):
        count = 0
        while n % i == 0:
            n //= i
            count += 1
        if count > 0:
            divisors_count *= (count + 1)
    
    # Nếu n vẫn lớn hơn 2 thì nó là một số nguyên tố
    if n > 2:
        divisors_count *= 2
    
    return divisors_count

# Sinh một test case duy nhất
def generate_test_case(test_number):
    n = random.randint(1, 10**12)  # Sinh ngẫu nhiên n trong khoảng 1 đến 10^12
    input_data = str(n)
    
    # Tính số ước dựa trên hàm đã viết
    divisors_count = count_divisors(n)
    output_data = str(divisors_count)
    
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
for i in range(100):  # Bắt đầu từ 0 đến 49
    generate_test_case(i)
    os.system('cls' if os.name == 'nt' else 'clear')  # Xóa màn hình
    print(f"{i + 1}/50 test cases generated.")

print("50 test cases have been written to input/input000.txt - input/input049.txt and output/output000.txt - output/output049.txt.")
