#include <iostream>

#define MAXSIZE 2 

typedef struct {
    int number; 
    int arrivetime; 
} SElemType;

typedef struct {
    SElemType* base; 
    SElemType* top; 
    int stacksize; 
} SqStack;

typedef struct {
    int number; 
    int arrivetime; 
} QElemType;

typedef struct QNode {
    QElemType data;
    struct QNode* next;
} QNode, * QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

void init_stack(SqStack& S);
void push_stack(SqStack& S, SElemType e);
void pop_stack(SqStack& S, SElemType& e);
bool is_stack_full(SqStack S);
int locate_se(SqStack S, SElemType e);

void init_queue(LinkQueue& Q);
void enqueue(LinkQueue& Q, QElemType e);
void dequeue(LinkQueue& Q, QElemType& e);
bool is_queue_empty(LinkQueue Q);
int locate_qe(LinkQueue Q, QElemType e);

void arrival(SqStack &Sstation, LinkQueue &Wait);
void leave(SqStack &Sstation, SqStack &Stemp, LinkQueue &Wait);

int main() {
    char ch;
    SqStack Sstation, Stemp;
    LinkQueue Wait;
    init_stack(Sstation); 
    init_stack(Stemp);   
    init_queue(Wait);    

    while (1) { 
        std::cout << "A. The Car Arrive  D. The Car Leave   E. Exit System" << std::endl;
        std::cin >> ch;
        switch (ch) { 
            case 'A': arrival(Sstation, Wait);  break; 
            case 'D': leave(Sstation, Stemp, Wait);   break; 
            case 'E': return 0;            
            default: break;
        } 
    }
    return 0;
}

void arrival(SqStack &Sstation, LinkQueue &Wait) {  
    SElemType se;
    QElemType qe;
    std::cin >> se.number >> se.arrivetime;
    qe.number = se.number;
    qe.arrivetime = se.arrivetime;
    if (!is_stack_full(Sstation)) {  
        push_stack(Sstation, se);
        std::cout << "parking location: " << Sstation.top - Sstation.base << std::endl;
    }
    else {
        enqueue(Wait, qe);
        std::cout << "sidewalk location: "  << locate_qe(Wait, qe) << std::endl;
    }
}

void leave(SqStack &Sstation, SqStack &Stemp, LinkQueue &Wait) { 
    SElemType se, setemp;
    QElemType qe;
    int num, leavetime, n;
    std::cin >> num >> leavetime;
    se.number = num;

    n = locate_se(Sstation, se);
    if (n != 0) {  
        SElemType* p = Sstation.top - 1;
        while ((p - Sstation.base) >= n) {
            pop_stack(Sstation, setemp);
            push_stack(Stemp, setemp);
            p--;
        }
        pop_stack(Sstation, setemp); 
        std::cout << " time:  " << leavetime - setemp.arrivetime << "  parking fees :  " << leavetime - setemp.arrivetime << std::endl;
        p = Stemp.top - 1;
        while (p >= Stemp.base) {
            pop_stack(Stemp, setemp);
            push_stack(Sstation, setemp);
            p--;
        }
        if (!is_queue_empty(Wait)) {
            dequeue(Wait, qe);
            se.number = qe.number;
            se.arrivetime = leavetime;
            push_stack(Sstation, se);
        }
    }
    else {
        dequeue(Wait, qe);
        std::cout << "leave:free" << qe.number;
    }
}

void init_stack(SqStack& S) {
    S.base = new SElemType[MAXSIZE];
    if (!S.base)
        exit(-2); 
    S.top = S.base; 
    S.stacksize = MAXSIZE; 
}

bool is_stack_full(SqStack S) {
    if (S.top - S.base == S.stacksize)
        return true;
    else
        return false;
}

int locate_se(SqStack S, SElemType e) {
    SElemType* p;
    for (p = S.base; p < S.top; p++)
        if (p->number == e.number) return p - S.base + 1;
    return 0;
}

void push_stack(SqStack& S, SElemType e) {
    if (S.top - S.base >= S.stacksize) 
        return;
    *(S.top)++ = e; 
}

void pop_stack(SqStack& S, SElemType& e) {
    if (S.top == S.base) {
        std::cout << ("stack is empty"); return;
    }
    e = *--S.top; 
}

void init_queue(LinkQueue& Q) {
    Q.front = Q.rear = new QNode;
    if (!Q.front) exit(-2);
    Q.front->next = NULL;
}

void enqueue(LinkQueue& Q, QElemType e) {
    QueuePtr p;
    p = new QNode;
    if (!p) exit(-2);
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}

void dequeue(LinkQueue& Q, QElemType& e) {
    QueuePtr p;
    if (Q.front == Q.rear) return;
    p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) Q.rear = Q.front;
    free(p);
}

bool is_queue_empty(LinkQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

int locate_qe(LinkQueue Q, QElemType e) {
    int n = 0;
    QueuePtr p = Q.front;
    while (p != Q.rear) {
        n++;
        p = p->next;
    }
    return n;
}