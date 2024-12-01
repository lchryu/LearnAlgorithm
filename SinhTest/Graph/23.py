import random
import os

MAX_VERTICES = 1000
MAX_EDGES = 1000

# DFS for the original graph
def dfs(graph, visited, node):
    visited[node] = 1
    for neighbor in graph[node]:
        if visited[neighbor] == 0:
            dfs(graph, visited, neighbor)

# DFS for the transposed graph
def dfs_transposed(graph, visited, node):
    visited[node] = 1
    for neighbor in graph[node]:
        if visited[neighbor] == 0:
            dfs_transposed(graph, visited, neighbor)

# Check if the graph is strongly connected using Kosaraju's algorithm
def is_strongly_connected(n, graph, transposed_graph):
    visited = [0] * (n + 1)
    
    # Run DFS on the original graph starting from node 1
    dfs(graph, visited, 1)

    # Check if all nodes were visited in the original graph
    if any(visited[i] == 0 for i in range(2, n + 1)):
        return False

    # Reset visited array and run DFS on the transposed graph
    visited = [0] * (n + 1)
    dfs_transposed(transposed_graph, visited, 1)

    # Check if all nodes were visited in the transposed graph
    if any(visited[i] == 0 for i in range(2, n + 1)):
        return False

    return True

# Generate a random test case and check if the graph is strongly connected
def generate_test_case(test_num):
    # Random number of vertices and edges
    n = random.randint(2, MAX_VERTICES)
    m = random.randint(1, min(n * (n - 1), MAX_EDGES))

    # Generate edges
    edges = set()
    while len(edges) < m:
        u = random.randint(1, n)
        v = random.randint(1, n)
        if u != v:  # Ensure no self-loops
            edges.add((u, v))

    graph = [[] for _ in range(n + 1)]
    transposed_graph = [[] for _ in range(n + 1)]
    
    # Build the adjacency list for the original and transposed graphs
    for u, v in edges:
        graph[u].append(v)
        transposed_graph[v].append(u)

    # Write input file
    input_filename = f"input/input{test_num:03d}.txt"
    os.makedirs('input', exist_ok=True)
    with open(input_filename, 'w') as input_file:
        input_file.write(f"{n} {m}\n")
        for u, v in edges:
            input_file.write(f"{u} {v}\n")
    
    # Check if the graph is strongly connected and write output
    output_filename = f"output/output{test_num:03d}.txt"
    os.makedirs('output', exist_ok=True)
    with open(output_filename, 'w') as output_file:
        if is_strongly_connected(n, graph, transposed_graph):
            output_file.write("1\n")
        else:
            output_file.write("0\n")

# Generate 50 test cases and update the terminal
for i in range(50):  # Generate test cases from 0 to 49
    generate_test_case(i)
    os.system('cls' if os.name == 'nt' else 'clear')  # Clear the screen
    print(f"{i + 1}/50 test cases generated.")

print("50 test cases have been written to input/input000.txt - input/input049.txt and output/output000.txt - output/output049.txt.")
