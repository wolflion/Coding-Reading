## 第2篇  shell脚本编程基础  209（224/621）
### chap11 构建基本脚本   210(225/621）
+ 11.1、使用多个命令
	+ 用`;`分隔
	+ 最大命令行字符数不能超过255
+ 11.2、创建shell脚本文件
	+ shell的第一行要指定使用的shell。`#!/bin/bash`  **虽然#是注释符，但第一行是例外**
	+ 要找到自己写的shell脚本
		+ 将shell脚本的目录添加到PATH环境变量中
		+ 在提示符中用绝对或相对路径执行
	+ shell脚本的执行权限
		+ umask的值
+ 11.3、显示消息
	+ `echo`中的单引号或双引号的问题
+ 11.4、使用变量
	+ 环境变量
	+ 用户变量
	+ 命令替换
		+ 反引号字符（`）
		+ `$()`格式
+ 11.5、重定向输入和输出
	+ 输出重定向
	+ 输入重定向
+ 11.6、管道
+ 11.7、执行数学运算
	+ expr命令
		+ `expr 1+5`，`expr 5 \*2 `（*要用反斜杠）
	+ 使用方括号`$[]`
		+ `var1=$[1+5]`
	+ 浮点解决方案
		+ `bc`的基本用法 
+ 11.8、退出脚本
	+ 查出退出状态码
	+ exit命令
+ 11.9、小结

### chap12 使用结构化命令  232（247/621）
+ 12.1、使用if-then语句
+ 12.2、使用if-then-else语句
+ 12.3、嵌套if
+ 12.4、test命令
+ 12.5、复合条件测试
+ 12.6、if-then的高级特性
+ 12.7、case命令
+ 12.8、小结

### chap13 更多的结构化命令  260（275/621）

#### 13.1、for命令

#### 13.2、C语言风格的for命令



### chap14、处理用户输入

#### 14.2、特殊参数变量

##### 14.2.1、参数统计


### chap16 