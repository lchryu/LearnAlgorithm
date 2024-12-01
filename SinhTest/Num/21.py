import random
import math
import os

# Create input and output directories if they don't exist
os.makedirs("input", exist_ok=True)
os.makedirs("output", exist_ok=True)

# Function to generate a random pair (a, b) where 1 <= a <= b <= 10^12
def generate_test_case():
    a = random.randint(1, 10**12)
    b = random.randint(a, 10**12)  # Ensure b is greater than or equal to a
    return a, b

# Function to check if a number is a perfect square
def is_perfect_square(n):
    root = int(math.sqrt(n))
    return root * root == n

# Function to generate output for a given test case (a, b)
def generate_output(a, b):
    results = []
    start = math.ceil(math.sqrt(a))
    end = math.floor(math.sqrt(b))
    
    for i in range(start, end + 1):
        results.append(i * i)
    
    return results

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
    output = generate_output(a, b)
    with open(f"output/output{i:03}.txt", 'w') as outfile:
        if output:
            outfile.write(" ".join(map(str, output)) + "\n")
        else:
            outfile.write("\n")  # If no perfect squares are found

print("Generated 50 test cases.")
