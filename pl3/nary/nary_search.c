/*
Class:TE B
Roll no:20
*/

#include<stdio.h>
#include<math.h>
#include<omp.h>

int main()
{

	int sep[20],array[20],key,i,j,n,left,right,size,interval,index,break_value=0,tid;
	 
	printf("Enter the size of array\n");
	scanf("%d",&size);
	 
	
	for(i=0;i<size;i++)
	{
		printf("Enter the element %d:  \t",i);
		scanf("%d",&array[i]);
	}
 
	printf("\nEnter the key to be searched: \n");
	scanf("%d",&key);
	printf("Enter the value of partition:  \n");
	
	scanf("%d",&n);
 
	left=0;
	right=size-1;
 
	if(key>=array[left] && key<=array[right])
  	{
	   	while(left!=right)
	   	{
	     	
		     	printf("left=%d, right=%d, size=%d\n",left,right,size);
		     	if(size<=n)		//imp executed at second
		     	{
			      	#pragma parallel for num_threads(size)
			       	for(i=0;i<size;i++)
				{
				 	sep[i]=left+i;
				 	tid=omp_get_thread_num();
				 	printf("Thread %d allocated sep[%d]=%d\n",tid,i,array[sep[i]]);
				}
	      		}
	      
	     		else
	      		{	//executed first
	      			#pragma parallel for num_threads(n-1)		
	       			sep[0]=left;
	       			interval=ceil((float)size/(float)n);
	     
	     
	       			for(i=1;i<=n-1;i++)
				{
					 sep[i]=left+(interval*i)-1;
					 tid=omp_get_thread_num();
					 printf("Thread %d allocated sep[%d]=%d\n",tid,i,array[sep[i]]);
				}
		
	      			sep[n]=right;
	       		}
	       
	      		for(i=0;i<=n;i++)
	       		{
		 		if(key==array[sep[i]])
		  		{
					    index=sep[i];
					    printf("Element is at position %d\n",index);
					    break_value=1;
					    break;
		  		}
		 		if(key<array[sep[i]])
		  		{
					    right=sep[i];
					    if(i!=0);
					    left=1+sep[i-1];
					    size=right-left+1;
					    break;
				}
	       		}
	      		if(break_value==1)
			break;
   		}
	}
	if(left==right || !(key>=array[left] && key<=array[right]))
	printf("Element not found\n");
}

/*Output:
unix@unix-HP-280-G1-MT:~/Desktop$ gcc -fopenmp nary_search.c -lm
unix@unix-HP-280-G1-MT:~/Desktop$ ./a.out
Enter the size of array
7
Enter the element 0:  	12
Enter the element 1:  	24
Enter the element 2:  	36
Enter the element 3:  	40
Enter the element 4:  	59
Enter the element 5:  	62
Enter the element 6:  	78

Enter the key to be searched: 
40
Enter the value of partition:  
3
left=0, right=6, size=7
Thread 0 allocated sep[1]=36
Thread 0 allocated sep[2]=62
left=3, right=5, size=3
Thread 0 allocated sep[0]=40
Thread 0 allocated sep[1]=59
Thread 0 allocated sep[2]=62
Element is at position 3
*/
