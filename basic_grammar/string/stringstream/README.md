## stringstream��

��C++�������ַ�������һ����sstream�ж��壬 ��һ����strstream�ж��塣
����ʵ�ֵĶ�������һ����
����������C�����е�sprintf()/scanf()

**strstream��**
```cpp
#include <strstream>
```
strstream�����
class strstreambuf;
class istrstream;
class ostrstream;
class strstream;
�����ǻ���C�����ַ���char*��д��

**sstream��**
```cpp
#include <sstream>
```
sstream�а���
class istringstream;
class ostringstream;
class stringbuf;
class stringstream;
class ����.
�����ǻ���std::string��д��

���ostrstream::str()���ص���char*���͵��ַ���
��ostringstream::str()���ص���std::string���͵��ַ���

��ʹ�õ�ʱ��Ҫע�⵽���ߵ�����һ��������Ƽ�ʹ��std::string���͵��ַ���
��Ȼ���Ϊ�˱��ֺ�C�ļ��ݣ�ʹ��strstreamҲ�ǲ����ѡ��

ʹ�÷�����
1. �Կո�ָ������ַ���
    
2. ���г���������ת��

**ע������**���ظ�ʹ��strigstream����ʱ��ת��ǰҪʹ��clear()������

[����](stringstream.cpp)



