import random
import os

# Create input and output directories if they don't exist
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Function to generate random test cases for the graph problem
def generate_test_case(test_number):
    n = random.randint(2, 1000)  # Number of vertices
    m = random.randint(1, min(n * (n - 1) // 2, 1000))  # Number of edges
    
    edges = set()
    input_data = []
    adjacency_list = [[] for _ in range(n + 1)]
    
    for _ in range(m):
        while True:
            u = random.randint(1, n)
            v = random.randint(1, n)
            if u != v and (u, v) not in edges and (v, u) not in edges:
                edges.add((u, v))
                break
        input_data.append(f"{u} {v}")
        adjacency_list[u].append(v)
        adjacency_list[v].append(u)

    # Format the test case number with three digits (e.g., 000, 001, ... 049)
    formatted_number = f"{test_number:03}"
    
    # Write input data to input/inputXXX.txt
    input_filename = f'input/input{formatted_number}.txt'
    with open(input_filename, 'w') as input_file:
        input_file.write(f"{n} {m}\n" + "\n".join(input_data) + "\n")
    
    # Write expected output data to output/outputXXX.txt
    output_filename = f'output/output{formatted_number}.txt'
    with open(output_filename, 'w') as output_file:
        articulation_points = count_articulation_points(n, adjacency_list)
        output_file.write(f"{articulation_points}\n")

def dfs(graph, visited, node):
    visited[node] = True
    for neighbor in graph[node]:
        if not visited[neighbor]:
            dfs(graph, visited, neighbor)

def count_components(n, graph, exclude=-1):
    visited = [False] * (n + 1)
    components = 0
    for i in range(1, n + 1):
        if i != exclude and not visited[i]:
            dfs(graph, visited, i)
            components += 1
    return components

def count_articulation_points(n, graph):
    original_components = count_components(n, graph)
    articulation_points = 0
    for i in range(1, n + 1):
        if count_components(n, graph, exclude=i) > original_components:
            articulation_points += 1
    return articulation_points

# Generate 50 test cases and update on the terminal
for i in range(50):  # Generate test cases from 0 to 49
    generate_test_case(i)
    os.system('cls' if os.name == 'nt' else 'clear')  # Clear the screen
    print(f"{i + 1}/50 test cases generated.")

print("50 test cases have been written to input/input000.txt - input/input049.txt and output/output000.txt - output/output049.txt.")
