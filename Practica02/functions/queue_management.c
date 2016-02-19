// #include "../headers/queue_management.h"

unsigned char bfnEnqueue(char* cpData, unsigned short wSize) {
  int add_item;
  if (rear == MAX - 1)
    printf("Queue Overflow \n");
  else {
    if (front == - 1)
      /*If queue is initially empty */
      front = 0;
    printf("Inset the element in queue : ");
    scanf("%d", &add_item);
    rear = rear + 1;
    queue_array[rear] = add_item;
  }
}
 
unsigned char bfnDequeue(char* cpData, unsigned short wSize) {
  if (front == - 1 || front > rear) {
    printf("Queue Underflow \n");
    return 0;
  }
  else {
    printf("Element deleted from queue is : %d\n", queue_array[front]);
    front = front + 1;
  }
} /*End of delete() */


/* display() { */
/*   int i; */
/*   if (front == - 1) */
/*     printf("Queue is empty \n"); */
/*   else { */
/*     printf("Queue is : \n"); */
/*     for (i = front; i <= rear; i++) */
/*       printf("%d ", queue_array[i]); */
/*     printf("\n"); */
/*   } */
/* } /\*End of display() *\/ */
