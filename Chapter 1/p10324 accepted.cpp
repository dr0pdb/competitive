#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<string>
using namespace std;


int main()
{
	string s;
	int caseno=1;
	while ((cin>>s))
	{
		

		int n;
		cin>>n;

		
		cout<<"Case "<<caseno++<<":"<<endl;

		while (n-- !=0)
		{
			int a;
			int b;
			cin>>a>>b;
			bool issame=true;

			for (int  i = min(a,b)+1; i <=max(a,b); i++)
			{
				if (s[i] !=s[min(a,b)])
				{
					issame=false;
					break;
				}

			}

			if (issame)
			{
				cout<<"Yes"<<endl;
			}
			else
			{
				cout<<"No"<<endl;
			}


		}



	}



	return 0;
}

