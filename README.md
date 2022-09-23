# tsnnls
Solver for non-negative sparse least squares.

To run:
export LD_LIBRARY_PATH=/home/grads/mbr5797/tsnnls/tsnnls/tsnnls_install/lib:/usr/local/lib:/usr/local/cuda/lib:/usr/local/cuda/lib64:/usr/local/lib:/usr/local/cuda/lib:/usr/local/cuda/lib64:
export CPATH=/home/grads/mbr5797/tsnnls/tsnnls/tsnnls_install/include/libtsnnls/taucs_basic/:/home/grads/mbr5797/tsnnls/tsnnls/tsnnls_install/include/libtsnnls/

Compile with:
gcc -Wall solver.c -ltsnnls
