import os
import random
import string

# LCS function to compute the longest common subsequence between two strings
def lcs(s, t):
    n, m = len(s), len(t)
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if s[i - 1] == t[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    
    return dp[n][m]

# Function to generate a random string of a given length
def generate_random_string(length):
    letters = string.ascii_lowercase
    return ''.join(random.choice(letters) for _ in range(length))

# Function to generate a single test case and compute its LCS
def generate_test_case(test_number):
    n = random.randint(1, 1000)  # Random length for string s
    m = random.randint(1, 1000)  # Random length for string t
    
    # Generate random strings s and t
    s = generate_random_string(n)
    t = generate_random_string(m)
    
    # Write the input to a file
    formatted_number = f"{test_number:03}"
    input_file_path = f'input/input{formatted_number}.txt'
    output_file_path = f'output/output{formatted_number}.txt'
    
    with open(input_file_path, 'w') as input_file:
        input_file.write(f"{s}\n")
        input_file.write(f"{t}\n")
    
    # Compute the LCS for the generated strings
    lcs_length = lcs(s, t)
    
    # Write the LCS result to the output file
    with open(output_file_path, 'w') as output_file:
        output_file.write(f"{lcs_length}\n")

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
