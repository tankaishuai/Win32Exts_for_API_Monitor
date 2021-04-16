/*
文件捆绑器用法：
（1）宿主程序（盾）中，将 PePacker.cpp 文件添加入工程即可，核心代码已高度封装并优化，无需添加任何额外代码。

（2）捆绑方法：假设宿主程序为 a.exe, 需要捆绑：d:\b1.exe 及 d:\b2.exe 及 d:\b3.exe （可 1~任意多个），
并以 b1.exe 的【图标及版本信息】做为生成文件的 【图标及版本信息】，
    直接打开 GUI程序：【PePackerUI.exe】 依此选择文件执行捆绑即可。

也可以使用命令行，依此执行如下命令：
    a.exe --concat=d:\b1.exe
    a.exe --concat=d:\b2.exe
    a.exe --concat=d:\b3.exe
执行后宿主程序同级目录下存在一个：a.exe.new 的文件，将其改名为你想要的任意文件名 x.exe 发布即可。
*/
