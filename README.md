# 算法设计与分析


## 基本文件操作食用方法：

这个仓库的主要包含的文件有 `*.sin` `*.vcxproj` `*.vcxproj.filters` `*.cpp` `*.h`

`*.sin` 可以理解为解决方案，记录了一些版本号和一些**全局变量信息的加载，用来维护两个文件中项目的状态信息**

详情参考：[项目解决方案 （.sln）](https://learn.microsoft.com/zh-cn/visualstudio/extensibility/internals/solution-dot-sln-file?view=vs-2022) 

`*.vcxpro` 是将工程中的**所有文件和配置信息都**记录在一起形成整体的文件

**`*.vcxproj.filters` 是**筛选器文件，指定哪些是头(header)文件，哪些是源文件等。

详情参考：[vcxproj.filters 文件](https://learn.microsoft.com/zh-cn/cpp/build/reference/vcxproj-filters-files?view=msvc-170)

<aside>
💡


说人话：`*.sin` `*.vcxproj`  `.vcxproj.filters` 这三个东西是直接打包好的环境，点击`*.sin`就可以打开项目了

</aside>