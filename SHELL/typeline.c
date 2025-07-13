#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>

  //t1  : "typeline"
  //t2  :"a"   ------->option[]
  //t3  :"a.txt"----  >fname[]
  
  //typeline(t2,t3);


  void typeline(char option[],char fname[])
    {
        int n; 
        int handle;
        char ch;
        int lcnt;     
       
       handle = open(fname,O_RDONLY);
       if(handle == -1)
        {
        
           printf("Unable To Open File  %s \n",fname);
           return;
        }
       
       
       
       
       
       
       if(strcmp(option,"a")== 0)
       {
             printf("Displaying All Lines From %s \n",fname);
             
             while(read(handle,&ch,1))
               {
                  //All lines
                   printf("%c",ch);
               }
                 close(handle);
           
       }
      else
       {                                  // "3"                            ->     3
                     n = atoi(option);//atoi converts character number into -> intrger number
                     if(n>=0)
                      {
                         //positive number
                         
                         printf("Displaying First %d Lines From %s \n",n,fname);
                         
                         lcnt=0;
                         
                         while(read(handle,&ch,1))
                            {
               
                                printf("%c",ch);
                                if(ch=='\n')
                                 {
                                   lcnt++;
                                 }  //0    3  given line reach to limt or not ->we given 3
                                if(lcnt==n) //check line count equal to n.  3=n
                                 {
                                    
                                    break;  // go to out of loop
                                 }
                            }
                            close(handle);
                      }
                     else
                      {
                        //negative number 
                        
                            lcnt=0;  //5 =total lines in file
                          while(read(handle,&ch,1))
                            {
               
                                
                                if(ch=='\n')
                                 {
                                   lcnt++;
                                 }     
                            }                 //a.txt-> have 5 lines  ->  "typeline -2 a.txt"
                            
                             n = lcnt +n;   //  converting -3 into 3, now n=3 ,skip that many lines 
                        
                             lseek(handle,0,SEEK_SET); //skip 3 lines and print rest of two  ,lseek-> srart to end 
                        
                            lcnt=0;
                            while(read(handle,&ch,1))
                              {
               
                                
                                         if(ch=='\n')
                                         {
                                            lcnt++;
                                         }  
                                          if(lcnt==n)
                                          {
                                             break;
                                  
                                          }   
                             } 
                            while(read(handle,&ch,1))
                            {
                         
                                 printf("%c",ch);
                         
                         
                         
                             }  
                              close(handle);    
                            
                            
                            
                  }
       }
        
       
       
       
       
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
                   
                   if( strcmp(t1,"typeline")==0)
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
