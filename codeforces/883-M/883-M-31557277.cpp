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
	ll x1,y1,x2,y2;
	cin>>x1>>y1 >>x2>>y2;
	ll xdis= labs(x1-x2) +1;
	if(xdis==1)xdis++;
	ll ydis = labs(y1-y2)+1;
	if(ydis==1)ydis++;
	ll ans = 2*xdis + 2*ydis ;
	cout<<ans;
}