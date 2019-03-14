/*
	For single query
*/

ll _sieve_size;
bitset<10000010> bs;
vi primes;

vi primeFactors(ll N) {
	vi factors;
	ll PF_idx = 0, PF = primes[PF_idx];
	while (PF * PF <= N) {
		
		while (N % PF == 0) { N /= PF; factors.push_back(PF); }
			
		PF = primes[++PF_idx];
		
	}
	if (N != 1) factors.push_back(N);

	return factors;
}

void sieve(ll upperbound) {
	
	_sieve_size = upperbound + 1;
	
	bs.set();
	bs[0] = bs[1] = 0;
	
	for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
		
		for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
		primes.push_back((int)i);
		
	} 
}


/*
	For calculating factors for a large set of numbers use sieve.
*/
const int MAXN = 100001; 
  
// stores smallest prime factor for every number 
int spf[MAXN];
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
        spf[i] = i; 
  
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
  
vector<int> getFactorization(int x) 
{ 
    vector<int> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
}

/*
	For calculating only the factors and not their powers use this.
*/
vi factors[1000001];
bitset<1000001> bs;
void sieve() {
	bs.set(); bs[0] = bs[1] = 0;
	for(int i = 2; i < 350; i++) {if(bs[i]) {
		for(int j = i; j < 1000001; j+=i) {bs[j] = 0; factors[j].pb(i);}
	}}
}
