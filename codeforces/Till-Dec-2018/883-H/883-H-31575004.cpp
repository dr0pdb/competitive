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
char rechar(int i)
{
	if(i>=0&&i<=25)
		return 'A'+i;
	if(i>=26&&i<=51)
		return 'a'+(i -26);
	if(i>=52&&i<=61)
		return '0'+(i -52);
}
int main()
{
	int ch[65]={};
	ll n,i,j,k;
	string s;
	cin>>n;
	cin>>s;
	FOR0(i,n)
	{
	      if(s[i]>='A'&&s[i]<='Z')
			  ch[s[i]-'A']++;
		  else if( s[i] >='a'&&s[i]<='z')
			  ch[26+s[i]-'a']++;
		  else
			  ch[52+s[i]-'0']++;
	}
	vi centers;
	ll np=0;
	FOR0(i,62)
	{
		if(ch[i]%2!=0)
		{
			centers.pb(i);
			ch[i]--;
			np++;
		}
	}
	if(np==0)
	{
		cout<<1<<endl;
		ll mid=n/2;
		string out ;
		FOR0(j,mid)
		{
			FOR0(k,62)
			{
				if(ch[k]>0)
				{
					ch[k]-=2;
					out.pb(rechar(k));
					break;
				}
				
			}
		}
		for(j=1;j+mid<=n;j++)
		{
			out.pb(out[mid-j]);
		}
         cout<<out;
		 return 0;
	}
	while(!(n%np==0&&(n/np)%2!=0))
	{
		FOR0(i,62)
		{
			if(ch[i]>0)
			{
				centers.pb(i);
				centers.pb(i);
				ch[i]-=2;
				np+=2;
				if(n%np==0&&(n/np)%2!=0)
					break;
			}
		}
	}
	ll sp= n/np;
    cout<<np<<endl;
	FOR0(i,centers.size())
	{
		string out ;
		ll mid=sp/2;
		FOR0(j,mid)
		{
			FOR0(k,62)
			{
				if(ch[k]>0)
				{
					ch[k]-=2;
					out.pb(rechar(k));
					break;
				}
				
			}
		}
		out.pb(rechar(centers[i]));
		for(j=1;j+mid<sp;j++)
		{
			out.pb(out[mid-j]);
		}
         cout<<out<< " ";
	
	}
	
}