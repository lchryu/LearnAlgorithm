import random
import os

# Create input and output directories if they don't exist
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

def generate_test_case(test_number):
    n = random.randint(2, 1000)  # Number of vertices
    adj_matrix = [[0] * n for _ in range(n)]
    adj_list = [[] for _ in range(n)]

    for i in range(n):
        for j in range(n):
            if i != j and random.choice([True, False]):
                adj_matrix[i][j] = 1
                adj_list[i].append(j + 1)

    # Format the test case number with three digits (e.g., 000, 001, ... 049)
    formatted_number = f"{test_number:03}"
    
    # Write input data to input/inputXXX.txt
    input_filename = f'input/input{formatted_number}.txt'
    with open(input_filename, 'w') as input_file:
        input_file.write(f"{n}\n")
        for row in adj_matrix:
            input_file.write(" ".join(map(str, row)) + "\n")
    
    # Write expected output data to output/outputXXX.txt
    output_filename = f'output/output{formatted_number}.txt'
    with open(output_filename, 'w') as output_file:
        for i in range(n):
            output_file.write(f"{i + 1}: " + " ".join(map(str, sorted(adj_list[i]))) + "\n")

# Generate 50 test cases and update on the terminal
for i in range(50):  # Generate test cases from 0 to 49
    generate_test_case(i)
    os.system('cls' if os.name == 'nt' else 'clear')  # Clear the screen
    print(f"{i + 1}/50 test cases generated.")

print("50 test cases have been written to input/input000.txt - input/input049.txt and output/output000.txt - output/output049.txt.")
"""
5
0 1 1 1 0 
1 0 1 1 1 
1 1 0 1 1 
1 1 1 0 1 
0 1 1 1 0


1: 2 3 4
2: 1 3 4 5
3: 1 2 4 5
4: 1 2 3 5
5: 2 3 4
"""