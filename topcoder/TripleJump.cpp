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

class TripleJump {
public:
	vector <double> getProbabilities(int, int, int, vector <int>);
};

int l, u, n;

double f(int val) {
	if(val <= 2*l) return 1;
	if(val >= 2*u) return 0;
	double denom = 2 * (u - l) * (u - l);
	if(val > 2*l && val <= u + l) {
		double num = (val - 2*l)*(val - 2*l);
		double res = 1;
		res -= num/denom;
		return res;	
	}
	double num = (val - 2*u)*(val - 2*u);
	return num/denom;
}

vector <double> TripleJump::getProbabilities(int lower, int upper, int first, vector <int> opponents) {
	l = lower; u = upper; n = opponents.size();
	FOR(i, 0, n) opponents[i] -= first;
	sort(opponents.begin(), opponents.end(), greater<int>());
	vector<double> ans(n+1, 0.0), fff(n);
	FOR(i, 0, n) fff[i] = f(opponents[i]);
	double sm = 0;
	ans[0] = fff[0]; sm += ans[0];
	FOR(i, 1, n) {
		ans[i] = fff[i] - fff[i-1];
		sm += ans[i];
	}
	ans[n] = 1 - sm;
	return ans;
}


double test0() {
	int p0 = 1;
	int p1 = 2;
	int p2 = 1;
	int t3[] = {1,2,3,4};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	TripleJump * obj = new TripleJump();
	clock_t start = clock();
	vector <double> my_answer = obj->getProbabilities(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double t4[] = {0.5, 0.5, 0.0, 0.0, 0.0 };
	vector <double> p4(t4, t4+sizeof(t4)/sizeof(double));
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
	int p0 = 3;
	int p1 = 7;
	int p2 = 5;
	int t3[] = {9,9,19,19,19};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	TripleJump * obj = new TripleJump();
	clock_t start = clock();
	vector <double> my_answer = obj->getProbabilities(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double t4[] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0 };
	vector <double> p4(t4, t4+sizeof(t4)/sizeof(double));
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
	int p0 = 1;
	int p1 = 10;
	int p2 = 1;
	int t3[] = {5};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	TripleJump * obj = new TripleJump();
	clock_t start = clock();
	vector <double> my_answer = obj->getProbabilities(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double t4[] = {0.9753086419753086, 0.024691358024691357 };
	vector <double> p4(t4, t4+sizeof(t4)/sizeof(double));
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
	int p0 = 1;
	int p1 = 10;
	int p2 = 5;
	int t3[] = {1,2,3,5,10,11,12,19};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	TripleJump * obj = new TripleJump();
	clock_t start = clock();
	vector <double> my_answer = obj->getProbabilities(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double t4[] = {0.22222222222222227, 0.6234567901234567, 0.05555555555555558, 0.043209876543209846, 0.05555555555555558, 0.0, 0.0, 0.0, 0.0 };
	vector <double> p4(t4, t4+sizeof(t4)/sizeof(double));
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
