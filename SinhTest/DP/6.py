import os
import random

MOD = 10**9 + 7

# Function to compute the number of ways the frog can jump to the top
def frog_jumps(n):
    dp = [0] * (n + 1)
    dp[0] = 1  # Base case: 1 way to stay at the start
    
    for i in range(1, n + 1):
        for j in range(1, min(i, 3) + 1):  # The frog can jump 1, 2, or 3 steps
            dp[i] = (dp[i] + dp[i - j]) % MOD
    
    return dp[n]

# Function to generate a single test case
def generate_test_case(test_number):
    n = random.randint(1, 40)  # Random N value within the given constraints

    # Write the input to a file
    formatted_number = f"{test_number:03}"
    input_file_path = f'input/input{formatted_number}.txt'
    output_file_path = f'output/output{formatted_number}.txt'
    
    with open(input_file_path, 'w') as input_file:
        input_file.write(f"{n}\n")
    
    # Compute the result using dynamic programming
    result = frog_jumps(n)
    
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
