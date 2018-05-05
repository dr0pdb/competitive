#include<bits/stdc++.h>
using namespace std;


int main()
{

	int n,s,t;

	cin>>n>>s>>t;

	int p[n+1];

	for (int i = 1; i <=n; i++)
	{

		cin>>p[i];	
	}	

	int steps=0;

	while (s!=t && p[s]!=0)
	{
		int temp=p[s];
		p[s]=0;
		s=temp;
		steps++;
	}

	if (s==t)
	{
		cout<<steps<<endl;

	}

	else
	{
		cout<<-1<<endl;
	}
	return 0;
}