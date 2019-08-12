/*
    My implementation.
*/
typedef vector<vll> mat;

int n;
mat adj; 

void mult(mat &a, mat b) {
    mat tmp(n, vll(n, 0));
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            FOR(k, 0, n) {
                tmp[i][j] += (a[i][k] * b[k][j]) % MOD;
                tmp[i][j] %= MOD;
            }
        }
    }
    a = tmp;
}

mat exp(mat a, ll kk) {
    mat b(n, vll(n, 0));
    FOR(i, 0, n) b[i][i] = 1LL;
    while(kk) {
        if(kk % 2) {
            mult(b, a);
        }
        mult(a, a);
        kk >>= 1LL;
    }
    return b;
}


//Source : http://fusharblog.com/solving-linear-recurrence-for-programming-contest/

#define REP(i,n) for (int i = 1; i <= n; i++)

typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007;
const int K = 2;

// computes A * B
matrix mul(matrix A, matrix B)
{
    matrix C(K+1, vector<ll>(K+1));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

// computes A ^ p
matrix pow(matrix A, int p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

// returns the N-th term of Fibonacci sequence
int fib(int N)
{
    // create vector F1
    vector<ll> F1(K+1);
    F1[1] = 1;
    F1[2] = 1;

    // create matrix T
    matrix T(K+1, vector<ll>(K+1));
    T[1][1] = 0, T[1][2] = 1;
    T[2][1] = 1, T[2][2] = 1;

    // raise T to the (N-1)th power
    if (N == 1)
        return 1;
    T = pow(T, N-1);

    // the answer is the first row of T . F1
    ll res = 0;
    REP(i, K)
        res = (res + T[1][i] * F1[i]) % MOD;
    return res;
}
