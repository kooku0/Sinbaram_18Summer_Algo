A = int(input())
B = input()

for i in range(len(B) - 1, -1, -1):
    print(A*int(B[i]))

print(A*int(B))
