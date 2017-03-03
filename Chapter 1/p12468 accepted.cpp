#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
using namespace std;


int main()
{
	
	while (true)
	{
	int a;
	int b;
	cin>>a>>b;

	if (a==-1 && b==-1)
	{
		break;
	}


	cout<<min(abs(b-a),100-abs(a-b))<<endl;

	
	}

	
	return 0;
}

