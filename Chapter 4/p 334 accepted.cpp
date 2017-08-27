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

	int nc,tn=1;
	while(cin>>nc && nc){
		std::map<string, int> si;
		std::vector<string> is;
		int adjlist[200][200]={0};
		int ne,index=0;

		F(i, 0, nc){
			cin>>ne;
			string s;
			std::vector<int> curr;
			F(j, 0, ne){
				cin>>s;
				si[s]=index;
				is.push_back(s);

				F(k, 0, curr.size()){
					//adjlist[index][curr[k]]=1;
					adjlist[curr[k]][index]=1;
				}
				curr.push_back(index);
				index++;
			}
		}

		int nm;
		cin>>nm;

		string a,b;
		F(i, 0, nm){
			cin>>a>>b;
			adjlist[si[a]][si[b]]=1;
			//adjlist[si[b]][si[a]]=1;
		}

		F(k, 0, index){
			F(i, 0, index){
				F(j, 0, index){
					adjlist[i][j] |= (adjlist[i][k] & adjlist[k][j]);
				}
			}
		}

		vii conc;
		int ans=0;
		F(i, 0, index){
			F(j, i+1,index ){
				if (adjlist[i][j]==0 && adjlist[j][i]==0)
				{
					conc.push_back(ii(i,j));
					ans++;
				}
			}
		}
		if (!ans)
		{
			cout<<"Case "<<tn++<<", no concurrent events.\n";
		}else{
			cout<<"Case "<<tn++<<", "<<ans<<" concurrent events:\n";
			F(i, 0, conc.size()){
				ii temp = conc[i];
				cout<<"("<<is[temp.first]<<","<<is[temp.second]<<") ";
				if (i==1)
				{
					break;
				}
			}
			cout<<"\n";
		}
		
	}
	

	return 0;
}