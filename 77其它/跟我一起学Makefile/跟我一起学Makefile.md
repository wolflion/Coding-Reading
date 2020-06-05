## 跟我一起学Makefile

### chap1、概述

+ 0
  + makefile定义了一系列的规则来指定，哪些文件需要先编译，哪些文件需要后编译，哪些文件需要重新编译。
  + make是一个命令工具，是一个解释makefile中指令的命令工具。

#### 1.1、关于程序的编译和链接

+ **编译**是生成.o文件（Object File），把大量的Object File合并执行文件，这个叫**链接（Link）**。
+ 链接时，主要是链接函数和全局变量。**要给中间目标文件打个包，就是`.a文件`（Archive File）**，windows下叫“库文件（Library File）”，也就是`.lib文件`。
+ 在编译时，编译器只检测程序语法和函数、变量是否被声明。如果函数未被声明，编译器会给出一个警告，但可以生成Object File。
+ 在链接程序时，链接器会在所有的Object File中找寻函数的实现，如果找不到，那就会报链接错误码。

### chap2、makefile介绍

+ 0（规则是：）
  + 1、如果这个工程没有编译过，那么我们的所有c文件都要编译并被链接。
  + 2、如果这个工程的某几个c文件被修改，那么我们只编译被修改的c文件，并链接目标程序。
  + 3、如果这个工程的头文件被改变了，那么我们需要编译引用了这几个头文件的c文件，并链接目标程序。

#### 2.1、makefile的规则

+ 以下命令的解释：target这一个或多个的目标文件依赖于prerequisites中的文件，其生成规则定义在command中。
  + target：可以是一个object file（目标文件），也可以是一个执行文件，还可以是一个标签（label）。*标签这个特性，参考“伪目标”*。
  + prerequisites：生成该target所依赖的文件和/或target
  + command：该target要执行的命令（任意的shell命令）

```makefile
target ... : prerequisities ...
	command
	...
	...
```

+ **prerequisites中如果有一个以上的文件比target文件要新的话，command所定义的命令就会被执行。**--Makefile的规则，也是最核心的内容。

#### 2.2、一个示例

+ 依赖关系的实质就是说明了目标文件是由哪些文件生成的，换言之，目标文件是哪些文件更新的。
  + **clean不是一个文件，它只不过是一个动作名字，其冒号后什么也没有，那么make就不会自动去找它的依赖性，也就不会自动执行其后所定义的命令**。要执行其后的命令，就要在make命令后明显得指出这个label的名字。*比如`make clean`*

#### 2.3、make是如何工作的

+ 只输入make命令，那么：
  + 1、make会在当前目录下找名字"Makefile"或"makefile"的文件
  + 2、如果能找到，会找文件中的第一个目标文件（target），并把这个文件作为最终的目标文件。*上例中的edit*
  + 3、如果edit文件不存在，或者所依赖的.o文件的文件修改时间要比edit文件新，那么就会执行后面的命令来生成edit文件。
  + 4、如果edit所依赖的.o文件也不存在，那么会在当前文件中找目标.o文件的依赖性，如果找到再根据规则生成.o文件。
  + 5、你的.c和.h文件应该在，于是make会生成.o文件，再用.o文件生成make的终极任务，也就是执行文件edit了。

#### 2.4、makefile中使用变量

+ makefile的变量也就是一个字符串，**理解成C语言中的宏可能会更好**。
+ 改良版的makefile，**用了objects变量**。

#### 2.5、让make自动推导

+ **只要make看到一个.o文件，它就会自动的把.c文件加在依赖关系中**，如果make找到一个whatever.o，那么whatever.c就会是whatever.o的依赖文件。
+ 改良版的makefile，**用了.c的自动推导**。
+ `.PHONY : clean`加了这一行，.PHONY表示clean是个伪目标文件。

#### 2.6、另类风格的makefiles

+ *为了用上自动推导，会把.o文件的生成弄得很乱*，不是太建议。

```makefile
objects = main.o kdb.o command.o display.o \
	insert.o search.o files.o utils.o

edit : $(objects)
	cc -o edit $(objects)

$(objects) : defs.h
kdb.o command.o files.o : command.h
display.o insert.o search.o files.o : buffer.h

.PHONY : clean
clean :
	rm edit $(objects)
```

#### 2.7、清空目标文件的规则

+ 不成文的规矩是：**“clean从来都是放在文件的最后”**。clean的规则不要放在文件的开头，不然，这就会变成make的默认目标。
+ **更推荐的做法**：（`-rm`前面加个`-`，表示也许某些文件出现问题，但不要管，继续做后面的事）

```makefile
.PHONY : clean
clean :
	-rm edit $(objects)
```

#### 2.8、Makefile里有什么？

+ Makfile里主要包含了五个东西：
  + 显式规则：如何生成一个或多个目标文件。显式指出要生成的文件、文件的依赖文件和生成的命令。
  + 隐晦规则：make的自动推导功能。
  + 变量定义：类似于C语言中的宏
  + 文件指示
    + （1）一个Makefile中引用另一个Makefile，类似于include
    + （2）根据某些情况指定Makefile中的有效部分，类似于预编译#if
    + （3）定义一个多行的命令
  + 注释：用`#`注释，想使用#字符，必须转义`\#`
+ **Makefile中的命令，必须要以Tab键开始**。

#### 2.9、Makefile的文件名

+ make命令会在当前目录下按顺序找寻文件名为“GNUmakefile”，“makefile”，“Makfefile”。
+ **最好使用Makeflie**，首字母大写会显目点。**最好不用GNUmakefile**。
+ 如果定义了“Make.Linux”或“Make.Solaries”，可以用`make -f`或`make --file`来指定特定的Makefile。

#### 2.10、引用其它的Makefile（未完）

+ **include前面可以有一些空字符，但是绝不能是Tab键开始**。

#### 2.11、环境变量MAKEFILES（未完）

+ **不建议使用MAKEFILES这个环境变量**。

#### 2.12、make的工作方式（未完）

+ 1、

### chap3、书写规则  13（18/81）

+ 0
  + **规则包含两个部分**：一个是依赖关系，一个是生成目标的方法。
  + Makefile中只应该有一个最终目标，其它的目标都是被这个目标所连带出来的。**第一条规则中的目标将被确立为最终的目标**。

#### 3.1、规则举例

+ 例子

```makefile
foo.o : foo.c defs.h  # foo 模块
	cc -c -g foo.c
```

#### 3.2、规则的语法

+ 语法1

```makefile
targets : prerequisites
	command
	...
```

+ 语法2

```makefile
targets : prerequisites ; command  # 写一行，后面要加;才行
	command
	...
```

#### 3.3、在规则中使用通配符（未完）

+ make支持三个通配符：**`*,?,~`**
+ **`~/test`，表示当前用户的$HOME目录下的test目录**
+ 本节提到的关键字
  + **wildcard**和**patsubst**。

#### 3.4、文件搜寻（未完）

+ Makefile文件中的特殊变量**VPATH**完成这个功能，如果没有提明这个变量，make只会在当前的目录中去找寻依赖文件和目标文件。

#### 3.5、伪目标

+ 我们并不生成"clean"这个文件。“伪目标”并不是一个文件，只是一个标签。
+ 为了避免和文件重名的这种情况，需要一个**特殊的标记`.PHONY`来显式地指明一个目标是“伪目标”**。如`.PHONY : clean`
+ 伪目标一般没有依赖的文件。但是，我们也可以为伪目标指定所依赖的文件。

#### 3.6、多目标（未完）

+ **自动化变量`$@`**
+ 例子1：

```makefile
bigoutput littleoutput : text.g
	generate text.g -$(subset output,,$@) > $@
```

+ 等价的例子：

```makefile
bigoutput : text.g
	generate text.g -big > bigoutput
littleoutput : text.g
	generate text.g -little > littleoutput
```

#### 3.7、静态模式（未看）

#### 3.8、自动生成依赖性（未完）

+ `gcc -M main.c`和`gcc -MM main.c`的差异。

### chap4、书写命令 23（28/81）

+ 0
  + make的命令默认是被`/bin/sh`

#### 4.1、显示命令

+ `@`字符
+ `make -n 或 --just-print`，只是显示命令，但不会执行命令，**用于调试我们的Makefile**。
+ `make -s 或 --silent 或 --quiet`则全面禁止命令的显示。

#### 4.2、命令执行

+ 命令1

```makefile
exec :
	cd /home/hchen
	pwd
```

+ 命令2（等价于命令1）

```makefile
exec :
	cd /home/hchen; pwd
```

#### 4.3、命令出错（未看）

#### 4.4、嵌套执行make（未看）

#### 4.5、定义命令包

+ 为相同的命令序列定义一个变量，**以define开始，以endef结束**。

```makefile
define run-yacc
yacc $(firstword $^)
mv y.tab.c $@
endef
```

+ 上面的 run-yacc 是命令包的名字。

```makefile
foo.c : foo.y
	$(run-yacc)
```

### chap5、使用变量

+ 0

#### 5.1、变量的基础

+ 使用变量的值，**要在变量名前加上`$`符号**，最好用小括号`()`或大括号`{}`把变量给包括起来，要使用真实的`$`字符，需要用`$$`来表示。
+ 例子

```makefile
objects = program.o foo.o utils.o
program : $(objects)
	cc -o program $(objects)
	
$(objects) : defs.h
```

#### 5.2、变量中的变量

+ 第一种定义方式：

```makefile
foo = $(bar)
bar = $(ugh)
ugh = Huh?

all :
	echo $(foo)
```

+ 第二种定义方式：

```makefile
x := foo
y := $(x) bar
x := later
```

#### 5.3、变量高级用法

+ 变量值的替换
+ 

#### 5.4、追加变量值

+ 用`+=`操作符给变量追加值

```makefile
objects = main.o foo.o bar.o utils.o
objects += another.o
```

+ 等价于

```makefile
objects = main.o foo.o bar.o utils.o
objects := $(objects) another.o
```



#### 5.5、override指示符（未懂）

#### 5.6、多行变量

+ 使用define关键字设置变量的值可以有换行，以endef结束。

```makefile
define two-lines
echo foo
echo $(bar)
endef
```



#### 5.7、环境变量（未懂）

#### 5.8、目标变量

+ 语法

```makefile
<target ...> : <variable-assignment>;
<target ...> : overide <variable-assignment>
```



#### 5.9、模式变量

+ 给定一种“模式”，可以把变量定义在符合这种模式的所有目标上。
+ **make的“模式”一般是至少含有一个%的**。`%.o : CFLAGS = -o`

### chap6、使用条件判断

#### 6.1、示例

+ 例子1

```makefile
libs_for_gcc = -lgnu
normal_libs =

foo: $(objects)
ifeq ($(CC),gcc)
	$(CC) -o foo $(objects) $(libs_for_gcc)
else
	$(CC) -o foo $(objects) $(normal_libs)
endif
```



#### 6.2、语法

+ 4个关键字
  + ifeq
  + ifneq
  + ifdef
  + ifndef

### chap7、使用函数

### chap8、make的运行

### chap9、隐含规则

### chap10、使用make更新函数库文件

### chap11、后序