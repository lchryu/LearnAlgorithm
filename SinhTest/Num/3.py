import random
import os
import math

# Create input and output directories if they don't exist
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Sieve of Eratosthenes function to find all primes <= max_n (1e6 in this case)
def sieve(max_n):
    is_prime = [True] * (max_n + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(math.sqrt(max_n)) + 1):
        if is_prime[i]:
            for j in range(i * i, max_n + 1, i):
                is_prime[j] = False
    return is_prime

# Generate the prime list for numbers up to 1e6
max_n = 10**6
primes = sieve(max_n)

# Function to generate random test cases
def generate_test_case(test_number):
    T = random.randint(1, 1000)  # Random number of test cases (between 1 and 1000)
    input_data = f"{T}\n"
    
    output_data = ""
    for _ in range(T):
        n = random.randint(0, max_n)  # Random number between 0 and 1e6
        input_data += f"{n}\n"
        # Get the expected output
        output_data += "YES\n" if primes[n] else "NO\n"

    # Format the test case number with three digits (e.g., 000, 001, ... 049)
    formatted_number = f"{test_number:03}"
    
    # Write input data to input/inputXXX.txt
    input_filename = f'input/input{formatted_number}.txt'
    with open(input_filename, 'w') as input_file:
        input_file.write(input_data)
    
    # Write expected output data to output/outputXXX.txt
    output_filename = f'output/output{formatted_number}.txt'
    with open(output_filename, 'w') as output_file:
        output_file.write(output_data)

# Generate 50 test cases
for i in range(50):  # Generate test cases from 0 to 49
    generate_test_case(i)

print("50 test cases have been written to input/input000.txt - input/input049.txt and output/output000.txt - output/output049.txt.")
