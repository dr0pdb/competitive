#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define SIEVELIM 1000000+10
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
 	// std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	while(cin>>n){

		ll dig = (ll)log10(n)+1;
		int arr[dig];
		F(i, 0, dig){
			arr[i]=n%10;
			n/=10;
		}
		sort(arr,arr+dig,greater<ll>());
		ll sorted = 0;
		ll isorted = 0;
		ll multiplier=1;
		RF(i, dig-1, 0){
			sorted+=(arr[i]*multiplier);
			multiplier*=10;
		}
		int index = dig-1;
		while(arr[index]==0){
			index--;
		}

		int temp = arr[dig-1];
		arr[dig-1] = arr[index];
		arr[index] = temp;

		multiplier=1;
		F(i, 0, dig){
			isorted +=arr[i]*multiplier;
			multiplier*=10;
		}

		printf("%lld - %lld = %lld = 9 * %lld\n",sorted,isorted,sorted-isorted,(sorted-isorted)/9);
	}
	
	return 0;
}