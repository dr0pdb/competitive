#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int gcd(int a, int b)
{
    if (a == 0 || b == 0)
       return 0;
 
    if (a == b)
        return a;
    
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}
int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	int n;
	cin>>n;

	int a=n/2,b=n-a;
	while(gcd(a,b) != 1){
		a--;
		b++;
	}
	cout<<a<<" "<<b;
	return 0;
}