#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int isValidNumber(int number) {
 
int c=0,r=0;
if(number>0)
{
    while(number>0)
    {
number=number/10;
c++;
    }
if(c==5)
r=1;
else 
r=0;
}
else
r=0;
    return r;
}
 
int isNumberExists(int* speeddials, int speeddials_size, int number) {
 
int r,i,flag=0;
for(i=0;i<speeddials_size;i++)
{
    if(speeddials[i]==number)
    {
        flag=1;
    r=i;
    break;
    }
}
if(flag==0)
{
    r=-1;
}
    return r;
}
 
int autoAssignSpeedDial(int* speeddials, int speeddials_size, int number) {
 
int r,flag=0,i;
for(i=0;i<speeddials_size;i++)
{
    if(speeddials[i]==number)
    {
        r=-1;
        break;
    }
    if(speeddials[i]==0)
    flag=1;
}
if(flag!=1)
r=-1;
else{
for(i=0;i<speeddials_size;i++)
{
    if(speeddials[i]==0)
    {
        r=i;
    speeddials[i]=number;
    break;
    }
}
}
    return r;
}
 
int assignSpeedDial(int* speeddials, int speeddials_size, int number, int index, int overwrite) {
 
int i,c=0,number1,r;
number1=number;
while(number1>0)
{
    number1=number1/10;
    c++;
}
for(i=0;i<speeddials_size;i++)
{
if(c!=5 || speeddials[i]==number || (speeddials[index]!=0 && overwrite==0))
{
    r=-1;
    break;
}
else{
    if(overwrite==1)
    {
        speeddials[index]=number;
        r=index;
    }
    else if(overwrite==0)
    {
        if(speeddials[index]==0)
        {
            r=index;
            speeddials[index]=number;
            break;
        }
    }
}
}
    return r;
}
 
int removeSpeedDialByActualNumber(int* speeddials, int speeddials_size, int number) {
 
int i,r,flag=0;
for(i=0;i<speeddials_size;i++)
{
    if(speeddials[i]!=number)
    {
       r=-1;
       flag=1;
    }
        else if(speeddials[i]==number)
        {
              flag=0;
              break;
        }
}
if(flag!=1)
{
    for(i=0;i<speeddials_size;i++)
    {
     if(speeddials[i]==number)
    {
        speeddials[i]=0;
        r=i;
        break;
    }
    }
}
    return r;
}
 
int removeSpeedDial(int* speeddials, int speeddials_size, int speedDialNumber) {
 
int r,i;
for(i=0;i<speeddials_size;i++)
{
    if(speeddials[speedDialNumber]!=0)
    {
        speeddials[speedDialNumber]=0;
        r=speedDialNumber;
        break;
    }
    else{
        r=-1;
    }
}
    return r;
}
 
void printSpeedDialsArray(int* speeddials, int speeddials_size) {
 
int i;
    printf("SpeedDials:");
for(i=0;i<speeddials_size;i++)
{
    printf(" %d",speeddials[i]);
}
printf("\n");
    return ;
}
 
void printHistoryArray(int* history, int history_size) {
 
int i;
printf("History:");
for(i=0;i<history_size;i++)
{
    if(history[i]!=0)
    printf(" %d",history[i]);
}
printf("\n");
    return ;
}
 
int callSpeedDial(int* speeddials, int speeddials_size, int* history, int* history_cur_size_ptr, int speedDialNumber) {
 
int i,r,flag=0;
    if(speeddials[speedDialNumber]==0)
    {
       r=-1;
       history_cur_size_ptr=0;
    }
     if(speeddials[speedDialNumber]!=0)
    {
        history[*history_cur_size_ptr]=speeddials[speedDialNumber];
        *history_cur_size_ptr=1;
        r=1;
    }
    return r;
}
 
int callNumber(int* history, int* history_cur_size_ptr, int number) {
 
int number1=number,c=0,r;
while(number1>0)
{
    number1=number1/10;
    c++;
}
if(c==5 && number>0)
{
    r=1;
    history[*history_cur_size_ptr]=number;
    *history_cur_size_ptr=1;
}
else if(c!=5 || number<0){
    r=-1;
}
    return r;
}
 
void listSpeedDialCallCount(int* speeddials, int speeddials_size, int* history, int history_size) {
 
int i,j,c;
printf("SpeedDial Number Count\n");
for(i=0;i<speeddials_size;i++)
{
    if(speeddials[i]!=0)
    {
    c=0;
    for(j=0;j<history_size;j++)
    {
        if(speeddials[i]==history[j])
        c++;
    }
    printf("    %d      %d   %d\n",i,speeddials[i],c);
}
}
    return ;
}
 
void printTopKLargestNumbers(int* history, int history_size, int k) {
 
int i,j,h[history_size],temp=0,k1;
for(i=0;i<history_size;i++)
{
    h[i]=history[i];
}
for(i=0;i<history_size;i++)
{
 for(j=i+1; j<history_size; j++)
        {
            if(h[i] < h[j])
            {
                temp = h[i];
                h[i] = h[j];
                h[j] = temp;
            }
        }
}
for(i = 0; i < history_size; i++)
    {
        for(j = i+1; j < history_size; )
        {
            if(h[j] == h[i])
            {
                for(k1 = j; k1 < history_size; k1++)
                {
                    h[k] = h[k1+1];
                }
                history_size--;
            }
            else
            {
                j++;
            }
        }
    }
for(i=0;i<k;i++)
{
    if(h[i]!=h[i-1])
    printf("%d\n",h[i]);
    else
    printf("%d\n",h[i+1]);
}
    return ;
}
 
void performOperations() {
 
 int speeddials[25] = { 0 };
   int history[100] = { 0 };
   int speeddials_size = 25;
   int history_size = 50;
   int history_cur_size = 0;
   int* history_cur_size_ptr = &history_cur_size;
   while(1) {
       /*
       1. AutoAssignSpeedDial
       2. AssignSpeedDial
       3. removeSpeedDialByActualNumber
       4. removeSpeedDial
       5. callSpeedDial
       6. callNumber
       7. listSpeedDialCallCount
       8. printTopKCalledNumbers
       9. printSpeedDialsArray
       10. printHistoryArray
       11. Exit
       */
       int oType;
       scanf("%d ",&oType);
       if (oType == 1) {
           int number;
           scanf("%d ",&number);
           int returnvalue_var=autoAssignSpeedDial(speeddials,speeddials_size,number);
           if (returnvalue_var!=-1) {
                printf("Auto Assigned %d to speedDial %d\n",number,returnvalue_var);
           } else {
                printf("Auto Assign SpeedDial Failed for %d\n",number);
           }
       } else if (oType == 2) {
           int number;
           scanf("%d ",&number);
           int index;
           scanf("%d ",&index);
          in returnvalue_var1; returnvalue_var1=assignSpeedDial(speeddials,speeddials_size,number,index, 0);
       if (returnvalue_var1!=-1) {
                printf("Assigned %d to speedDial %d\n",number,returnvalue_var1);
           }
          
       }  else if (oType == 3) {
           int number;
           scanf("%d ",&number);
           removeSpeedDialByActualNumber(speeddials,speeddials_size,number);
       }  else if (oType == 4) {
           int number;
           scanf("%d ",&number);
           removeSpeedDial(speeddials,speeddials_size,number);
       }   else if (oType == 5) {
           int number;
           scanf("%d ",&number);
           int called ;           called=callSpeedDial(speeddials,speeddials_size,history,history_cur_size_ptr,number);
           if (called != -1) {
                printf("Called SpeedDial: %d, Number: %d\n",number, speeddials[number]);
           } else {
               printf("No speeddial exists for %d\n",number);
           }
       }  else if (oType == 6) {
           int number;
           scanf("%d ",&number);
           callNumber(history,history_cur_size_ptr,number);
           printf("Called Number: %d\n",number);
       }  else if (oType == 7) {
           listSpeedDialCallCount(speeddials,speeddials_size,history, history_size);
       }  else if (oType == 8) {
           int k;
           scanf("%d ",&k);
           printTopKLargestNumbers(history,history_size,k);
       } else if(oType == 9) {
           printSpeedDialsArray(speeddials,speeddials_size);
       } else if(oType == 10) {
           printHistoryArray(history,history_size);
       }
       if (oType == 11) {
           break;
       }
   }
    
    return ;
}




