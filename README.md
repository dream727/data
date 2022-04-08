# data
一个关于日志的小项目，本人技术并不是很好所以可能会有很多可优化地方
## 1.0
- 1.增加日志：键盘直接输出，时间输入1会自动输入当前时间
>思路：直接向硬盘写入键盘输出数据
- 2.修改日志：输入1修改时间，输入2修改事件
>思路：先将储存的文件读取到容器内，修改容器内的数据后在覆盖写入硬盘 ~~（很暴力吧）~~
- 3.删除日志：输入删除行数
>思路：和修改一样
- 4.查看日志：输入1查看全部，输入2查看指定行数
>思路：读取硬盘文件，查看指定行是循环到输入的行数然后输出此行
- 5.修改路径：输入路径后修改
>思路：修改save属性后，将save属性覆盖写入硬盘
- 6.获取行数：输入对应时间
>思路：在文件中一行一行查找，找到就输出行数和时间内容
- c. ~~钝角~~ 退出
>思路： ~~这个没人不会吧[doge]~~ 返回0
## 2.0
- 1.修改日志增加功能都修改
- 2.把所有 _ifstream<<str;_ 改为 _getline(ifstream,str);_ 可以读取空格
- 3.修改路径合并，修改后时间和事件都存入此路径
- 4.修复 _getTime()_ 中不会格式化天数的小bug
- 5.修改默认创建文件夹名称改为databyDream防止与同名文件夹冲突
## 3.0
- 增加删除日志时需要确认
