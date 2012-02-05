# About #
This is the Jerasure project, by James S. Plank, Scott Simmerman, and
Catherine D. Schuman.  More details can be found at
[http://web.eecs.utk.edu/~plank/plank/papers/CS-08-627.html](http://web.eecs.utk.edu/~plank/plank/papers/CS-08-627.html)

See technical report CS-08-627 for a description of the code.  

There are two directories:

* The project home directory contains the jerasure code.
* The Examples directory contains the example programs.  

## Hints ##
* building works with GNU make
* only temporary use of shared objects (no make install)
  * Linux http://tldp.org/HOWTO/Program-Library-HOWTO/shared-libraries.html
  * FreeBSD: man 8 ldconfig, man 1 rtld

## Issues ##
* memory leaks (unconfirmed)
  * reed_sol_vandermonde_coding_matrix
  * jerasure_matrix_decode
