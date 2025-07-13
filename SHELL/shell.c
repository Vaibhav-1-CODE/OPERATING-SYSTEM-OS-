#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>

  //t1  : "count "
  //t2  :"c"   ------->option[]
  //t3  :"a.txt"----  >fname[]
  
  //count(t2,t3);


  void count(char option[],char fname[])
    {
        int ccnt=0,wcnt=0,lcnt=0; //counters
        
        int handle;   //use to control file
        char ch;     //used to store read character
        
           handle = open(fname,O_RDONLY);
        
           if(handle == -1)
              {
                 printf("Unable To Open File  %s !!\n",fname);
                 return;
              }
                         
                         
                            //logic
             
                            while(read(handle,&ch,1))
                            {
                               ccnt++;   //for character
                               
                               if(ch==' ' || ch=='\t')
                                {
                                   wcnt++;  //for words
                                }
                               else if(ch=='\n')
                                {
                                  lcnt++;
                                  wcnt++;
                                
                                } 
                            }
             
             
             
        
        
        
        
                           //for print
        
                      if(strcmp(option,"c")==0)
                          {
                              printf("Number Of Character  :%d \n",ccnt);
          
          
                          }
                     else if(strcmp(option,"w")==0)
                         {
                             printf("Number Of Words    : %d \n",wcnt);
           
                         } 
    
                    else if(strcmp(option,"l")==0)
                      {
                             printf("Number Of Lines   : %d \n",lcnt);
               
                      }
                    else
                     {
                            printf("Invalid Option Is Given For Count Command !!!\n");
          
                    }
    
    
    } 

   void typeline(char option[],char fname[])
  
  {
          printf("I Am In Typeline \n");
  }




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
  
   
   //   printf("Number Of Tokens  :%d\n",n);
  
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
                   
                   if( strcmp(t1,"count")==0)
                    {
                        count(t2,t3);  // t2:"c"  t3: "a.txt"
                     
                    }
                   
                   
                   else if( strcmp(t1,"typeline")==0)
                    {
                        typeline(t2,t3);  // t2:"c"  t3: "a.txt"
                     
                    }
                   
                    else
                     {
                    
                    
                             if( fork()==0)
                               {              //ls
                                execlp(t1,t1,t2,t3,NULL);
                               }
                                  wait(0);
                      }       
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
