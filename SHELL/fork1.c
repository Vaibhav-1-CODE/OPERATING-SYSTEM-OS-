#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main()
{

   if(fork()==0)
   
   {
   
      execlp("vlc","vlc",NULL);
   
   
   }
   
   
   
   
   wait(0);
   
   printf("Task Perform");
   
   return (0);
   
}
