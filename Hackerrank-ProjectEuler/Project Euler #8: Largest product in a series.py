#!/bin/python3

import sys

digits = []
def multiply(a,b):
    value =1
    for j in range(a,b):
        value*=digits[j]
    return value

t = int(input().strip())
for a0 in range(t):
    n,k = input().strip().split(' ')
    n,k = [int(n),int(k)]
    num = int(input().strip())
    digits.clear()
    for i in range(0,n):
        digits.append(num % 10)
        num/= 10
    maximum = 0
    for i in range(0,n-k+1):
        product=multiply(i,i+k)
        if product > maximum:
            maximum = product
    print(maximum)
