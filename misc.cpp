#include "misc.hpp"



const int BLOCK_SIZE = 128 * 1024 * 2;

const int SIEVE_NAMES_SIZE = 4;
const char* SIEVE_NAMES[] = {"soe", "soe_odd_only", 
"soe_odd_only_blockwise", "soe_odd_only_blockwise_sqrt"};
long long(*SIEVE_FUNCTIONS[])(long long N, bool isOpenMP) = {
sieve, sieveOdd, sieveOddBlockwise, sieveOddBlockwiseSqrt};
std::vector < uint > oddPrimes;

void printErrorAndExit(const char* error) {
    printf("Error: %s\n"
    "Usage: ./main sieve_name sieve_bound [P]\n"
    "Where sieve_name is the name of sieve to use, sieve_bound is sieve bound "
    "and P is optional flag to enable parallelization\n", error);
    printf("Possible sieve names:\n");
    for (int i = 0; i < SIEVE_NAMES_SIZE; i++) {
        printf("%s%s", SIEVE_NAMES[i], 
        i + 1 == SIEVE_NAMES_SIZE ? "\n" : ", ");
    }
    exit(0);
}