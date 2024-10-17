a, b, c = map(int, input().split())
p = (a + b + c) / 2
area = (p * (p - a) * (p - b) * (p - c)) ** 0.5
r = a * b * c / (4 * area)
print(f'{r:.3f}')
