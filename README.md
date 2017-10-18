# LeetCode题解

本仓库用来记录我的LeetCode题解，仓库中列出的题目均已AC，每题均提供Python、Java和C++解法。

## 代码格式化规约

### Python

Python代码格式化使用autopep8工具

命令：

```bash
autopep8 -i -r --max-line-length 99 -v ./
```

### Java

Java代码格式化使用astyle工具

配置文件：

```ini
# Java Coding Style Options
# Obtained from Java source code.

# braces and indent
style=java
# indent=spaces    # this is the default

# indentation
min-conditional-indent=0
max-continuation-indent=80

# padding
pad-oper
pad-header
unpad-paren
align-pointer=type

# formatting
break-one-line-headers
keep-one-line-blocks
keep-one-line-statements
convert-tabs

lineend=linux
```

命令：

```bash
astyle -n -R '*.java' --options=~/java.ini
```

### C++

C++代码格式化使用astyle工具

配置文件：

```ini
# LLVM Coding Style Options
# http://llvm.org/docs/CodingStandards.html

# braces and indent
style=attach
indent=spaces=4

# indentation
indent-continuation=2
indent-preproc-define
min-conditional-indent=0
max-continuation-indent=80

# padding
pad-oper
pad-header
unpad-paren
align-pointer=name

# formatting
break-one-line-headers
keep-one-line-blocks
keep-one-line-statements
convert-tabs
close-templates

# objective-c
pad-method-prefix
unpad-return-type
unpad-param-type
align-method-colon
pad-method-colon=none

lineend=linux
```

命令：

```bash
astyle -n -R '*.cpp' --options=~/llvm.ini
```
