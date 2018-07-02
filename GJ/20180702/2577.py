from sys import stdin

A = int(stdin.readline())
B = int(stdin.readline())
C = int(stdin.readline())

temp =  [int(x) for x in str(A * B * C)]

for i in xrange(10):
    print temp.count(i)
