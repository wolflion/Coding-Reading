## 11、asyn、future、packaged_task、promise

### 11.1、std::asyn、std::future创建后台任务并返回值

+ std::asyn是个**函数模板**，用来启动一个异步任务，启动起来一个异步任务之后，返回一个std::future对象，std::future是个**类模板**。
+ **什么叫启动异步任务**：就是自动创建一个线程并开始执行对应的线程入口函数，它返回一个std::future对象，这个std::future对象里面就含有线程入口函数所返回的结果。（**也就是线程返回结果**）可以通过std::future的成员函数get()来获取结果。
+ `std::future`：提供了一种访问异步操作结果的机制。【这个结果你可能没有办法马上拿到，在不久的将来，在线程执行完毕的时候，你就能拿到结果了】future对象里会保存一个值，在将来的某个时刻会拿到。

### 11.2、std::packaged_task

### 11.3、std::promise

### 11.4、小结