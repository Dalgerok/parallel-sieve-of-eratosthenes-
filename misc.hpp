#include <cstdio>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <cstring>

#include <omp.h> // OpenMP


long long sieve(long long, bool);
long long sieveOdd(long long, bool);
long long sieveOddBlockwise(long long, bool);
long long sieveOddBlockwiseSqrt(long long, bool);
std::vector < uint > findOddPrimes(uint);

extern std::vector < uint > oddPrimes;

extern const int BLOCK_SIZE; // block size for parallelization

extern const int SIEVE_NAMES_SIZE;
extern const char* SIEVE_NAMES[];
extern long long(*SIEVE_FUNCTIONS[])(long long, bool);

extern void printErrorAndExit(const char*);