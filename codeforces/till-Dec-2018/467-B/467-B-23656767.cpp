#include<bits/stdc++.h>
using namespace std;


int main()
{

	int n,m,k;
	cin>>n>>m>>k;

	int army[m];
	for (int i = 0; i < m; i++)
	{
		cin>>army[i];
	}

	int fedorarmy;
	cin>>fedorarmy;
	int counter=0;
	for (int i = 0; i < m; i++)
	{
		int t=fedorarmy^army[i];

		int a = __builtin_popcount (t);
		if (a<=k)
		{
			counter++;
		}

	}
	cout<<counter<<endl;
	return 0;
}