import os
import math
import random
# Create directories for input and output
os.makedirs("input", exist_ok=True)
os.makedirs("output", exist_ok=True)

# Sieve of Eratosthenes to find all primes <= n
def sieve_of_eratosthenes(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    p = 2
    for p in range(2, int(math.sqrt(n)) + 1):
        if is_prime[p]:
            for i in range(p * p, n + 1, p):
                is_prime[i] = False
    return is_prime

# Function to check if the last digit of the number is the largest
def check_largest_last_digit(n):
    s = str(n)
    last_digit = s[-1]  # Last digit of the number
    return all(last_digit >= s[i] for i in range(len(s) - 1))

# Function to generate a random n value
def generate_random_n():
    return random.randint(1, 10**7)

# Precompute all primes <= 10^7
max_n = 10**7
is_prime = sieve_of_eratosthenes(max_n)

# Generate the output for a given n
def generate_output(n):
    primes_with_largest_digit = []
    for i in range(2, n + 1):
        if is_prime[i] and check_largest_last_digit(i):
            primes_with_largest_digit.append(i)
    return primes_with_largest_digit

# Write test cases to files
for i in range(50):
    n = generate_random_n()

    # Write input file
    with open(f"input/input{i:03}.txt", 'w') as infile:
        infile.write(f"{n}\n")

    # Generate the corresponding output
    result_primes = generate_output(n)

    # Write output file
    with open(f"output/output{i:03}.txt", 'w') as outfile:
        if result_primes:
            outfile.write(" ".join(map(str, result_primes)) + "\n")
            outfile.write(f"{len(result_primes)}\n")
        else:
            outfile.write("\n0\n")

print("50 test cases generated successfully.")
