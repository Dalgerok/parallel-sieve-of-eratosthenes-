# Parallel Sieve of Eratosthenes

Project was made for the course of Concurrent Programming on faculty of Theoretical Computer Science at Jagiellonian University.

The idea was to parallelize some well-known algorithm, e.g Sieve of Eratosthenes, using OpenMP.

## Compile and Run

1. Run `make` or `make all` to compile and `make clean` to clean objects files and binaries.

2. Run `./main sieve_name sieve_bound [P]` where `sieve_bound` is sieve bound, `[P]` is optional flag to enable parallelization and `sieve_name` is one possible sieve names: 
- "soe" - simple algorithm.
- "soe_odd_only" - only odd numbers optimization.
- "soe_odd_only_blockwise" - only odd numbers with block by block optimization.
- "soe_odd_only_blockwise_sqrt" - only odd prime numbers <= sqrt(sieve_bound) with block by block optimization. 

Example usage: 
```console
user@login:~/parallel-sieve-of-eratosthenes$ make
g++ -fopenmp -c misc.cpp -o misc.o
g++ -fopenmp -c soe.cpp -o soe.o
g++ -fopenmp -c soe_odd_only.cpp -o soe_odd_only.o
g++ -fopenmp -c soe_odd_only_blockwise.cpp -o soe_odd_only_blockwise.o
g++ -fopenmp -c soe_odd_only_blockwise_sqrt.cpp -o soe_odd_only_blockwise_sqrt.o
g++ -fopenmp -c main.cpp -o main.o
g++ -fopenmp misc.o soe.o soe_odd_only.o soe_odd_only_blockwise.o soe_odd_only_blockwise_sqrt.o main.o -o main
user@login:~/parallel-sieve-of-eratosthenes$ ./main soe_odd_only_blockwise 1000000000 P
50847534
```

## Benchmarking

Run `python3 benchmark.py` to see benchmark results in console.

Example benchmark, runned on Intel(R) Xeon(R) CPU X5650 @ 2.67GHz with 24 CPUs:
```console
user@long:~/parallel-sieve-of-eratosthenes$ python3 benchmark.py 
+-------+--------+--------+--------------+----------------+------------------------+--------------------------+-----------------------------+-------------------------------+
|       |  soe   |  soe P | soe_odd_only | soe_odd_only P | soe_odd_only_blockwise | soe_odd_only_blockwise P | soe_odd_only_blockwise_sqrt | soe_odd_only_blockwise_sqrt P |
+-------+--------+--------+--------------+----------------+------------------------+--------------------------+-----------------------------+-------------------------------+
|  10^6 | 0.02   |  0.02  |     0.01     |      0.02      |          0.01          |           0.01           |             0.01            |              0.01             |
|  10^7 | 0.23   |  0.04  |     0.1      |      0.03      |          0.08          |           0.02           |             0.08            |              0.02             |
|  10^8 | 4.76   |  0.38  |     2.22     |      0.18      |          0.82          |           0.07           |             0.75            |              0.08             |
|  10^9 | 57.05  |  5.29  |     28.02    |      2.84      |          8.18          |           0.68           |             7.24            |              0.6              |
| 10^10 | 800.22 |  70.24 |     302.16   |      31.82     |         100.96         |           7.43           |            79.91            |              6.03             |
| 10^11 | MEM    |  MEM   |     MEM      |      MEM       |        1603.32         |          116.27          |            972.61           |             69.94             |
+-------+--------+--------+--------------+----------------+------------------------+--------------------------+-----------------------------+-------------------------------+
```
