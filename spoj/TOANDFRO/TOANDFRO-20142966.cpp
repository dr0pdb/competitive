#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define MOD 1000000000+7
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	int col;
	string s;
	while(cin>>col && col){
		cin>>s;
		vector<string> ans;

		int index=0,turn=1;
		while(index<s.length()){
			if (turn%2)
			{
				ans.push_back(s.substr(index,col));
			}else{
				string temp = s.substr(index,col);
				reverse(temp.begin(),temp.end());
				ans.push_back(temp);
			}
			
			index+=col;
			turn++;
		}
		F(j, 0, ans[0].size()){
			F(i, 0, ans.size()){
				cout<<ans[i][j];
			}
		}
		
		cout<<"\n";
	}
	return 0;
}