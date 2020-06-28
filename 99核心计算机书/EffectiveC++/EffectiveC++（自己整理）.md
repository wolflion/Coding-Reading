## 内容

### Part01、Accustoming Yourself to C++

#### Itm01：View C++ as a federation of languages

+ C
+ Object-Oriented C++
+ Template C++
+ STL
+ *不知道C++11，C++20的特性会不会再加大这个区分*

#### Item02： Perfer consts, enums,and inlines to #define

+ `#define`时**宏名有可能并未记入符号表**。

#### Item03：Use const whenever possible

+ **const在`*`号左边，物是常量；const 在`*`号右边，指针是常量**
  + `const char* p = greeting;//const data`
  + `char* const p = greeting;//const pointer`
+ 迭代器中也有这样的区分
  + `::const_iterator` **迭代器所指的东西不可被改动**。
+ const成员函数
  + 是不是只能const成员函数，调用const对象？
  + const成员函数和非const成员函数，如何重载？
+ **显式加上`mutable`关键字**

#### Item04：Make sure that objects are initialized before they're used

+ 内置类型的初始化？
+ 自定义类型的初始化？
+ 内置类型的（local,static）的初始化不同。

### Part02、Constructors、Destructors、and Assignment Operators

+ 几乎你写的每一个class都会有一或多个构造函数、一个析构函数、一个copy assignment操作符。

#### Item05：Know what functions C++ silently writes and calls

+ **编译器可以暗自为class创建default构造函数、copy构造函数、copy assignment操作符，以及析构函数。

#### Item06：Explicitly disallow the use of compiler-generated functions you do not want。

+ **为了驳回编译器自动（暗自）提供的机能，可将相应的成员函数声明为private并且不予实现**。使用像Uncopyable这样的base class也是一种方法。

#### Item07：Declare destructions virtual in polymorphic base classes

+ polymorphic（带多态性质的）base classes 应该声明一个virtual析构函数。如果class带有任何virtual函数，它就应该拥有一个virtual析构函数。
+ Classes的设计目的如果不是作为base classes使用，或不是为了具备多态性（polymorphically），就不该声明virtual析构函数。

#### Item08：Prevent exceptions from leaving destructors

+ 析构函数绝对不要吐出异常。如果一个被析构函数调用的函数可能抛出异常，析构函数应该捕捉任何异常，然后吞下它们（不传播）或结束程序。
+ 如果客户需要对某个操作函数运行期间抛出的异常做出反应，那么class应该提供一个普通函数（而非在析构函数中）执行该操作。

#### Item09：Never call virtual functions during construction or destruction

+ 在构造和析构期间不要调用virtual函数，因为这类调用从不下降至derived class（比起当前执行构造函数和析构函数的那层）。

#### Item10：Have assignment operators return a reference to *this

+ 令赋值（assignment）操作符返回一个reference to *this。

#### Item11：Handle assignment to self in operator=

+ 确保当对象自我赋值时`operator=`有良好行为。其中技术包括比较“来源对象”和“目标对象”的地址、精心周到的语句顺序、以及copy-and-swap。
+ 确定任何函数如果操作一个以上的对象，而其中多个对象是同一个对象时，其行为仍然正确。

#### Item12：Copy all parts of an object

+ Copying函数应该确保复制“对象内的所有成员变量”及“所有base class成分”。
+ 不要尝试以某个copying函数实现另一个copying函数。应该将共同机能放进第三个函数中，并由两个copying函数共同调用。