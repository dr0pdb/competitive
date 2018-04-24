#!/bin/python3

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    hasanswer=False
    maximum=0
    for a in range(1,n//3+1):
        b=((n*n)-2*n*a) // (2*(n-a))
        c=((n*n)+(2*a*a)-(2*n*a)) // (2*(n-a))
        if ((n*n)-2*n*a) / (2*(n-a)) == b and b>a and c>b:
            if ((n*n)+(2*a*a)-(2*n*a))/(2*(n-a)) == c :
                hasanswer=True
                if maximum < a*b*c:
                    maximum=a*b*c
    if hasanswer:
        print("{:.0f}".format(maximum))
    else:
        print(-1)

'''
	The Following code got timeout in test case 5
	#!/bin/python3

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    hasanswer=False
    maximum=0
    for a in range(1,n):
        b=((n*n)-2*n*a) // (2*(n-a))
        c=((n*n)+(2*a*a)-(2*n*a)) // (2*(n-a))
        if ((n*n)-2*n*a) / (2*(n-a)) == b:
            if ((n*n)+(2*a*a)-(2*n*a))/(2*(n-a)) == c and b>a and c>b:
                hasanswer=True
                if maximum < a*b*c:
                    maximum=a*b*c
    if hasanswer:                
        print("{:.0f}".format(maximum))
    else:
        print(-1)


'''
