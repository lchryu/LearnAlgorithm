import random
import math
import os

# Create directories for input and output
os.makedirs("input", exist_ok=True)
os.makedirs("output", exist_ok=True)

# Function to calculate the number of perfect squares between a and b
def count_perfect_squares(a, b):
    x = math.isqrt(a)  # integer square root of a
    y = math.isqrt(b)  # integer square root of b

    if x * x != a:
        x += 1  # If a is not a perfect square, start from the next perfect square

    return max(0, y - x + 1)  # Ensure the count is not negative

# Function to generate random test case
def generate_test_case():
    a = random.randint(1, 10**18)
    b = random.randint(a, 10**18)  # Ensure b >= a
    return a, b

# Generate 50 test cases
test_cases = []
for _ in range(50):
    a, b = generate_test_case()
    test_cases.append((a, b))

# Generate input and output files for each test case
for i, (a, b) in enumerate(test_cases):
    # Write input file
    with open(f"input/input{i:03}.txt", 'w') as infile:
        infile.write(f"{a} {b}\n")
    
    # Write output file
    result = count_perfect_squares(a, b)
    with open(f"output/output{i:03}.txt", 'w') as outfile:
        outfile.write(f"{result}\n")

print("Generated 50 test cases.")
