//To find x = (1/a) (mod m)  NOTE: It only exists when 'a' and 'm' are co-prime i.e. gcd(a,m) = 1

//Method 1. General case using euclid's extended algorithm , works all the time (inverse should exist though)


//solve a*x+b*y = gcd(a,b) i.e finds x,y and returns gcd
ll gcdExtended (ll a, ll b, ll & x, ll & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

ll modInverse(ll a, ll m){
	ll x, y;
	gcdExtended (a, m, x, y);              
	return ((x % m + m) % m);             //gcd should be one only!
}




//Method 2. When m is a prime, we can use euler's theorem with fermat's little theorem.


//return x^y mod m
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


//Method 3. Recommended in most cases.

ll euler_phi(ll n){
	ll phi[n+1];

	for (ll i = 1; i <= n; ++i) {
	  phi[i] += i;
	  for (ll j = 2 * i; j <= n; j += i) {
		phi[j] -= phi[i];
	  }
	}
	return phi[n];
}

ll modInverse(ll a, ll m){
	return power(a,euler_phi(m)-1,m);
}


// Generate modulo inverse for all numbers between 1 to m-1. 
// m must pe prime.
inv[1] = 1;
for(int i = 2; i < m; ++i)
    inv[i] = (m - (m/i) * inv[m%i] % m) % m;
