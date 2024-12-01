import os
import random

# Function to compute the maximum value the thief can carry
def knapsack(n, m, weights, values):
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            dp[i][j] = dp[i - 1][j]
            if j >= weights[i - 1]:
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i - 1]] + values[i - 1])
    
    return dp[n][m]

# Function to generate a single test case
def generate_test_case(test_number):
    n = random.randint(1, 1000)  # Random N value (number of items)
    m = random.randint(1, 1000)  # Random V value (max weight of the bag)
    
    # Random weights and values for the items
    weights = [random.randint(1, 500) for _ in range(n)]
    values = [random.randint(1, 500) for _ in range(n)]
    
    # Write the input to a file
    formatted_number = f"{test_number:03}"
    input_file_path = f'input/input{formatted_number}.txt'
    output_file_path = f'output/output{formatted_number}.txt'
    
    with open(input_file_path, 'w') as input_file:
        input_file.write(f"{n} {m}\n")
        input_file.write(" ".join(map(str, weights)) + "\n")
        input_file.write(" ".join(map(str, values)) + "\n")
    
    # Compute the result using dynamic programming
    result = knapsack(n, m, weights, values)
    
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
