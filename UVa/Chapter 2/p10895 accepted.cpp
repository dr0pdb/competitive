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

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	int r,c;
	while(cin>>r>>c){
		int graph[r][c];
		memset(graph,0,sizeof(graph));

		F(i, 0, r){
			int t,x;
			cin>>t;
			vi v;

			if (t){
				
				F(j, 0, t){
					cin>>x;
					x--;
					v.push_back(x);
				}
				F(j, 0, t){
					cin>>x;
					graph[i][v[0]]=x;
					v.erase(v.begin());
				}
			}else{
				cin.ignore();
			}
			
		}

		cout<<c<<" "<<r<<"\n";
		F(j, 0, c){
			vii v;
			F(i, 0, r){
				if (graph[i][j]!=0)
				{
					v.push_back(ii(i,graph[i][j]));
				}
			}
			if (!v.size())
			{
				cout<<0<<"\n\n";
			}else{
				cout<<v.size();
				F(i, 0, v.size()){
					cout<<" "<<v[i].first+1;
				}
				cout<<"\n";
				F(i, 0, v.size()){
					if (!i)
					{
						cout<<v[i].second;
					}else{
						cout<<" "<<v[i].second;	
					}
				}
				cout<<"\n";
			}
		}

	}	

	return 0;
}