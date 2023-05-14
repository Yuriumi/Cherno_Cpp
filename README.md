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

## 头文件

``` cpp
// main.cpp

void Log(const char* message)
{
    std::cout << message << std::endl;
}

int main()
{
    Log("Hello World!"); // 正常调用
}
```

``` cpp
// 新建Log.cpp
void LogInit()
{
    Log("Log Init"); // 编译时报错,无法找到"Log"函数
}
```

我们需要**函数的声明**来告诉编译器`Log`函数确实存在,只不过他的定义在其他的文件.

``` cpp
// Log.cpp
void Log(const char* message);

void LogInit()
{
    Log("Log Init"); // 编译时报错,无法找到"Log"函数
}
```

程序正常运行,但如果我们在创建一个新的文件,意味着我们要**重复添加**函数的声明,尤其是在不止一个函数的时候,复制粘贴显得很麻烦,而且可读性也很糟糕;这个时候就需要使用头文件.

``` cpp
// 新建Log.h
#pragma once

void Log(const char* message);
```

``` cpp
// Log.cpp
#include "Log.h"

void LogInit()
{
    Log("Log Init");
}
```

程序正常运行.

现在在`mian`函数中无法使用`LogInit`函数,我们依旧可以使用头文件来解决问题.

``` cpp
// Log.h
#pragma once

void Log(const char* message);
void LogInit();
```

``` cpp {.line-numbers}
// main.cpp
#include <iostream>
#include "Log.h"

void Log(const char* message)
{
    std::cout << message << std::endl;
}

int main()
{
    std::cout << "Hello World!" << std::endl;
    std::cout << "--------------------" << std::endl;

    LogInit();
    Log("Hello World!");

    std::cin.get();
}
```

程序正常运行.

### #pragma once

用于防止**重定义**的出现,下述案例使用结构体演示

``` cpp
// Log.h
// #pragma once

void Log(const char* message);
void LogInit();

struct Player {};
```

``` cpp {.line-numbers}
// main.cpp
#include <iostream>
#include "Log.h"
#include "Log.h"

void Log(const char* message)
{
    std::cout << message << std::endl;
}

int main()
{
    std::cout << "Hello World!" << std::endl;
    std::cout << "--------------------" << std::endl;

    LogInit();
    Log("Hello World!");

    std::cin.get();
}
```

编译时报错,`Player`被重定义;但这种简单的错误我们正常是不会犯得,但如果换一种情况.

``` cpp
// 新建other.h
#include "Log.h"
```

``` cpp {.line-numbers}
// main.cpp
#include <iostream>
#include "other.h"
#include "Log.h"

void Log(const char* message)
{
    std::cout << message << std::endl;
}

int main()
{
    std::cout << "Hello World!" << std::endl;
    std::cout << "--------------------" << std::endl;

    LogInit();
    Log("Hello World!");

    std::cin.get();
}
```

编译时报错,`Player`被重定义;我们取消注释`#pragma once`,程序正常运行.

`#pragma once` 的功能与`#ifndef`相同.

``` cpp
// Log.h
#ifndef _LOG_H
#define _LOG_H

#include <iostream>

void Log(const char* message);
void LogInit();

struct Player {};

#endif
```

程序正常运行.

### <> 和 "" 的区别

<>用于表示绝对路径(编译器包含路径),""则表示相对路径.

`iostream`不带文件后缀是为了与C语言的头文件进行区分.

## 条件与分支

C++中并不包含`else if`关键字,他仅仅是将`else`与`if`写在同一行,是一种"小聪明".

在程序中我们应当避免使用**条件分支语句**它会拖慢程序的运行效率,我们应该使用一些数学运算来更好的优化代码.

## 循环

### for

``` cpp
// 通常写法
for (unsigned int i = 0; i < 5; i++)
{
    Log("Hello World!");
}
```

``` cpp
// 与上相同
unsigned int i = 0;

for ( ; i < 5; )
{
    Log("Hello World!");

    i++;
}
```

``` cpp
// 死循环
for ( ; ; )
{
    Log("Hello World!");
}
```

### while

``` cpp
unsigned int i = 0;

while(i < 5)
{
    Log("Hello World!");
    i++;
}
```

``` cpp
unsigned int i = 0;

do
{
    Log("Hello World!");
    i++;
}while(i < 5);
```

## 控制流语句

主要的控制流语句`continue`,`break`,`return`.

- `continue` : 结束当前循环,进入下一次循环迭代.
- `break` : 跳出循环.
- `return` : 结束当前所在的方法.

## 指针

一个指针,只是一个内存地址,仅此而已!

``` cpp {.line-numbers}
int var = 8;

void* ptr = 0; // 表示空指针,0对于内存地址是无效的
ptr = NULL;
ptr = nullptr;

ptr = &var; // 使用&获取变量的内存地址

std::cout << *ptr << std::endl; // 使用*访问指针存储的对象
```

``` cpp {.line-numbers}
int var = 5;

void* ptr = &var;
*ptr = 10; // 错误的,编译器无法知道指针类型,为变量分配内存

int* ptr = var;
*var = 10;
```

指针不是数据,我们不知道指针的大小.

``` cpp
char* buffer = new char[8];
memset(buffer, 0 ,8); // 为该指针指向的内存区域8个字节填充数据,数据为0.
```

![memory1](img/memory.jpg)

这个语句向系统申请了8个字节的空间,并返回一个指向那块内存开始的指针.

``` cpp
char** ptr = &buffer;
```

双指针,指向另一个指针;指针本身是变量(对象).

## 引用

引用是引用现有变量的一种方式,他们并不占用内存;可以理解为变量访问的快捷方式(语法糖).

编译器在编译时会将引用优化成对应的变量.

声明一个引用时,应立即对其进行初始化.

``` cpp
int a = 5;
int& ref_a = a;

ref_a = 2;
```

``` cpp
void Increment(int value)
{
    value++;
}

int main()
{
    Increment(a);
    std::cout << a << std::endl;
}
```

上述案例的操作是将变量`a`的值赋予新的变量`value`,累加操作作用的是`value`;如果我们想对变量`a`进行累加第一种方法是我们可以使用指针.

``` cpp
void PointIncrement(int* value)
{
    (*value)++;
}
```

可以看出使用指针的方法很麻烦也不利于增强代码的可读性,使用引用可以更好的解决问题.

``` cpp
void RefIncrement(int& value)
{
    value++;
}
```

## 类

``` cpp {.line-numbers}
class Player // 一个类不标明可访问性时,默认为私有
{
public:
    int x, y;
    int speed;

    void Move(int xa, int ya)
    {
        x += xa * speed;
        y += ya * speed;
    }
};
```

## 类与结构体对比

在C++中区别于他们的可访问性,默认情况下`struct`的可见性是`public`,`class`的可见性是`private`;目的是向下兼容C语言.

### 如何选择

仅仅表示一些变量与结构时使用`struct`(例如数学中的向量).

希望表示更多功能或者有明确的继承关系使用`class`.

## 如何写一个C++类

以一个`Log`类为例,我们可以先认为类已经写完,看看我们需要什么功能.

``` cpp {.line-numbers}
Log log;
log.SetLevel(log.LogLevelWarning);
log.Error("Hello!");
log.Warn("Hello!");
log.Info("Hello!");
```

需求确定完成后,我们去完善我们的类.

``` cpp {.line-numbers}
class Log
{
public:
    const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2;

private:
    int m_LogLevel = LogLevelInfo;

public:
    void SetLevel(int level)
    {
        m_LogLevel = level;
    }

    void Error(const char* message)
    {
        if (m_LogLevel >= LogLevelError)
            LOG("[ERROR]: " << message);
    }

    void Warn(const char* message)
    {
        if (m_LogLevel >= LogLevelWarning)
            LOG("[WARNING]: " << message);
    }

    void Info(const char* message)
    {
        if (m_LogLevel >= LogLevelInfo)
            LOG("[INFO]: " << message);
    }
};
```

这样一个基本可用的类就编写完成了.

## 类和结构体外的静态

- 在类或结构体外部使用静态

这意味着你定义的函数和变量只对他声明所在的cpp文件(翻译单元.obj)是"可见"的.

- 在类或结构体内使用静态

此时表示静态变量所在的内存是所有类的实例共享的,静态变量的实例只有一个.

类中的静态函数也一样，静态函数中没有该实例的指针（this）。在类中没有实例会传递给该函数.

除非你真的需要,否则没必要将其设置为全局变量.

我们不能声明两个标识符相同的全局变量.

使用`extern`声明可以将一个变量改为另一个翻译单元的变量的引用.

``` cpp {.line-numbers}
// static.cpp中
int s_var = 5;

// main.cpp
extern int s_var;   //注意这里没有了赋值
int main(){
    std::cout << s_var << std::endl;
}

// 输出5
```

## 类与结构体内的静态

- **静态方法**不能访问**非静态成员**
- **静态方法没有类实例**
- 本质上在类中写的每个**非静态方法**都会获得当前类的实例作为参数.
- 静态成员在变量编译时存储在**静态存储区**,即**定义过程在编译时完成**,因此一定要**在类外进行定义**,但可以不进行初始化.静态成员变量是所有实例共享的;但是其**只在类中进行了声明,并未定义或初始化**(分配内存).类或者类实例就无法访问静态成员变量，这显然是不对的,**所以必须先在类外部定义**,也就是分配内存.
- 通过**类的实例引用静态成员是没有意义的**,在**静态函数中引用类的实例成员也是没有意义**的.

静态方法和在类外编写函数是一致的.

``` cpp {.line-numbers}
struct Entity
{
    int x;

    static void print()
    {
        cout << x << endl;  // 报错，不能访问到非静态变量x
    }
};
//在类外面写一个print()函数
static void print()
{
    cout << x << endl;  // 报错，x是什么？没被定义。
}
```

使用参数列表可以访问类的实例成员.

``` cpp {.line-numbers}
struct Entity
{
    int x;

    static void print(Entity e)
    {
        cout << e.x << endl;  // 报错，不能访问到非静态变量x
    }
};
```

## 局部静态

- 变量的生命周期指的是变量从创建到销毁之间的时间.
- 作用域指的是变量的可访问范围.

局部静态变量允许我们声明一个变量,它的生命周期相当于整个程序的生命周期,然而他的作用域却是局部的.

``` cpp {.line-numbers}
void Function()
{
    static int i = 0;
    i++;
    LOG(i);
}

Function();
Function();
Function();

// 输出结果为1,2,3
```

典型的案例还有单例类(该类有且只有一个实例)

``` cpp {.line-numbers}
// 不使用局部静态
class Singleton
{
private:
    static Singleton* s_Instance;
public:
    static Singleton& Get() { return *s_Instance; }
};

Singleton* Singleton::s_Instance = nullptr;
```

``` cpp {.line-numbers}
// 用局部静态
class Singleton
{
public:
    static Singleton& Get()
    {
        static Singleton instance;
        return instance;
    }
};
```

## 枚举

枚举只是将一些特定值进行命名的一种方式,最大的好处是他是已经归类好的了.

``` cpp {.line-numbers}
enum Example // 默认为Int类型的几何A = 0, B = 1, ...
{
    A, B, C
};

Example value = B;

if (value == B)
{
    // Do something here
}
```

``` cpp
enum Example : unsigned char
{
    A = 65, B, C
}
```

我们也可以更改其类型(类型必须为整数,例如float是不可行的).

我们可以修改完善Log类了.

``` cpp
enum Level
{
    Error = 0, Warning, Info
};
```

枚举并不是命名空间,不可以通过`::`访问其成员,它只属于所在的类.

## 构造函数

构造函数特殊的函数,他没有返回值,名字与类名保持一致.

它用于对我们的自定义类进行初始化.

其他语言可能会对基本类型进行初始化,但C++不会,你必须手动对他进行初始化.

如果你不指定构造函数,你仍然有一个构造函数,这叫做默认构造函数,是默认就有的.但是,我们仍然可以删除该默认构造函数.

``` cpp
// 默认构造函数
Entity() {}
```

``` cpp
Entity() = delete;
```

使用函数的重载可以为一个类创建多个构造函数.

构造函数会在创建实例时运行;所以如果你使用一个该类的静态函数,构造函数是不会执行的.

## 析构函数

当一个对象被销毁时调用析构函数;来清理内存.

析构函数同时适用于栈和堆分配的内存.

- 栈上的对象当超出其作用域时,对象会被删除,调用析构函数.
- 使用new关键字在在堆上创建对象,当使用delete关键字删除对象时,析构函数将会被调用.

!!!warning
    **析构函数没有参数列表,不能被重载**,因此一个类只有一个析构函数.
    不显式的定义析构函数系统会调用默认析构函数