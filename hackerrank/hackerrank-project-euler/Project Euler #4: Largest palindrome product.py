#!/bin/python3

import sys
import math

palindromes = []

def ispalindrome(k):
    strep = str(k)
    numlen = math.floor(math.log(k,10)) +1
    ispal = True
    for i in range(0,(numlen+1)//2):
        if strep[i] != strep[-i-1]:
            ispal = False
            break
    return ispal

for i in range (100 ,1000):
    for j in range (100,1000):
        if ispalindrome(i*j) == True:
            palindromes.append(i*j)
palindromes.sort()
t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    index = len(palindromes)-1
    while palindromes[index] >= n:
        index -= 1
    print(palindromes[index+1])

