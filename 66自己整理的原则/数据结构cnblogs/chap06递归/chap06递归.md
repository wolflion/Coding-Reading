## chap06、递归  （157/364）

### 1、课前秀

+ 自已调用自已，**直接递归**
+ **间接递归**

### 2、递归设计方法

#### 2.1、递归模型

+ `f(1)=1` ：递归的终止条件（递归出口）
+ `f(n)=n*f(n-1) n > 1`：递归体，给出了f(n)的值与f(n-1)的值之间的关系。

#### 2.2、递归的执行过程

+ 把“大问题”分解为**求解过程和环境都相似**的“小问题”。

#### 2.3、递归设计

+ （1）对原问题f(s)进行分析，假设出合理的“较小问题”f(s')；
+ （2）假设f(s')是可解的，在此基础上确定f(s)的解，即给出f(s)与f(s')之间的关系；
+ （3）确定一个特定情况（如f(1)或f(0)）的解，由此作为递归出口。

#### 2.4、递归到非递归的转换

+ 直接求值，不需要回溯，**使用中间变量**保存中间结果，称为**直接转换法**。

  + ```
    题目：
    f(1)=1
    f(2)=1
    f(n)=f(n-1)+f(n-2) n>2
    ```

  + ```cpp
    int f(int n)
    {
        int i,s;
        s1 = 1;//s1用于保存f(n-1)的值
        s2 = 1;//s2用于保存f(n-2)的值
        s = 1;
        for(i=3;i<=n;i++)
        {
            s = s1+s2;
            s2 = s1;
            s1 = s;
        }
        return (s);
    }
    ```

  + NULL

+ 不能直接求值，需要回溯，**使用栈**保存中间结果，称为**间接转换法**

  + ```cpp
    //伪算法过程
    将初始状态s0进栈
    while(栈不为空)
    {
        退栈，将栈顶元素赋给s
        if(s是要找的结果)
            返回
        else
        {
            寻找到s的相关状态s1
            将s1进栈
        }
    }
    ```

  + ```cpp
    //非递归方法计算一棵二叉树的所有结点个数
    #define n 100
    typedef struct node
    {
        char data;
        struct node *left,*right;
    }bltree;
    
    int counter(bltree *t)
    {
        bltree *st[n],*p;
        int top,count = 0;
        if(t!=NULL)
        {
            top = 1;
            stack[top] = t;//将根结点入栈
            while(top > 0)
            {
                count++;//结点计数器增1
                node = stack[top];//将栈顶结点退栈并赋给node
                top--;
                if(node->left != NULL)
                {
                    top++;
                    stack[top]=node->left;
                }
                if(node->right != NULL)
                {
                    top++;
                    stack[top]=node->right;
                }
            }
        }
        return (count);
    }
    ```

  + NULL

## ReadMe

+ 20200623看了《李春葆：数据结构习题与解析》电子版，自已的实体书还没看呢。
  + 基本能理解，但习题还没做，不知道自考真题有没有相关。
  + *递归到非递归的转换*要好好理解一下，代码还没有run呢。