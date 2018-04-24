#!/bin/python3

import math

def gcd(a , b):

    if b > a:
        a , b = b, a
    while b:
        a , b = b, a % b
    return a

def lcm(a,b):
    return (a*b)//gcd(a,b)

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    if n == 1:
        print(1)
        continue
    ans =2
    for i in range(3,n+1):
        ans=lcm(ans,i)
    print(ans)

