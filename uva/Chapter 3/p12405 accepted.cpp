#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;

int main(){
	int t;
	cin>>t;

	for (int i = 1; i <= t; ++i)
	{
		int n;
		cin>>n;
		int count=0;

		char field[n];
		for (int j = 0; j < n; ++j)
		{
			cin>>field[j];
		}

		for (int j = 0; j < n; ++j)
		{
			if (field[j] == '.')
			{
				count++;
				field[j]='#';
				field[j+1]='#';
				field[j+2]='#';
			}
		}

		cout<<"Case "<<i<<": "<<count<<"\n";
	}
	return 0;
}