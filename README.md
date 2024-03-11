# The Abstract Machine (AM)

## How to build benchmark flash image
- clone `nexus-am` from github:
``` shell
git clone git@github.com:OpenXiangShan/nexus-am.git
```
- enter benchmark directory (using `apps/coremark` as an example):
```
cd /apps/coremark
make ARCH=riscv64-xs-nhv3
cd ./build
ls
```
- you will find a ".bin" file, this is a benchmark image in flash

## Nanhu-V3裸机程序增加

参考任意一个现有的 apps（如coremark）的目录结构与 Makefile 文件.

1. 在 apps 中新建一个 workload 目录存放程序源代码。
2. 参考其他 workload 编辑 Makefile。
3. 编译架构使用 riscv64-xs-nhv3 `make ARCH=riscv64-xs-nhv3`
