import random
import os
import subprocess

# Create input and output directories if they don't exist
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# DFS function to find the path
def dfs(graph, visited, pre, node, target):
    visited[node] = True
    if node == target:
        return True
    for neighbor in sorted(graph[node]):
        if not visited[neighbor]:
            pre[neighbor] = node
            if dfs(graph, visited, pre, neighbor, target):
                return True
    return False

# Function to find path using DFS
def find_path(n, m, s, t, edges):
    graph = {i: [] for i in range(1, n + 1)}
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    visited = [False] * (n + 1)
    pre = [-1] * (n + 1)
    
    if not dfs(graph, visited, pre, s, t):
        return "-1"

    path = []
    node = t
    while node != -1:
        path.append(node)
        node = pre[node]
    
    return " ".join(map(str, reversed(path)))

# Function to generate random test cases
def generate_test_case(test_number):
    n = random.randint(2, 1000)  # Number of vertices
    m = random.randint(1, min(n * (n - 1) // 2, 1000))  # Number of edges
    s = random.randint(1, n)  # Start node
    t = random.randint(1, n)  # Target node
    
    edges = set()
    edge_list = []
    
    for _ in range(m):
        while True:
            u = random.randint(1, n)
            v = random.randint(1, n)
            if u != v and (u, v) not in edges and (v, u) not in edges:
                edges.add((u, v))
                edge_list.append((u, v))
                break
    
    output_data = find_path(n, m, s, t, edge_list)

    # Format the test case number with three digits (e.g., 000, 001, ... 049)
    formatted_number = f"{test_number:03}"
    
    # Write input data to input/inputXXX.txt
    input_filename = f'input/input{formatted_number}.txt'
    with open(input_filename, 'w') as input_file:
        input_file.write(f"{n} {m} {s} {t}\n" + "\n".join(f"{u} {v}" for u, v in edge_list) + "\n")
    
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
