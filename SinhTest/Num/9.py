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

# Precompute all T-primes (squares of prime numbers)
def compute_t_primes(max_n, is_prime):
    t_primes = []
    for i in range(2, max_n + 1):
        if is_prime[i]:
            t_primes.append(i * i)
    return t_primes

# Generate the prime list for numbers up to 1e6 and precompute T-primes
max_n = 10**6
primes = sieve(max_n)
t_primes = compute_t_primes(int(10**6), primes)

# Function to generate random test cases
def generate_test_case(test_number):
    N = random.randint(1, 10**12)  # Random number between 1 and 1e12
    input_data = f"{N}\n"

    # Calculate the expected output
    count = sum(1 for tp in t_primes if tp <= N)
    output_data = f"{count}\n"

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
