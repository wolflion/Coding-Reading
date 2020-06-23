## chap09、图（273/364）

### 0、课前秀

+ 可以把线性表和树，看成简单的图。

### 1、图的存储及其运算

#### 1.1、图的基本术语

+ **图**：图G由两个集合V和E组成，记为`G=(V,E)`，V是顶点的有穷非空集合，E是V中顶点偶对有穷集，这些顶点偶边称为边。
+ **有向图**：对于一个图G，若边集合E(G)为有向边的集合。
+ **无向图**：对于一个图G，若边集合E(G)为无向边的集合。
+ **端点和邻接点**：在一个无向图中，若存在一条边<Vi,Vj>，则称Vi,Vj为该边的两个**端点**，并称它们互为**邻接点**。
+ **起点和终点**：
+ **度、入度和出度**：
  + 图中每个顶点的度定义为以该顶点为一个端点的边的数目，记为D(v).
+ **子图**
+ **无向完全图**：具有n(n-1)/2条边的无向图
+ **有向完全图**：具有n(n-1)/2条边的有向图
+ **稀疏图**：边很少（如e<nlog2n）的图
+ **稠密图**：边很多的图
+ **路径和路径长度**：
+ **简单路径**：若一条路径上除了开始顶点和结束顶点为同一个顶点外，其余顶点均不重复出现的路径。
+ **回路或环**：若一条路径的开始顶点和结束顶点为同一个顶点。
+ **连通、连通图和连通分量**：
+ **强连通图和强连通分量**：
+ **权和网**：在一个图中，每条边可以标上具有某种意义的数值，该数值称为**该边的权**。边上带权的图称为**带权图（也称为网）**。

#### 1.2、图的存储方式

+ 邻接矩阵

  + ```cpp
    #define MAXVEX 100
    struct vertex
    {
        int num;//顶点编号
        char data;//顶点的信息
    };
    
    typedef struct graph
    {
        struct vertex vexs[MAXVEX];//顶点集合
        int edges[MAXVEX][MAXVEX];//边的集合
    }adjmax;
    ```

  + NULL

+ 邻接表

  + ```cpp
    #define MAXVEX 30
    struct edgenode
    {
        int adjvex;//邻接点序号
        char info;//邻接点信息
        struct edgenodes *next;
    };
    
    struct vexnode
    {
        char data;//结点信息
        struct edgenode *link;
    };
    typedef struct vexnode adjlist[MAXVEX];
    ```

  + NULL

#### 1.3、图的基本运算

+ 深度优先搜索法

  + ```cpp
    int visited[MAXVEX];
    void dfs(adjlist adj, int v)
    {
        int i;
        struct edgenode *p;
        for(i=1;i<=n;i++)
            visited[i] = 0;//给visited数组赋初值0
        visited[v] = 1;
        printf("%d",v);//取v的边的表头指针
        p = adj[v]->link;
        while(p != NULL)
        {
            //从v的未访问过的邻接点出发进行深度优先搜索
            if(visited[p->adjvex] == 0)
                dfs(adjlist,p->adjvex);
            p = p->next; //找v的下一个邻接点
        }
    }
    ```

  + NULL

+ 宽度优先搜索法

  + ```cpp
    int visited[MAXVEX];
    int queue[MAXVEX];
    void bfs(adjlist adj, int vi)
    {
        int front = 0,rear =1,v;
        struct edgenode *p;
        visited[vi] = 1;//访问初始顶点
        printf("%d",v);
        queue[rear] = vi;//初始顶点入队列
        while(fornt != rear) //队列不为空
        {
            front = (front + 1) % m;
            v = queue[front];//按访问次序依次出队列
            p = adj[v]->link;//找v的邻接点
            while(p != NULL)
            {
                if(visited[p->adjvex] == 0)
                {
                    visited[p->adjvex] = 1;
                    printf("%d",p->adjvex);//访问该点并使之入队列
                    rear = (rear+1)%m;
                    queue[rear] = p->adjvex;
                }
                p=p->next;//找v的下一个邻接点
            }
        }
    }
    ```

  + NULL

+ 生成最小生成树法

  + ```cpp
    //普里姆算法
    ```

  + ```cpp
    //克鲁
    ```

  + NULL

+ 产生最短路径法

  + ```cpp
    //Dijkstra
    #define MAXVEX 100   //定义最多顶点数
    void shortpath(cost, dist, path, n, v0)
        
    ```

  + NULL

+ 拓扑排序法

### 2、