a, b = map(int, input().split(" "))



# print gcd and lcm a b

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def lcm(a, b):
    return abs(a * b) // gcd(a, b)

print(gcd(a, b), end=" ")

print(lcm(a, b))