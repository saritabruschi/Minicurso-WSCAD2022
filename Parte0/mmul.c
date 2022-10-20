#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void matrix_fill_rand(int n, double *restrict _A)
{
    #define A(i, j) _A[n*(i) + (j)]
	int i, j;

	for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            A(i, j) = 10*(double) rand() / (double) RAND_MAX;

    #undef A
}

void mmul(int n, double *restrict _C, double *restrict _A, double *restrict _B)
{
    // Macros para acesso aos elementos das matrizes
    #define A(i, j) _A[n*(i) + (j)]
    #define B(i, j) _B[n*(i) + (j)]
    #define C(i, j) _C[n*(i) + (j)]

    int min_BLC = 32;
    int max_BLC = 1024;

    // Tamanho do bloco aleatorio entre min_BLC e max_BLC
    int BLC = min_BLC + (rand()/(double) RAND_MAX)*(max_BLC - min_BLC);

    int ib, jb, kb, i, j, k;
    int num_blocks = n/BLC + 1;

    for (ib = 0; ib < num_blocks; ++ib)
        for (kb = 0; kb < num_blocks; ++kb)
            for (jb = 0; jb < num_blocks; ++jb)
                for (i = ib*BLC; i < (ib+1)*BLC && i < n; ++i)
                    for (k = kb*BLC; k < (kb+1)*BLC && k < n; ++k)
                        for (j = jb*BLC; j < (jb+1)*BLC && j < n; ++j)
                            C(i, j) += A(i, k)*B(k, j);

    #undef A
    #undef B
    #undef C
}

int main()
{
    double *restrict A;
    double *restrict B;
    double *restrict C;

    int n = 2048;

    // Aloque memoria com alinhamento de 8 bytes
    A = aligned_alloc(8, n*n*sizeof(*A)); 
    B = aligned_alloc(8, n*n*sizeof(*B));
    C = aligned_alloc(8, n*n*sizeof(*C));

    // Usar tempo atual como seed para geracao de numeros (pseudo-)aleatorios
    srand(time(0));

    // Matrizes A e B preenchidas com valores aleatorios
    matrix_fill_rand(n, A);
    matrix_fill_rand(n, B);

    // Matriz C inicialmente preenchida com zeros
    memset(C, 0x00, n*n*sizeof(*A));

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    // Calcula o produto das matrizes A e B e armazena o
    // resultado na matriz C
    mmul(n, C, A, B);
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("%lf\n", cpu_time_used);

    free(A);
    free(B);
    free(C);

    return 0;
}