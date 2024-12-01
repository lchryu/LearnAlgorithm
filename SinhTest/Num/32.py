import random
import os
import math

# Create input and output directories if they don't exist
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Precompute the prime factorizations of all numbers up to max_n (for fast test case generation)
def precompute_prime_factors(max_n):
    factors = [[] for _ in range(max_n + 1)]
    for i in range(2, max_n + 1):
        if not factors[i]:  # i is prime
            for j in range(i, max_n + 1, i):
                temp = j
                while temp % i == 0:
                    factors[j].append(i)
                    temp //= i
    return factors

# Precompute prime factors for numbers up to 10^7 (adjustable)
max_n = 10**7
precomputed_factors = precompute_prime_factors(max_n)

# Function to find the k-th prime factor of n
def kth_prime_factor(n, k):
    if k <= len(precomputed_factors[n]):
        return precomputed_factors[n][k-1]
    else:
        return -1

# Function to generate random test cases
def generate_test_case(test_number):
    N = random.randint(2, max_n)  # Random number between 2 and 10^7
    K = random.randint(1, len(precomputed_factors[N])) if precomputed_factors[N] else 1  # Random k for valid prime factors
    input_data = f"{N} {K}\n"
    
    # Calculate the expected output
    output_data = f"{kth_prime_factor(N, K)}\n"

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
