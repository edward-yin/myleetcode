#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 1024
typedef struct {
    int stackHead;
    int stackTail;
    int stackIn[MAX_STACK_SIZE];
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue *queue = (MyQueue *)malloc(sizeof(MyQueue));
    if (queue == NULL) {
        return NULL;
    }
    memset(queue, 0, sizeof(MyQueue));
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    if (!obj) {
        return;
    }
    int inTop = obj->stackTail;
    if (obj->stackHead >= MAX_STACK_SIZE - 1) {
        return;
    }
    obj->stackIn[inTop] = x;
    obj->stackTail++;
    return;
}

int myQueuePop(MyQueue* obj) {
    if (!obj) {
        return 0;
    }
    if (obj->stackHead >= MAX_STACK_SIZE - 1 || obj->stackTail <= 0 || obj->stackHead >= obj->stackTail) {
        return 0;
    }
    int ret = obj->stackIn[obj->stackHead];
    obj->stackHead++;
    return ret;
}

int myQueuePeek(MyQueue* obj) {
    if (!obj) {
        return 0;
    }
    if (obj->stackHead >= MAX_STACK_SIZE - 1 || obj->stackTail <= 0 || obj->stackHead >= obj->stackTail) {
        return 0;
    }
    return obj->stackIn[obj->stackHead];
}

bool myQueueEmpty(MyQueue* obj) {
    if (!obj) {
        return false;
    }
    if (obj->stackHead == obj->stackTail) {
        return true;
    }
    return false;
}

void myQueueFree(MyQueue* obj) {
    if (!obj) {
        return;
    }
    free(obj);
    obj = NULL;
}

int main(int argc, const char *argv[])
{
    MyQueue* obj = myQueueCreate();
    if (!obj) {
        printf("NULL\n");
    }
    myQueuePush(obj, 1);
    myQueuePush(obj, 2);
    int param_3 = myQueuePeek(obj);
    printf("%d\n",param_3);
    int param_2 = myQueuePop(obj);
    printf("%d\n",param_2);
    bool param_4 = myQueueEmpty(obj);
    printf("%d\n",param_4);
    myQueueFree(obj);
    return 0;
}