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
	while (true)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;

		if (x1==0 && y1==0 && x2==0 && y2==0)
		{
			break;
		}

		else
		{
			int nosteps;

			int diffx=abs(x2-x1);
			int diffy=abs(y2-y1);

			if ((diffx+diffy)==0)
			{
				cout<<0<<endl;
			}
			
			else if (diffx==diffy || diffx==0|| diffy==0)
			{
				cout<<1<<endl;
			}
			else
			{
				cout<<2<<endl;
			}

		}


	}

	



	return 0;
}

