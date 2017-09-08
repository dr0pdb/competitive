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
	//std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	int t,n,distance;

	cin>>t;

	F(tn, 1, t+1){
        cin>>n>>distance;
	    vector<pair<char,int> > arr;
		arr.push_back(make_pair('B',0));
		bool used[n+2];
		memset(used, false, n+2);
		char c,temp;
		int d;
		F(i, 0, n){
			cin>>c>>temp>>d;
			arr.push_back(make_pair(c, d));
		}
		arr.push_back(make_pair('B',distance));
		int ans=-1;
		int index=0;
		pair<char, int> curr = arr[0];
		while(index<=n+1){
			if (arr[index].first == 'S')
			{
				index++;	
			}
            if(index<=n+1){
                ans = MAX(ans, arr[index].second-curr.second);
                used[index]=true;
                curr = arr[index];
                
            }
            index++;
		}
		index = n+1;
		curr = arr[n+1];
		while(index>=0){
			if (arr[index].first == 'S' && used[index])
			{
				index--;
				continue;
			}else{
				ans = MAX(ans,curr.second-arr[index].second);
				curr = arr[index];
				index--;
			}
		}

		cout<<"Case "<<tn<<": "<<ans<<"\n";
	}
	return 0;
}