#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define SIEVELIM 10000000+10
#define MOD 1000000000+7
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	int n;
	while(cin>>n && n){
		stack<int> s;
		
		vi num(n);
		F(i, 0, n){
			cin>>num[i];
		}
		bool poss=true;
		int index=0,curr=1;
		while(index<n){
			if (num[index]==curr)
			{
				index++;
				curr++;
			}else{
				if (s.size() && s.top()==curr)
				{
					curr++;
					s.pop();
				}else if (num[index]>curr)
				{
					s.push(num[index]);
					index++;
				}else{
					poss = false;
					break;
				}

			}
		}

		while(!s.empty()){
			if (s.top()==curr)
			{
				s.pop();
				curr++;
			}else{
				poss = false;
				break;
			}
		}

		if (poss)
		{
			cout<<"yes"<<"\n";
		}else{
			cout<<"no\n";
		}
	}
	return 0;
}