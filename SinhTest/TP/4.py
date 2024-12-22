import os
import random

def solve(n, s, arr):
   sum_val = 0
   left = 0
   ans = 0
   
   for right in range(n):
       sum_val += arr[right]
       while sum_val > s and left <= right:
           sum_val -= arr[left]
           left += 1
       ans = max(ans, right - left + 1)
           
   return ans

# Tạo thư mục input và output ngay từ đầu
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

def generate_test_case(case_num):
   if case_num < 10:  # Small test cases
       n = random.randint(1, 20)
       s = random.randint(1, 50)
       max_val = 10
   elif case_num < 40:  # Medium test cases
       n = random.randint(20, 1000)
       s = random.randint(50, 10**6)
       max_val = 1000
   else:  # Large test cases
       n = random.randint(1000, 10**6)
       s = random.randint(10**6, 10**9)
       max_val = 10**6

   arr = [random.randint(1, max_val) for _ in range(n)]
   answer = solve(n, s, arr)
   
   input_data = f"{n} {s}\n" + " ".join(map(str, arr)) + "\n"
   output_data = f"{answer}\n"
   
   with open(f'input/input{case_num:02d}.txt', 'w') as f:
       f.write(input_data)
   with open(f'output/output{case_num:02d}.txt', 'w') as f:
       f.write(output_data)

def generate_special_cases():
   special_cases = [
       # Minimum case
       (1, 1, [1]),  
       # Case khi tổng S lớn hơn tổng tất cả phần tử
       (5, 100, [1, 2, 3, 4, 5]),  
       # Case tất cả phần tử bằng nhau
       (5, 10, [2, 2, 2, 2, 2]),  
       # Case có thể lấy tất cả phần tử
       (5, 20, [1, 2, 3, 4, 5]),
       # Case chỉ có thể lấy 1 phần tử
       (5, 2, [2, 3, 4, 5, 6]),
       # Case có nhiều đáp án có thể
       (6, 8, [3, 1, 1, 5, 2, 3])
   ]
   return special_cases

# Generate special cases first
special_cases = generate_special_cases()
for i, (n, s, arr) in enumerate(special_cases):
   input_data = f"{n} {s}\n" + " ".join(map(str, arr)) + "\n"
   output_data = f"{solve(n, s, arr)}\n"
   
   with open(f'input/input{i:02d}.txt', 'w') as f:
       f.write(input_data)
   with open(f'output/output{i:02d}.txt', 'w') as f:
       f.write(output_data)

# Generate remaining random test cases
for i in range(len(special_cases), 50):
   generate_test_case(i)

print("Successfully generated 50 test cases!")