## C++ ���߳�

���߳��Ƕ��������һ��������ʽ���������������õ���ͬʱ�����������������ϵĳ���һ������£��������͵Ķ����������ڽ��̺ͻ����̡߳�

 - ���ڽ��̵Ķ��������ǳ���Ĳ���ִ��.
 - �����̵߳Ķ���������ͬһ�����Ƭ�εĲ���ִ�С�

���̳߳����������ͬʱ���е������������֡������ĳ����е�ÿ�����ֳ�Ϊһ���̣߳�ÿ���̶߳�����һ��������ִ��·����

### pthread

��linuxϵͳ�У���ʹ��POSIX Threads/pthread�ṩ��API��д���߳�C++����

pthread�̴߳���������
```cpp
#include <pthread.h>
pthread_create (thread, attr, start_routine, arg)
```

�߳���ֹ
```cpp
pthread_exit (status)
```
**ע��**����� main() ���������������߳�֮ǰ��������ͨ�� pthread_exit() �˳�����ô�����߳̽�����ִ�С��������ǽ��� main() ����ʱ�Զ�����ֹ
�̴߳���[����](/Threads/pthread.cpp)

ʹ�� -lpthread ��������
    $ g++ test.cpp -lpthread -o test.o

#### ���Ӻͷ����߳�
���������������̵߳�����

��������    -->  ����Ҫ�����߳�ȥ����pthread_join()��������Դ��
�Ƿ�������  -->  ��Ҫ������߳�ȥ����pthread_join��������Դ��

����ʹ�������������������ӻ�����̣߳�
```cpp
pthread_join (threadid, status) 
pthread_detach (threadid)
```

### std::thread
C++ 11 ֮��������µı�׼�߳̿� std::thread��std::thread �� <thread> ͷ�ļ������������ʹ�� std::thread ʱ��Ҫ���� �� <thread> ͷ�ļ�

���뷽ʽ��

$ g++ -std=c++11 test.cpp 

std::thread Ĭ�Ϲ��캯��������һ���յ� std::thread ִ�ж���

```cpp
#include<thread>
std::thread thread_object(callable)
```

һ���ɵ��ö�����������������е��κ�һ����
- ����ָ��
- ��������
- lambda ���ʽ

### �߳�/����ͬ��


