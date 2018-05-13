#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);
	
	ll n,l,u;
	while(cin>>n>>l>>u){
		ll ans=0;
		RF(i, 32, 0){
			ll bit = (n & (1L<<i));
			if (bit)
			{
				ll temp = bit-1;
				//turning the bit off
				temp |= ans;
				if (temp < l)
				{
                    //turning the bit on
					ans |= bit;
				}
			}else{
				ll temp = ans;
				temp |= (1L<<i);
				if (temp <= u)
				{
					ans = temp;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

