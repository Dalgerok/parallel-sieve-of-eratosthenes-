#include "misc.hpp"


// procces only odd numbers for a specified block
int sieveProcessOddBlockSqrt(long long l, long long r) {
    const int size = (r - l + 1) >> 1;

    char* isPrime = new char[size];
    for (int i = 0; i < size; i++) isPrime[i] = 1;

    for (uint i : oddPrimes) {
        if (i * 1LL * i > r) break;
        // put start to inside the block
        long long start = ((l + i - 1) / i) * i;
        if (start < i * 1LL * i) start = i * 1LL * i;
        if ((start & 1) == 0) start += i; // must be odd
        for ( ; start <= r; start += i << 1) isPrime[(start - l) >> 1] = 0;
    }

    int result = 0;
    for (int i = 0; i < size; i++) result += isPrime[i];
    if (l <= 2) result++;

    delete[] isPrime;
    return result;
}

// odd-only block-by-block sqrt optimized Sieve of Erathosthenes to find the number of primes up to N
long long sieveOddBlockwiseSqrt(long long N, bool isOpenMP) {
    omp_set_num_threads(isOpenMP ? omp_get_num_procs() : 1);
    long long result = 0;

    oddPrimes = findOddPrimes((uint)sqrtl((long double)N));

    #pragma omp parallel for reduction(+:result)
    for (long long l = 2; l <= N; l += BLOCK_SIZE) {
        long long r = l + BLOCK_SIZE;
        if (r > N) r = N;
        result += sieveProcessOddBlockSqrt(l, r);
    }
    return result;
}