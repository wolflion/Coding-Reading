## 缘起

## 内容

### 13、[罗马数字转整数](https://leetcode-cn.com/problems/roman-to-integer/)

+ 1、我的第1遍代码和思路

```cpp
class Solution {
public:
    int romanToInt(string s) {
    int i = 0;  //这个地方，我用了static，有啥风险点？
	for (int j = 0; j < s.size(); j++)
	{
		switch (s[j])
		{
		case 'M':
			i += 1000;
			break;
		case 'D':
			i += 500;
			break;
		case 'C':
			if (s[j + 1] == 'D')
			{
				i += 400; j++;
			}
			else if (s[j + 1] == 'M')
			{
				i += 900; j++;
			}
			else
				i += 100;
			break;
		case 'L':
			i += 50;
			break;
		case 'X':
			if (s[j + 1] == 'L')
			{
				i += 40; j++;
			}
			else if (s[j + 1] == 'C')
			{
				i += 90; j++;
			}
			else
				i += 10;
			break;
		case 'V':
			i += 5;
			break;
		case 'I':
			if (s[j + 1] == 'V')
			{
				i += 4; j++;
			}
			else if (s[j + 1] == 'X')
			{
				i += 9; j++;
			}
			else
				i += 1;
			break;
		default:
			break;
		}
	}
    return i;
    }
};
```

### 20、[有效的括号](https://leetcode-cn.com/problems/valid-parentheses/)

+ 是我AC的代码，也是改了几回的。
  + 比如pop()前没有判断stack是否空，直接core掉了。
  + 没有先判断长度，是不是偶数；**当然，最后一步没有判断stack是否为空了**。
  + *最开始，我竟然想通过直接数组的方式，顺序查找*，果然有用例没有跑到。
  + `for (auto i: s)`这样的特性还不熟悉，不知道`i`中存放的是啥？

```cpp
class Solution {
public:
	bool isValid(string s) {
bool bValue = true;
	stack<char> cStack;
	if (s.size() % 2 == 1)
	{
		return false;
	}
	for (auto i : s)
	{
		switch (i)
		{	
		case '(':
		case '[':
		case '{':
			cStack.push(i);
			break;
		case ')':
			if (cStack.size() == 0|| cStack.top() != '(')
				bValue = false;
                if(cStack.size() > 0)
			cStack.pop();
			break;
		case '}':
			if (cStack.size() == 0 || cStack.top() != '{')
				bValue = false;
                if(cStack.size() > 0)
			cStack.pop();
			break;
		case ']':
			if (cStack.size() == 0 || cStack.top() != '[')
				bValue = false;
                if(cStack.size() > 0)
			cStack.pop();
			break;
		default:
			break;
		}
	}
	if (cStack.size() > 0)
		bValue = false;
		
    return bValue;
	}
};
```

### 14. [最长公共前缀](https://leetcode-cn.com/problems/longest-common-prefix/)

+ 自己AC后的代码
  + 1、`vecotr<string>`的初始化问题，除了`push_back()`外，是不是还有别的方法？
  + 2、对这种`vector<string>`竟然有点懵了。

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";  // 这是自己没有考虑到的。
        /*
	* 执行出错信息：
Line 1034: Char 9: runtime error: reference binding to null pointer of type 'std::__cxx11::basic_string<char>' (stl_vector.h)
最后执行的输入：
[]
	*/
        string base = strs[0];
	for (auto str : strs) // 想到用这种for了，但没想到怎么去找个参考点，【因为只是比较，所以auto &str，是不是引用，应该关系不大】。
	{
		for (int i = 0; i < base.length(); i++)
		{
			if (str[i] != base[i])
			{
                // 这个写法要get一下，先找到位置，然后再求字符串内容
				base = base.substr(0, i);
			}
		}
	}
	return base;
    }
};
```

### 58、[最后一个单词的长度](https://leetcode-cn.com/problems/length-of-last-word/)

+ 我写的代码：
  + 有点没太理解 "a "，这样的情况，返回的length是1，于是注释掉我写的，然后网上找的一段。
  + **`break`和`continue`还是要活用一下**。
+ 思路：（1）想着就`reverse`，（2）求长度后，从最后一个往前，找到空格，就是num了。

```cpp
int Solution::lengthOfLastWord(string s)
{
	if (s.size() == 0)
		return 0;

	int iCnt = 0;
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
			iCnt++;
		else if (iCnt != 0)
			break;
		/*
		else if (s[i] == ' ')
		{
			return iCnt;
		}
		*/
			
	}
	return iCnt;
}
```

### 17、[ 电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)

+ 思路
  + 我想到了用字母对应的关系，但我定义的`vector<string>`后，我竟然用的是`push_back()`，**感觉到不太好，但没想到可以直接初始化**。
  + **回溯法**还不太理解。
+ 代码（copy）的

```cpp
class Solution {
private:
    vector<string> res;
    // 我想的是vetor<string>，不过没想到初始化的方式，用的还是push_back()的老思路。
    const string letterMap[10]{""," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    void findCombination(const string& digits, int index, const string& s){
        if(index == digits.size()){
            //保存结果
            res.push_back(s);
            return;
        }
        char c = digits[index]; //获取字符串中的指定位置的数字
        string letters = letterMap[c -'0']; //获取上述数字对应的字母
        for(int i =0; i < letters.size(); i++){ //遍历上述数字对应字母的每种可能性，然后对之后的数字字符串递归上述操作
            findCombination(digits, index + 1, s + letters[i]);
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        res.clear();
        if(digits == "")
            return res;
        findCombination(digits, 0, "");
        return res;
    }
};
```



### 0、