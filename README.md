# Parallel Sieve of Eratosthenes

University project was made for the course of Concurrent Programming on faculty of Theoretical Computer Science at Jagiellonian University.

The idea was to parallelize some well-known algorithm, e.g Sieve of Eratosthenes.

## Compile and Run

1. Run `make` or `make all` to compile and `make clean` to clean objects files and binaries.

2. Run `./main sieve_name sieve_bound [P]` where `sieve_bound` is sieve bound, `[P]` is optional flag to enable parallelization and `sieve_name` is one possible sieve names: 
- "soe" - simple algorithm.
- "soe_odd_only" - only odd numbers optimization.
- "soe_odd_only_blockwise" - only odd numbers with block by block optimization.
- "soe_odd_only_blockwise_sqrt" - only odd prime numbers <= `$\sqrt{sieve_bound}$` with block by block optimization. 

## Benchmarking

1. Run `python3 benchmark.py` to see benchmark results in console.
