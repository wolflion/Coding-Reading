## 19、unique_ptr独占的智能指针

### 0、课前秀

### 1、unique_ptr

+ 不允许通过赋值将一个unique_ptr赋值给另外一个unique_ptr。

```cpp
unique_ptr<T> myPtr(new T);
unique_ptr<T> myOhterPtr = myPtr; //错误：不能复制
```

+ 可以通过函数返回给其他的unique_ptr，还可以通过std::move来转移到其他的unique_ptr，这样它本身就不再拥有原来指针的所有权了。

```cpp
unique_ptr<T> myPtr(new T); //Okay
unique_ptr<T> myOhterPtr = std::move(myPtr);//Okay，
unique_ptr<T> ptr = myPtr; //错误，只能移动，不可复制
```

### 2、用make_unique方法来创建智能指针

+ unique_ptr不像shared_ptr那样可以通过make_shared方法来创建智能指针。

```cpp
//支持普通指针
template<class T, class... Args> inline
typename enable_if<!is_array<T>::value, unique_ptr<T>>::type
    make_unique(Args&&... args)
{
    return unique_ptr<T>(new T(std::forward<Args>(args)...));
}

//支持动态数组
template<class T> inline
typename enable_if<is_array<T>::value && extent<T>::value==0,unique_ptr<T>>::type
    make_unique(size_t size)
{
    typedef typename remove_extent<T>::type U;
    return unique_ptr<T>(new U[size]());
}

//过滤掉定长数组的情况
template<class T, class... Args>
typename enable_if<extent<T>::value != 0,void>::type 
    make_unique(Args&&...) = delete;
```

## ReadMe

+ 20200522工作期间看了会儿，感觉内容不如看《CPP Primer》第5版的一章节呢，没有get好，留着后期再复习吧。