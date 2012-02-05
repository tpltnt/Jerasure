# About #
This is the Jerasure project, by James S. Plank, Scott Simmerman, and
Catherine D. Schuman.  More details can be found at
[http://web.eecs.utk.edu/~plank/plank/papers/CS-08-627.html](http://web.eecs.utk.edu/~plank/plank/papers/CS-08-627.html)

See technical report CS-08-627 for a description of the code.  

There are three directories:

* The ``src`` directory contains the jerasure code.
* The ``lib`` directory contains the libraries/shared objects.
* The ``Examples`` directory contains the example programs.  

## Hints ##
* building works with [GNU mak](http://www.gnu.org/s/make/)
* talloc is *not* the [Samba one](http://talloc.samba.org/talloc/doc/html/index.html)
  * defined as ``#define talloc(type, num) (type *) malloc(sizeof(type)*(num))``
* only temporary use of shared objects (no make install)
  * set $LD_LIBRARY_PATH to Jerasure/lib
  * Linux: [Program Library HOWTO](http://tldp.org/HOWTO/Program-Library-HOWTO/shared-libraries.html)
  * FreeBSD: man 8 ldconfig, man 1 rtld
* ``make install`` installs shared objects into home-directory

## Issues ##
* memory leaks (unconfirmed)
  * jerasure_matrix_decode
