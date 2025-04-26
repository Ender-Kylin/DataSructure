#include <iostream>

using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef char TElemType;
typedef int Status;

typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BitTree;



//通过先序遍历构造二叉树
BiTNode * CreateBitTree(const string & temp, int &index)
{
    if(index >= temp.size() || temp[index] == '#')
    {
        index ++;
        return nullptr;
    }
    BiTNode * node = new BiTNode;
    node ->data=temp[index++];
    node->lchild = CreateBitTree(temp,index);
    node ->rchild = CreateBitTree(temp,index);
    return node;
}

void levelOrderTraversal(BitTree & T)
{
    if(!T)
    {
        return;
    }
    BiTNode * q[MAXSIZE];//指向结构体的指针
    int front = 0, rear = 0;
    q[rear ++] = T;
    while(front < rear)
    {
        BiTNode * current = q[front++];
        cout<<current->data;
        if(current->lchild)
        {
            q[rear ++] = current->lchild;
        }
        if(current->rchild)
        {
            q[rear++] = current->rchild;
        }
    }
}


int main()
{
    string temp;
    cin>>temp;
    int index = 0;
    BitTree T = CreateBitTree(temp,index);
    levelOrderTraversal(T);
    return 0;    
}