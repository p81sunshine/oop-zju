# Lab3

## 编译

本实现使用了结构化绑定，所以确保您的编译器支持`c++17`。

所有平台用户都可以使用以下命令来编译运行：

```sh
g++ Game.cpp Room.cpp -o game.exe -std=c++17
./game.exe
```

## 地图格式

`Map.txt`是地图文件，第一行是房间数量，随后是房间的名字，随后是房间之间如何连接。格式是`from direction to`。
如果要修改地图，请务必使用此格式。
