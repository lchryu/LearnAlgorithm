import random
import math
import os

# Tạo thư mục cho input và output
os.makedirs("input", exist_ok=True)
os.makedirs("output", exist_ok=True)

# Hàm tính tổng ước của n
def sum_of_divisors(n):
    ans = 0
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            ans += i
            if n // i != i:  # Đảm bảo không cộng trùng khi i là căn bậc hai của n
                ans += n // i
    return ans

# Hàm sinh test case ngẫu nhiên
def generate_test_case():
    n = random.randint(1, 10**12)  # Sinh số ngẫu nhiên từ 1 đến 10^12
    return n

# Sinh 50 test case
test_cases = [generate_test_case() for _ in range(50)]

# Sinh các tệp input và output cho mỗi test case
for i, n in enumerate(test_cases):
    # Ghi file input
    with open(f"input/input{i:03}.txt", 'w') as infile:
        infile.write(f"{n}\n")
    
    # Tính tổng các ước cho test case này
    result = sum_of_divisors(n)
    
    # Ghi file output
    with open(f"output/output{i:03}.txt", 'w') as outfile:
        outfile.write(f"{result}\n")

print("Đã sinh 50 test case.")
