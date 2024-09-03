## 智能指针

### 简介

**为什么要学智能指针**

智能指针就是帮我们C++程序员管理动态分配的内存的，它会帮助我们自动释放new出来的内存（堆区 heap），从而避免内存泄漏！

依赖库

    include<memory>;

### 智能指针类型

标准库提供了两种智能指针类型来管理动态对象。
分别是：
 - **shared_ptr**允许多个指针指向同一个对象
 - **unique_ptr**”独占“所指对象

另外，标准库还定义了weak_ptr


#### shared_ptr类


类似于vector，智能指针也是模板。创建方式如下：

    shared_ptr<string> p1;          //shared_ptr 可以指向string

*shared_ptr自动销毁所管理的对象：*
当指向一个对象的最后一个shared_ptr被销毁时，shared_ptr类会自动销毁此对象。


