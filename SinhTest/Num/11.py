import random
import os
import math

# Create input and output directories if they don't exist
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Precompute the smallest prime factor for every number up to max_n (100000 in this case)
def precompute_smallest_prime(max_n):
    smallest_prime = list(range(max_n + 1))
    smallest_prime[1] = 1  # Special case for 1
    for i in range(2, int(math.sqrt(max_n)) + 1):
        if smallest_prime[i] == i:  # i is prime
            for j in range(i * i, max_n + 1, i):
                if smallest_prime[j] == j:
                    smallest_prime[j] = i
    return smallest_prime

# Function to generate random test cases
def generate_test_case(test_number, smallest_prime):
    N = random.randint(1, 100000)  # Random number between 1 and 100000
    input_data = f"{N}\n"
    
    # Compute the expected output for all numbers from 1 to N
    output_data = "\n".join(str(smallest_prime[i]) for i in range(1, N + 1)) + "\n"

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

# Precompute the smallest prime divisor for numbers up to 100000
max_n = 100000
smallest_prime = precompute_smallest_prime(max_n)

# Generate 50 test cases
for i in range(50):  # Generate test cases from 0 to 49
    generate_test_case(i, smallest_prime)

print("50 test cases have been written to input/input000.txt - input/input049.txt and output/output000.txt - output/output049.txt.")
