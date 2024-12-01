import os
import random
import string
import heapq
from collections import Counter

# Ham tinh gia tri nho nhat cua xau sau khi loai bo K ky tu
def calculate_min_value(s, k):
    # Dem tan suat xuat hien cua moi ky tu trong chuoi
    frequency = Counter(s)
    
    # Su dung heapq de tao priority queue voi tan suat theo thu tu giam dan
    pq = [-freq for freq in frequency.values()]  # Dung so am de gia lap max-heap
    heapq.heapify(pq)
    
    # Loai bo K ky tu
    while k > 0 and pq:
        top = -heapq.heappop(pq)  # Lay ra tan suat lon nhat (phai doi dau)
        top -= 1  # Giam tan suat di 1
        k -= 1
        if top > 0:
            heapq.heappush(pq, -top)  # Dua lai gia tri da cap nhat vao heap
    
    # Tinh tong binh phuong cua cac tan suat con lai
    result = sum((-freq) ** 2 for freq in pq)
    
    return result

# Ham sinh mot bo test
def generate_test_case(test_number, max_length, max_k):
    t = random.randint(1, 10)  # So luong test case moi file (gioi han 1-10)

    input_file_path = f'input/input{test_number:03}.txt'
    output_file_path = f'output/output{test_number:03}.txt'

    with open(input_file_path, 'w') as input_file, open(output_file_path, 'w') as output_file:
        input_file.write(f"{t}\n")
        for _ in range(t):
            n = random.randint(1, max_length)  # Do dai chuoi ngau nhien
            s = ''.join(random.choices(string.ascii_uppercase, k=n))  # Chuoi ngau nhien ky tu [A-Z]
            k = random.randint(0, min(n, max_k))  # Gia tri K khong vuot qua do dai cua chuoi

            # Ghi input vao file
            input_file.write(f"{k}\n")
            input_file.write(f"{s}\n")

            # Tinh toan output dua tren solution
            result = calculate_min_value(s, k)
            output_file.write(f"{result}\n")

# Ham sinh nhieu bo test
def generate_multiple_test_cases(num_cases, max_length=1000, max_k=500):
    os.makedirs('input', exist_ok=True)
    os.makedirs('output', exist_ok=True)

    for i in range(num_cases):
        generate_test_case(i, max_length, max_k)

    print(f"{num_cases} test cases have been generated.")

# Sinh 50 bo test voi do dai toi da la 1000 va gia tri K toi da la 500
generate_multiple_test_cases(50)
