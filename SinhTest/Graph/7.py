import random
import os

# Create input and output directories if they don't exist
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

def generate_test_case(test_number):
    n = random.randint(2, 1000)  # Number of vertices
    adj_list = [[] for _ in range(n)]
    adj_matrix = [[0] * n for _ in range(n)]

    for i in range(n):
        num_neighbors = random.randint(0, n - 1)
        neighbors = random.sample(range(1, n + 1), num_neighbors)
        adj_list[i] = sorted(neighbors)
        for neighbor in neighbors:
            adj_matrix[i][neighbor - 1] = 1

    # Format the test case number with three digits (e.g., 000, 001, ... 049)
    formatted_number = f"{test_number:03}"
    
    # Write input data to input/inputXXX.txt
    input_filename = f'input/input{formatted_number}.txt'
    with open(input_filename, 'w') as input_file:
        input_file.write(f"{n}\n")
        for neighbors in adj_list:
            input_file.write(" ".join(map(str, neighbors)) + "\n")
    
    # Write expected output data to output/outputXXX.txt
    output_filename = f'output/output{formatted_number}.txt'
    with open(output_filename, 'w') as output_file:
        for row in adj_matrix:
            output_file.write(" ".join(map(str, row)) + "\n")

# Generate 50 test cases and update on the terminal
for i in range(50):  # Generate test cases from 0 to 49
    generate_test_case(i)
    os.system('cls' if os.name == 'nt' else 'clear')  # Clear the screen
    print(f"{i + 1}/50 test cases generated.")

print("50 test cases have been written to input/input000.txt - input/input049.txt and output/output000.txt - output/output049.txt.")
