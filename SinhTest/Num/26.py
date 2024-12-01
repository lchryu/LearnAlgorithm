import random
import os

# Create directories for input and output
os.makedirs("input", exist_ok=True)
os.makedirs("output", exist_ok=True)

# List of known perfect numbers less than 10^18
perfect_numbers = [
    6, 
    28, 
    496, 
    8128, 
    33550336, 
    8589869056, 
    137438691328, 
    2305843008139952128
]

# Function to check if a number is a perfect number
def is_perfect_number(n):
    if n in perfect_numbers:
        return True
    return False

# Function to generate a random number between 1 and 10^18
def generate_random_test_case():
    return random.randint(1, 10**18)

# Function to write input/output files
def write_test_case(i, n, result):
    # Write input
    with open(f"input/input{i:03}.txt", 'w') as infile:
        infile.write(f"{n}\n")
    
    # Write output
    with open(f"output/output{i:03}.txt", 'w') as outfile:
        outfile.write(f"{result}\n")

# Generate 25 test cases containing perfect numbers
for i in range(25):
    n = random.choice(perfect_numbers)  # Select a random perfect number
    result = "YES" if is_perfect_number(n) else "NO"
    write_test_case(i, n, result)

# Generate 25 random test cases
for i in range(25, 50):
    n = generate_random_test_case()  # Generate a random number
    result = "YES" if is_perfect_number(n) else "NO"
    write_test_case(i, n, result)

print("50 test cases generated successfully.")
