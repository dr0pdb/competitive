#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n,d;
	cin>>n>>d;

	int songs[n];
	int sumtime=0;
	
	for (int i = 0; i <n; i++)
	{
		cin>>songs[i];
		sumtime+=songs[i];
	}	

	if (sumtime+(n-1)*10>d)
	{
		cout<<-1<<endl;
	}

	else
	{
		cout<<(d-sumtime)/5<<endl;
	}
	return 0;
}