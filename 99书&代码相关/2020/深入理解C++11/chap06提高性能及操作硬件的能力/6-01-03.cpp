constexpr int f();
int a = f();
const int b = f();
//constexpr  int c = f(); // 无法通过编译  【 error: ‘constexpr int f()’ used before its definition】
constexpr int f() { return  1; }
constexpr int d = f();

// g++ -std=c++11 -c 6-01-03.cpp

// Clion对应的工具也不行，选的也是C++11，必须要linux平台，这不合理啊。