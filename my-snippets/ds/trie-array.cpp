#include <bits/stdc++.h>
using namespace std;

#define maxx 100000
#define intt int

intt trie[maxx][26], finish[maxx];
intt nxt = 1;
void insert (string s){
    intt node = 0;
    for (intt i = 0; s[i] != '\0'; i++) {
        if(trie[node][s[i] - 'a'] == 0) {
            node = trie[node][s[i] - 'a'] = nxt;
            nxt++;
        } else {
            node = trie[node][s[i] - 'a'];
        }
    }
    finish[nxt - 1] = 1;
}

intt find (string s) {
    intt idx = 0;
    for (intt i = 0; i < s.size(); i++)
        if (trie[idx][s[i] - 'a'] == 0)
            return 0;
        else
            idx = trie[idx][s[i] - 'a'];
    return finish[idx];
}


/*
    2nd implementation.
*/
int tot = 0;
int ch[5000001][2];
int s[5000001]; // contains the count of child.

void insert(int x) {
    int Root = 0;
    for (int i = 30; i >= 0; i --) {
        int tmp = (x >> i) & 1;
        if (!ch[Root][tmp]) {
            ch[Root][tmp] = ++ tot;
            s[tot] = 0;
            memset(ch[tot], 0, sizeof(ch[tot]));
        }
        Root = ch[Root][tmp];
        ++ s[Root];
    }
}

void del(int x) {
    int Root = 0;
    for (int i = 30; i >= 0; i --) {
        int tmp = (x >> i) & 1;
        Root = ch[Root][tmp];
        -- s[Root];
    }
}

// query for maximizing xor.
int query(int x) {
    int Root = 0, ans = 0;
    for (int i = 30; i >= 0; i --) {
        int tmp = (x >> i) & 1;
        if (s[ch[Root][tmp ^ 1]]) ans += (1 << i), Root = ch[Root][tmp ^ 1];
        else Root = ch[Root][tmp];
    }
    return ans;
}