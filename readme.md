# gitNote
一个基于 git 进行数据同步的云笔记
## 依赖
Qt 5.12.11
## 构建
### 设置环境变量
需要设置系统环境变量 `CMAKE_PREFIX_PATH` 为 Qt 的安装目录下的 `lib` 或 `lib/cmake`。
### 编译
1. 建立 `build` 目录：`mkdir build && cd build`
1. CMake 配置：`cmake ..`
1. 编译：`cmake --build .`

## 注意
由于历史残留原因，`textedit`目录下还有 qmake 用的项目文件，不建议使用。