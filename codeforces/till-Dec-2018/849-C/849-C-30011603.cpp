#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	int k;
	cin>>k;

	string s;
	cin>>s;

	F(i, 0, 26){
		int cnt = 1;
		while(cnt*(cnt+1)/2 <= k)cnt++;
		k-=cnt*(cnt-1)/2;
        F(j, 0, cnt){
			cout<<(char)('a'+i);
		}
        if(!k){
            break;
        }
	}

	return 0;
}