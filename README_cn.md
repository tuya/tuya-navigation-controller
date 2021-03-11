注意：当前仓库继承自即将被 [废弃的涂鸦Github仓库](https://github.com/TuyaInc/TYNavigationController)，请使用当前 Github 仓库进行涂鸦 SDK相关开发。更换远程Github仓库URL的教程，可以参考 [这里](https://docs.github.com/cn/free-pro-team@latest/github/using-git/changing-a-remotes-url).

# TYNavigationController

TYNavigationController 是涂鸦自研的导航栏组件。为了统一应用内导航栏风格，建议接入涂鸦 UI 业务包的客户统一使用 TYNavigationController 作为导航栏组件。



### TYNavigationController 的特性

- 原生视觉体验、原生过渡动画

- 链式语法

- item 支持状态控制

- 导航栏背景支持颜色、图片、layer

- 支持 alpha 渐变、blur 渐变、transform 动画

- 支持全局默认样式配置

- 支持全屏返回手势

- 每个 VC 可独立维持样式，对上级 VC 无影响

- 上级 VC 可为下级 VC 提供默认样式，下级 VC 也可以覆盖默认样式

  

## 示例

运行 Example 项目，请先克隆仓库，然后在 Example 目录下运行 `pod install` 。

更多用法，参考 [TYNavigationController Example](https://github.com/tuya/tuya-navigation-controller/tree/main/Example)。

## 安装

TYNavigationController 可以通过 [CocoaPods](https://cocoapods.org) 进行安装, 需要在 Podfile 文件中添加如下声明:

```ruby
source 'https://github.com/TuyaInc/TYPublicSpecs.git'

pod 'TYFoundationKit'
```

## 作者

TuyaInc, https://www.tuya.com
