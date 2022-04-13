int msb(int x) {  // log2(x) in O(1)
    union { double a; int b[2]; };
    a = x;
    return (b[1] >> 20) - 1023;
}
