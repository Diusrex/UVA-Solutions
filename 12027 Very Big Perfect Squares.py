
solutions = []

maxAllowed = 10**1000
value = 1
base = 1

while value * value <= maxAllowed:
    while value < base * 10:
        solutions.append(value)
        value += base
    base = value

solutions.append(value)

while True:
    num = int(input())
    
    if num == 0:
        break
    
    # Binary search
    # start is inclusive, end is not
    start = 0
    end = len(solutions)
    
    while start + 1 < end:
        middle = (start + end) // 2
        # Too high
        if solutions[middle] * solutions[middle] > num:
            end = middle
        else:
            start = middle;
    
    print(solutions[start])