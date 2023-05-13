# Cherno C++

[TOC]

## 参考资料

教程源地址: [Youtobe](https://www.youtube.com/playlist?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb) The Cherno
中文翻译地址: [BiliBili](https://space.bilibili.com/364152971/channel/collectiondetail?sid=13909) 神经元猫
大佬笔记: [知乎](https://zhuanlan.zhihu.com/p/553387258) 萨达哈鲁

## 变量

位于内存中堆和栈上的**容器**.

不同变量(**原始数据类型**)的唯一区别是在内存中占用的大小.

`unsigned`取消符号,使原始数据类型仅表示**无符号**数据.

例如`int`表示的范围为$ 2^{31} $(约正负21亿),其中一位用作表示数据的正负,在`int`前加上`unsigned`表示数据的范围改为$ 2^{32} $(约42亿).

``` cpp
// 其他原始数据类型
// char,float,double,long,long int,bool, ...
```

`char`用于存储*单个字符*,字符使用数字来表示.

``` cpp
char a = 'A';
char b = 65;

std::cout<< a <<std::endl;
std::cout<< b <<std::endl;
```

输出结果

``` cpp
A
A
```

`float`与`double`用于存储浮点数,通常情况下,字面量浮点数的数据类型为`double`;在字面量后加`f`使其存储为`float`类型.

``` cpp
// 5.5  double
float variable_a = 5.5; // double
double variable_b = 5.5; // double
float variable_c = 5.5f; // float
```

`bool`**非零既一**,这里的非零既一并不是零或一,而是只要不是零都视为一.零代表**假**,一代表**真**.

使用`sizeof`查询数据类型所占的内存空间.

``` cpp
std::cout << sizeof(bool);
```

## 函数

函数是我们书写的**特定功能**的代码块,用于执行特定的任务,避免**代码重复**.

### 函数的声明与定义

``` cpp
int Multiply(int a, int b)
{
    return a * b;
}
```

- `int`的位置为**函数的返回值**,他的任务是告诉并规定该函数执行完需要返回一个`int`类型的值,如果希望不返回值或返回值为其他类型只要将其改为`void`或其他类型即可.
- `Multiply`为函数的标识符,标识符可以是任意名字,但最好的命名是使改名字具有意义,例如描述该函数的功能.
- `(int a, int b)`函数的参数列表,该函数需要什么数据;参数列表也可为空`()`.
- `{}`函数体,函数的内容,如果该函数有返回值,需要加上`return`语句,来返回最终处理的值.

### 函数的调用

``` cpp
int main()
{
    Multiply(3,4);
    std::cout<< Multiply(3,4) <<std::endl;
    int result = Multiply(3,4);
}
```

需要注意的使第一个,我们没有对返回的值进行储存等处理,最后返回的结果会被直接丢弃.

### main函数的int返回值

一个自定义函数如果表明了返回值类型,但没有返回相应类型的值,在编译时会产生报错(Debug模式下).

在一个程序中,只有主函数被豁免(不一定是main函数),它会自动假设你返回0.
