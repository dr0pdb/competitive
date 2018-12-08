#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<bits/stdc++.h>
#include<queue>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
inline long long  MAX2(long long  a, long long int b){return (a)>(b)?(a):(b);}
inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN2(long long  a, long long  b){return (a)<(b)?(a):(b);}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
vector < set<int> > graph(105);
vector<int> temp;
int visited[105]={};
int k=0;
int indegree[105]={};
void dfs(int i)
{
     if(visited[i]==1)return;
     visited[i]=1;
     temp.push_back(i);
     if(graph[i].size())
     {
          dfs(*graph[i].begin());
     }
}
int main()
{
     int inl[105],inr[105],outl[105],outr[105],l;
     int n,i,j,flag=0,flag1=0,flag2=0; 
     int nl=0;
     list<int> ::iterator it;
     cin>>n;	
     FOR(i,1,n+1)
     {
     	cin>>inl[i]>>inr[i];
          if(inl[i])
          {graph[inl[i]].insert(i);
               indegree[i]++;
          }
          if(inr[i])
          {
               graph[i].insert(inr[i]);
               indegree[inr[i]]++;
          }
          if(!inl[i])flag1++;
          if(!inr[i])flag2++;
     }
     if(flag1==1&&flag2==1)
     FOR(i,1,n+1)
     {cout<<inl[i]<<" "<<inr[i]<<endl; 
     }
     else 
     {
          memset(visited,0,sizeof visited);
     FOR(i,1,n+1)
     {
     	if(indegree[i]==0)
               {
                   dfs(i);
               }
     }
     FOR0(i,temp.size())
     {
     	if(i!=0)
     		outl[temp[i]]=temp[i-1];
     	else outl[temp[i]]=0;
     	if(i+1<temp.size())
     		outr[temp[i]]=temp[i+1];
     	else outr[temp[i]]=0;
     }
     FOR(i, 1, n+1)
     {
     	cout<<outl[i]<<" "<<outr[i]<<endl; 
     }
     } 
     return 0 ;

}