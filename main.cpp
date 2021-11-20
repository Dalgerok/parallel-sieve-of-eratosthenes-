#include "misc.hpp"


int main(int argc, char* argv[]) {
    // check whether number of arguments is correct
    if (argc < 3 || argc > 4) {
        printErrorAndExit("Bad number of arguments");
    }

    // check whether sieve name is provided correctly
    int index = -1;
    for (int i = 0; i < SIEVE_NAMES_SIZE; i++) {
        if (strcmp(SIEVE_NAMES[i], argv[1]) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printErrorAndExit("Bad sieve name");
    }


    // check whether N is provided correctly
    long long N; // count primes up to N (bound)
    try {
        std::size_t pos;
        N = std::stol(std::string(argv[2]), &pos);
        if (pos < std::char_traits< char >::length(argv[2])) {
            printErrorAndExit("Bad bound N");
        }
    } catch (std::invalid_argument const &ex) {
        printErrorAndExit("Bad bound N");
    } catch (std::out_of_range const &ex) {
        printErrorAndExit("Bad bound N");
    }
    if (N < 0) {
        printErrorAndExit("Bad bound N");
    }
    
    // check whether parallelization flag is provided correctly
    if (argc == 4 && strcmp(argv[3], "P") != 0) {
        printErrorAndExit("Bad [P] flag");
    }
    
    printf("%lld\n", (*SIEVE_FUNCTIONS[index])(N, argc == 4));
}