// find minimum value that passes check
int lo = 0, hi = N;
while (lo < hi) {
    int mid = lo + (hi-lo) / 2;  // prevent int overflow, negative rounding
    if (check(mid)) hi = mid;    // if it passes, don't exclude
    else lo = mid + 1;           // if it fails, exclude it.
}
return lo;


// find maximum value that passes check
int lo = 0, hi = N;
while (lo < hi) {
    int mid = lo + (hi-lo+1) / 2;  // (hi-lo+1) / 2  ==  ceil((hi-lo) / 2.0)
    if (check(mid)) lo = mid;
    else hi = mid - 1;
}
return lo;


// find if exists
int lo = 0, hi = N;
while (lo <= hi) {
    int mid = lo + (hi-lo) / 2;
    int c = check(mid);
    if (c == 0) hi = mid-1;
    if (c == 1) return mid;  // found ans
    if (c == 2) lo = mid+1;
}
return -1;  // never found
