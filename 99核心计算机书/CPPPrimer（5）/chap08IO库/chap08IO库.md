## chap08、IO库 277（303/864）

+ 别的都用过也知道，**`getline()`**不太熟。
  + 从一个给定的istream读取一行数据，存入一个给定的string对象中。

### 8.1、IO类  278（304/864）

+ 3个独立的头文件
  + `<iostream>` 定义了用于读写流的基本类型  【**对流操作**】
  + `<fstream>`定义了读写命名文件的类型 【**对文件操作**】
  + `<sstream>`定义了读写内存string对象的类型 【**对string操作**】
+ 为了支持使用宽字符的语言，标准库定义了一组类型和对象来操作**`wchar_t`类型**的数据。**宽字符版本的类型和函数的名字以一个`w`开始**。wcin、wcout和wcerr是分别对应cin、cout和cerr的宽字符版对象。
+ IO类型间的关系
  + 标准库使我们能忽略这些不同类型的流之间的差异，这是通过**继承机制（inheritance）**实现的。

#### 8.1.1、IO对象无拷贝或赋值

+ 我们不能拷贝或对IO对象赋值
  + 由于不能拷贝IO对象，因此我们**也不能将形参或返回类型设置为流类型**。
  + **进行IO操作的函数通常以引用方式传递和返回流**。
  + 读写一个IO对象会改变其状态，因此传递和返回的引用不能是const的。

```cpp
ofstream out1,out2;
out1 = out2;//错误： 不能对流对象赋值
ofstream print(ofstream);//错误：不能初始化ofstream参数
out2 = print(out2);//错误：不能拷贝流对象
```

#### 8.1.2、无条件状态

+ IO库条件状态
  + **里面有很多值啊**
+ 查询流的状态
+ 管理条件状态

```cpp
//记住cin的当前状态
auto old_state = cin.rdstate();  //记住cin的当前状态
cin.clear();  //使cin有效
process_input(cin); //使用cin
cin.setstate(old_state); //将cin置为原有状态
```

#### 8.1.3、管理输出缓冲

+ 导致缓冲刷新（即，数据真正写到输出设备或文件）的原因：
  + 程序正常结束，作为main函数的return操作的一部分，缓冲刷新被执行。
  + 缓冲区满时，需要刷新缓冲，而后新的数据才能继续写入缓冲区
  + 我们可以使用操纵符如endl来显式刷新缓冲区
+ 刷新输出缓冲区
  + 操纵符`endl`：完成换行并刷新缓冲区的工作
  + 操纵符`flush`：刷新缓冲区，但不输出任何额外的字符
  + 操作符`ends`：向缓冲区插入一个空字符，然后刷新缓冲区

```cpp
cout<<"hi!"<<endl; //输出hi和一个换行，然后刷新缓冲区
cout<<"hi!"<<flush; //输出hi，然后刷新缓冲区，不附加任何额外字符
cout<<"hi!"<<ends; //输出hi和一个空字符，然后刷新缓冲区
```

+ unitbuf操纵符

```cpp
cout << unitbuf; //所有输出操作后都会立即刷新缓冲区
//任何输出都立即刷新，无缓冲
cout << nounitbuf; //回到正常的缓冲方式
```

+ **警告：如果程序崩溃，输出缓冲区不会被刷新**
+ 关联输入和输出流

### 8.2、文件输入输出  283（309/864）

+ fstream特有的操作

#### 8.2.1、使用文件流对象

+ 0
+ 用fstream代替iostream&
+ 成员函数open和close

```cpp
ifstream in(ifile); //构筑一个ifstream并打开给定文件
ofstream out;  //输出文件流未与任何文件相关联
out.open(ifile + ".copy"); //打开指定文件
```

+ 自动构造和析构

#### 8.2.2、文件模式

+ 文件模式和它们的含义
+ 以out模式打开文件会丢弃已有数据
+ 每次调用open时都会确定文件模式

```cpp
ofstream out; //未指定文件打开模式
out.open("scratchpad"); //模式隐含设置为输出和截断
out.close();//关闭out，以便我们将其用于其他文件
out.open("precious",ofstream::app);//模式为输出和追加
out.close();
```

### 8.3、sring流  287（313/864）

+ stringstream特有的操作

#### 8.3.1、使用istringstream

+ 例子

```cpp
string line,word;  //分别保存来自输入的一行和单词
vector<PersonInfo> people; //保存来自输入的所有记录
//逐行从输入读取数据，直至cin遇到文件尾（或其他错误）
while(getline(cin, line)){
    PersonInfo info;//创建一个保存此记录数据的对象
    istringstream record(line);//将记录绑定到刚读入的行
    record >> info.name;  //读取名字
    while(record >> word) //读取电话号码
        info.phones.push_back(word);//保持它们
    people.push_back(info); //将此记录追加到people末尾
}
```

#### 8.3.2、使用ostringstream

+ 例子

```cpp
for(const auto& entry:people) {//对people中第一项
    ostringstream formatted,badNums;//每个循环步创建的对象
    for(const auto &nums : entry.phones){ //对每个数
        if(!valid(nums)){
            badNums << " " << nums; //将数的字符串形式存入badNums
        }else
        {
            //将格式化的字符串“写入”formatted
            formatted << " "<<format(nums);
        }
    }
    if(badNums.str().empty()) //没有错误的数
        os<<entry.name<< " "<<formatted.str()<<endl;//打印名字和格式化的数
    else  //否则，打印名字和错误的数
        cerr<<"input error: "<<entry.name << "invalid number(s) "<<badNums.str()<<endl;
}
```

### 小结  290（316/864）

### 术语表

## ReadMe

+ 20200522全章过了一遍，但感觉对于写代码的语法或技能，没有太多提升啊，但确实有点知识点不知道的。