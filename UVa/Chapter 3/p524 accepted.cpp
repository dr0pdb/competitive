#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;
int T = 0, n;
int circle[20];
bool used[20];
 
bool is_prime(int p) {
    for(int i = 2; i <= sqrt(p); i++)
        if(p % i == 0) return false;
    return true;
}
 
void search(int m) {
    if(m == n - 1 && is_prime(circle[n - 1] + circle[n])) {
        for(int i = 0; i < n; i++)
            printf(i == n - 1? "%d" : "%d ", circle[i]);
        printf("\n");
        return;
    }
    for(int i = 2; i <= n; i++)
        if(!used[i] && is_prime(circle[m] + i)) {
            used[i] = true;
            circle[m + 1] = i;
            search(m + 1);
            used[i] = false;
        }
}
 
int main() {
    while(scanf("%d", &n) == 1) {
        T++;
        if(T > 1) printf("\n");
        circle[0] = circle[n] = 1;
        printf("Case %d:\n", T);
        search(0);
    }
}

/*
 * 
 * #include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;
bool isPrime[17]={false};
std::vector<int> v;

void solve(int n, bool used[]){
	if (v.size() == n)
	{
        if(isPrime[1 + v[n-1]]){
            for (int i = 0; i < n; ++i)
            {
                if (!i)
                {		
                    cout<<v[i];
                }else{
                    cout<<" "<<v[i];
                }
            }
		cout<<"\n";
        }
		return;
	}

	for (int i = 2; i <= n; ++i)
	{
		if (isPrime[v[v.size()-1] + i ] && !used[i])
		{
			used[i]=true;
			v.push_back(i);
			solve(n,used);
            v.pop_back();
			used[i]=false;
		}
	}
}

int main(){
	
	isPrime[1]=true;
	isPrime[2]=true;
	isPrime[3]=true;
	isPrime[5]=true;
	isPrime[7]=true;
	isPrime[11]=true;
	isPrime[13]=true;
	int n,count=0;
	while(cin>>n && n){
		bool used[n+1]={false};
        v.clear();
        v.push_back(1);
		used[0]=true;
		used[1]=true;
		cout<<"Case "<<++count<<":"<<"\n";
		solve(n,used);
		cout<<"\n";
	}	
	return 0;
}
 * 
 * */
