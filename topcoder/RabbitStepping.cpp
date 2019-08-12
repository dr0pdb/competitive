#include<bits/stdc++.h>
#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;
#define deb(x )     cerr << #x << " here "<< x << endl;
#define endl    "\n"
#define printCase() "Case #" << caseNum << ": "
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
#define ff first
#define ss second
/*----------------------------------------------------------------------*/

class RabbitStepping {
public:
	double getExpected(string, int);
};

const int N = 17;
int n, rr;
string arr;

int solve(int mask, int curr, int prevmask = -1) {
	if(curr == 2) {
		int cnt = 0;
		FOR(i, 0, n) {
			if(mask & (1 << i)) cnt++;
		}
		return cnt;
	}
	int cf[n]; memset(cf, 0, sizeof(cf));
	FOR(i, 0, n) {
		if(mask & (1 << i)) {
			char c = arr[i];
			if(!i) {
				cf[1]++;
			} else if(i >= curr-2) {
				cf[i-1]++;
			}
			else if(c == 'W') {
				cf[i-1]++;
			} else if(c == 'B') {
				cf[i+1]++;
			} else {
				if(prevmask == -1) {
					cf[i-1]++;
				} else {
					char cc = arr[i + 1];
					if(cc == 'W' && (prevmask & (1 << (i+1)))) {
						cf[i+1]++;
					} else cf[i-1]++;
				}
			}
		}
	}
	int nmask = 0;
	FOR(i, 0, n) {
		if(cf[i] == 1) {
			nmask |= (1 << i);
		}
	}
	
	return solve(nmask , curr - 1, mask);
}

double RabbitStepping::getExpected(string field, int r) {
	n = field.size(); rr = r;
	arr = field; int tot=0, ones=0, twos=0, zeroes=0;
	FOR(i, 0, (1 << n)) {
		int cnt = 0;
		FOR(j, 0, n) {
			if(i & (1 << j)) cnt++;
		}
		if(cnt == r) {
			int res = solve(i, n);
			tot++;
			if(res == 0) zeroes++;
			else if(res == 1) ones++;
			else twos++;
		}
	}
	return (ones + 2.0*twos)/tot;
}


double test0() {
	string p0 = "WRBRW";
	int p1 = 4;
	RabbitStepping * obj = new RabbitStepping();
	clock_t start = clock();
	double my_answer = obj->getExpected(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.8;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string p0 = "WWB";
	int p1 = 2;
	RabbitStepping * obj = new RabbitStepping();
	clock_t start = clock();
	double my_answer = obj->getExpected(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 1.3333333333333333;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string p0 = "WW";
	int p1 = 1;
	RabbitStepping * obj = new RabbitStepping();
	clock_t start = clock();
	double my_answer = obj->getExpected(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 1.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string p0 = "BBBBBBBBBB";
	int p1 = 4;
	RabbitStepping * obj = new RabbitStepping();
	clock_t start = clock();
	double my_answer = obj->getExpected(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.9523809523809523;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string p0 = "RRBRRWRRBRRW";
	int p1 = 8;
	RabbitStepping * obj = new RabbitStepping();
	clock_t start = clock();
	double my_answer = obj->getExpected(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.9696969696969697;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
