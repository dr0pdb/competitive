#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bits/stdc++.h>
#include<queue>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define pb push_back
inline long long  MAX2(long long  a, long long int b){return (a)>(b)?(a):(b);}
inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN2(long long  a, long long  b){return (a)<(b)?(a):(b);}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector< pair<int,int> > vii;
typedef long long ll;
int main()
{
	int n,i,j,m,k;
	int a[27]={};
	int words[1005][27]={};
	cin>>n;
	string in;
	string st;
	vector < string > w;
	cin>>st;
	FOR0(i,n)
	{
		if(st[i]>='a'&&st[i]<='z')
			a[st[i]-'a']=1;
	}
	cin>>m;
	FOR0(i,m)
	{
		in.clear();
		cin>>in;
		w.pb(in);
		FOR0(j,n)
		{
			words[i][in[j]-'a']=1;
		}
	}
	vi out;
	FOR0(i,m)
	{
			FOR0(k,n)
			{
				if(st[k]=='*'&& a[w[i][k]-'a']==1)
					break;
				else if(st[k]!='*'&&(st[k]!=w[i][k]))
					break;
			}
			if(k==n)
				out.pb(i);
	}
	int ans=0;
	FOR0(j,26)
	{
		if(a[j]==1)continue;
		FOR0(i,out.size())
		{
			if(words[out[i]][j]==0)
				break;
		}
		if(i==out.size())ans++;
	}
	cout<<ans;
	
}