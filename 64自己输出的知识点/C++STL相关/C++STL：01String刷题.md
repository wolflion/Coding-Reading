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

