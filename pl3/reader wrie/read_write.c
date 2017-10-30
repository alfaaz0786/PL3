#include<stdio.h>
#include<omp.h>

omp_lock_t readlock;
omp_lock_t writelock;
int data=5;

void *reader(int arg)
{
	int f=((int)arg);
	omp_set_lock(&writelock);
	printf("\n Reading data %d by thread %d \n",data,f);
	printf("\n Writing going to sleep for 3 sec \n");
	omp_unset_lock(&writelock);
}

void *writer(int arg)
{
	int w=((int) arg);
	omp_set_lock(&readlock);
	omp_set_lock(&writelock);
	data=data*2;
	printf("\n Writing data %d by thread %d \n",data,w);
	printf("\n Reading going to sleep for 3 sec \n");
	omp_unset_lock(&writelock);
	omp_unset_lock(&readlock);
}

int main()
{
	omp_init_lock(&readlock);
	omp_init_lock(&writelock);
	omp_set_num_threads(2);
	#pragma omp parallel
	{
		int id=omp_get_thread_num();
		switch(id)
		{
			case 0:
				//sleep(3);
				reader(0);
				break;
			
			case 1:
				writer(1);
				//sleep(3);
				break;
		}
	}
	return 0;
}

/*Output:
unix@unix-HP-280-G1-MT:~$ gcc -fopenmp read_write.c
unix@unix-HP-280-G1-MT:~$ ./a.out

 Reading data 5 by thread 0 

 Writing going to sleep for 3 sec 

 Writing data 10 by thread 1 

 Reading going to sleep for 3 sec 
*/
