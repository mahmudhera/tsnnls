#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<malloc.h>
#include<tsnnls.h>

double *random_matrix(int m, int n)
/* Creates a random sparse-ish matrix for test purposes. In each column, we fill in
   about 1/10 of the entries with nonzero elements. */
{
    double *A = malloc(m*n*sizeof(double));
    int i,j;
    for(j = 0; j < n; j++) {
        for(i = 0; i < 5; i++) {
            A[(rand() % m) + m*j] = 2.0*((double)(rand())/(double)(RAND_MAX)) - 1.0;
        }
    }
    return A;
}

void test_basic() {
      printf("This is a test program\n");

      double *mat = random_matrix(10, 10);
      int i, j;
      taucs_ccs_matrix *mat_cc;
      taucs_ccs_matrix *mat_cc_transpose;

      for (i = 0; i < 10; i++) {
          for (j = 0; j < 10; j++) {
              printf("%.3f\t", mat[i*10 + j]);
          }
          printf("\n");
      }
      printf("Successfully printed matrix\n");

      mat_cc = taucs_construct_sorted_ccs_matrix(mat, 10, 10);
      printf("Succesful matrix creation. Testing printing...\n");
      taucs_print_ccs_matrix(mat_cc);

      mat_cc_transpose = taucs_ccs_transpose(mat_cc);
      printf("Now printing the transpose...\n");
      taucs_print_ccs_matrix(mat_cc_transpose);
}

int main()
{
    //test_basic();
    int i;
    double A[12] = {1, 1, 0,
                    0, 1, 0,
                    0, 1, 0,
                    1, 1, 0};

    taucs_ccs_matrix *taucs_A = taucs_construct_sorted_ccs_matrix(A, 3, 4);
    taucs_print_ccs_matrix(taucs_A);

    double b[4] = {1, 2, 2, 1};
    taucs_double *taucs_b = b;

    taucs_double *result = t_snnls(taucs_A, taucs_b, NULL, 0, 0);
    for (i = 0; i < 3; i++) {
        printf("%.3lf ", result[i]);
    }
    printf("\n");

    return 0;
}
