def characterReplacement(self, s, k):
    res = lo = 0
    counts = collections.Counter()
    for hi in range(len(s)):
        counts[s[hi]] += 1
        max_char_n = counts.most_common(1)[0][1]
        while (hi - lo - max_char_n + 1 > k):
            counts[s[lo]] -= 1
            lo += 1
        res = max(res, hi - lo + 1)
    return res
