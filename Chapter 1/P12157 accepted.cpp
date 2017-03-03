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
	int testcase=1;

	while (t-- !=0)
	{

		int n;
		cin>>n;
		int duration;

		int milecost=0;
		int juicecost=0;

		while (n-- !=0)
		{
			cin>>duration;

			milecost+=((duration/30)+1)*10;
			juicecost+=((duration/60)+1)*15;
		}

		cout<<"Case "<<testcase++<<": ";

		if (milecost<juicecost)
		{
			cout<<"Mile "<<milecost<<endl;
		}		
		else if (milecost==juicecost)
		{
			cout<<"Mile Juice "<<milecost<<endl;
		}
		else
		{
			cout<<"Juice "<<juicecost<<endl;
		}
	}


	return 0;
}

