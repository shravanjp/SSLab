//program to demonstrate Shift reduce parsing

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i,j,c,z;
char a[20],ac[20],stk[20],act[20];

void check();

void main()
{
        puts("grammar is \n E->E+T|T\n T->T*F|F\n F->(E)|id \n");
        printf("Enter the string :\t");
        scanf("%s",a);
        c=strlen(a);
        strcpy(act,"shift->");
        puts("stack\t\t input\t\t action\t");
            
        for(i=0,j=0;j<c;i++,j++)
        {
                if(a[j]=='i' && a[j+1]=='d')
                {
                        stk[i]=a[j];
                        stk[i+1]=a[j+1];
                        stk[i+2]='\0';
                        a[j]=' ';
                        a[j+1]=' ';
                        printf("$%s\t %s$\t %sid\n",stk,a,act);
                        check();
                 }
                 else{
                        stk[i]=a[j];
                        stk[i+1]='\0';
                        a[j]=' ';
                        printf("$%s\t %s$\t %ssymbol\n",stk,a,act);
                        check();
                      }
          }
}

void check()
{
        strcpy(ac,"Reduce");
        for(z=0;z<c;z++)
        {
                if (stk[z]=='(' && stk[z+1]=='E' && stk[z+2]==')')
                {
                        stk[z]='F';
                        stk[z+1]='\0';
                        stk[z+2]='\0';
                        printf("$%s\t %s$\t %s\n",stk,a,ac);
                        i=i-2;
                 }
          }

        for(z=0;z<c;z++)
        {
                if (stk[z]=='i'  && stk[z+1]=='d')
                {
                        stk[z]='F';
                        stk[z+1]='\0';
                        printf("$%s\t %s$\t %s\n",stk,a,ac);
                        j=j+1;
                 }
         }

        for(z=0;z<c;z++)
        {
                if (stk[z]=='T' && stk[z+1]=='*' && stk[z+2]=='F')
                {
                        stk[z]='T';
                        stk[z+1]='\0';
                        stk[z+2]='\0';
                        printf("$%s\t %s$\t %s\n",stk,a,ac);
                        i=i-2;
                 }
                 else if(stk[z]=='F')
                 {
                        stk[z]='T';
                        stk[z+1]='\0';
                         printf("$%s\t %s$\t %s\n",stk,a,ac);
                      
                  }
          }
          
         for(z=0;z<c;z++)
        {
                if (stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='T' && stk[z+3]=='*')
                        break;
                if (stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='T')             
                 {
                        if(a[j+1]=='*')
                                break;
                        else{
                                  stk[z]='E';
                                  stk[z+1]='\0';
                                  stk[z+2]='\0';
                                  printf("$%s\t %s$\t %s\n",stk,a,ac);
                                  i=i-2;
                             }
                 }else if(stk[z]=='T')
                        {
                                stk[z]='E';
                                stk[z+1]='\0';
                                printf("$%s\t %s$\t %s\n",stk,a,ac);
                           
                        }
         }
}


/*

goutham@ubuntu:~/Desktop/COLLEGE$ cc Lab05.c
goutham@ubuntu:~/Desktop/COLLEGE$ ./a.out
grammar is 
 E->E+T|T
 T->T*F|F
 F->(E)|id 

Enter the string :	id+id*id
stack		 input		 action	
$id	   +id*id$	 shift->id
$F	   +id*id$	 Reduce
$T	   +id*id$	 Reduce
$E	   +id*id$	 Reduce
$E+	    id*id$	 shift->symbol
$E+id	      *id$	 shift->id
$E+F	      *id$	 Reduce
$E+T	      *id$	 Reduce
$E+T*	       id$	 shift->symbol
$E+T*id	         $	 shift->id
$E+T*F	         $	 Reduce
$E+T	         $	 Reduce
$E	         $	 Reduce
goutham@ubuntu:~/Desktop/COLLEGE$ 

*/