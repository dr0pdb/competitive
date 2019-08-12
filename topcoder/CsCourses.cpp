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

class CsCourses {
public:
	vector <int> getOrder(vector <int>, vector <int>, vector <int>, int);
};

int n, dp[51][51][51], par[51][51][51], bound;

int solve(int month, int th, int pr, vector <int> &tv, vector <int> &pv, vector <int> &exp) {
	int &res = dp[month][th][pr];
	if(res >= 0) return res;
	res = INF;
	if(th >= bound && pr >= bound) return res = 0;
	FOR(i, 0, n) {
		if(month < exp[i] && (th >= tv[i] - 1) && (pr >= pv[i] - 1)) {
			int tmp = 1 + solve(month + 1, max(th, tv[i]), max(pr, pv[i]), tv, pv, exp);
			if(res > tmp) {
				res = tmp;
				par[month][th][pr] = i;
			}
		}
	}
	return res;
}

void generate(vi &ans, int month, int th, int pr, vector <int> &tv, vector <int> &pv) {
	int idx = par[month][th][pr];
	if(idx == -1) return;
	ans.push_back(idx);
	int nth = max(th, tv[idx]); int np = max(pr, pv[idx]);
	generate(ans, month+1, nth, np, tv, pv);
}

vector <int> CsCourses::getOrder(vector <int> tv, vector <int> pv, vector <int> exp, int skillBound) {
	memset(dp, -1, sizeof(dp)); memset(par, -1, sizeof(par));
	n = exp.size();
	bound = skillBound;
	int res = solve(0, 0, 0, tv, pv, exp);
	vi ans;
	if(res >= INF) return ans;
	generate(ans, 0, 0, 0, tv, pv);
	return ans;
}


double test0() {
	int t0[] = {1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 1;
	CsCourses * obj = new CsCourses();
	clock_t start = clock();
	vector <int> my_answer = obj->getOrder(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t4[] = {0 };
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {1, 2, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2, 1, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {5, 5, 5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 2;
	CsCourses * obj = new CsCourses();
	clock_t start = clock();
	vector <int> my_answer = obj->getOrder(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t4[] = {2, 0, 1 };
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {1, 2, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2, 1, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1, 1, 1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 2;
	CsCourses * obj = new CsCourses();
	clock_t start = clock();
	vector <int> my_answer = obj->getOrder(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	vector <int> p4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {1, 2, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2, 1, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {3, 2, 1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 2;
	CsCourses * obj = new CsCourses();
	clock_t start = clock();
	vector <int> my_answer = obj->getOrder(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t4[] = {2, 1, 0 };
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {1, 2, 3, 4, 5, 6, 7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 2, 3, 4, 5, 6, 7};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1, 2, 3, 4, 5, 6, 7};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 7;
	CsCourses * obj = new CsCourses();
	clock_t start = clock();
	vector <int> my_answer = obj->getOrder(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t4[] = {0, 1, 2, 3, 4, 5, 6 };
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int t0[] = {0, 1, 2, 2, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0, 0, 1, 2, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {9, 9, 9, 9, 9};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 2;
	CsCourses * obj = new CsCourses();
	clock_t start = clock();
	vector <int> my_answer = obj->getOrder(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t4[] = {4, 3 };
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
