# Easy2D

Easy2D 是一个简单易用的2D图形库。

它可以协助我们在学习C/C++语言阶段，编写有趣的图形化小程序。

## Easy2D的使用 (别忘了右上角 Star 一下)

正如其名，使用非常简单。

项目拉取后，其中 sdk 目录关系到您的程序的开发与发布。

- sdk/lib：当前目录中的 Easy2D.h 是我们基于 Easy2D 库开发程序的接口文件。
- sdk/bin：程序运行时库，当你发布或运行程序时，需要将所有文件拷贝到程序所在目录。

让我们从搭建 Easy2D 环境开始，在此之前需要做两步工作：

- 1：使用 VS2015 创建一个空的 Win32 控制台应用程序 项目。
- 2：拷贝 sdk/lib 文件夹下的文件到当前项目所在文件夹。

```
// #1：包含Easy2D库头文件
#include "Easy2D.h"

int main()
{
    // #2：初始化库（创建指定标题与大小的窗口）
    if (E2D_Init("Hello, Easy2D!", 800, 600))
    {
        // #3：让库运行起来
        E2D_Run();

        // #4：关闭窗口时执行库清理操作
        E2D_Release();
    }

    return 0;
}
```

** 生成完成后，你需要将 sdk/bin 目录中的所有文件拷贝到当前 Exe 所在目录。**

这时运行程序，你会看到一个背景漆黑一片的窗口，恭喜你，学会了 Easy2D 的使用了！

---
## 关于作者

有志于代码改变世界，其实没那能力。现在也就写些简简单单的程序，发些编程软文与教程。

> 我的站点：[http://www.glimix.com](http://www.glimix.com)


微信公众号：皮拉夫大王

![我的微信公众号](http://glimix.com/images/2020/qrcode_for_gh_4915cab7ce09_258.png)


## Reward

如果你喜欢 Easy2D，可以通过赞赏来支持我们：

![我的赞赏码](http://glimix.com/images/2020/mm_reward_qrcode_1587216010693.png)


## Easy2D 的更多说明

- Easy2D 是基于 [SDL](https://www.libsdl.org/) 2.0 创建。
- Easy2D 应用于 Microsoft Visual Studio 2015 及其以上版本。