
#include<stdio.h>
#define size 4
int array[size];
int front= 0;int Rear= 0;
int isEmpty()
{
   if(front==Rear)
   return 1; return -1;
}
void dequeue()
{
   if(isEmpty()==1)
       printf("Queue is Empty.\n");
   else
   {
       printf("Dequeued element=%d\n",array[front]);
       front++;
   }
}
int isQueueFull()
{
   if(Rear==size)
return 1; return -1;
}
void enQ(int val)
{
   if(isQueueFull()==1)
       printf("Queue is Full\n");
   else
   {
       array[Rear]=val;
       Rear=Rear+1;
   }
}
int main()
{
   enQ(100);
   enQ(300);
   enQ(400);
   enQ(500);
   enQ(600);
   dequeue();      
   dequeue();     
   dequeue();      
   dequeue();      
   dequeue();      
   return 0;
}