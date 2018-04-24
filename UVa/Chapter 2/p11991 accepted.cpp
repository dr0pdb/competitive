#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

int main(){
	std::ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m){

		vector<vi > adjlist(1000010);
		int x;
		F(i, 0, n){
			cin>>x;
			adjlist[x].push_back(i+1);
		}

		int k,v;
		while(m--){
			cin>>k>>v;
			if (adjlist[v].size() < k)
			{
				cout<<0<<"\n";
			}else{
				cout<<adjlist[v][k-1]<<"\n";
			}
		}
	}
	
	return 0;
}

