import os
import random
from tqdm import tqdm

def solve(n, k, arr):
    # Solution using Two Pointers
    arr_sorted = sorted(arr)
    l, r = 0, n-1
    while l < r:
        if arr_sorted[l] + arr_sorted[r] == k:
            return "YES"
        elif arr_sorted[l] + arr_sorted[r] < k:
            l += 1
        else:
            r -= 1
    return "NO"

# Tạo thư mục input và output
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

def generate_test_case(case_num):
    if case_num < 10:  # Small test cases
        n = random.randint(1, 20)
        k = random.randint(1, 50)
        max_val = 50
    elif case_num < 40:  # Medium test cases
        n = random.randint(20, 1000)
        k = random.randint(1, 10**6)
        max_val = 10**6
    else:  # Large test cases
        n = random.randint(1000, 5000)
        k = random.randint(1, 10**9)
        max_val = 10**9

    arr = [random.randint(1, max_val) for _ in range(n)]
    answer = solve(n, k, arr)
    
    input_data = f"{n} {k}\n" + " ".join(map(str, arr)) + "\n"
    output_data = f"{answer}\n"
    
    with open(f'input/input{case_num:02d}.txt', 'w') as f:
        f.write(input_data)
    with open(f'output/output{case_num:02d}.txt', 'w') as f:
        f.write(output_data)

def generate_special_cases():
    special_cases = [
        # Minimum case
        (2, 3, [1, 2]),  # YES
        # Case với mảng có cặp số bằng nhau
        (4, 8, [4, 2, 6, 2]),  # NO
        # Case với k nhỏ hơn tất cả các tổng có thể
        (5, 2, [5, 4, 3, 2, 1]),  # NO
        # Case với k lớn hơn tất cả các tổng có thể
        (5, 100, [1, 2, 3, 4, 5]),  # NO
        # Case với nhiều cặp số có tổng bằng k
        (6, 7, [2, 5, 3, 4, 1, 6]),  # YES
        # Case với các số giống nhau
        (5, 10, [5, 5, 5, 5, 5]),  # YES
        # Case với một cặp số ở hai đầu mảng
        (5, 11, [2, 5, 6, 7, 9])  # YES
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