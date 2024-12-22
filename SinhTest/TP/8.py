import os
import random
from collections import defaultdict
from tqdm import tqdm

def solve(n, k, arr):
    mp = defaultdict(int)
    ans = 0
    left = 0
    
    for i in range(n):
        mp[arr[i]] += 1
        while len(mp) > k:
            mp[arr[left]] -= 1
            if mp[arr[left]] == 0:
                del mp[arr[left]]
            left += 1
        ans += i - left + 1
            
    return ans

# Tạo thư mục input và output
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

def generate_test_case(case_num):
    if case_num < 10:  # Small test cases
        n = random.randint(1, 20)
        k = random.randint(1, min(n, 10))
        max_val = 10
    elif case_num < 40:  # Medium test cases
        n = random.randint(20, 1000)
        k = random.randint(1, min(n, 100))
        max_val = 1000
    else:  # Large test cases
        n = random.randint(1000, 10**5)
        k = random.randint(1, min(n, 1000))
        max_val = 10**6

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
        (1, 1, [1]),
        # Case với mảng tất cả phần tử giống nhau
        (5, 1, [1, 1, 1, 1, 1]),
        # Case với K = 1
        (5, 1, [1, 2, 1, 2, 1]),
        # Case với K = N
        (5, 5, [1, 2, 3, 4, 5]),
        # Case với K = N/2
        (6, 3, [1, 2, 1, 2, 3, 3]),
        # Case với các phần tử lặp lại theo chu kỳ
        (6, 2, [1, 2, 1, 2, 1, 2]),
        # Case với nhiều phần tử giống nhau xen kẽ
        (7, 3, [1, 2, 1, 3, 1, 2, 3])
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