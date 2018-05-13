#!/bin/python3

import sys
import math

def isprime(a):
    r=math.floor(math.sqrt(a))+1
    for j in range(2, r):
        if a % j == 0:
            return False
    return True

primes = []
primes.append(2)
count=1
i=3
while count <= 10000:
    if isprime(i):
        primes.append(i)
        count+=1
    i+=1


t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    print(primes[n-1])

