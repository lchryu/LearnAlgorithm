import random
import math
import os

# Create directories for input and output
os.makedirs("input", exist_ok=True)
os.makedirs("output", exist_ok=True)

# Function to check if a number is prime
def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

# Function to check if a number is palindromic
def is_palindromic(n):
    return str(n) == str(n)[::-1]

# Function to count distinct prime divisors of a number
def count_prime_divisors(n):
    divisors = set()
    for i in range(2, int(math.sqrt(n)) + 1):
        while n % i == 0:
            divisors.add(i)
            n //= i
    if n > 1:
        divisors.add(n)
    return len(divisors)

# Function to check if a number is "beautiful"
def is_beautiful(n):
    if is_palindromic(n) and count_prime_divisors(n) >= 3:
        return True
    return False

# Function to generate test cases
def generate_test_case():
    a = random.randint(1, 10**7)
    b = random.randint(a, 10**7)  # Ensure b >= a
    return a, b

# Function to generate the output based on the problem requirements
def generate_output(a, b):
    beautiful_numbers = []
    for i in range(a, b + 1):
        if is_beautiful(i):
            beautiful_numbers.append(i)
    return beautiful_numbers if beautiful_numbers else [-1]

# Generate 50 test cases
for i in range(50):
    # Generate input values
    a, b = generate_test_case()

    # Write input to file
    with open(f"input/input{i:03}.txt", 'w') as infile:
        infile.write(f"{a} {b}\n")

    # Generate output for this test case
    result = generate_output(a, b)

    # Write output to file
    with open(f"output/output{i:03}.txt", 'w') as outfile:
        outfile.write(" ".join(map(str, result)) + "\n")

print("50 test cases generated successfully.")
