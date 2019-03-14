#include <bits/stdc++.h>
using namespace std;

struct FenwickTree2D {
    vector<vector<int>> bit;
    int n, m;

    FenwickTree2D(int n, int m) {
        this->n = n + 1;
        this->m = m + 1;
        bit.assign(n + 1, vector<int> (m + 1, 0));
    }

    FenwickTree2D(vector<vector<int> > a)
        : FenwickTree2D(a.size(), a[0].size()) {
        for (size_t i = 0; i < a.size(); i++) {
            for (size_t j = 0; j < a[0].size(); ++j)
            {
                add(i, j, a[i][j]);                
            }
        }
    }

    // x and y as zero based index.
    int sum(int x, int y) {
        int ret = 0;
        for (int i = x+1; i > 0; i -= i & (-i))
            for (int j = y+1; j > 0; j -= j & (-j))
                ret += bit[i][j];
        return ret;
    }

    // x and y as zero based index.
    void add(int x, int y, int delta) {
        for (int i = x+1; i < n; i += i & (-i))
            for (int j = y+1; j < m; j += j & (-j))
                bit[i][j] += delta;
    }
};