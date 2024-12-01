import os
import random

# Function to compute f(n)
def calculate_f(n):
    if n % 2 == 0:
        return n // 2
    else:
        return -(n // 2 + 1)

# Create directories for input and output if they don't exist
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Function to generate test cases
def generate_test_case(test_number):
    # Randomly select n in the given constraint range
    n = random.randint(1, 10**16)

    # Calculate f(n)
    input_data = f"{n}\n"
    output_data = f"{calculate_f(n)}\n"

    # Format the test case number with three digits (e.g., 001, 002, ..., 050)
    formatted_number = f"{test_number:03}"

    # Write input to file
    input_filename = f'input/input{formatted_number}.txt'
    with open(input_filename, 'w') as input_file:
        input_file.write(input_data)

    # Write output to file
    output_filename = f'output/output{formatted_number}.txt'
    with open(output_filename, 'w') as output_file:
        output_file.write(output_data)

# Generate 50 test cases
for i in range(50):
    generate_test_case(i)

print("50 test cases have been generated.")
