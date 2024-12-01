import random
import os

# Create directories for input and output
os.makedirs("input", exist_ok=True)
os.makedirs("output", exist_ok=True)

# Function to check if a number is a "lộc phát" number
def is_loc_phat(n):
    return all(c in '068' for c in str(n))

# Function to generate a random number between 1 and 10^18
def generate_random_number():
    return random.randint(1, 10**18)

# Function to generate a "lộc phát" number
def generate_loc_phat_number():
    length = random.randint(1, 18)  # Generate a number with 1 to 18 digits
    return int(''.join(random.choice('068') for _ in range(length)))

# Prepare test cases in memory
test_cases = []
for i in range(25):
    # Generate 25 "lộc phát" numbers
    loc_phat_number = generate_loc_phat_number()
    test_cases.append((loc_phat_number, 1))  # Expected output is 1

for i in range(25):
    # Generate 25 random numbers, which may or may not be "lộc phát"
    random_number = generate_random_number()
    expected_output = 1 if is_loc_phat(random_number) else 0
    test_cases.append((random_number, expected_output))

# Write the test cases to files
for i, (n, result) in enumerate(test_cases):
    # Write input file
    with open(f"input/input{i:03}.txt", 'w') as infile:
        infile.write(f"{n}\n")
    
    # Write output file
    with open(f"output/output{i:03}.txt", 'w') as outfile:
        outfile.write(f"{result}\n")

print("50 test cases generated successfully.")
