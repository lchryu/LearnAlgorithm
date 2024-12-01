import random
import os

# Create input and output directories if they don't exist
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

MOD = 10**9 + 7

# Function to calculate the number of divisors of N given its prime factorization
def count_divisors(test_case):
    result = 1
    for base, exponent in test_case:
        result *= (exponent + 1)
        result %= MOD
    return result

# Function to generate random test cases
def generate_test_case(test_number):
    T = random.randint(1, 100)  # Random number of distinct primes (T)
    input_data = f"{T}\n"
    
    test_case = []
    for _ in range(T):
        p = random.randint(2, 100000)  # Random prime number
        e = random.randint(1, 100000)  # Random exponent
        test_case.append((p, e))
        input_data += f"{p} {e}\n"
    
    # Calculate the expected output
    output_data = f"{count_divisors(test_case)}\n"

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
