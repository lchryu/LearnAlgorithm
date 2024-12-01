import random
import os

# Create input and output directories if they don't exist
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

def generate_test_case(test_number):
    n = random.randint(2, 1000)  # Number of vertices
    
    adjacency_list = [[] for _ in range(n + 1)]
    edges = []

    # Populate the adjacency list randomly
    for i in range(1, n + 1):
        num_neighbors = random.randint(0, n - 1)
        neighbors = random.sample(range(1, n + 1), num_neighbors)
        for neighbor in neighbors:
            if neighbor != i:
                adjacency_list[i].append(neighbor)
                if i < neighbor:
                    edges.append((i, neighbor))

    # Format the test case number with three digits (e.g., 000, 001, ... 049)
    formatted_number = f"{test_number:03}"
    
    # Write input data to input/inputXXX.txt
    input_filename = f'input/input{formatted_number}.txt'
    with open(input_filename, 'w') as input_file:
        input_file.write(f"{n}\n")
        for i in range(1, n + 1):
            input_file.write(" ".join(map(str, sorted(adjacency_list[i]))) + "\n")
    
    # Write expected output data to output/outputXXX.txt
    output_filename = f'output/output{formatted_number}.txt'
    with open(output_filename, 'w') as output_file:
        for edge in sorted(edges):
            output_file.write(f"{edge[0]} {edge[1]}\n")

# Generate 50 test cases and update on the terminal
for i in range(50):  # Generate test cases from 0 to 49
    generate_test_case(i)
    os.system('cls' if os.name == 'nt' else 'clear')  # Clear the screen
    print(f"{i + 1}/50 test cases generated.")

print("50 test cases have been written to input/input000.txt - input/input049.txt and output/output000.txt - output/output049.txt.")
