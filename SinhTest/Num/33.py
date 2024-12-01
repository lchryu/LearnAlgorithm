import random
import os

# Create input and output directories if they don't exist
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Define prime digits
prime_digits = {'2', '3', '5', '7'}

# Function to generate a random large integer
def generate_large_number():
    length = random.randint(1, 18)  # Length of the number (since n <= 1e18)
    number = ''.join(random.choices('0123456789', k=length))
    # Ensure the number doesn't start with '0'
    if number[0] == '0':
        number = random.choice('123456789') + number[1:]
    return number

# Function to generate the expected output for a given number n
def generate_output(n):
    s = str(n)
    mp = {}

    # Count occurrences of prime digits
    for x in s:
        if x in prime_digits:
            mp[x] = mp.get(x, 0) + 1

    # First part: prime digits in ascending order
    sorted_primes = sorted(mp.items())
    first_output = '\n'.join(f"{digit} {count}" for digit, count in sorted_primes)

    # Second part: prime digits in the order they appeared in n
    seen = set()
    second_output_lines = []
    for x in s:
        if x in prime_digits and x not in seen:
            second_output_lines.append(f"{x} {mp[x]}")
            seen.add(x)

    second_output = '\n'.join(second_output_lines)

    # Combine both parts with a blank line in between
    output = f"{first_output}\n\n{second_output}\n"
    return output

# Function to generate a single test case
def generate_test_case(test_number):
    n = generate_large_number()
    input_data = f"{n}\n"
    output_data = generate_output(n)

    # Format the test case number with three digits
    formatted_number = f"{test_number:03}"

    # Write input data to input/inputXXX.txt
    input_filename = f'input/input{formatted_number}.txt'
    with open(input_filename, 'w') as input_file:
        input_file.write(input_data)

    # Write output data to output/outputXXX.txt
    output_filename = f'output/output{formatted_number}.txt'
    with open(output_filename, 'w') as output_file:
        output_file.write(output_data)

# Generate 50 test cases
for i in range(50):
    generate_test_case(i)

print("50 test cases have been written to input/ and output/ directories.")
