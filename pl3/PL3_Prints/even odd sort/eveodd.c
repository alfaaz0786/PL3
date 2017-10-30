//Odd_even
#include<stdio.h>
#include<omp.h>
int i,k;
void EvenOdd(int a[],int size);
void display(int a[], int size);
void main()
{
	int size;
	printf("\nEnter the size of array:\t");
	scanf("%d",&size);
	int l[size];
	printf("\nEnter the array Elements:\n");
	for(i=0;i<size;i++)
	{
	  scanf("%d",&l[i]);
	}
	printf("\nArray elements are:\n");
	for(i=0;i<size;i++)
	{
	   printf("%d\t",l[i]);
	}
	printf("\n");
	EvenOdd(l,size);
    
}
 
void display(int a[], int size)
{
	for( k=0;k<size;k++)
	{
		printf("%d",a[k]);
		printf("\t");
	}
} 
     
void EvenOdd(int a[],int size)
{
	double starttime=omp_get_wtime();
	printf("\nStart time is:\t%lf",starttime);
	int temp=0,state,t;

     	for(state=0;state<size;state++)
     {	

     		  if(state%2==0)
	     	{
	      #pragma omp  parallel for default(none) shared(a,size) private(i,temp)
     		for(i=1;i<size;i+=2)
     		if(a[i-1]>a[i])
     		{
     			temp=a[i];
     			a[i]=a[i-1];
     			a[i-1]=temp;
     		}
     		printf("\nEven State:\n");
     		printf("\n");
    			for(t=0;t<size;t++)
   			{
         			printf("%d\t",a[t]);
     		}
    		}
     	
     	else
     	{
     		 #pragma omp  parallel for default(none) shared(a,size) private(i,temp)
     		for(i=2;i<size;i+=2)
     		if(a[i-1]>a[i])
     		{
     			temp=a[i];
     			a[i]=a[i-1];
     			a[i-1]=temp;
     		}
     		printf("\nOdd State:\n");
     		printf("\n");
     		for(t=0;t<size;t++)
     		{
     		    printf("%d\t",a[t]);
    		}
     			
     	}	
    	}	
    	double endtime=omp_get_wtime();
     printf("\n End time is:\t%lf",endtime);
     printf("\nSorted Array elements are:\n");
     display(a,size);
     /*printf("\n");
     for(i=0;i<size;i++)
     {
         printf("%d\t",a[i]);
         
     }*/
     	printf("\nTime require for execution is:\t%lf",endtime-starttime);

}


/*
Output:


unix@unix-HP-dx2280-MT-RA529AV:~$ gcc -fopenmp eveodd.c
unix@unix-HP-dx2280-MT-RA529AV:~$ ./a.out

Enter the size of array:	8

Enter the array Elements:
55
33
11
22
44
99
88
77

Array elements are:
55	33	11	22	44	99	88	77	

Start time is:	1340.209935
Even State:

33	55	11	22	44	99	77	88	
Odd State:

33	11	55	22	44	77	99	88	
Even State:

11	33	22	55	44	77	88	99	
Odd State:

11	22	33	44	55	77	88	99	
Even State:

11	22	33	44	55	77	88	99	
Odd State:

11	22	33	44	55	77	88	99	
Even State:

11	22	33	44	55	77	88	99	
Odd State:

11	22	33	44	55	77	88	99	
 End time is:	1340.210505
Sorted Array elements are:
11	22	33	44	55	77	88	99	
Time require for execution is:	0.000569

*/

