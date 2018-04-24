#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
using namespace std;


int main()
{

	int t;
	cin>>t;

	while (t-- !=0)
	{
		int n;
		cin>>n;

		int position=0;
		int moves[n];
		string s;
		int check;

		for (int i = 0; i < n; i++)
		{
			cin>>s;

			if (s[0]=='R')
			{
				position+=1;
				moves[i]=1;

			}
			else if (s[0]=='L')
			{
				position+=-1;
				moves[i]=-1;
			}

			else
			{
				cin>>s;
				cin>>check;
				position+=moves[check-1];
				moves[i]=moves[check-1];

			}


		}

			cout<<position<<endl;	


	}


	
	return 0;
}

