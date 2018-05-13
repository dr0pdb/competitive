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
	
	vi ans;
	int n,x;

	while(cin>>n && n){
		ans.clear();
		F(i, 0, n){
			cin>>x;
			if (x)
			{
				ans.push_back(x);
			}		
		}

		if (ans.size())
		{
			F(i, 0, ans.size()){
				if (!i)
				{
					cout<<ans[i];
				}else{
					cout<<" "<<ans[i];
				}
			}	
		}else{
			cout<<0;
		}

		
		cout<<"\n";
	}
	return 0;
}

