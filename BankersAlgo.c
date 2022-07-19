//program to implement Banker's Algorithm

#include<stdio.h>
int max[10][10],allocation[10][10],need[10][10];
int avail[10];
int np,nr;

void readMatrix(int matrix[10][10])
{
        int i,j;
        for(i=0;i<np;i++)
                for(j=0;j<nr;j++)
                        scanf("%d",&matrix[i][j]);
}

void displayMatrix(int matrix[10][10])
{
	int i,j;
         for(i=0;i<np;i++)
                printf("\n P%d\t",i);
                for(j=0;j<nr;j++)
                        printf("R%d",j);
}

void calculate_need()
{
	int i,j;
        for(i=0;i<np;i++)
                for(j=0;j<nr;j++)
                        need[i][j]=max[i][j]-allocation[i][j];
}

void bankers()
{
        int i,j,k=0,flag;
        int finish[10],safe_seq[10];
        for(i=0;i<np;i++)
                finish[i]=0;
        
        for(i=0;i<np;i++)
        {
                flag=0;
                if(finish[i]==0)
                {
                        for(j=0;j<nr;j++)
                        {
                                if(need[i][j]>avail[j])
                                {
                                      flag=1;
                                      break;
                                }
                        }
                        if(flag==0)  
                        {
                        	finish[i]=1;
                        	safe_seq[k]=i;
                        	k++;
                        	for(j=0;j<nr;j++)
                        		avail[j]=avail[j]+allocation[i][j];
                        		i=-1;
                        }
                   }
        }
        
        flag=0;
        for(i=0;i<np;i++)
        {
        	if(finish[i]==0)
        	{
			printf("System is in deadlock\n");
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("System is in safe sequence \t the sequence is \n");
		for(i=0;i<np;i++)
			printf("P%d\t",safe_seq[i]);
	}
}

void main()
{
	int j;
	printf("Enter the number of process :\t ");
	scanf("%d",&np);
	printf("Enter the no of resources :\t");
	scanf("%d",&nr);
	
	printf("Enter the maximum requirement matrix :\n");
	readMatrix(max);
	printf("Enter the allocated Matrix :\n");
	readMatrix(allocation);
	
	printf("Allocated Resources :\n"); 
	for(j=0;j<nr;j++)
		scanf("%d",&avail[j]);
	
	calculate_need();
	bankers();
}                      
                        
/*                        
goutham@ubuntu:~/Desktop/COLLEGE$ cc Bankers.c
goutham@ubuntu:~/Desktop/COLLEGE$ ./a.out
Enter the number of process :	 5   
Enter the no of resources :	3
Enter the maximum requirement matrix :
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
Enter the allocated Matrix :
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Allocated Resources :
3 3 2
System is in safe sequence 	 the sequence is 
P1	P3	P0	P2	P4	

*/

                      
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        