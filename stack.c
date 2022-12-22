#include <stdio.h>

int size=3;       
int stack[3];     
int top=-1;            

int empty() {

   if(top==-1)
      return 1; return 0;

}
int full() {
   if(top==size)
      return 1; return 0;
}

int peek() {
   return stack[top];
}

int pop() {
   int data;
	
   if(!empty()) {
      data=stack[top];
      top--;
      return data;
} else {
      printf("can't retern data because the Stack is empty.\n");
}
}

int put(int data) {

   if(!full()) {
      top=top+1;   
      stack[top]=data;
 } else {
      printf("Can't add data because the Stack is full.\n");
}
}

int main() {
   put(1);put(2);put(3);
   printf("First element of the stack: %d\n" ,peek());
   printf("Elements:\n");
   while(!empty()) {
      int data=pop();
      printf("%d\n",data);
}
   printf("Stack is full: %s\n" , full()?"yes":"no");
   printf("Stack is empty: %s\n" , empty()?"yes":"no");
   
   return 0;
}