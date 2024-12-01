import os
import random
import math

# Create directories for input and output
input_dir = 'input/'
output_dir = 'output/'
os.makedirs(input_dir, exist_ok=True)
os.makedirs(output_dir, exist_ok=True)

# Function to check if a number is a perfect square
def is_square(n):
    root = int(math.sqrt(n))
    return root * root == n

# Generate test cases
num_tests = 50
test_cases = [random.randint(1, 10**18) for _ in range(num_tests)]

# Generate input and output files
for i, n in enumerate(test_cases):
    input_filename = f"{input_dir}input{i:03}.txt"
    output_filename = f"{output_dir}output{i:03}.txt"
    
    # Write the input file
    with open(input_filename, 'w') as infile:
        infile.write(f"{n}\n")
    
    # Write the output file
    result = "YES" if is_square(n) else "NO"
    with open(output_filename, 'w') as outfile:
        outfile.write(f"{result}\n")

print(f"Generated {num_tests} test cases in 'input/' and 'output/' directories.")
