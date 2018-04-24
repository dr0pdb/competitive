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
	
	cout<<"Lumberjacks:"<<endl;

	while (t-- !=0)
	{
		int n1,n2;
		cin>>n1;

		bool up=false;
		bool down=false;
		for (int i = 0; i < 9; i++)
		{
			cin>>n2;

			if (n1>n2)
			{
				down=true;
			}
			else
			{
				up=true;
			}
			n1=n2;
		}
	
		if (up && down)
		{
			cout<<"Unordered"<<endl;
		}
        else
     	{
			 cout<<"Ordered"<<endl;
		}

		}


	return 0;
}

