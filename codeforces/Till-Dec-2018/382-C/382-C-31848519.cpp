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
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
inline double nextdouble(){double temporary; scanf("%lf",&temporary); return temporary;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
int leftChild(int p ){return p<<1;}
int rightChild(int p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
/*----------------------------------------------------------------------*/

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

  	int n;
  	cin>>n;

  	int arr[n];
  	vi ans;
  	
  	F(i, 0, n){
  		cin>>arr[i];
  	}
 		
  	sort(arr,arr+n);

  	if (n==1)
  	{
  		cout<<-1;
  		return 0;
  	}
  	if (n==2)
  	{
  		int diff= arr[1]-arr[0];
  		if (diff==0)
  		{
  			cout<<1<<endl<<arr[0];
  			return 0;
  		}

  		if (diff%2==0)
  		{
  			ans.push_back(arr[0]+(diff/2));
  		}
  		ans.push_back(arr[0]-diff);
  		ans.push_back(arr[1]+diff);
  	}else{
  		map<int,int>m;
  		F(i, 1, n){
  			m[arr[i]-arr[i-1]]++;
  		} 

  		int sz = m.size();

  		std::map<int, int>::iterator itr;

  		if (sz==1)
 		{
 			itr = m.begin();
 			if (itr->first ==0)
 			{
 				cout<<1<<endl<<arr[0];
 				return 0;
 			}

 			ans.push_back(arr[0]-itr->first);
 			ans.push_back(arr[n-1]+itr->first);
 		}else if (sz ==2)
 		{
 			vii p;
 			int minCountValue,maxCountValue;
			for(itr=m.begin();itr!=m.end();itr++){
				p.push_back(make_pair(itr->first,itr->second));
			}

			if(p[0].second==1||p[1].second==1){
				if(p[0].second==p[1].second){
					if(p[0].first<p[1].first){
						minCountValue=p[1].first;
						maxCountValue=p[0].first;
					}
				}
				else if(p[0].second<p[1].second){
					minCountValue=p[0].first;
					maxCountValue=p[1].first;
				}
				else{
					minCountValue=p[1].first;
					maxCountValue=p[0].first;
				}
				if(maxCountValue*2==minCountValue){
					F(i,1,n){
						if(arr[i]-arr[i-1]==minCountValue){
							ans.push_back(arr[i-1]+maxCountValue);
						}
					}
					
				}
				else{
					cout<<"0";
					return 0;
				}
			}
			else{
				cout<<"0";
				return 0;
			}
 		} 		
  	}

  	cout<<ans.size()<<endl;
  	sort(ans.begin(),ans.end());
  	F(i, 0, ans.size()){
  		cout<<ans[i]<<" ";
  	}


 	return 0;
}