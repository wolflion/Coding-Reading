## 10、condition_variable、wait、notify_one、notify_all

+ **condition_variable是个类**，等待一个条件达成，需要跟互斥量配合工作，要生成一个类对象。

### 10.1、条件变量std::condition_variable、wait()、notify_one()

+ 线程A：等待一个条件满足
+ 线程B：专门往消息队列中扔消息（数据）
+ **条件变量（condition_variable）是个类**。
+ wait()的第2个参数，如果不写就是false，**如果写，可以用lambda表达式**。
+ notify_one()尝试把wait()线程唤醒。
+ 具体见 条件变量.cpp的例子。**要先in，然后再out才行**。
+ 这里面需要一些问题需要思考：
  + 因为锁的问题，有可能会存在**in了很多了条，但out的时候，好久才处理一次**。
  + 可能会存在in的时候唤醒你的时候，会存在**无效唤醒的时候**（因为当时并不一定正卡在wait()堵塞的时候）。

### 10.2、上述代码深入思考

+ 有可能msgRecv队列多了（in的次数比out次数多）
  + 这种情况下要特殊处理比一下（比如限流；比如再开一个线程处理out）。
+ 没有wait()时，光调用wait_one()是啥用也没有的。

### 10.3、notify_all()

+ **notify_one()只能通知1个线程**
+ 如果有2个out线程时，取出当前线程ID观察一下`std::this_thread::get_id()`
+ 把notify_one()换成notify_all()就能唤醒多个，**但只有一个线程能拿到锁，其它的都得卡着**。

## ReadMe

+ **代码，能写出来，跟能写好，中间差着10万8000里呢**。