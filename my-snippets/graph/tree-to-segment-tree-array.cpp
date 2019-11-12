int in[N],out[N], timer=0;
vi g[N];

// range of subtree of i will be [in[i], out[i]-1].
void dfs(int curr, int par = -1) {
    in[curr] = curr++;

    for(int nxt : g[curr]) {
        if(nxt != par) {
            dfs(nxt, curr);
        }
    }

    out[curr] = curr;
}