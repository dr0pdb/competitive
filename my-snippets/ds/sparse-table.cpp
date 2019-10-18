/*
	Range sum query
*/
const int MAXN = 1e6+1;
const int K = 35;
int N;
long long st[MAXN][K];

void pre(int array[]) {
	for (int i = 0; i < N; i++)
    	st[i][0] = array[i];

	for (int j = 1; j <= K; j++)
	    for (int i = 0; i + (1 << j) <= N; i++)
	        st[i][j] = st[i][j-1] + st[i + (1 << (j - 1))][j - 1];
}

long long query(int L, int R) {
	long long sum = 0;
	for (int j = K; j >= 0; j--) {
	    if ((1 << j) <= R - L + 1) {
	        sum += st[L][j];
	        L += 1 << j;
	    }
	}
	return sum;
}


/*
	Range min query
*/
int logg[MAXN+1];

void pre(int array[]) {
	logg[1] = 0;
	for (int i = 2; i <= MAXN; i++)
    	logg[i] = logg[i/2] + 1;

    for (int i = 0; i < N; i++)
    	st[i][0] = array[i];

	for (int j = 1; j <= K; j++)
	    for (int i = 0; i + (1 << j) <= N; i++)
	        st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]); // make sure to check if 1 << j overflows or not.
}

int query(int L, int R) {
	int j = logg[R - L + 1];
	int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
}
