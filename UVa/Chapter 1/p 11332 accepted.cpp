#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
using namespace std;

int sumofdigits(long n){

	int sum=0;

	while (n!=0)
	{	
		sum+=n%10;
		n=n/10;
	}	

	return sum;
}




int main()
{
	while (true)
	{
	long n;
	cin>>n;	

	if (n==0)
	{
		break;
	}
	
	int answer=n;

	while (n/10 !=0)
	{
		answer=sumofdigits(n);
		n=answer;
	}

	cout<<answer<<endl;
	
	}
	
	
	
	
	
	return 0;
}

