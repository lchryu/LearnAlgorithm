import random
import math
import os

# Create directories for input and output
os.makedirs("input", exist_ok=True)
os.makedirs("output", exist_ok=True)

# Function to check if a number is a perfect square
def is_perfect_square(n):
    x = int(math.sqrt(n))
    return x * x == n

# Function to generate a random test case
def generate_test_case():
    return random.randint(1, 10**18)

# Generate 50 test cases
test_cases = [generate_test_case() for _ in range(50)]

# Write test cases and outputs to files
for i, n in enumerate(test_cases):
    # Write input file
    with open(f"input/input{i:03}.txt", 'w') as infile:
        infile.write(f"{n}\n")
    
    # Calculate output
    result = "YES" if is_perfect_square(n) else "NO"
    
    # Write output file
    with open(f"output/output{i:03}.txt", 'w') as outfile:
        outfile.write(f"{result}\n")

print("50 test cases generated successfully.")
