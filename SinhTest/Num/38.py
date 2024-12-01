import math
import random
MOD = 10**9 + 7
MAX_N = 100000  # Upper limit for n to be used for random test case generation

# Function to check if a number is prime
def check(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

# Function to count the number of divisors for a given prime factor
def uocSo(n, p):
    ans = 0
    i = p
    while i <= n:
        ans += n // i
        ans %= MOD
        i *= p
    return ans

# Main computation logic to calculate divisors for n!
def compute_divisors(n):
    ans = 1
    for i in range(2, n + 1):
        if check(i):
            ans *= (uocSo(n, i) + 1)
            ans %= MOD
    return ans

# Generate random input
def generate_test_case():
    return random.randint(1, MAX_N)

# Write input and output to files
def write_test_case(test_number, n, result):
    formatted_number = f"{test_number:03}"
    with open(f'input/input{formatted_number}.txt', 'w') as input_file:
        input_file.write(f"{n}\n")
    
    with open(f'output/output{formatted_number}.txt', 'w') as output_file:
        output_file.write(f"{result}\n")

# Generate 50 test cases and calculate the results
def generate_50_tests():
    for i in range(50):
        n = generate_test_case()
        result = compute_divisors(n)
        write_test_case(i, n, result)
    
    print("50 test cases generated and written to input/output files.")

# Run the test case generation
if __name__ == "__main__":
    generate_50_tests()
