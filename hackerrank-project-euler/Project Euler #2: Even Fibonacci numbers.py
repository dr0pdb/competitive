#!/bin/python3

import sys

t = int(input().strip())
n1 = 2
n2 = 8
for a0 in range(t):
    prev = n2
    prev2 = n1
    current = 10
    summation = 10
    n = int(input().strip())
    while True:
        if (4*prev)+prev2 <= n:
            current = (4*prev)+prev2
            summation += current
            prev2 = prev
            prev = current
        else:
            break
    print("{}".format(summation))
