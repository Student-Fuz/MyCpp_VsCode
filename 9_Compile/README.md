# 编译知识

## Ⅰ 直接编译

### 环境配置

[VSCode+MinGW+CMake环境配置](https://www.cnblogs.com/evergl0w/p/18392392)

### 编译相关指令

**C++**

1. **最简便编译指令**

```bash
g++ src.cpp
```

执行效果：在当前文件夹下生成a.exe程序（Windows）。

2. **自定义可执行文件名**

```bash
g++ src.cpp -o execute.exe
```

执行效果：生成一个名字为demo.exe的可执行文件，-o就是输出的意思()



## CMake编译

### 一、基本概念

#### 1.1 编译流程

**toolchain预处理 -> 编译 -> 汇编 -> 链接 -> 可执行文件**

#### 1.2 makefile工具编译

**makefile脚本 -> make批处理**

首先写下**makefile脚本**用于指示程序的编译流程，在使用**make**命令进行批处理操作进行编译。

#### 1.3 动态库、静态库

