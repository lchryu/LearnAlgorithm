import os
import random
from tqdm import tqdm

def solve(n, k, arr):
    from sortedcontainers import SortedList
    sl = SortedList()
    ans = 0
    left = 0
    
    for right in range(n):
        sl.add(arr[right])
        while len(sl) > 0 and sl[-1] - sl[0] > k:
            sl.remove(arr[left])
            left += 1
        ans += right - left + 1
            
    return ans

# Tạo thư mục input và output
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

def generate_test_case(case_num):
    if case_num < 10:  # Small test cases
        n = random.randint(1, 20)
        k = random.randint(1, 50)
        max_val = 10
    elif case_num < 40:  # Medium test cases
        n = random.randint(20, 1000)
        k = random.randint(1, 10**3)
        max_val = 1000
    else:  # Large test cases
        n = random.randint(1000, 10**5)
        k = random.randint(1, 10**6)
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
        (5, 0, [1, 1, 1, 1, 1]),
        # Case với mảng tăng dần
        (5, 2, [1, 2, 3, 4, 5]),
        # Case với mảng giảm dần
        (5, 2, [5, 4, 3, 2, 1]),
        # Case với mảng xen kẽ
        (6, 3, [1, 4, 1, 4, 1, 4]),
        # Case với một giá trị lớn giữa các giá trị nhỏ
        (5, 8, [2, 2, 10, 2, 2]),
        # Case với mảng dạng "núi"
        (7, 1, [1, 2, 3, 4, 3, 2, 1])
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