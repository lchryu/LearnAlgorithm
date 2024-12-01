import random
import os

# Tạo thư mục input và output nếu chưa tồn tại
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

def generate_graph(n, m):
    edges = set()
    while len(edges) < m:
        u = random.randint(1, n)
        v = random.randint(1, n)
        if u != v:
            edge = (min(u, v), max(u, v))  # Đảm bảo u < v để tránh trùng lặp cạnh
            edges.add(edge)
    return list(edges)

# Sinh test case và lưu vào file
def generate_test_case(test_number):
    # Sinh số đỉnh ngẫu nhiên từ 2 đến 1000
    n = random.randint(2, 1000)
    # Sinh số cạnh ngẫu nhiên từ 1 đến m = n * (n - 1) // 2 (số cạnh tối đa của đồ thị vô hướng)
    m = random.randint(1, min(5000, n * (n - 1) // 2))
    
    # Sinh đồ thị
    edges = generate_graph(n, m)
    
    # Ghi input vào file
    input_filename = f'input/input{test_number:03}.txt'
    with open(input_filename, 'w') as input_file:
        input_file.write(f"{n} {m}\n")
        for u, v in edges:
            input_file.write(f"{u} {v}\n")
    
    # Chạy thuật toán DFS kiểm tra chu trình (giả sử chúng ta đã có thuật toán kiểm tra chu trình)
    output_filename = f'output/output{test_number:03}.txt'
    with open(output_filename, 'w') as output_file:
        # Thay thế phần này bằng cách chạy thuật toán của bạn để kiểm tra chu trình trên đồ thị
        output_file.write("1\n")  # Giả sử tồn tại chu trình (cần thay đổi khi chạy thuật toán thực tế)
from os import system
# Sinh 50 test case
for i in range(50):
    system("cls")
    generate_test_case(i)
    print(f"Test case {i+1}/50 generated.")
