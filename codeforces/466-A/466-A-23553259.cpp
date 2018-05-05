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

	int n,m,a,b;
	cin>>n>>m>>a>>b;

	if (a*m>b)
	{
		int remainingcost=(n%m)*a;

		if (remainingcost>b)
		{
			cout<<(n/m)*b+b<<endl;
		}
		else
		{
			cout<<(n/m)*b+remainingcost<<endl;
		}
	}

	else
	{
		cout<<a*n<<endl;
	}



	return 0;
}