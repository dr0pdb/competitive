#!/bin/python3

import sys
import math

primes = [True]*1000001

primes[1]=False
for i in range(2,1001):
    if primes[i] == True:
        for j in range(i*i , 1000001 , i ):
            primes[j]=False

sum = [0]*1000001
sum[1]=0
for i in range(1,1000001):
    if primes[i]==True:
        sum[i]=sum[i-1]+i
    else:
        sum[i]=sum[i-1]
        
t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    print(sum[n])
