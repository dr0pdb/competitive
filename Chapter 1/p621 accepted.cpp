#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
using namespace std;


int main()
{
	int n;
	cin>>n;
	
	while (n-- !=0)
	{
		string in;
		cin>>in;

		if (in=="1"|| in=="4"|| in=="78")
			{
				cout<<'+'<<endl;
			}
	
		else
		{
			int length=in.length();

			if (in[length-1]=='5' && in[length-2]=='3')
			{
				cout<<'-'<<endl;
			}

			else if (in[0]=='9' && in[length-1]=='4')
			{
				cout<<'*'<<endl;
			}

			else 
			{
				cout<<'?'<<endl;
			}

		}

	}
	
	

	return 0;
}

