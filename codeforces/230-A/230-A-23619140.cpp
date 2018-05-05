#include<bits/stdc++.h>
using namespace std;


int main()
{
	
	int s,n;
	cin>>s>>n;


	int poweropp;
	int bonus;
	
	vector<pair<int,int> > dragons;
	for (int i = 0; i < n; i++)
	{
		cin>>poweropp;
		cin>>bonus;

		dragons.push_back(pair<int,int> (poweropp,bonus));
	}

	sort(dragons.begin(), dragons.end());

	bool ispossible=true;

	for (int i = 0; i < n; i++)
	{
		if (s>dragons[i].first)
		{
			s+=dragons[i].second;
		}

		else
		{
			ispossible=false;
			break;
		}
	}

	if (ispossible)
	{
		cout<<"YES"<<endl;
	}

	else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}