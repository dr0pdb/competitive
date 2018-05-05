#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define MOD 1000000000+7
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

ll merge(ll arr[], ll temp[], ll left, ll mid, ll right)
{
  ll i, j, k;
  ll inv_count = 0;
 
  i = left; 
  j = mid; 
  k = left; 
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
 
      inv_count = inv_count + (mid - i);
    }
  }

  while (i <= mid - 1)
    temp[k++] = arr[i++];

  while (j <= right)
    temp[k++] = arr[j++];
 
  for (i=left; i <= right; i++)
    arr[i] = temp[i];
 
  return inv_count;
}


ll countInv(ll arr[],ll temp[],ll left,ll right){
	ll mid, inv_count = 0;
	  if (right > left)
	  {
	    mid = (right + left)/2;
	 
	    inv_count  = countInv(arr, temp, left, mid);
	    inv_count += countInv(arr, temp, mid+1, right);
	 
	    inv_count += merge(arr, temp, left, mid+1, right);
	  }
	  return inv_count;
}	

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	ll t,n;
	cin>>t;

	while(t--){
		cin>>n;
		ll arr[n];
		F(i, 0, n){
			cin>>arr[i];
		}
		cin.ignore();
		ll temp[n];
		ll ans = countInv(arr,temp,0,n-1);
		cout<<ans<<"\n";
	}

	return 0;
}