import os
import random
import heapq

# Hàm tính chi phí nối dây, bám sát theo solution đã cung cấp
def calculate_cost(lengths):
    pq = lengths[:]
    heapq.heapify(pq)  # Chuyển danh sách thành heap (priority queue)
    total_cost = 0

    while len(pq) > 1:
        top1 = heapq.heappop(pq)
        top2 = heapq.heappop(pq)
        cost = top1 + top2
        total_cost += cost
        heapq.heappush(pq, cost)

    return total_cost

# Hàm sinh một bộ test
def generate_test_case(test_number):
    t = random.randint(1, 10)  # Số lượng test case trong mỗi file
    max_n = 1000  # Giới hạn N để tránh quá tải trong quá trình chạy
    max_length = 10**6  # Độ dài tối đa của mỗi sợi dây

    input_file_path = f'input/input{test_number:03}.txt'
    output_file_path = f'output/output{test_number:03}.txt'

    with open(input_file_path, 'w') as input_file, open(output_file_path, 'w') as output_file:
        input_file.write(f"{t}\n")
        for _ in range(t):
            n = random.randint(2, max_n)  # Số lượng sợi dây ít nhất là 2
            lengths = [random.randint(1, max_length) for _ in range(n)]

            # Ghi input vào file
            input_file.write(f"{n}\n")
            input_file.write(" ".join(map(str, lengths)) + "\n")

            # Tính toán chi phí nối dây và ghi output
            result = calculate_cost(lengths)
            output_file.write(f"{result}\n")

# Hàm sinh nhiều bộ test
def generate_multiple_test_cases(num_cases):
    os.makedirs('input', exist_ok=True)
    os.makedirs('output', exist_ok=True)

    for i in range(num_cases):
        generate_test_case(i)

    print(f"{num_cases} test cases have been generated.")

# Sinh 50 bộ test
generate_multiple_test_cases(50)
