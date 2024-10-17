def calculate_perimeter_area(a, b):
    perimeter = (a + b) * 2
    area = a * b
    return perimeter, area


a, b = map(int, input().split())
_perimeter, _area = calculate_perimeter_area(a, b)
print(_perimeter, _area)
