import os
import random

# Create directories for input and output
os.makedirs("input", exist_ok=True)
os.makedirs("output", exist_ok=True)

# Function to check if a number is beautiful based on the solution provided
def check_beautiful(n):
    dem6 = 0
    tong = 0
    m = n
    sum_reversed = 0
    
    while n:
        r = n % 10
        sum_reversed = sum_reversed * 10 + r  # Reverse number
        if r == 6:
            dem6 += 1
        tong += r
        n //= 10
    
    return dem6 >= 1 and (tong % 10 == 8) and sum_reversed == m

# Function to generate a random range [a, b]
def generate_random_range():
    a = random.randint(1, 10**6)
    b = random.randint(a, 10**6)  # Ensure b >= a
    return a, b

# Function to generate the output for a given range [a, b]
def generate_output(a, b):
    result = []
    for i in range(a, b + 1):
        if check_beautiful(i):
            result.append(str(i))
    return " ".join(result) if result else "-1"

# Generate 50 test cases
for i in range(50):
    a, b = generate_random_range()
    
    # Write input file
    with open(f"input/input{i:03}.txt", 'w') as infile:
        infile.write(f"{a} {b}\n")
    
    # Generate output using the check function
    output = generate_output(a, b)
    
    # Write output file
    with open(f"output/output{i:03}.txt", 'w') as outfile:
        outfile.write(output + "\n")

print("50 test cases generated successfully.")
