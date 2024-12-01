import random
import os
import subprocess

# Create input and output directories if they don't exist
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# DFS function to count the connected components
def dfs(graph, visited, node):
    stack = [node]
    visited[node] = True
    
    while stack:
        current = stack.pop()
        for neighbor in graph[current]:
            if not visited[neighbor]:
                visited[neighbor] = True
                stack.append(neighbor)

def count_connected_components(n, graph):
    visited = [False] * (n + 1)
    components = 0
    
    for node in range(1, n + 1):
        if not visited[node]:
            components += 1
            dfs(graph, visited, node)
    
    return components

# Function to generate random test cases for the connected components problem
def generate_test_case(test_number):
    n = random.randint(2, 1000)  # Number of vertices
    m = random.randint(0, min(n * (n - 1) // 2, 1000))  # Number of edges
    
    edges = set()
    graph = {i: [] for i in range(1, n + 1)}
    input_data = []
    
    for _ in range(m):
        while True:
            u = random.randint(1, n)
            v = random.randint(1, n)
            if u != v and (u, v) not in edges and (v, u) not in edges:
                edges.add((u, v))
                graph[u].append(v)
                graph[v].append(u)
                input_data.append(f"{u} {v}")
                break

    output_data = count_connected_components(n, graph)

    # Format the test case number with three digits (e.g., 000, 001, ... 049)
    formatted_number = f"{test_number:03}"
    
    # Write input data to input/inputXXX.txt
    input_filename = f'input/input{formatted_number}.txt'
    with open(input_filename, 'w') as input_file:
        input_file.write(f"{n} {m}\n" + "\n".join(input_data) + "\n")
    
    # Write expected output data to output/outputXXX.txt
    output_filename = f'output/output{formatted_number}.txt'
    with open(output_filename, 'w') as output_file:
        output_file.write(f"{output_data}\n")

# Generate 50 test cases and update on the terminal
for i in range(50):  # Generate test cases from 0 to 49
    generate_test_case(i)
    subprocess.run(['cls' if os.name == 'nt' else 'clear'], shell=True)  # Clear the screen
    print(f"{i + 1}/50 test cases generated.")

print("50 test cases have been written to input/input000.txt - input/input049.txt and output/output000.txt - output/output049.txt.")
