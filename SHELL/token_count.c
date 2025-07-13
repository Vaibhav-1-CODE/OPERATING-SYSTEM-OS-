#include<stdio.h>

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
   
          printf("Token 1 : %s\n",t1);
          printf("Token 2 : %s\n",t2);
          printf("Token 3 : %s\n",t3);
          printf("Token 4 : %s\n",t4);
   
   
   printf("Number Of Tokens  :%d\n",n);
   
   
   }
   return 0;
   
}
