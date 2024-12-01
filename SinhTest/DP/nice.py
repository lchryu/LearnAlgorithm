import os
import random
import string
import subprocess

# Function to generate a random string of a given length
def generate_random_string(length):
    letters = string.ascii_lowercase
    return ''.join(random.choice(letters) for _ in range(length))

# Function to generate a single test case and run the C++ solution to get the output
def generate_test_case(test_number):
    # Random lengths for strings s and t
    n = random.randint(1, 1000)  # Length for string s
    m = random.randint(1, 1000)  # Length for string t
    
    # Generate random strings s and t
    s = generate_random_string(n)
    t = generate_random_string(m)
    
    # Write the input to a file
    formatted_number = f"{test_number:03}"
    input_file_path = f'input/input{formatted_number}.txt'
    output_file_path = f'output/output{formatted_number}.txt'
    
    with open(input_file_path, 'w') as input_file:
        input_file.write(f"{s}\n")
        input_file.write(f"{t}\n")
    
    # Run the C++ solution with the generated input and capture the output
    result = subprocess.run(["./lcs_solution"], input=f"{s}\n{t}\n", text=True, capture_output=True)
    
    # Write the actual output of the C++ program to the output file
    with open(output_file_path, 'w') as output_file:
        output_file.write(result.stdout.strip())

# Generate multiple test cases
def generate_multiple_test_cases(num_cases):
    # Create directories for input and output files
    os.makedirs('input', exist_ok=True)
    os.makedirs('output', exist_ok=True)

    # Generate the specified number of test cases
    for i in range(num_cases):
        generate_test_case(i)

    print(f"{num_cases} test cases have been generated.")

# Compile C++ solution first
def compile_cpp_solution():
    compile_result = subprocess.run(["g++", "-o", "lcs_solution", "1.cpp"])
    if compile_result.returncode != 0:
        print("Compilation failed!")
        exit(1)
    print("C++ solution compiled successfully.")

# Compile and then generate 50 test cases
compile_cpp_solution()
generate_multiple_test_cases(50)
