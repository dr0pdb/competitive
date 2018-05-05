#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

//clockwise order
int state[4]={118,60,94,62};

int remainder(int a, int b)
{
    return a - (a / b) * b;
}
int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}

int main(){
	std::ios::sync_with_stdio(false);
    char a,b;
	int init,last;
	cin>>a>>b;
    init = (int)a;
    last = (int)b;   
    
	long long n;
	cin>>n;

	F(i, 0, 4){
		if (state[i] == init)
		{
			init = i;
		}
		if (state[i] == last)
		{
			last = i;
		}
	}

	if ((init + n)%4 == last && mod(init-n,4) == last)
	{
		cout<<"undefined";
	}else if(mod(init-n,4) == last){
		cout<<"ccw";
	}else if((init + n)%4 == last ){
		cout<<"cw";
	}
	return 0;
}