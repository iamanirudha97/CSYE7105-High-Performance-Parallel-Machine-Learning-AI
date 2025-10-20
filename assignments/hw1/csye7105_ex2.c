/* CSYE7105 HW1 Q2: totals 14 points*/

#include <omp.h>
#include <stdio.h>
#define N 1000
#define N_THREADS 4

int main () 
{
int tid, i, chunk;
double a[N], b[N], c[N];
		  	  
chunk = N/N_THREADS;

//initialization
// for(i = 0; i < N; i++)
// {
//   a[i] = b[i] = i * 1.0;
// }

// Parallelize the following block using OpenMP directives: 5 points
/* Give the data scope for the parallel region: 6 points */
/* Use clause to define the number of threads using N_THREADS: 2 points 
   and put this in the second line: 1 points */

#pragma omp parallel private(i, tid) shared(a, b, c, chunk) \
                                     num_threads(N_THREADS)                                   
  {
  tid = omp_get_thread_num();
  // #pragma omp for schedule(dynamic, chunk)  nowait <-- if i use this the program runs on a single thread
  for (i = tid * chunk; i < (tid+1) * chunk; i++)
    {
    c[i] = a[i] + b[i];
    // printf("c[i] is %f on thread : %d\n ", c[i], omp_get_thread_num()); 
    }
  }  /* end of parallel region */     
  // printf("c[i] is %f", c[1]); 
}