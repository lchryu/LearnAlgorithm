import random
import os
import math

# Create input and output directories if they don't exist
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Function to compute Euler's Totient function for a given number n
def euler_totient(n):
    res = n
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            while n % i == 0:
                n //= i
            res -= res // i
    if n > 1:
        res -= res // n
    return res

# Function to generate random test cases
def generate_test_case(test_number):
    N = random.randint(1, 10**7)  # Random number between 1 and 10^7
    input_data = f"{N}\n"
    
    # Calculate the expected output using Euler's Totient function
    output_data = f"{euler_totient(N)}\n"

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
