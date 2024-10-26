# 浪土豆语言（TuDouLang）中文官方文档

# Installation

**浪土豆语言（TuDouLang）不提供 Windows/MacOS 平台安装方法。** *因为创始人土豆哥说过，还有人没有使用 Linux 桌面吗* **？**

## Building on a Unix-like system

**注：仅限 Deepin 发行版可安装，** *因为创始人土豆哥不使用其它发行版* **。**

### Dependencies

**本语言唯一依赖为 Java。** *因为创始人土豆哥说过，不要学其它语言，学 Java 就可以了* **。**

* **Java**

#### Build steps

```shell
git clone https://github.com/tudou-lang/tudou.git
cd tudou
```

**Configure the build settings:**

```shell
make
```

**‍tudoulang example**
```tudoulang
class Animal {
    init() {
        this.x = 8;
    }

    bark() {
        print "...";
    }
}

class Dog < Animal {
    init() {
        this.x = 5;
    }

    bark() {
        print "Woof!";
    }

    supBark() {
        super.bark();
    }

    cavolo(f) {
        print f(this.x);
    }
}

var dog = Dog();
print dog.x;
dog.bark();
print dog.x;
dog.supBark();

dog.cavolo(fun (a) {
    return a + 1;
});

```

[https://www.tudou-lang.icu/](https://www.tudou-lang.icu/) 目前正在积极筹款建设中...

**如果您也是土豆的语言的拥护者和收益者，感谢您的积极赞助。**

**我们后期可能规划签名墙，友链 用于感谢您的支持**

![](https://cdn.nlark.com/yuque/0/2024/png/599612/1729242612537-8dd7ac6e-f084-4478-b6b1-c989a4717ae0.png)
