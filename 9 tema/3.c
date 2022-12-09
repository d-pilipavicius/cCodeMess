#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

typedef struct Point
{
    double x,y;
}Point;

typedef struct Stk
{
    Point *stackArr;
    int siz;
}Stk;

#define WHAT_SIZEOF sizeof(Point)

Point createPoint(double x, double y)
{
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

void initStack(Stk *stk)
{
    stk->siz = 0;
    stk->stackArr = (Point*) malloc(stk->siz*WHAT_SIZEOF);
    for(int i = 0; i < stk->siz; ++i)
    {
        stk->stackArr[i].x = 0;
        stk->stackArr[i].y = 0;
    }
}

void printStack(Stk *stk)
{
    assert(stk->siz > 0);
    for(int i = 0; i < stk->siz; ++i)
    {
        double dist = sqrt((stk->stackArr[i].x)*(stk->stackArr[i].x)+(stk->stackArr[i].y)*(stk->stackArr[i].y));
        printf("(%f:%f) atstumas nuo koordinaciu pradzios: %f\n", stk->stackArr[i].x, stk->stackArr[i].y, dist);
    }
}

int getStackSize(Stk *stk)
{
    assert(stk->siz >= 0);
    return stk->siz;
}

void push(Stk *stk, Point value)
{
    assert(stk->siz >= 0);
    stk->stackArr = realloc(stk->stackArr, (++stk->siz)*WHAT_SIZEOF);
    stk->stackArr[stk->siz-1] = value;
}

Point top(Stk *stk)
{
    assert(stk->siz >= 0);
    if(stk->siz == 0) return createPoint(0,0);
    else return stk->stackArr[stk->siz-1];
}

Point pop(Stk *stk)
{
    assert(stk->siz >= 0);
    Point tempSave;
    if(stk->siz == 0) return createPoint(0,0);
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
    push(&stk, createPoint(2,5));
    push(&stk, createPoint(12,-6));
    push(&stk, createPoint(4,6));
    push(&stk, createPoint(-3,4));
    push(&stk, createPoint(100,200));
    printStack(&stk);
    return 0;
}
