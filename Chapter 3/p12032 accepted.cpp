#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;
int rung[100000];
int n;

bool tryPower(int high){
	if (rung[0]>high)
	{
		return false;
	}
	if (rung[0]==high)
	{
		high--;
	}
	for (int i = 1; i < n; ++i)
	{	
		if (rung[i]-rung[i-1] > high)
		{
			return false;
		}
		if (rung[i]-rung[i-1] == high)
		{
			high--;
		}
		if (high <= 0)
		{
			return false;
		}
	}
	return true;
}

int main(){
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;

	for (int i = 1; i <=t; ++i)
	{
		cin>>n;
		for (int j = 0; j < n; ++j)
		{
			cin>>rung[j];
		}

		int low=0,high=10000001;
		while(high - low > 0){
			if (tryPower(high))
			{
				high = low + (high - low)/2;
			}
			else{
				low = high;
				high = high + high/2;
			}
		}

		cout<<"Case "<<i<<": "<<high+1<<"\n";
	}
	return 0;
}