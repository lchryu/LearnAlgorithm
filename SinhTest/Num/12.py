import random
import os
import math

# Create input and output directories if they don't exist
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Precompute prime factorizations for all numbers up to max_n (10^7 for this example)
def precompute_prime_factorizations(max_n):
    factorization = [[] for _ in range(max_n + 1)]
    for i in range(2, max_n + 1):
        if not factorization[i]:  # i is prime
            for j in range(i, max_n + 1, i):
                cnt = 0
                temp = j
                while temp % i == 0:
                    temp //= i
                    cnt += 1
                factorization[j].append(f"{i}^{cnt}")
    return factorization

# Function to generate random test cases using precomputed factorizations
def generate_test_case(test_number, max_precompute, precomputed_factors):
    N = random.randint(2, 10**7)  # Limiting N to precomputed range (2 to 10^7)
    input_data = f"{N}\n"
    
    # Retrieve the precomputed factorization
    output_data = " * ".join(precomputed_factors[N]) + "\n"

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

# Precompute the prime factorizations for numbers up to 10^7
max_precompute = 10**7
precomputed_factors = precompute_prime_factorizations(max_precompute)

# Generate 50 test cases
for i in range(50):  # Generate test cases from 0 to 49
    generate_test_case(i, max_precompute, precomputed_factors)

print("50 test cases have been written to input/input000.txt - input/input049.txt and output/output000.txt - output/output049.txt.")
