# example_for_yacon
Here you can see an example сode for multiplication of two sparse matrices (with elements of the residue field modulo 4294967161). Matrices are defined as a sequence of its nonzero elements in the form of a triple (RGB), where R - row is an unsigned 32-bit number, C - column is an unsigned 32-bit number, V is the corresponding element of the matrix. Rows and columns are numbered from 0.
Two multipliable matrices are set on the standard input stream. The matrices are separated by a triple of numbers 0 0 4294967161.
As an answer, the program provides a matrix-the result of the same format.
