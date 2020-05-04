## 14unordered container无序容器

### 0、课前秀

+ 比起有序容器，无序容器（unordered_map/unordered_multimap和unordered_set/unordered_multiset）里的元素是不排序的。
+ map和set内部是**红黑树**，插入元素时会自动排序，无序容器用的是**散列表（Hash Table）**，通过hash，而不是排序来操作元素，从而效率更高。

### 1、知识点

+ 无序容器和key需要提供hash_value函数，其他用法和map/set的用法是一样的。
+ **对于自定义的key，需要提供Hash函数和比较函数**。(基本类型的就不需要)

### 2、代码2-6：无序容器的基本用法

```c++
#include<unordered_map>
#include<vector>
#include<bitset>
#include<string>
#include<utility>

struct Key
{
    std::string first;
    std::string second;
};

struct KeyHash
{
    std::size_t operator()(const Key& k)const
    {
        return std::hash<std::string>()(k.first)^(std::hash<std::string>()(k.second) << 1);
    }
};

struct KeyEqual
{
    bool operator()(const Key& lhs, const Key& rhs)const
    {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }
};

int main()
{
    //default constructor: empty map
    std::unordered_map<std::string,std::string>ml;
    
    //list constructor
    std::unordered_map<int,std::string> m2=
    {
        {1,"foo"},{3,"bar"},{2,"baz"},
    };
    
    //copy constructor
    std::unordered_map<int,std::string> m3 = m2;
    
    //move constructor
    std::unordered_map<int,std::string>m4 = std::move(m2);
    
    //range constructor
    std::vector<std::pair<std::bitset<8>,int>> v = {{0x12,1},{0x01,-1}};
    std::unordered_map<std::bitset<8>,double>> m5(v.begin(),v.end());
    
    //constructor for a custom type
    std::unordered_map<Key, std::string, KeyHash, KeyEqual> m6={
        {{"John","Doe"},"example"},  
         {{"Mary","Sue"},"another"}
    };
}
```

## ReadMe

+ 20200504看完第1版，《深入应用C++11》的2.4。
  + 代码也没调一下，只是初略的看一下内容。