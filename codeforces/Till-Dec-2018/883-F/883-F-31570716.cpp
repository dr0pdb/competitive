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
	int n,i,j;
	string in;
	cin>>n;
	set < string > s;
	FOR0(i,n)
	{
		cin>>in;
		string out;
		FORD(j,in.size()-1,0)
		{
				if(j>0&&in[j]=='h'&&in[j-1]=='k')
				{
					in[j]='0';
					in[j-1]='h';
				}
		}
		FOR0(j,in.size())
		if(in[j]!='0')
			out+=in[j];
		string temp;
		FOR0(j,out.size())
		{
			if(out[j]=='u')
				temp+="oo";
			else temp+=out[j];
		}
		s.insert(temp);
	}
	cout<<s.size();
	
}