import random
import os
from collections import defaultdict

# Function to perform DFS
def dfs(graph, visited, node, skip_u=None, skip_v=None):
    visited[node] = True
    for neighbor in graph[node]:
        if not visited[neighbor]:
            # Skip the edge (skip_u, skip_v)
            if (node == skip_u and neighbor == skip_v) or (node == skip_v and neighbor == skip_u):
                continue
            dfs(graph, visited, neighbor, skip_u, skip_v)

# Function to count connected components in the graph
def count_connected_components(graph, n, skip_u=None, skip_v=None):
    visited = [False] * (n + 1)
    components = 0
    for i in range(1, n + 1):
        if not visited[i]:
            dfs(graph, visited, i, skip_u, skip_v)
            components += 1
    return components

# Function to check if an edge is a bridge
def is_bridge(graph, n, u, v):
    initial_components = count_connected_components(graph, n)
    new_components = count_connected_components(graph, n, u, v)
    return new_components > initial_components

# Function to generate random test cases
def generate_test_case(test_number):
    n = random.randint(2, 1000)  # Number of vertices
    m = random.randint(1, min(n * (n - 1) // 2, 1000))  # Number of edges
    
    edges = set()
    graph = defaultdict(list)
    
    # Randomly generate edges
    while len(edges) < m:
        u = random.randint(1, n)
        v = random.randint(1, n)
        if u != v and (u, v) not in edges and (v, u) not in edges:
            edges.add((u, v))
            graph[u].append(v)
            graph[v].append(u)

    # Calculate the number of bridge edges
    bridge_count = 0
    for u, v in edges:
        if is_bridge(graph, n, u, v):
            bridge_count += 1
    
    # Format the test case number with three digits (e.g., 000, 001, ... 049)
    formatted_number = f"{test_number:03}"
    
    # Write input data to input/inputXXX.txt
    input_filename = f'input/input{formatted_number}.txt'
    with open(input_filename, 'w') as input_file:
        input_file.write(f"{n} {m}\n")
        for u, v in edges:
            input_file.write(f"{u} {v}\n")
    
    # Write expected output data to output/outputXXX.txt
    output_filename = f'output/output{formatted_number}.txt'
    with open(output_filename, 'w') as output_file:
        output_file.write(f"{bridge_count}\n")

# Create input and output directories if they don't exist
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Generate 50 test cases
for i in range(50):
    generate_test_case(i)
    print(f"{i + 1}/50 test cases generated.")

print("50 test cases have been written to input/input000.txt - input/input049.txt and output/output000.txt - output/output049.txt.")
