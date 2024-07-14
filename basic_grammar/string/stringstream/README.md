## stringstream类

在C++有两种字符串流，一种在sstream中定义， 另一种在strstream中定义。
它们实现的东西基本一样。
作用类似于C语言中的sprintf()/scanf()

**strstream库**
```cpp
#include <strstream>
```
strstream里包含
class strstreambuf;
class istrstream;
class ostrstream;
class strstream;
它们是基于C类型字符串char*编写的

**sstream库**
```cpp
#include <sstream>
```
sstream中包含
class istringstream;
class ostringstream;
class stringbuf;
class stringstream;
class …….
它们是基于std::string编写的

因此ostrstream::str()返回的是char*类型的字符串
而ostringstream::str()返回的是std::string类型的字符串

在使用的时候要注意到二者的区别，一般情况下推荐使用std::string类型的字符串
当然如果为了保持和C的兼容，使用strstream也是不错的选择。

使用方法：
1. 以空格分隔输入字符串
    
2. 进行常见的类型转换

**注意事项**：重复使用strigstream对象时，转换前要使用clear()方法。

[例程](stringstream.cpp)



