#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define mes(i,a) memset(a,i,sizeof(a))
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

int main(){
	std::ios::sync_with_stdio(false);
	
	int n,k;
	cin>>n>>k;

	int id[n],ad[n];
	F(i, 0, n){
		cin>>id[i];
	}

	F(i, 0, n){
		cin>>ad[i];
	}

	vector<ii>pairs;
	F(i, 0, n){
		pairs.push_back(ii(i,id[i]-ad[i]));
	}
	sort(pairs.begin(),pairs.end(),sortbysec);
	
	ll ans=0;

	F(i, 0, pairs.size()){
		if(i<k){
			ans+=id[pairs[i].first];
		}else if(pairs[i].second <=0){
			ans+=id[pairs[i].first];
		}else{
			ans+=ad[pairs[i].first];
		}	
	}
	cout<<ans;
	return 0;
}