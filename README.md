# 基于fcitx5的简单输入法

出于本人对输入法框架的兴趣，决定写一个关于fcitx5的简单输入法。  
旨在帮助社区上更多的人理解和使用fcitx5输入法框架。    
随时欢迎交流与输入法框架相关的问题：hantengwy@163.com

# 构建方法
```
1. mkdir build
2. cd build
3. cmake .. -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_INSTALL_LIBDIR=lib/${CMAKE_LIBRARY_ARCHITECTURE}
4. make && sudo make install
```