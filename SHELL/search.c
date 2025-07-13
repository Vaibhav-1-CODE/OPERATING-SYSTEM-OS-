#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>

  
 //                t2:f    t3:india       t4:a.txt  
  void search(char option[],char pat[],char fname[])
    {
    
           int handle;
           char ch;
           char data[1000];// stores lines
           int i;
           int count; // to keep number of occourances
           char *ptr;
           
           handle=open(fname,O_RDONLY);
            if(handle == -1)
               {
                 printf("Unable To Open Files  %s  !!\n",fname);
                 return;
               }
             
             // for first occurance
             if(strcmp(option,"F")==0)
              {
                       i=0;
                       while( read(handle,&ch,1))
                        {
                            data[i]=ch;  //read the data from zero index,
                            i++;
                            
                            if(ch=='\n')  //checking the end of line
                            {
                               data[i]='\0';
                               
                                 if(strstr(data, pat) !=NULL)
                                 {
                                        printf("First Occurance Line : %s \n",data);
                                        close(handle);
                                        return;
                                 }
                            
                                      i=0;
                            }
                        
                        
                        
                        }
              
              
              
              }
              
              //for  all occurance
             else if(strcmp(option,"A")==0)
              { 
              
                printf("Displaying All Occarances of %s  \n",pat);
                      i=0;
                       while( read(handle,&ch,1))
                        {
                            data[i]=ch;  //read the data from zero index,
                            i++;
                            
                            if(ch=='\n')  //checking the end of line
                            {
                               data[i]='\0';
                               
                                 if(strstr(data, pat) !=NULL)
                                 {
                                        printf(" Occurance Line  is   : %s \n",data);
                                        
                                 }
                            
                                      i=0;
                            }
                        
                        
                        
                        }
              
              
              
              }
              // count the number of occurance ,how many times any word is repate
             else if(strcmp(option,"C")==0)
              {
              
              count=0;
                        i=0;
                       while( read(handle,&ch,1))
                        {
                            data[i]=ch;  //read the data from zero index,
                            i++;
                            
                            if(ch=='\n')  //checking the end of line
                            {
                               data[i]='\0';
                               
                               /*  if(strstr(data, pat) !=NULL)  // for single occurance not for many
                                 {
                                        count++;
                                        
                                 }*/
                                 
                                
                                 ptr=data;
                                while( (ptr=strstr(ptr,pat)) !=NULL)
                                {
                                     count++;
                                     ptr++;
                                    
                                   
                                }
                            
                                      i=0;
                            }
                        
                        
                        
                        }
                        printf("%s Is Occures %d times  \n",pat,count);
                        close(handle);
              
              }
              
             else
             {
                          printf("Invalid optionnn is given  !!!\n");
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
            
           case 3  : //cp a,txt p.txt       
                   
                    if( fork()==0)
                        {              
                           execlp(t1,t1,t2,t3,NULL);
                        }
                      wait(0);
                     break;  
            case 4 :  // t1   t2  t3    t4
                     //search f india a.txt
                     
                     if(strcmp(t1,"search")==0)
                       {
                               search(t2,t3,t4);                      
                       }
            
                    else
                          {
                                        if( fork()==0)
                                          {              //ls
                                                execlp(t1,t1,t2,t3,t4,NULL);
                                          }
                          }                  wait(0);
                    break;              
                              
                   
       } 
   
   
   }
   return 0;
   
}


/*SEARCH COMMAND FROM SHELL 
         - MY SHELL] search F india  a.txt -> print first occurance of 'india'
         - MY SHELL] search A india  a.txt -> print ALL occurance of 'india'
         - MY SHELL] search C india  a.txt -> print  NO. occurance of 'india
         
*/
