import random
import os

# Create input and output directories if they don't exist
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

def generate_test_case(test_number):
    n = random.randint(2, 1000)  # Number of vertices
    m = random.randint(1, min(n * (n - 1) // 2, 1000))  # Number of edges
    
    adj_list = {i: [] for i in range(1, n + 1)}
    edges = set()

    while len(edges) < m:
        u = random.randint(1, n)
        v = random.randint(1, n)
        if u != v and (u, v) not in edges and (v, u) not in edges:
            edges.add((u, v))
            adj_list[u].append(v)
            adj_list[v].append(u)
    
    # Perform DFS to find connected components
    tplt = [0] * (n + 1)
    cnt = 1

    def dfs(node):
        tplt[node] = cnt
        for neighbor in adj_list[node]:
            if tplt[neighbor] == 0:
                dfs(neighbor)

    for i in range(1, n + 1):
        if tplt[i] == 0:
            dfs(i)
            cnt += 1

    q = random.randint(1, 10000)  # Number of queries
    queries = []
    outputs = []

    for _ in range(q):
        s = random.randint(1, n)
        t = random.randint(1, n)
        queries.append((s, t))
        if tplt[s] == tplt[t]:
            outputs.append("1")
        else:
            outputs.append("-1")

    # Format the test case number with three digits (e.g., 000, 001, ... 049)
    formatted_number = f"{test_number:03}"

    # Write input data to input/inputXXX.txt
    input_filename = f'input/input{formatted_number}.txt'
    with open(input_filename, 'w') as input_file:
        input_file.write(f"{n} {m}\n")
        for u, v in edges:
            input_file.write(f"{u} {v}\n")
        input_file.write(f"{q}\n")
        for s, t in queries:
            input_file.write(f"{s} {t}\n")

    # Write expected output data to output/outputXXX.txt
    output_filename = f'output/output{formatted_number}.txt'
    with open(output_filename, 'w') as output_file:
        for output in outputs:
            output_file.write(output + "\n")

# Generate 50 test cases and update on the terminal
for i in range(50):  # Generate test cases from 0 to 49
    generate_test_case(i)
    os.system('cls' if os.name == 'nt' else 'clear')  # Clear the screen
    print(f"{i + 1}/50 test cases generated.")

print("50 test cases have been written to input/input000.txt - input/input049.txt and output/output000.txt - output/output049.txt.")
