# ([games-score-statistics](games-score-statistics))

## 如何使用 (Usage)

### 下载或者克隆项目到本地 （Download or clone the project to your local）

-	下载项目到本地
-	Download the project to the local

![](https://i.loli.net/2019/01/09/5c34f854148ad.png)

-	Clone 项目到本地（需要GIT）
-	Clone project to local（Need GIT）

```shell
Git clone https://github.com/mossnodie/games-score-statistics.git
```

![image003.png](https://i.loli.net/2019/01/09/5c34f8984be1b.png)

## Cygwin

本程序在cygwin下测试通过，通过cmake（3.6.2）编译，修改程序可以在配置cygwin的CLion中使用。  
This program is tested under cygwin and compiled by cmake (3.6.2). The modified program can be redeveloped in CLion with cygwin configuration.

![](https://i.loli.net/2019/01/09/5c34f8a84d6fc.png)

![cygwin](https://www.cygwin.com/)

## cmake+make

在项目目录打开powershell  
Open powershell in the project directory

```shell
cd .\games-score-statistics\
```

执行  
Run it in the shell  

```shell
cmake .\CMakeLists.txt
make
```
 
等待  
Wait  

在项目目录下可以找到 `games-score-statistics.exe`
You can find `games-score-statistics.exe` in the project directory

![image007.png](https://i.loli.net/2019/01/09/5c34f8a891a3d.png)

## Enjoy

添加这些数据  
Add these data  

![](https://i.loli.net/2019/01/09/5c34f8a856a9a.png)

```shell

1
6
某某大学1
健身跑
1
1
55
某某大学2
健身跑
1
1
99
某某大学3
健身跑
1
1
11
某某大学1
健身跑
0
1
55
某某大学2
健身跑
0
1
99
某某大学3
健身跑
0
1
11

```

![](https://i.loli.net/2019/01/09/5c34f8a85ae88.png)

现在他已经可以运行了  
Now the program is ready to run.
