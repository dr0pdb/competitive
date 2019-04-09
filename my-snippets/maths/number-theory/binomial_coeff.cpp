const int MAXN = 1005;

ll comb[MAXN][MAXN];

void findCoeff(){
	comb[0][0] = 1;
	for (int i = 1; i < MAXN; i++) {
    	comb[i][0] = 1;
    	for (int j = 1; j <= i; j++) {
      		comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
    	}
	}	
}


const int MAXN = 1e6+1;
ll factorial[MAXN];
factorial[0] = 1;
for (int i = 1; i <= MAXN; i++) {
    factorial[i] = factorial[i - 1] * i % MOD;
}

ll power(ll x,ll y, ll p)
{
    ll res = 1;     
    x = x % p; 
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
 
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}

ll modInverse(ll a, ll m){
	return power(a,m-2,m);
}

ll binomial_coefficient(ll n, ll k) {
    return factorial[n] * modInverse(factorial[k], MOD) % MOD * modInverse(factorial[n - k], MOD) % MOD;
}


/*
    Code snippet for finding binomial coefficients. MOD should be prime.
*/
const int MAXN = 2e6+5;
ll factorial[MAXN], inverse[MAXN];

ll power(ll x,ll y, ll p)
{
    ll res = 1;     
    x = x % p; 
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
 
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}

ll modInverse(ll a, ll m){
    return power(a,m-2,m);
}

void pre() {
    factorial[0] = 1LL; inverse[0] = modInverse(factorial[0], MOD);
    for (int i = 1; i < MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
        inverse[i] = modInverse(factorial[i], MOD);
    }
}

ll binomial_coefficient(ll n, ll k) {
    return factorial[n] * inverse[k] % MOD * inverse[n - k] % MOD;
}
