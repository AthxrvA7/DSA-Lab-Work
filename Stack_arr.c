#include<stdio.h>
#include<stdlib.h>
#define MAX 2

int top = -1;
void push(int arr[], int val) {
  if(top == MAX-1) 
    printf("Stack Overflow.\n");
  else {
    top++;
    arr[top] = val;
  }
}

void peek(int arr[]) {
  if(top == -1)
    printf("Empty");
  else
    printf("%d\n", arr[top]);
}

void pop(int arr[]) {
  if (top == -1)
    printf("Stack Underflow.\n");
  else {
    int element = arr[top];
    top--;
    return element;
  }
}

int main() {
  int top = -1;
  int arr[MAX];

  pop(arr);

  push(arr, 6);
  peek(arr);
  push(arr, 7);
  peek(arr);
  pop(arr);
  peek(arr);
  push(arr, 4);
  push(arr, 12);


}
