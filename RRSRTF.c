#include<stdio.h>
#include<stdlib.h>

struct proc{
    int id;
    int arrive;
    int rem;
    int burst;
    int finish;
    int tat;
    int wt;
}process[10];
struct proc temp;
int np,n0,j,i,k,time=0;
float avgWait=0,avgTAT=0;


int checkProcess(int n){
    int x;
    for(x=1;x<=n;x++){
        if(process[i].rem!=0)
            return 1;
    }
    return 0;
}

int nextProcess(){
    int min=32000,l=1,k;
    for(k=1;k<=n0;k++){
        if(process[k].rem!=0 && process[k].rem<min){
                min=process[k].rem;
                l=k;
        }
    }
    return l;
}

void SRTF(){
    printf("Enter the number of process:\n");
    scanf("%d",&np);
    printf("Enter the burst time for %d arrival and burst time in sequence:\n",np);
    for(int i=1;i<=np;i++){
        process[i].id=i;
        scanf("%d",&process[i].arrive);
        scanf("%d",&process[i].burst);
        process[i].rem=process[i].burst;
    }

    for(i=1;i<=np;i++){
        for(j=i+1;j<=np;j++){
            if(process[i].arrive > process[j].arrive){
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    n0=0;
    j=1;

    while(checkProcess(np)==1){
        if(process[n0+1].arrive == time){
            while(process[n0+1].arrive==time){
                n0++;
            }

            if(process[j].rem==0)
                process[j].finish=time;
            
            j=nextProcess();
        }
        
        if(process[j].rem!=0){
            process[j].rem--;
            for(i=1;i<=n0;i++){
                if(i!=j && process[i].rem!=0){
                    process[i].wt++;
                }
            }
        }
        else{
            process[j].finish=time;
            j=nextProcess();
            time--;
            k=j;
        }

        time++;
    }
    process[k].finish=time;

    for(i=1;i<=np;i++){
        process[i].tat = process[i].wt+process[i].burst;
        avgTAT+=process[i].tat;
        avgWait+=process[i].wt;
    }

     printf("\tProcess\tBurst Time\tTAT\tWaiting Time\n");
    for(i=1;i<=np;i++){
        printf("\t%d\t%d\t\t%d\t\t%d\n",i+1,process[i].burst,process[i].tat,process[i].wt);
    }

}



void RoundRobin(){
    int burst_time[20],temp_burstTime[20],timeQuantum,n,processCount=0,temp,sq=0,i;
    float avgWaitingTime=0,avgTAT=0;
    int tat[20],wt[20];
    printf("Enter the number of process:\n");
    scanf("%d",&n);
    printf("Enter the burst time for %d process in sequence:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&burst_time[i]);
        temp_burstTime[i]=burst_time[i];
    }
    printf("Enter the value of Time Quantum:\n");
    scanf("%d",&timeQuantum);

    while(1){
        for(i=0,processCount=0;i<n;i++){
            temp = timeQuantum;
            if(temp_burstTime[i]==0){
                processCount++;
                continue;;
            }

            if(temp_burstTime[i]>timeQuantum){
                temp_burstTime[i] = temp_burstTime[i] - timeQuantum;
            }

            else if(temp_burstTime[i] >=0){
                temp = temp_burstTime[i];
                temp_burstTime[i]=0;
            }
            sq = sq + temp;
            tat[i] = sq;
        }

        if(processCount == n){
            break;
        }
    }
    for(i=0;i<n;i++){
        wt[i] = tat[i] - burst_time[i];
        avgWaitingTime += wt[i];
        avgTAT += tat[i];
    }

    avgWaitingTime = avgWaitingTime/(float)n;
    avgTAT = avgTAT/(float)n;

    printf("\tProcess\tBurst Time\tTAT\tWaiting Time\n");
    for(i=0;i<n;i++){
        printf("\t%d\t%d\t\t%d\t\t%d\n",i+1,burst_time[i],tat[i],wt[i]);
    }
    printf("Avg Waiting Time: %f\n",avgWaitingTime);
    printf("Avg Turn Around Time: %f\n",avgTAT);

}

int main(){
    int choice;
    printf("1:ROUND ROBIN\n2:SRTF\nEnter your choice:\n");
    scanf("%d",&choice);

    switch(choice){
        case 1:RoundRobin();break;
        case 2:SRTF();break;
        case 3:exit(0);
    }

    return 0;
}