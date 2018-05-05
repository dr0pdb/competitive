/*
ID: ashish1610
PROG:
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int ar[n][m], ans[n][m];
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			ans[i][j]=1;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			cin>>ar[i][j];
			if(ar[i][j]==0)
			{
				for(int k=0;k<n;++k)
					ans[k][j]=0;
				for(int k=0;k<m;++k)
					ans[i][k]=0;
			}
		}
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(ar[i][j]==1)
			{
				bool flag=false;
				for(int k=0;k<n;++k)
					if(ans[k][j])
						flag=true;
				for(int k=0;k<m;++k)
					if(ans[i][k])
						flag=true;
				if(!flag)
				{
					cout<<"NO\n";
					return 0;
				}
			}
		}
	}
	cout<<"YES\n";
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}