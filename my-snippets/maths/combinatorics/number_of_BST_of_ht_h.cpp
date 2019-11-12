ll dp[40][40];


// returns the number of BST of num distinct numbers with height ht.
ll cnt(int num, int ht) {
    if(num == 0) return ht == 0;
    if(ht <= 0) return 0;
    ll &ret = dp[num][ht];
    if(ret >= 0) return ret;
    ret = 0;

    FOR(leftn, 0, num) {
        int rightn = num - leftn - 1;
        ll rightsum = 0;
        FOR(rh, 0, ht) {
            rightsum += cnt(rightn, rh);
        }
        ret += cnt(leftn, ht - 1) *  rightsum;
        ll leftsum = 0;
        FOR(lh, 0, ht - 1) {
            leftsum += cnt(leftn, lh);
        }
        ret += cnt(rightn, ht - 1) * leftsum;
    }

    return ret;    
}