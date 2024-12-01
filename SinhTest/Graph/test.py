import heapq

def dijkstra(graph, start):
    distances = {vertex: float('infinity') for vertex in graph}
    distances[start] = 0
    priority_queue = [(0, start)]

    while priority_queue:
        current_distance, current_vertex = heapq.heappop(priority_queue)

        if current_distance > distances[current_vertex]:
            continue

        for neighbor, weight in graph[current_vertex].items():
            distance = current_distance + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))

    return distances

# Chuyển đổi ma trận kề thành danh sách kề
def convert_matrix_to_list(matrix):
    graph = {}
    num_vertices = len(matrix)
    for i in range(num_vertices):
        graph[i] = {}
        for j in range(num_vertices):
            if matrix[i][j] != 0:  # Chỉ thêm cạnh nếu trọng số khác 0
                graph[i][j] = matrix[i][j]
    return graph

# Ma trận kề
adjacencyMatrix = [
    [0, 10, 0, 30, 100],
    [10, 0, 50, 0, 0],
    [0, 50, 0, 20, 10],
    [30, 0, 20, 0, 60],
    [100, 0, 10, 60, 0]
]

# Chuyển đổi sang danh sách kề
graph = convert_matrix_to_list(adjacencyMatrix)

# Chạy thuật toán Dijkstra từ đỉnh 0
start_vertex = 0
distances = dijkstra(graph, start_vertex)

# In kết quả
for vertex in distances:
    print(f"Distance from {start_vertex} to {vertex}: {distances[vertex]}")

'''

'''