#include <iostream>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef char SElemType;
typedef int Status;

using namespace std;

typedef struct {
    SElemType* base;
    SElemType* top;
} SqStack;

int getindex(char c) {
    int index = 0;
    switch (c) {
    case '+': index = 0; break;
    case '-': index = 1; break;
    case '*': index = 2; break;
    case '/': index = 3; break;
    case '(': index = 4; break;
    case ')': index = 5; break;
    case '#': index = 6; break;
    default: index = -1; break; 
    }
    return index;
}

char judge(char c1, char c2) {
    const char priority[7][7] = {
        { '>','>','<','<','<','>','>' },
        { '>','>','<','<','<','>','>' },
        { '>','>','>','>','<','>','>' },
        { '>','>','>','>','<','>','>' },
        { '<','<','<','<','<','=','0' },
        { '>','>','>','>','0','>','>' },
        { '<','<','<','<','<','0','=' },
    };
    int index1 = getindex(c1);
    int index2 = getindex(c2);
    return priority[index1][index2];
}

Status InitStack(SqStack& S) {
    S.base = new SElemType[MAXSIZE];
    if (!S.base) {
        exit(OVERFLOW);
    }
    S.top = S.base;
    return OK;
}

Status Pop(SqStack& S, SElemType& e) {
    if (S.top == S.base) {
        return ERROR;
    }
    e = *--S.top;
    return OK;
}

Status Push(SqStack& S, SElemType e) {
    if (S.top - S.base == MAXSIZE) {
        return ERROR;
    }
    *S.top++ = e;
    return OK;
}

SElemType Gettop(SqStack S) {
    if (S.top != S.base)
        return *(S.top - 1);
    else
        return '\0'; 
}

Status StackEmpty(SqStack S) {
    return S.top == S.base ? 1 : 0;
}

int In(char ch) {
    return (ch <= '9' && ch >= '0') ? 0 : 1;
}

int operate(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b; 
    default: return 0;
    }
}

int main() {
    SqStack OPTR, OPND;
    char ch;
    InitStack(OPTR);
    InitStack(OPND);
    Push(OPTR, '#');
    cin >> ch;
    while (ch != '#' || Gettop(OPTR) != '#') {
        if (!In(ch)) {
            Push(OPND, ch);
            cin >> ch;
        }
        else {
            switch (judge(Gettop(OPTR), ch)) {
            case '<':
                Push(OPTR, ch);
                cin >> ch;
                break;
            case '=': {
                SElemType temp;
                Pop(OPTR, temp);
                cin >> ch;
                break;
            }
            case '>': {
                SElemType op;
                Pop(OPTR, op);
                SElemType b, a;
                Pop(OPND, b);
                Pop(OPND, a);
                int result = operate(b - '0', a - '0', op);
                Push(OPND, result + '0'); 
                break;
            }
            }
        }
    }
    
    if (!StackEmpty(OPND)) {
        SElemType result;
        Pop(OPND, result);
        cout <<  (result - '0') << endl; 
    }
    return 0;
}