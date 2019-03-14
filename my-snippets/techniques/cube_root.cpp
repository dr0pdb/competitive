ll cb(ll x) {
    ll l = 0, r = 1e6 + 5;
    ll ret = 1e9 + 10;
    while (l <= r) {
        ll mid = (l + r ) >> 1;
        if(mid*mid*mid >= x) {
            ret = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ret;
}