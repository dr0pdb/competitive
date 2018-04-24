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
