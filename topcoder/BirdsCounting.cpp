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

class BirdsCounting {
public:
	double computeProbability(int, int, int, int);
};

const int MAXN = 21;

ll comb[MAXN][MAXN];

void findCoeff(){
	memset(comb, 0, sizeof(comb));
	comb[0][0] = 1;
	for (int i = 1; i < MAXN; i++) {
    	comb[i][0] = 1;
    	for (int j = 1; j <= i; j++) {
      		comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]);
    	}
	}	
}

double dp[6][21];
int birdnum, cperday, daysnum, birdmarked;

double solve(int daysleft, int markedsofar) {
	if(daysleft == 0) return markedsofar == birdmarked;
	double &res = dp[daysleft][markedsofar];
	if(res >= 0) return res;
	res = 0.0;
	
	int unmarked = birdnum - markedsofar;
	int available = min(unmarked, cperday);
	FOR(newmarked, 0, available + 1) {
		ll num = comb[unmarked][newmarked] * comb[markedsofar][cperday - newmarked];
		ll denom = comb[birdnum][cperday];
		res += num * 1.0 / denom * solve(daysleft - 1, markedsofar + newmarked); 
	}
	return res;
}

double BirdsCounting::computeProbability(int birdsNumber, int caughtPerDay, int daysNumber, int birdsMarked) {
	findCoeff(); birdnum = birdsNumber; cperday = caughtPerDay; daysnum = daysNumber; birdmarked = birdsMarked;
	memset(dp, -1, sizeof(dp));
	return solve(daysNumber, 0);
}


double test0() {
	int p0 = 3;
	int p1 = 1;
	int p2 = 2;
	int p3 = 2;
	BirdsCounting * obj = new BirdsCounting();
	clock_t start = clock();
	double my_answer = obj->computeProbability(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 0.6666666666666666;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 3;
	int p1 = 1;
	int p2 = 5;
	int p3 = 1;
	BirdsCounting * obj = new BirdsCounting();
	clock_t start = clock();
	double my_answer = obj->computeProbability(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 0.012345679012345678;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 8;
	int p1 = 3;
	int p2 = 3;
	int p3 = 7;
	BirdsCounting * obj = new BirdsCounting();
	clock_t start = clock();
	double my_answer = obj->computeProbability(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 0.2582908163265306;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 5;
	int p1 = 3;
	int p2 = 2;
	int p3 = 4;
	BirdsCounting * obj = new BirdsCounting();
	clock_t start = clock();
	double my_answer = obj->computeProbability(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 0.6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 20;
	int p1 = 6;
	int p2 = 5;
	int p3 = 17;
	BirdsCounting * obj = new BirdsCounting();
	clock_t start = clock();
	double my_answer = obj->computeProbability(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 0.30035494805367574;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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
