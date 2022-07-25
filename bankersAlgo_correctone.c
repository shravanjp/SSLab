#include<stdio.h>
int alloc[20][20],maxneed[20][20],rem_need[20][20];
int available[20];
int resourceGiven[20];
int totalResAllocated[20]={0};
int np,nr,i,j;

void readMatrix(int matrix[20][20]){
    for(i=0;i<np;i++){
        for(j=0;j<nr;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
}

void calculate_RemainingNeed(){
    for(i=0;i<np;i++){
        for(j=0;j<nr;j++){
           rem_need[i][j] =maxneed[i][j] - alloc[i][j];
        }
    }
}

void calculate_TotalResourceAllocated(){
    for(i=0;i<np;i++){
        for(j=0;j<nr;j++){
            totalResAllocated[j]+=alloc[i][j];
        }
    }
    for(j=0;j<nr;j++){
        available[j] = resourceGiven[j] - totalResAllocated[j];
    }
}

int areResourcesSufficient(int x){
    int flag=0,k;
    for(k=0;k<nr;k++){
        if(available[k] >= rem_need[x][k]){
            flag = 1;
        }else{
            flag = 0;
            break;
        }
    }
    return flag;
}

void Bankers(){
    int isAllocated[20] = {0};
    int flag = 0;
    int c=0;
    while(c<np){
        flag = 0;
        for(i=0;i<np;i++){
            int isSufficient = areResourcesSufficient(i);
            if(isAllocated[i] == 0 && isSufficient == 1){
                printf("Allocated Resource to : P%d\n",i);
                isAllocated[i] = 1;
                flag =1;
                c++;
                for(j=0;j<nr;j++){
                    available[j] += alloc[i][j];
                }
            }
        }
        if(flag == 0){
            break;
        }
    }
    if(c==np){
        printf("Safely Allocated\n");
    }else{
         printf("unSafe Allocation\n");
    }
}

void main(){
    printf("Enter the number of Processes:\n");
    scanf("%d",&np);
    printf("Enter the number of Resources:\n");
    scanf("%d",&nr);

    printf("Enter the Total Resource Given:\n");
    for(i=0;i<nr;i++){
        scanf("%d",&resourceGiven[i]);
    }

    printf("Enter Allocation Matrix\n");
    readMatrix(alloc);
    printf("Enter the Max need matrix\n");
    readMatrix(maxneed);
    

    calculate_RemainingNeed();
    calculate_TotalResourceAllocated();
    Bankers();
}

/*
Enter the number of Processes:
5
Enter the number of Resources:
3
Enter the Total Resource Given:
10 5 7
Enter Allocation Matrix
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Enter the Max need matrix
7 5 3
3 2 2
9 0 2
4 2 2
5 3 3
Allocated Resource to : P1
Allocated Resource to : P3
Allocated Resource to : P4
Allocated Resource to : P0
Allocated Resource to : P2
Safely Allocated
*/