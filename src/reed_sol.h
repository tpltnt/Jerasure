/* reed_sol.h
 * James S. Plank

Jerasure - A C/C++ Library for a Variety of Reed-Solomon and RAID-6 Erasure Coding Techniques

Revision 1.2A
May 24, 2011

James S. Plank
Department of Electrical Engineering and Computer Science
University of Tennessee
Knoxville, TN 37996
plank@cs.utk.edu

Copyright (c) 2011, James S. Plank
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

 - Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

 - Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in
   the documentation and/or other materials provided with the
   distribution.

 - Neither the name of the University of Tennessee nor the names of its
   contributors may be used to endorse or promote products derived
   from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.


 */

/** This returns the last m rows of the distribution matrix in GF (2w), based on an extended Vandermonde matrix. This is a m x k matrix that can be used with the matrix routines in jerasure.c. The first row of this matrix is guaranteed to be all ones. The first column is also guaranteed to be all ones.
 * 
 * @param k Number of data devices
 * @param m Number of coding devices
 * @param w Word size
 * @see reed_sol_big_vandermonde_distribution_matrix(int rows, int cols, int w)
 * @todo fix
 */
extern int *reed_sol_vandermonde_coding_matrix(int k, int m, int w);

/** This creates an extended Vandermonde matrix with rows rows and cols columns in GF (2w).
 *
 * @param w Word size
 * @todo fix
 */
extern int *reed_sol_extended_vandermonde_matrix(int rows, int cols, int w);

/** This converts the extendedmatrix above into a distribution matrix so that the top cols rows compose an identity matrix, and the remaining rows are in the format returned by reed_sol_vandermonde_coding_matrix().
 *
 * @param w Word size
 * @see reed_sol_vandermonde_coding_matrix(int k, int m, int w)
 * @todo fix
 */
extern int *reed_sol_big_vandermonde_distribution_matrix(int rows, int cols, int w);

/** This encodes using the optimization. w must be 8, 16 or 32. Note, m is not needed because it is assumed to equal two, and no matrix is needed because it is implicit.
 * 
 * @param w Word size
 * @todo fix
 * @todo return
 */
extern int reed_sol_r6_encode(int k, int w, char **data_ptrs, char **coding_ptrs, int size);

/** This procedure returns the last two rows of the distribution matrix for RAID-6 for decoding purposes. The first of these rows will be all ones. The second of these rows will have 2 j in column j.
 *
 * @param k Number of data devices
 * @param w Word size
 * @todo fix
 */
extern int *reed_sol_r6_coding_matrix(int k, int w);

/** This performs the fast multiplication by two in GF (28) using Anvin's optimization [Anv07]. region must be long-word aligned, and nbytes must be a multiple of the word size.
 * @todo fix
 */
extern void reed_sol_galois_w08_region_multby_2(char *region, int nbytes);

/** This performs the fast multiplication by two in GF (216).
 * @todo fix
 */
extern void reed_sol_galois_w16_region_multby_2(char *region, int nbytes);

/** This performs the fast multiplication by two in GF (232).
 * @todo fix
 */
extern void reed_sol_galois_w32_region_multby_2(char *region, int nbytes);
