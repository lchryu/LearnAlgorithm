import os
import random

def solve(n, k, arr):
    """Solution function to generate correct output"""
    arr.sort()
    for i in range(n):
        for j in range(i + 1, n):
            left = j + 1
            right = n - 1
            while left < right:
                sum_val = arr[i] + arr[j] + arr[left] + arr[right]
                if sum_val == k:
                    return "YES"
                elif sum_val < k:
                    left += 1
                else:
                    right -= 1
    return "NO"

# Tạo thư mục input và output
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

def generate_test_case(case_num):
    if case_num < 10:  # Small test cases
        n = random.randint(4, 20)
        max_val = 100
    elif case_num < 40:  # Medium test cases
        n = random.randint(20, 100)
        max_val = 10**6
    else:  # Large test cases
        n = random.randint(100, 1000)
        max_val = 10**9

    arr = [random.randint(1, max_val) for _ in range(n)]
    
    # 50% chance to generate a YES case
    if random.random() < 0.5 and n >= 4:
        # Pick 4 random positions and make their sum equal to k
        positions = random.sample(range(n), 4)
        k = sum(arr[pos] for pos in positions)
    else:
        # Random k for NO case
        k = random.randint(1, 10**9)
    
    answer = solve(n, k, arr)
    
    input_data = f"{n} {k}\n" + " ".join(map(str, arr)) + "\n"
    output_data = f"{answer}\n"
    
    with open(f'input/input{case_num:02d}.txt', 'w') as f:
        f.write(input_data)
    with open(f'output/output{case_num:02d}.txt', 'w') as f:
        f.write(output_data)

def generate_special_cases():
    special_cases = [
        # Minimum case (n=4)
        (4, 10, [1, 2, 3, 4]),  # YES case
        
        # All elements same
        (4, 4, [1, 1, 1, 1]),  # YES case
        (4, 5, [1, 1, 1, 1]),  # NO case
        
        # Maximum possible sum case
        (4, 4*10**9, [10**9, 10**9, 10**9, 10**9]),  # YES case
        
        # Array with some duplicates
        (5, 10, [1, 2, 2, 3, 4]),  # YES case
        
        # Sorted array
        (6, 15, [1, 2, 3, 4, 5, 6]),  # Several possible combinations
        
        # Large array with all elements > k
        (10, 5, [10, 10, 10, 10, 10, 10, 10, 10, 10, 10])  # NO case
    ]
    return special_cases

# Generate special cases first
special_cases = generate_special_cases()
for i, (n, k, arr) in enumerate(special_cases):
    input_data = f"{n} {k}\n" + " ".join(map(str, arr)) + "\n"
    output_data = f"{solve(n, k, arr)}\n"
    
    with open(f'input/input{i:02d}.txt', 'w') as f:
        f.write(input_data)
    with open(f'output/output{i:02d}.txt', 'w') as f:
        f.write(output_data)

# Generate remaining random test cases
for i in range(len(special_cases), 50):
    generate_test_case(i)

print("Successfully generated 50 test cases!")