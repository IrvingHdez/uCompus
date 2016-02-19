#define MAX 50
int queue_array[MAX];
int rear = - 1;
int front = - 1;

void vfnQueueInit(void);
unsigned char bfnEnqueue(char* cpData, unsigned short wSize);
unsigned char bfnDequeue(char* cpData, unsigned short wSize);
// display();
