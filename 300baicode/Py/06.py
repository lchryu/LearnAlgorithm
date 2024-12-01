a, b, c = map(int, input().split())
perimeter = a + b + c
p = perimeter / 2
area = (p * (p - a) * (p - b) * (p - c)) ** 0.5
print(f'{perimeter:.1f} {area:.3f}')
