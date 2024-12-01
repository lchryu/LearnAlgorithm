import random
import os
from collections import deque

# Create input and output directories if they don't exist
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

def generate_test_case(test_number):
    n = random.randint(2, 1000)  # Number of vertices
    m = random.randint(1, min(n * (n - 1) // 2, 1000))  # Number of edges
    s = random.randint(1, n)  # Starting vertex
    t = random.randint(1, n)  # Ending vertex
    
    adj_list = {i: [] for i in range(1, n + 1)}
    edges = set()

    while len(edges) < m:
        u = random.randint(1, n)
        v = random.randint(1, n)
        if u != v and (u, v) not in edges:
            edges.add((u, v))
            adj_list[u].append(v)

    def bfs(start, end):
        visited = {i: False for i in range(1, n + 1)}
        predecessor = {i: -1 for i in range(1, n + 1)}
        queue = deque([start])
        visited[start] = True

        while queue:
            node = queue.popleft()
            for neighbor in sorted(adj_list[node]):
                if not visited[neighbor]:
                    visited[neighbor] = True
                    predecessor[neighbor] = node
                    queue.append(neighbor)
                    if neighbor == end:
                        break

        if not visited[end]:
            return [-1]
        else:
            path = []
            while end != -1:
                path.append(end)
                end = predecessor[end]
            path.reverse()
            return path

    path = bfs(s, t)

    # Format the test case number with three digits (e.g., 000, 001, ... 049)
    formatted_number = f"{test_number:03}"

    # Write input data to input/inputXXX.txt
    input_filename = f'input/input{formatted_number}.txt'
    with open(input_filename, 'w') as input_file:
        input_file.write(f"{n} {m} {s} {t}\n")
        for u, v in edges:
            input_file.write(f"{u} {v}\n")
    
    # Write expected output data to output/outputXXX.txt
    output_filename = f'output/output{formatted_number}.txt'
    with open(output_filename, 'w') as output_file:
        if path == [-1]:
            output_file.write("-1\n")
        else:
            output_file.write(" ".join(map(str, path)) + "\n")

# Generate 50 test cases and update on the terminal
for i in range(50):  # Generate test cases from 0 to 49
    generate_test_case(i)
    os.system('cls' if os.name == 'nt' else 'clear')  # Clear the screen
    print(f"{i + 1}/50 test cases generated.")

print("50 test cases have been written to input/input000.txt - input/input049.txt and output/output000.txt - output/output049.txt.")
