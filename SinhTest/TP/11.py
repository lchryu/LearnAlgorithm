import os
import random
from tqdm import tqdm

def solve(n, k, arr):
   # Solution bám sát code C++ đã cho
   arr.sort()
   # In ra mảng đã sort như trong solution
   print("Sorted array:", *arr)
   
   for i in range(n):
       left = i + 1
       right = n - 1
       while left < right:
           current_sum = arr[i] + arr[left] + arr[right]
           if current_sum == k:
               return "YES"
           elif current_sum < k:
               left += 1
           else:
               right -= 1
   return "NO"

# Tạo thư mục input và output
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

def generate_test_case(case_num):
   if case_num < 10:  # Small test cases
       n = random.randint(3, 20)
       k = random.randint(1, 50)  # Theo constraints, K > 0
       max_val = 50
   elif case_num < 40:  # Medium test cases
       n = random.randint(20, 1000)
       k = random.randint(1, 10**6)
       max_val = 10**6
   else:  # Large test cases
       n = random.randint(1000, 10**5)
       k = random.randint(1, 10**9)
       max_val = 10**9

   # Sinh mảng với các số dương theo constraints
   arr = [random.randint(1, max_val) for _ in range(n)]
   answer = solve(n, k, arr.copy())
   
   input_data = f"{n} {k}\n" + " ".join(map(str, arr)) + "\n"
   output_data = f"{answer}\n"
   
   with open(f'input/input{case_num:02d}.txt', 'w') as f:
       f.write(input_data)
   with open(f'output/output{case_num:02d}.txt', 'w') as f:
       f.write(output_data)

def generate_special_cases():
   special_cases = [
       # Test với 3 số liên tiếp
       (3, 6, [1, 2, 3]),
       
       # Test không có 3 số nào thỏa mãn
       (5, 100, [1, 2, 3, 4, 5]),
       
       # Test với 3 số ở các vị trí khác nhau
       (6, 10, [1, 3, 2, 7, 4, 6]),
       
       # Test với các số bằng nhau
       (5, 15, [5, 5, 5, 5, 5])
   ]
   return special_cases

print("Starting test case generation...")

# Generate special cases first with progress bar
special_cases = generate_special_cases()
for i, (n, k, arr) in enumerate(tqdm(special_cases, desc="Generating special cases")):
   input_data = f"{n} {k}\n" + " ".join(map(str, arr)) + "\n"
   output_data = f"{solve(n, k, arr)}\n"
   
   with open(f'input/input{i:02d}.txt', 'w') as f:
       f.write(input_data)
   with open(f'output/output{i:02d}.txt', 'w') as f:
       f.write(output_data)

# Generate remaining random test cases with progress bar
remaining_cases = range(len(special_cases), 50)
for i in tqdm(remaining_cases, desc="Generating random cases"):
   generate_test_case(i)

print("\nTest case generation completed successfully!")