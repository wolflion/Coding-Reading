#!/bin/bash

echo -n for_02
for test in Alabama Alaska Arizona Arkansas California Colorado
do
  echo The next state is $test
done

echo -n for_02
# testing the for variable after the looping
for test in Alabama Alaska Arizona Arkansas California Colorado
do
  echo "The next state is $test"
done
echo "The last state we visited was $test"
test=Connecticut
echo "Wait last state we visited was $test"  #$test变量保持了前面的值，在for循环之外一样使用它。

echo -n for_03
#读取列表中的复杂值
for test in I don't know if this'll work  #看到了列表的单引号并尝试使用它们来定义一个单独的数据值
do
  echo "word:$test"
done

echo -n for_04  # for循环假定每个值都是用空格分割的
#读取列表中的复杂值
for test in I don\'t know if "this'll" work  #用了转义和 双引号
do
  echo "word:$test"
done
