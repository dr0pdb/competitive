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

		int total=0;

		while (n-- !=0)
		{
			int sizefarmyard,noanimals,degree;
			cin>>sizefarmyard>>noanimals>>degree;

			total+=sizefarmyard*degree;
		}

		cout<<total<<endl;

	}


	return 0;
}

