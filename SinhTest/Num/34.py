import random
import os
import math

# Create input and output directories if they don't exist
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Function to compute gcd
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

# Function to compute lcm using gcd
def lcm(a, b):
    return a * b // gcd(a, b)

# Function to calculate the smallest number with exactly n digits divisible by x, y, z
def smallest_number(x, y, z, n):
    res = lcm(x, lcm(y, z))
    tmp = 10**(n - 1)
    kq = (tmp + res - 1) // res * res
    
    if kq < 10**n:
        return kq
    else:
        return -1

# Function to generate a single test case
def generate_test_case(test_number):
    # Random values for x, y, z, and n within the problem constraints
    x = random.randint(1, 10**4)
    y = random.randint(1, 10**4)
    z = random.randint(1, 10**4)
    n = random.randint(1, 16)

    # Input string
    input_data = f"{x} {y} {z} {n}\n"
    
    # Calculate the expected output
    output_data = f"{smallest_number(x, y, z, n)}\n"

    # Format the test case number with three digits (e.g., 000, 001, ... 049)
    formatted_number = f"{test_number:03}"

    # Write input data to input/inputXXX.txt
    input_filename = f'input/input{formatted_number}.txt'
    with open(input_filename, 'w') as input_file:
        input_file.write(input_data)

    # Write output data to output/outputXXX.txt
    output_filename = f'output/output{formatted_number}.txt'
    with open(output_filename, 'w') as output_file:
        output_file.write(output_data)

# Generate 50 test cases
for i in range(50):
    generate_test_case(i)

print("50 test cases have been written to input/ and output/ directories.")
