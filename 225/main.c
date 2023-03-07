#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 1024
typedef struct {
    int stackTop;
    int stack[MAX_STACK_SIZE];
} MyStack;

MyStack* myStackCreate() {
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    if (stack == NULL) {
        return NULL;
    }
    memset(stack, 0, sizeof(MyStack));
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    if (obj == NULL) {
        return;
    }
    if (obj->stackTop >= MAX_STACK_SIZE || obj->stackTop < 0) {
        return;
    }
    obj->stack[obj->stackTop] = x;
    obj->stackTop++;
    return;
}

int myStackPop(MyStack* obj) {
    if (obj == NULL) {
        return -1;
    }
    if (obj->stackTop >= MAX_STACK_SIZE || obj->stackTop < 0) {
        return -1;
    }
    int ret = obj->stack[obj->stackTop - 1];
    obj->stack[obj->stackTop - 1] = 0;
    obj->stackTop--;
    return ret;
}

int myStackTop(MyStack* obj) {
    if (obj == NULL) {
        return -1;
    }
    if (obj->stackTop >= MAX_STACK_SIZE || obj->stackTop < 0) {
        return -1;
    }
    return obj->stack[obj->stackTop - 1];
}

bool myStackEmpty(MyStack* obj) {
    if (obj == NULL) {
        return true;
    }
    if (obj->stackTop >= MAX_STACK_SIZE || obj->stackTop < 0) {
        return true;
    }
    if (obj->stackTop == 0) {
        return true;
    }
    return false;
}

void myStackFree(MyStack* obj) {
    if (obj == NULL) {
        return;
    }
    free(obj);
}

int main()
{
    MyStack* obj = myStackCreate();
    if (!obj) {
        printf("NULL\n");
    }
    myStackPush(obj, 1);
    myStackPush(obj, 2);
    int param_3 = myStackTop(obj);
    printf("%d\n",param_3);
    int param_2 = myStackPop(obj);
    printf("%d\n",param_2);
    bool param_4 = myStackEmpty(obj);
    printf("%d\n",param_4);
    myStackFree(obj);
    return 0;

}
