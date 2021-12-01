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
