#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<string>
using namespace std;


bool possible(bool s[],int length){

	for (int i = 0; i < length; i++)
	{
		if (s[i]==false)
		{
			return false;
			
		}
	}
	return true;

}





int main()
{
	int n;
	cin>>n;

	bool ispresent[n]={0};
	int p;
    cin>>p;
    
    int level;
	while (p-- !=0)
	{
		cin>>level;
		ispresent[level-1]=true;

	}
    
	int q;
	cin>>q;
	while (q-- !=0)
	{
		cin>>level;
		ispresent[level-1]=true;

	}
	
	bool ispossible=possible(ispresent,n);

	if (ispossible)
	{
		cout<<"I become the guy."<<endl;	
	}
	else
	{
		cout<<"Oh, my keyboard!"<<endl;
	}

	return 0;
}