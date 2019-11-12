#define MAX_N 100010

char T[MAX_N], P[MAX_N];
int prefix[MAX_N], n, m; // n = size of text, m = size of pattern.

void kmpPreprocess() {
	int i = 0, j = -1; prefix[0] = -1;

	while (i < m) {
		while (j >= 0 && P[i] != P[j]) j = prefix[j];
		i++; j++;
		prefix[i] = j;
	} 
}

void kmpSearch() {
	int i = 0, j = 0; 

	while (i < n) {
		while (j >= 0 && T[i] != P[j]) j = prefix[j];
		i++; j++;
		if (j == m) {
			// printf("P is found at index %d in T\n", i - j);
			j = prefix[j]; // prepare j for the next possible match
		}
	}
}

////////////////////////////

vi prefix(string s) {
    s.push_back('#');
    int n = s.size();
    vi p(s.size());
    FOR(i, 1, n) {
        int j = p[i - 1];
        while(j > 0 && s[i] != s[j]) j = p[j - 1];
        if(s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}
 
vii kmp(string txt, string pat, vi &p) {
    pat.push_back('#'); vii res;
    int nn = txt.size(), j = 0; int n = pat.size(); n--;
    FOR(i, 0, nn) {
        while(j > 0 && txt[i] != pat[j]) j = p[j-1];
        if(txt[i] == pat[j]) j++;
        if(j == n) {
            res.push_back({i-j+1, i});
        }
    }
    return res;
}


////// Prefix Automaton /////////

void compute_automaton(string s, vector<vector<int>>& aut) {
    s += '#';
    int n = s.size();
    vector<int> pi = prefix_function(s);
    aut.assign(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            if (i > 0 && 'a' + c != s[i])
                aut[i][c] = aut[pi[i-1]][c];
            else
                aut[i][c] = i + ('a' + c == s[i]);
        }
    }
}