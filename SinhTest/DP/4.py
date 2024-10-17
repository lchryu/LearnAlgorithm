import os
import random

# Function to generate a single test case and compute its result using dynamic programming
def generate_test_case(test_number):
    n = random.randint(1, 1000)  # Random number of elements in array
    s = random.randint(1, 1000)  # Random target sum

    # Generate random array of size n
    a = [random.randint(1, 1000) for _ in range(n)]
    
    # Write the input to a file
    formatted_number = f"{test_number:03}"
    input_file_path = f'input/input{formatted_number}.txt'
    output_file_path = f'output/output{formatted_number}.txt'
    
    with open(input_file_path, 'w') as input_file:
        input_file.write(f"{n} {s}\n")
        input_file.write(" ".join(map(str, a)) + "\n")
    
    # Use dynamic programming to compute the result
    dp = [False] * (s + 1)
    dp[0] = True
    for i in range(n):
        for j in range(s, a[i] - 1, -1):
            if dp[j - a[i]]:
                dp[j] = True

    # The result is whether we can form the sum `s`
    result = 1 if dp[s] else 0

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
