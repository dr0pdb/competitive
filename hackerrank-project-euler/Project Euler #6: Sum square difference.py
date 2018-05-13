#!/bin/python3

import sys


t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    ans = (n*(n+1)*((3*n*n)-n-2))/12
    print("{:.0f}".format(ans))
