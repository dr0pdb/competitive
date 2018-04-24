int lo = 1, hi = ;

while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (check(mid)) {
        //do something.
        hi = mid - 1;
    }
    else lo = mid + 1;
}
