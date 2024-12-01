import random
import os
import math

# Create input and output directories if they don't exist
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Function to generate a single test case
def generate_test_case(test_number):
    # Generate moderate values for a and b within reasonable limits
    a = random.randint(1, 10**6)  # Limit to 10^6 to avoid huge numbers
    b = random.randint(1, 10**6)  # Same limit for b

    # Input string
    input_data = f"{a} {b}\n"

    # Calculate the expected output using Python's built-in gcd and lcm
    gcd_value = math.gcd(a, b)
    lcm_value = (a * b) // gcd_value
    output_data = f"{gcd_value} {lcm_value}\n"

    # Format the test case number with three digits (e.g., 000, 001, ...)
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
