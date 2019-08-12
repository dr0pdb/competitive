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

class CrazyComponents {
public:
	double expectedProfit(int, vector <string>, vector <int>, vector <int>);
};

/*
	Split string on the basis of delimiter.
*/
vector<string> split(const string& s, char delimiter = ' ')
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

int n, kk;
vector<vi> deps;
vector<int> inc, expe;
double dp[51][(1<<15)];

double solve(int curr, int mask) {
	double &res = dp[curr][mask];
	if(res >= 0) return res;
	if(curr == kk) return 0;
	res = 0;
	
	FOR(i, 0, n) {
		bool sat = true;
		for(auto d : deps[i]) {
			if(!(mask & (1 << d))) {
				sat = false;
				break;
			}
		}
		double tmp = 1.0 / n * solve(curr+1, mask);
		if(sat) {
			double tmp2 = 1.0 / n;
			double prof = inc[i] - expe[i];
			double nxt = solve(curr+1, (mask | (1 << i)));
			tmp2 *= (prof + nxt);
			tmp = max(tmp, tmp2); 
		}
		res += tmp;
	}
	return res;
}

double CrazyComponents::expectedProfit(int k, vector <string> components, vector <int> income, vector <int> expense) {
	n = components.size(); deps.resize(n, vi()); inc = income; expe = expense; kk = k;
	FOR(i, 0, n) {
		vector<string> dd = split(components[i]);
		for(auto str : dd) {
			int num = stoi(str);
			deps[i].push_back(num);
		}
	}
	memset(dp, -1, sizeof(dp));
	return solve(0, 0);
}


double test0() {
	int p0 = 1;
	string t1[] = { "", "" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int t2[] = { 1, 2 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = { 0, 0 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	CrazyComponents * obj = new CrazyComponents();
	clock_t start = clock();
	double my_answer = obj->expectedProfit(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 1.5;
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
	int p0 = 2;
	string t1[] = { "1", "" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int t2[] = { 10, 0 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = { 0, 2 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	CrazyComponents * obj = new CrazyComponents();
	clock_t start = clock();
	double my_answer = obj->expectedProfit(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 1.5;
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
	int p0 = 3;
	string t1[] = { "1 2", "", "" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int t2[] = { 100, 0, 0 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = { 0, 0, 0 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	CrazyComponents * obj = new CrazyComponents();
	clock_t start = clock();
	double my_answer = obj->expectedProfit(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 7.407407407407408;
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
	string t1[] = { "1", "2", "0", "" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int t2[] = { 4, 5, 6, 7 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = { 0, 0, 0, 8 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	CrazyComponents * obj = new CrazyComponents();
	clock_t start = clock();
	double my_answer = obj->expectedProfit(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 0.0;
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
	int p0 = 10;
	string t1[] = { "", "", "", "", "", "", "", "", "", "" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int t2[] = { 142352, 2342, 34534, 2344, 12346, 7589, 79872, 973453, 96233, 34567 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = { 12432, 2345, 3678, 456, 345, 457, 56758, 4564, 774, 34567 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	CrazyComponents * obj = new CrazyComponents();
	clock_t start = clock();
	double my_answer = obj->expectedProfit(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 1269258.9999999998;
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
