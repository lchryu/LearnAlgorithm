import os

MOD = 10**9 + 7

# Function to precompute Pascal's triangle
def precompute_pascal(max_n):
    pascal = [[0] * (i + 1) for i in range(max_n + 1)]
    for i in range(max_n + 1):
        pascal[i][0] = pascal[i][i] = 1
        for j in range(1, i):
            pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % MOD
    return pascal

# Function to generate test cases
def generate_test_case(test_number, pascal, n):
    input_data = f"{n}\n"
    output_data = ""

    # Generating Pascal's triangle for height n
    for i in range(n):
        output_data += " ".join(str(pascal[i][j]) for j in range(i + 1)) + "\n"

    # Write input and output files
    formatted_number = f"{test_number:03}"
    with open(f'input/input{formatted_number}.txt', 'w') as input_file:
        input_file.write(input_data)

    with open(f'output/output{formatted_number}.txt', 'w') as output_file:
        output_file.write(output_data)

# Create input and output directories if they don't exist
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Precompute Pascal's triangle for the maximum height (100)
max_n = 100
pascal = precompute_pascal(max_n)

# Generate 50 test cases
for i in range(50):
    # Randomly choose n for each test case between 1 and max_n
    n = i + 1  # Increasing n for each test (you can randomize if needed)
    generate_test_case(i, pascal, n)

print("50 test cases have been generated.")
