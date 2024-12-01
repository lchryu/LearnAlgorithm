import random
import math
import os

# Create directories for input and output
os.makedirs("input", exist_ok=True)
os.makedirs("output", exist_ok=True)

# Function to count divisors using the same logic as the C++ code
def count_divisors(n):
    ans = 1
    original_n = n  # Save the original value of n for final check
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            cnt = 0
            while n % i == 0:
                cnt += 1
                n //= i
            ans *= (cnt + 1)
    if n > 1:  # If there's a prime factor greater than sqrt(n)
        ans *= 2
    return ans

# Function to generate a random test case
def generate_test_case():
    return random.randint(1, 10**14)

# Generate 50 test cases
test_cases = [generate_test_case() for _ in range(50)]

# Write test cases and outputs to files
for i, n in enumerate(test_cases):
    # Write input file
    with open(f"input/input{i:03}.txt", 'w') as infile:
        infile.write(f"{n}\n")
    
    # Calculate output
    result = count_divisors(n)
    
    # Write output file
    with open(f"output/output{i:03}.txt", 'w') as outfile:
        outfile.write(f"{result}\n")

print("50 test cases generated successfully.")
