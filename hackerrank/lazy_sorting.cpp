#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define SIEVELIM 10000000+10
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

vector<string> split_string(string);

ll fact[19];

// Complete the solve function below.
double solve(vector<int> p) {
    int n = p.size();
    bool sorted = true;
    int val = p[0];
    F(i, 1, n) {
        if(p[i] < val) {
            sorted = false;
            break;
        }

        val = p[i];
    }

    if(sorted) {
        return 0.0;
    }

    fact[0]=fact[1]=1;
    F(i, 2, 19) {
        fact[i] = i * fact[i-1];
    }

    long double ret = fact[n];
    ll dividor = 1;

    sort(p.begin(), p.end());
    val = p[0]; int cnt = 1;
    F(i, 1, n) {
        if(p[i] == val) {
            cnt++;
        } else {
            dividor *= fact[cnt];
            val = p[i];
            cnt = 1;
        }
    }

    if(cnt) {
        dividor *= fact[cnt];
    }

    ret /= (double)(dividor);

    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int P_count;
    cin >> P_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string P_temp_temp;
    getline(cin, P_temp_temp);

    vector<string> P_temp = split_string(P_temp_temp);

    vector<int> P(P_count);

    for (int i = 0; i < P_count; i++) {
        int P_item = stoi(P_temp[i]);

        P[i] = P_item;
    }

    double result = solve(P);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
