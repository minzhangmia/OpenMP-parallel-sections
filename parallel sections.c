#include <stdio.h>
#include <omp.h>

double count(double num)
{
	for(int i = 0;i < 1000;i++)
	{
		num = 3.6*num*(1 - num);
	}
	return num;
}

int main()
{
	omp_set_num_threads(4);
    #pragma omp parallel sections
	{
        #pragma omp section
		{
			printf("When x0 = 0.1,x1000 = %lf \n", count(0.1));
		}
		#pragma omp section
		{
			printf("When x0 = 0.2,x1000 = %lf \n", count(0.2));
		}
		#pragma omp section
		{
			printf("When x0 = 0.20001,x1000 = %lf \n", count(0.20001));
		}
        #pragma omp section
		{
			printf("When x0 = 0.200001,x1000 = %lf \n", count(0.200001));
		}
	}
}
