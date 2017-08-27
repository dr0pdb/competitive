#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

#define INF 1000000000

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	int p,r,tn=1;
	
	while(cin>>p>>r && p && r){
		int adjmat[p+5][p+5];

		F(i, 0, p){
			F(j, 0, p){
				adjmat[i][j]=INF;
			}
		}

		map<string, int> si;
		string is[50];
		int index=0;

		string a,b;
		F(i, 0, r){
			cin>>a>>b;
			if (si.find(a) == si.end())
			{
				is[index]=a;
				si[a]=index++;
			}

			if (si.find(b) == si.end())		
			{
				is[index]=b;
				si[b]=index++;
			}

			adjmat[si[a]][si[b]]=1;
			adjmat[si[b]][si[a]]=1;
		}

		F(k, 0, p){
			F(i, 0, p){
				F(j, 0, p){
					adjmat[i][j] = min(adjmat[i][j],adjmat[i][k]+adjmat[k][j]);
				}
			}
		}

		int deg=-1;
		bool disc=false;
		F(i, 0, p){
			F(j, i+1, p){
				if (adjmat[i][j] == INF)
				{
					disc = true;
					break;
				}else{
					deg = max(deg,adjmat[i][j]);
				}
			}
		}
		cout<<"Network "<<tn++<<": ";
		if (disc)
		{
			cout<<"DISCONNECTED\n";
		}else{
			cout<<deg<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}