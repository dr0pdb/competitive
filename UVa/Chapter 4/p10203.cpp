#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
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
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int leftChild(int p ){return p<<1;}
int rightChild(int p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
/*----------------------------------------------------------------------*/

double dist(double a, double b ,double c ,double d){
	return sqrt(pow(abs(c-a),2) + pow(abs(d-b),2));
}

void print(double total){
	int temp,hr,min;
	temp = int(total/20*60 + 0.5);
	hr = temp/60;
	min = temp%60;
	printf("%d:%02d\n", hr,min);
}

int main(){
 	// std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

 	int t = nextint();
 	F(tn, 0, t){
 		if (tn)
 		{
 			printf("\n");
 		}
 		int start[2];
 		scanf("%d %d",start,start+1);

 		string s;
 		getline(cin, s);
 		double total=0;

 		while(getline(cin,s) && !s.empty()){
 			istringstream iss(s);
 			int x1,y1,x2,y2;
 			iss>>x1>>y1>>x2>>y2;

 			total+=2*dist((double)x1/1000.000,(double)y1/1000.0,(double)x2/1000.0,(double)y2/1000.0);
 		}

 		print(total);
 	}

	return 0;
}

