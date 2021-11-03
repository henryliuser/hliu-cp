// find minimum value that passes check
int lo = 0, hi = N;
while (lo < hi) {
    int mid = lo + (hi-lo) / 2;  // protect against int overflow, negative rounding
    if (check(mid)) hi = mid;    // if it passes, don't exclude
    else lo = mid + 1;           // if it fails, exclude it.
}
return lo;
