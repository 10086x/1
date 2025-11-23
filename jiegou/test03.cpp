#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5  


typedef struct {
    int *data;     
    int top;       
    int size;       
} Stack;


typedef struct QueueNode {
    int carNumber;          
    struct QueueNode *next; 
} QueueNode;


typedef struct {
    QueueNode *front;   
    QueueNode *rear;   
    int length;          
} Queue;


Stack* createStack(int size) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(sizeof(int) * size);
    stack->top = -1;
    stack->size = size;
    return stack;
}

int isStackEmpty(Stack *stack) {
    return stack->top == -1;
}

int isStackFull(Stack *stack) {
    return stack->top == stack->size - 1;
}

int push(Stack *stack, int carNumber) {
    if (isStackFull(stack)) {
        return 0; // 栈已满
    }
    
    // 添加车号唯一性检查
    for (int i = 0; i <= stack->top; i++) {
        if (stack->data[i] == carNumber) {
            return -1; // 返回-1表示车号重复
        }
    }
    
    stack->data[++stack->top] = carNumber;
    return 1; // 添加成功
}

int pop(Stack *stack) {
    if (isStackEmpty(stack)) {
        return -1;
    }
    return stack->data[stack->top--];
}

int peek(Stack *stack) {
    if (isStackEmpty(stack)) {
        return -1;
    }
    return stack->data[stack->top];
}

void destroyStack(Stack *stack) {
    free(stack->data);
    free(stack);
}

Queue* createQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    queue->length = 0;
    return queue;
}

int isQueueEmpty(Queue *queue) {
    return queue->front == NULL;
}

void enqueue(Queue *queue, int carNumber) {
    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->carNumber = carNumber;
    newNode->next = NULL;
    
    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->length++;
}

int dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        return -1; 
    }
    
    QueueNode *temp = queue->front;
    int carNumber = temp->carNumber;
    queue->front = queue->front->next;
    
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    
    free(temp);
    queue->length--;
    return carNumber;
}

int getQueueLength(Queue *queue) {
    return queue->length;
}

void destroyQueue(Queue *queue) {
    while (!isQueueEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

void displayStatus(Stack *parkingLot, Queue *waitingQueue) {

    if (isStackEmpty(parkingLot)) {
        printf("停车场: 空\n");
    } else {
        printf("停车场(从北到南): ");
        Stack *tempStack = createStack(parkingLot->size);
        int count = 0;

        while (!isStackEmpty(parkingLot)) {
            int car = pop(parkingLot);
            push(tempStack, car);
            count++;
        }
        for (int i = 1; i <= count; i++) {
            int car = pop(tempStack);
            printf("%d号车 ", car);
            push(parkingLot, car);
        }
        printf("\n");
        destroyStack(tempStack);
    }
    if (isQueueEmpty(waitingQueue)) {
        printf("便道: 空\n");
    } else {
        printf("便道(等待顺序): ");
        QueueNode *current = waitingQueue->front;
        while (current != NULL) {
            printf("%d号车 ", current->carNumber);
            current = current->next;
        }
        printf("\n");
    }
    printf("==================\n");
}
int main() {
    printf("命令格式: A 车牌号 - 车辆到达\n");
    printf("          D 车牌号 - 车辆离开\n");
    printf("          0 或负数 - 退出系统\n\n");
    Stack *parkingLot = createStack(MAX_SIZE);
    Queue *waitingQueue = createQueue();
    
    char command;
    int carNumber;
    
    while (1) {
        printf("\n请输入命令 (A/D 车牌号): ");
        scanf(" %c", &command);
        
        if (command == '0') {
            break;
        }
        
        scanf("%d", &carNumber);
        if (carNumber <= 0) {
            break;
        }
        
        if (command == 'A' || command == 'a') {
    if (!isStackFull(parkingLot)) {
        int result = push(parkingLot, carNumber);
        if (result == 1) {
            printf(" %d已停入停车场\n", carNumber);
        } else if (result == -1) {
            printf("错误：%d号车已在停车场中\n", carNumber);
        }
    } else {
        // 检查便道中是否有重复车号
        QueueNode *current = waitingQueue->front;
        int duplicateInQueue = 0;
        while (current != NULL) {
            if (current->carNumber == carNumber) {
                duplicateInQueue = 1;
                break;
            }
            current = current->next;
        }
        
        if (duplicateInQueue) {
            printf("错误：%d号车已在便道等候\n", carNumber);
        } else {
            enqueue(waitingQueue, carNumber);
            printf(" %d在便道等候，前面有 %d \n", 
                   carNumber, getQueueLength(waitingQueue) - 1);
        }
    }
}
        
        
        else if (command == 'D' || command == 'd') {
            Stack *tempStack = createStack(MAX_SIZE);
            int found = 0;
            while (!isStackEmpty(parkingLot)) {
                int currentCar = pop(parkingLot);
                if (currentCar == carNumber) {
                    found = 1;
                    printf("%d已离开停车场\n", carNumber);
                    break;
                } else {
                    push(tempStack, currentCar);
                }
            }
            
            if (!found) {
                printf("错误：%d", carNumber);
                while (!isStackEmpty(tempStack)) {
                    push(parkingLot, pop(tempStack));
                }
            } else {
                while (!isStackEmpty(tempStack)) {
                    push(parkingLot, pop(tempStack));
                }
                if (!isQueueEmpty(waitingQueue)) {
                    int nextCar = dequeue(waitingQueue);
                    push(parkingLot, nextCar);
                    printf("%d", nextCar);
                }
            }
            
            destroyStack(tempStack);
            
        } else {
            printf("错误\n");
            continue;
        }
        displayStatus(parkingLot, waitingQueue);
    }

    
    return 0;
}
