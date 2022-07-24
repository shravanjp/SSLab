#include<stdio.h>
int frame[10],page[20],recent[10],f,n,i,j,k,choice;
int pageHit=0;

void FIFO(){
    int isPageHit, curPtr=0;
    for(i=0;i<n;i++){
        isPageHit = 0;
        for(j=0;j<f;j++){
            if(page[i] == frame[j]){
                pageHit++;
                isPageHit = 1;
            }
        }
        if(isPageHit == 0){
            curPtr = curPtr %f;
            frame[curPtr] = page[i];
            curPtr++;
        }
        printf("\nFrame:\t");
        for(k=0;k<f;k++){
            printf("%d  ",frame[k]);
        }
    }
    printf("\nNumber of Page Hit : %d\n",pageHit);
    printf("Number of page fault : %d \n",n-pageHit);
}

int findLeastRecentlyUsedPage(int recent[],int frameSize){
    int leastPageVal = recent[0];
    int leastPage = 0;
    int l;
    for(l = 1;l<frameSize;l++){
        if(recent[l] < leastPageVal){
            leastPageVal = recent[l];
            leastPage = l;
        }
    }
    return leastPage;
}

void LRU(){
    int isPageHit = 0,isFirstFramePages = 0,counter=0;
    pageHit=0;
    for(i=0;i<f;i++){
        frame[i] = -1;
    }
    
    for(i=0; i<n;i++){
        isFirstFramePages=0;
        isPageHit=0;

        for(j=0;j<f;j++){
            if(page[i] == frame[j]){
                isPageHit = 1;
                pageHit++;
                counter++;
                recent[j] = counter;
                break;
            }
        }

        if(isPageHit == 0){
            for(j=0;j<f;j++){
                if(frame[j] == -1){
                    isFirstFramePages = 1;
                    frame[j]=page[i];
                    counter++;
                    recent[j] = counter;
                    break;
                }
            }
        }
        if(isPageHit==0 && isFirstFramePages == 0){
            int pos = findLeastRecentlyUsedPage(recent,f);
            counter++;
            recent[pos]  = counter;
            frame[pos] = page[i];
        }

        for(k=0;k<f;k++)
            printf("%d ",frame[k]);
        printf("\n");

    }
    printf("Number of page hit : %d\n",pageHit );
    printf("Number of page fault : %d",n-pageHit);
}


void main(){
    printf("Enter page size:\n");
    scanf("%d",&n);
    printf("Enter %d page numbers/resources \n",n);
    for(i=0;i<n;i++){
        scanf("%d",&page[i]);
    }
    printf("Enter the frame Buffer size:\n");
    scanf("%d",&f);

    for(i=0;i<f;i++){
        frame[i] = -1;
    }

    printf("\n1:FIFO\n2:LRU\nEnter your choice:");
    scanf("%d",&choice);

    switch(choice){
        case 1: FIFO();
                break;

        case 2: LRU();
                break;
    }

}

/*
Enter page size:
10
Enter 10 page numbers/resources
7 0 1 2 0 3 0 4 2 3
Enter the frame Buffer size:
3

1:FIFO
2:LRU
Enter your choice:2
7 -1 -1
7 0 -1
7 0 1
2 0 1
2 0 1
2 0 3
2 0 3
4 0 3
4 0 2
4 3 2
Number of page hit : 2
Number of page fault : 8
PS D:\SSLab>
*/

/*
Enter page size:
10
Enter 10 page numbers/resources 
7 0 1 2 0 3 0 4 2 3
Enter the frame Buffer size:
3

1:FIFO
2:LRU
Enter your choice:1

Frame:  7  -1  -1         
Frame:  7  0  -1          
Frame:  7  0  1  
Frame:  2  0  1  
Frame:  2  0  1  
Frame:  2  3  1  
Frame:  2  3  0  
Frame:  4  3  0  
Frame:  4  2  0  
Frame:  4  2  3  
Number of Page Hit : 0    
Number of page fault : 10 
PS D:\SSLab> 
*/