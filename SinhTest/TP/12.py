import random

def generate_test_case(filename, n=None, k=None, a=None):
    """Generate a test case and write to file"""
    if n is None:
        n = random.randint(4, 1000)  # At least 4 elements needed
    if a is None:
        a = [random.randint(1, 10**9) for _ in range(n)]
    if k is None:
        # Randomly decide if we want a YES or NO case
        if random.random() < 0.5:  # 50% chance for YES case
            # Select 4 random distinct indices
            indices = random.sample(range(n), 4)
            k = sum(a[i] for i in indices)
        else:  # NO case
            k = random.randint(1, 10**9)
    
    # Write test case to file
    with open(f"{filename}.inp", "w") as f:
        f.write(f"{n} {k}\n")
        f.write(" ".join(map(str, a)))

# Generate different types of test cases
def generate_all_test_cases():
    # Test 1: Minimum size array (n=4) with YES answer
    a = [1, 1, 1, 1]
    generate_test_case("test1", n=4, k=4, a=a)
    
    # Test 2: Small size with NO answer
    a = [1, 2, 3, 4, 5]
    generate_test_case("test2", n=5, k=100, a=a)
    
    # Test 3: Medium size with guaranteed YES
    n = 100
    a = [random.randint(1, 1000) for _ in range(n)]
    indices = random.sample(range(n), 4)
    k = sum(a[i] for i in indices)
    generate_test_case("test3", n=n, k=k, a=a)
    
    # Test 4: Large size with all same numbers
    n = 1000
    a = [1] * n
    generate_test_case("test4", n=n, k=4, a=a)
    
    # Test 5: Maximum constraints
    n = 1000
    a = [10**9] * n
    generate_test_case("test5", n=n, k=4 * (10**9), a=a)
    
    # Test 6: Random large test
    n = 1000
    generate_test_case("test6")
    
    # Test 7: Array with some duplicates
    n = 100
    a = [random.randint(1, 10) for _ in range(n)]  # Small range to ensure duplicates
    generate_test_case("test7", n=n, a=a)

if __name__ == "__main__":
    generate_all_test_cases()
    print("Test cases generated successfully!")