import random
import os

# Tạo thư mục 'input' và 'output' nếu chưa tồn tại
os.makedirs('input', exist_ok=True)
os.makedirs('output', exist_ok=True)

# Hàm DFS để đánh dấu các ô thuộc cùng một phòng
def DFS(grid, n, m, i, j):
    # Các hướng di chuyển: phải, trái, xuống, lên
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    
    # Dùng stack thay vì đệ quy để tránh tràn bộ nhớ
    stack = [(i, j)]
    grid[i][j] = '#'
    
    while stack:
        x, y = stack.pop()
        for k in range(4):
            nx, ny = x + dx[k], y + dy[k]
            if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] == '.':
                grid[nx][ny] = '#'
                stack.append((nx, ny))

# Hàm sinh dữ liệu đầu vào và tính toán đầu ra
def generate_test_case(test_number):
    # Kích thước ngẫu nhiên cho bản đồ
    n = random.randint(1, 1000)
    m = random.randint(1, 1000)
    
    # Tạo bản đồ ngẫu nhiên với '.' (sàn) và '#' (tường)
    grid = []
    for i in range(n):
        row = ''.join(random.choice(['.', '#']) for _ in range(m))
        grid.append(list(row))
    
    # Tính số phòng bằng thuật toán DFS
    original_grid = [row[:] for row in grid]  # Copy bản đồ để không làm thay đổi khi tính output
    room_count = 0
    for i in range(n):
        for j in range(m):
            if grid[i][j] == '.':
                room_count += 1
                DFS(grid, n, m, i, j)
    
    # Lưu dữ liệu input vào file inputXXX.txt
    input_filename = f'input/input{test_number:03}.txt'
    with open(input_filename, 'w') as input_file:
        input_file.write(f"{n} {m}\n")
        for row in original_grid:
            input_file.write(''.join(row) + '\n')

    # Lưu kết quả output vào file outputXXX.txt
    output_filename = f'output/output{test_number:03}.txt'
    with open(output_filename, 'w') as output_file:
        output_file.write(f"{room_count}\n")

# Sinh 50 bộ test và cập nhật tiến độ trên terminal
for i in range(50):  # Sinh các bộ test từ 0 đến 49
    generate_test_case(i)
    os.system('cls' if os.name == 'nt' else 'clear')  # Xóa màn hình
    print(f"{i + 1}/50 test cases generated.")

print("50 test cases have been written to input/input000.txt - input/input049.txt and output/output000.txt - output/output049.txt.")
