gcd (int a, int b) {
   return  b == 0 ? a : gcd(b, a%b);
}

lcm (int a, int b) {
    return a * b / gcd (a, b);
}
