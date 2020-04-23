## [type alias（类型别名）]( https://zh.cppreference.com/w/cpp/language/type_alias )

### 0、课前秀

+ `typedef unsigned int unit_t;`是C++98/03熟悉的类型别名，**局限性在于无法重定义一个模板**。

### 1、using语法通过赋值来定义别名

+ 重定义unsigned int（**using的别法语法覆盖了typedef的全部功能**）
  + `using unit_t = unsigned int;`

## ReadMe

+ 20200422第1版：参考《深入应用C++11》1.2.2的内容
  + 是不是看得简单了，就试了下简单的内置类型。