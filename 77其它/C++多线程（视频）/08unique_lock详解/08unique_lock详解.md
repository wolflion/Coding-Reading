## 08、unique_lock详解

### 8.1、unique_lock取代lock_guard

+ **unique_lock**是个类模板，工作中，一般lock_guard（推荐使用）就够用了。
+ lock_guard取代了mutex的lock()和unlock()函数。
+ unique_lock比lock_guard灵活很多，但效率上差一点，内存占比多一点。

### 8.2、unqiue_lock的第2个参数

+ lock_guard也可以带第二个参数`std::lock_guard<std::mutex> sbguard1(my_mutex,std::adopt_lock);//adopt_lock就是起标记作用`

#### 8.2.1、std::adopt_lock

+ 作为标记，是第2个参数的位置；**表示这个互斥量已经被lock了（你必须要把互斥量提前lock，否则会报异常）**。
+ 这个标记的效果就是“假设调用方线程已经拥有了互斥的所有权（已经lock()成功了），**才能使用std::adopt_lock标记**”
+ 通知lock_guard不需要在构造函数中lock这个互斥量了。
+ **unique_lock跟lock_guard含义相同**。

#### 8.2.2、std::try_to_lock

+ 我们会尝试用mutex的lock()去锁定这个mutex，但如果没有锁定成功，**我也会立即返回，并不会阻塞在那里**。
+ **用这个try_to_lock的前提，是你自己不能先去lock**，否则相当于调2次lock了。

#### 8.2.3、std::defer_lock

+ **用std::defer_lock的前提是，你不能自己先lock，否则会报异常**
+ 用defer_lock，就是 并没有给mutex加锁，初始化一个没有加锁的mutex。

### 8.3、unqiue_lock的成员函数

#### 8.3.1、lock()

#### 8.3.2、unlock()

+ 一般情况下是不用自己unlock()的，但是**一些非共享代码要处理**
+ **相当于在unique_lock对象的生存期内多次调用lock()和unlock()，因为最终unique_lock对象会被析构掉**。
+ **自己在退出时也可以调用unlock()，但属于画蛇添足，系统析构前会判断一下**。

#### 8.3.3、try_lock()

+ 尝试给互斥量加锁，拿到了锁，返回ture，没拿到锁，返回false，**只不过不堵塞在那**。

#### 8.3.4、release()

+ 返回它所管理的mutex对象指针，并释放所有权。**也就是这个mutex和unique_lock不再有关系**。
+ **要严格区分，unlock()和release()的区别，不要混淆**。
+ 如果原来mutex对象处于加锁状态，你有责任接管过来并直接解锁。
+ **release返回的是原始的mutex指针**。
+ 为什么有时候需要unlock()，因为你lock锁住的代码段越少，执行得越快，等待的时间越少，运行效率越高。
+ 有人也把锁头锁住代码行数的多少，称为**锁的粒度**，一般用粗细来描述。（粒度粗，就是锁住代码有点多；粒度细，就可能会导致锁不全）**粒度的选择很重要，高级程序员的能力**。

### 8.4、unique_lock所有权的传递

+ 主要是**mutex**，unique_lock与mutex配合使用。
+ `std::unique_lock<std::mutex> sbguard1(my_mutex1);`
  + sbguard1拥有my_mutex1的所有权。
  + sbguard1可以把自己对mutex(my_mutex1)的所有权转移给其它的unique_lock()对象。
+ **所以，unique_lock对象这个mutex的所有权属于 “可以转移，但不能复制”**。
+ `std::unique_lock<std::mutex> sbguard2(std::move(my_mutex1));`所有权被转移了，指向了sbguard2了。
+ 所有权的转移两种方法
  + `std::move()`
  + `return std::unique_lock<std::mutex> `