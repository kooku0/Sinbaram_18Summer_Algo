from sys import stdin

N = int(stdin.readline())

result = 0
for num in xrange(1, N + 1):
    list = [int(x) for x in str(num)]
    prev_gap = -1 
    prev = -1
    state = True
    for i, value in enumerate(list):
        if i == 0:
            prev = value
        elif i == 1:
            prev_gap = value - prev
            prev = value
        else:
            gap = value - prev
            if gap != prev_gap:
                state = False
                break
            prev_gap = gap
    
    if state == True:
        result = result + 1

print result
