#include <iostream>

using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef char TElemType;
typedef int Status;

typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


BiTNode * CreateBiTree(const string & temp, int & index)
{
    if(index>=temp.size() || temp[index] == '#')
    {
        index ++;
        return nullptr;
    }
    BiTNode * node = new BiTNode;
    node ->data = temp[index++];
    node->lchild = CreateBiTree(temp, index);
    node->rchild = CreateBiTree(temp, index);
    return node;
}

void PreOrderTree(BiTree T)
{
    if(T)
    {
        cout<<T->data;
        PreOrderTree(T->lchild);
        PreOrderTree(T->rchild);
    }
}

void InOrderTree(BiTree T)
{
    if(T)
    {
        InOrderTree(T->lchild);
        cout<<T->data;
        InOrderTree(T->rchild);
    }
}

void PostOrderTree(BiTree T)
{
    if(T)
    {
        
        PostOrderTree(T->lchild);
        PostOrderTree(T->rchild);
        cout<<T->data;
    }
}

int LeafNum(BiTree T)
{
    static int num = 0;
    if(!T->lchild || !T->rchild)
    {
        num++;
    }
    else
    {
        LeafNum(T->lchild);
        LeafNum(T->rchild);
    }
    return num;
}

int Depth(BiTree T)
{
    if(!T)
    {
        return 0;
    }
    else

    {
       int m = Depth(T->lchild);
       int n = Depth(T->rchild);
        return m>n ? (m+1):(n+1);
    }
}

Status NodeSwap(BiTree &a)
{
    if(!a)
    {
        return ERROR;
    }
    BiTNode *temp = a->lchild;
    a->lchild = a->rchild;
    a->rchild = temp;
    return OK;
}

void TreeSwap(BiTree T)
{
    if(!T)
    {
        return;
    }
    else

    {
        TreeSwap(T->lchild);
        TreeSwap(T->rchild);
        NodeSwap(T);

        return;
    }
}

int main()
{
    string temp;
    cin>>temp;
    int index = 0;
    BiTree T = CreateBiTree(temp,index);
    PreOrderTree(T);
    cout<<" ";
    InOrderTree(T);
    cout<<" ";
    PostOrderTree(T);
    cout<<endl<<LeafNum(T)<<" "<<Depth(T)<<endl;
    TreeSwap(T);
    PreOrderTree(T);
    cout<<" ";
    InOrderTree(T);
    cout<<" ";
    PostOrderTree(T);
    return 0;
}