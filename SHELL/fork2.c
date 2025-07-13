#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()


{
   char str[100];
   char t1[30],t2[30],t3[30],t4[30];
   int n;
   
  while(1)
  
  {
  
     printf("MYSHELL $]");
     fgets(str, sizeof(str) ,stdin);
   
     n=sscanf(str, "%s %s %s %s",t1,t2,t3,t4);
  
   
   printf("Number Of Tokens  :%d\n",n);
  
     switch(n)
       {
          case 1 :
                   if( fork()==0)
                     {              //ls
                         execlp(t1,t1,NULL);
                     }
                    wait(0);
                    break; 
                    
          case 2  :// ls -l
                   if( fork()==0)
                     {              //ls
                         execlp(t1,t1,t2,NULL);
                     }
                    wait(0);
                    break;
            
           case 3  : //cp a,txt p.txt       count c a.txt
                   
                    
                             if( fork()==0)
                               {              //ls
                                execlp(t1,t1,t2,t3,NULL);
                               }
                                  wait(0);
                             
                    break;  
            case 4 :
                    if( fork()==0)
                     {              //ls
                         execlp(t1,t1,t2,t3,t4,NULL);
                     }
                    wait(0);
                    break;              
                              
                   
       } 
   
   
   }
   return 0;
   
}
