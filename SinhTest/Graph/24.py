import os
import random
from collections import defaultdict, deque

# Tạo thư mục input và output nếu chưa tồn tại
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Hàm sinh cây
def generate_tree(n):
    edges = []
    if n > 1:
        for i in range(2, n+1):
            edges.append((i, random.randint(1, i-1)))  # Sinh cạnh ngẫu nhiên từ i đến 1 đến i-1
    return edges

# Hàm kiểm tra cây
def is_tree(n, edges):
    if len(edges) != n - 1:  # Một cây phải có đúng n-1 cạnh
        return 0

    adj = defaultdict(list)
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)

    visited = [False] * (n + 1)
    parent = [-1] * (n + 1)
    
    # Sử dụng BFS để duyệt đồ thị
    q = deque([1])
    visited[1] = True

    while q:
        node = q.popleft()
        for neighbor in adj[node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                parent[neighbor] = node
                q.append(neighbor)
            elif parent[node] != neighbor:
                return 0  # Tồn tại chu trình

    # Kiểm tra xem tất cả các đỉnh đã được duyệt hay chưa
    if all(visited[1:n+1]):
        return 1
    return 0

# Hàm ghi test case
def write_test_case(test_number, n, edges, result):
    input_filename = f'input/input{test_number:03}.txt'
    output_filename = f'output/output{test_number:03}.txt'
    
    with open(input_filename, 'w') as f_input:
        f_input.write(f"{n} {len(edges)}\n")
        for u, v in edges:
            f_input.write(f"{u} {v}\n")
    
    with open(output_filename, 'w') as f_output:
        f_output.write(f"{result}\n")

# Sinh 50 test case
for i in range(50):
    n = random.randint(2, 1000)  # Sinh ngẫu nhiên số đỉnh từ 2 đến 1000
    tree = random.choice([True, False])  # Xác định có phải cây hay không
    if tree:
        edges = generate_tree(n)  # Sinh cây ngẫu nhiên
    else:
        edges = generate_tree(n)
        extra_edges = random.randint(1, 5)  # Thêm vài cạnh ngẫu nhiên để làm đồ thị không phải cây
        for _ in range(extra_edges):
            u = random.randint(1, n)
            v = random.randint(1, n)
            if u != v and (u, v) not in edges and (v, u) not in edges:
                edges.append((u, v))
    
    result = is_tree(n, edges)  # Kết quả có phải cây hay không
    write_test_case(i, n, edges, result)
    print(f"Test case {i + 1}/50 generated.")

print("50 test cases have been written to the input and output directories.")
