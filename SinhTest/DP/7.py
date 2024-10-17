import os
import random

# Function to compute the maximum weight of cows John can take to the movies
def max_cow_weight(m, n, weights):
    dp = [False] * (m + 1)
    dp[0] = True
    
    for i in range(n):
        for j in range(m, weights[i] - 1, -1):
            if dp[j - weights[i]]:
                dp[j] = True
    
    # Find the maximum weight John can carry
    for i in range(m, -1, -1):
        if dp[i]:
            return i
    return 0

# Function to generate a single test case
def generate_test_case(test_number):
    m = random.randint(1000, 25000)  # Random capacity C
    n = random.randint(20, 100)  # Random number of cows N
    weights = [random.randint(1, m) for _ in range(n)]  # Random weights of cows (all <= C)
    
    # Write the input to a file
    formatted_number = f"{test_number:03}"
    input_file_path = f'input/input{formatted_number}.txt'
    output_file_path = f'output/output{formatted_number}.txt'
    
    with open(input_file_path, 'w') as input_file:
        input_file.write(f"{m} {n}\n")
        input_file.write(" ".join(map(str, weights)) + "\n")
    
    # Compute the result using dynamic programming
    result = max_cow_weight(m, n, weights)
    
    # Write the result to the output file
    with open(output_file_path, 'w') as output_file:
        output_file.write(f"{result}\n")

# Generate multiple test cases
def generate_multiple_test_cases(num_cases):
    # Create directories for input and output files
    os.makedirs('input', exist_ok=True)
    os.makedirs('output', exist_ok=True)

    # Generate the specified number of test cases
    for i in range(num_cases):
        generate_test_case(i)

    print(f"{num_cases} test cases have been generated.")

# Generate 50 test cases
generate_multiple_test_cases(50)
