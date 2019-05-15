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

class TreeLine {
public:
	int longest(vector <int>, vector <int>);
};

int maxPointOnSameLine(vector< pair<int, int> > points) 
{ 
    int N = points.size(); 
    if (N < 2) 
        return N; 
  
    int maxPoint = 0; 
    int curMax, overlapPoints, verticalPoints; 

    map<pair<int, int>, int> slopeMap;  
  
    for (int i = 0; i < N; i++) 
    { 
        curMax = overlapPoints = verticalPoints = 0; 

        for (int j = i + 1; j < N; j++) 
        { 
            if (points[i] == points[j]) 
                overlapPoints++; 
            else if (points[i].first == points[j].first) 
                verticalPoints++; 
  
            else
            { 
                int yDif = points[j].second - points[i].second; 
                int xDif = points[j].first - points[i].first; 
                int g = __gcd(xDif, yDif); 
  
                yDif /= g; 
                xDif /= g; 
  
                slopeMap[make_pair(yDif, xDif)]++; 
                curMax = max(curMax, slopeMap[make_pair(yDif, xDif)]); 
            } 
  
            curMax = max(curMax, verticalPoints); 
        } 
  
        maxPoint = max(maxPoint, curMax + overlapPoints + 1); 
        slopeMap.clear(); 
    } 
  
    return maxPoint; 
} 

int TreeLine::longest(vector <int> x, vector <int> y) {
	vector<pair<int,int> > pts;
	for(int i = 0; i < x.size(); i++) {
		pts.push_back({x[i], y[i]});
	}
	return maxPointOnSameLine(pts);
}


double test0() {
	int t0[] = {0, 3, 6};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0, 3, 6};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TreeLine * obj = new TreeLine();
	clock_t start = clock();
	int my_answer = obj->longest(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	int t0[] = {0, 3, 6};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0, 3, 7};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TreeLine * obj = new TreeLine();
	clock_t start = clock();
	int my_answer = obj->longest(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	int t0[] = {0, 3, 6, 20, 12};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0, 3, 0, 20, 11};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TreeLine * obj = new TreeLine();
	clock_t start = clock();
	int my_answer = obj->longest(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
