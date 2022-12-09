#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct Stk
{
    int *stackArr;
    int siz;
}Stk;

#define WHAT_SIZEOF sizeof(int)

void initStack(Stk *stk)
{
    stk->siz = 0;
    stk->stackArr = (int*) malloc(stk->siz*WHAT_SIZEOF);
    for(int i = 0; i < stk->siz; ++i)
    {
        stk->stackArr[i] = 0;
    }
}

void printStack(Stk *stk)
{
    assert(stk->siz > 0);
    for(int i = 0; i < stk->siz; ++i)
    {
        printf("Steko %d elementas: %d\n", i, stk->stackArr[i]);
    }
}

int getStackSize(Stk *stk)
{
    assert(stk->siz >= 0);
    return stk->siz;
}

void push(Stk *stk, int value)
{
    assert(stk->siz >= 0);
    stk->stackArr = realloc(stk->stackArr, (++stk->siz)*WHAT_SIZEOF);
    stk->stackArr[stk->siz-1] = value;
}

int top(Stk *stk)
{
    assert(stk->siz >= 0);
    if(stk->siz == 0) return 0;
    else return stk->stackArr[stk->siz-1];
}

int pop(Stk *stk)
{
    assert(stk->siz >= 0);
    int tempSave;
    if(stk->siz == 0) return 0;
    else
    {
        tempSave = stk->stackArr[stk->siz-1];
        stk->stackArr = realloc(stk->stackArr, (--stk->siz)*WHAT_SIZEOF);
        return tempSave;
    }
}

void destroyStack(Stk *stk)
{
    assert(stk->siz >= 0);
    stk->siz = 0;
    free(stk->stackArr);
    stk->stackArr = NULL;
}

int main()
{
    Stk stk;
    initStack(&stk);
    printStack(&stk);
    printf("\n");
    assert(stk.siz == getStackSize(&stk));
    push(&stk, 10);
    assert(top(&stk) == 10);
    printStack(&stk);
    printf("\n");
    assert(pop(&stk) == 10);
    printStack(&stk);
    destroyStack(&stk);
    assert(stk.siz == 0);
    assert(stk.stackArr == NULL);
    return 0;
}
