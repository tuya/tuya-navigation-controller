## TYNavigationController 使用指南

TYNavigationController 是涂鸦自研导的航栏组件。为了统一应用内导航栏风格，建议 ODM 客户统一使用 TYNavigationController 作为导航栏组件

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



### 核心类

#### [TYNavigationController](https://github.com/TuyaInc/TYNavigationController/blob/master/TYNavigationController/Headers/TYNavigationController.h)

用于替代UINavigationController的控制器类，一般只有一级页面需要用到，用法如下

#### [UIViewController+TYNavigation](https://github.com/TuyaInc/TYNavigationController/blob/master/TYNavigationController/Headers/UIViewController%2BTYNavigation.h)

用于记录 VC 的导航栏样式的分类，引用头文件后可以直接使用

#### [TYNavigationBarItem](https://github.com/TuyaInc/TYNavigationController/blob/master/TYNavigationController/Headers/TYNavigationBarItem.h)

用于替代 UIBarButtonItem 的类，支持大量参数配置，支持链式语法

#### [TYNavigationTopBarProtocol](https://github.com/TuyaInc/TYNavigationController/blob/master/TYNavigationController/Headers/TYNavigationTopBarProtocol.h)

由 UIViewController+TYNavigation 引入并实现了该协议，该协议包含所有以 ty_topBar 开头的 VC 分类属性与方法，一般均使用该协议内方法

所有以 ty_topBar 开头的属性或方法，均表示该属性或方法 仅对 当前页面生效，不影响 push / pop 以后的页面

#### [TYNavigationNaviBarProtocol](https://github.com/TuyaInc/TYNavigationController/blob/master/TYNavigationController/Headers/TYNavigationNaviBarProtocol.h)

由 UIViewController+TYNavigation 引入并实现了该协议，该协议包含所有以 ty_naviBar 开头的 VC 分类属性与方法

所有以 ty_naviBar 开头的属性或方法，均表示该属性或方法 可以 对 push 后的页面产生影响（在 push 后页面没有通过 ty_topBar方法覆盖时可产生影响）

#### [TYNavigationBarAppearance](https://github.com/TuyaInc/TYNavigationController/blob/master/TYNavigationController/Headers/TYNavigationBarAppearance.h)

全局默认样式配置类，当 VC 没有实现相关 ty_topBar 与 ty_naviBar 方法时，使用该类的对应属性替代



### 基本使用方法

#### 设置 title

````objective-c
// 导入头文件
#import "UIViewController+TYNavigation.h"

// self 即当前 vc

// 使用默认样式 [TYNavigationBarAppearance shareAppearance]
self.title = @"title";

// 自定义样式
self.ty_topBarCenterItem = [TYNavigationBarItem itemWithMaker:^(TYNavigationBarItemMaker *maker) {
    maker.normalTitle(@"title")		// 设置 title
    .titleFont([UIFont systemFontOfSize:14]) 	// 设置字体字号
    .normalTintColor([UIColor orangeColor]);	// 设置 tintColor
}];
````

#### 设置rightItem

````objective-c
// 导入头文件
#import "UIViewController+TYNavigation.h"

// self 即当前 vc
self.ty_topBarRightItem = [TYNavigationBarItem itemWithMaker:^(TYNavigationBarItemMaker *maker) {
    maker.normalTitle(@"Right")			// 设置文本
    .normalImage([UIImage imageNamed:@"xxx"])		// 设置图片
    .status(UIControlStateNormal);	// 设置状态
}];

// 响应点击
- (void)ty_naviRightItemAction:(TYNavigationBarItem *)item {
  // 右按钮点击
}
````

#### 隐藏导航栏

````objective-c
// 导入头文件
#import "UIViewController+TYNavigation.h"

// self 即当前 vc
self.ty_topBarHidden = YES;
````

#### 设置背景

````objective-c
// 导入头文件
#import "UIViewController+TYNavigation.h"

// self 即当前 vc

// 使用颜色设置背景
self.ty_topBarBackgroundColor = [UIColor orangeColor];

// 使用图片设置背景
self.ty_topBarBackgroundImage = [UIImage imageNamed:@"xxx"];
````

#### 设置分割线

````objective-c
// 导入头文件
#import "UIViewController+TYNavigation.h"

// self 即当前 vc

// 使用颜色设置
self.ty_topBarSeparatorColor = [UIColor orangeColor];
````

#### 设置返回手势

````objective-c
// 导入头文件
#import "UIViewController+TYNavigation.h"

// self 即当前 vc

// 左侧侧滑返回
self.ty_topBarPopGestureType = TYNavigationPopGestureType_LeftEdge;

// 全屏侧滑返回
self.ty_topBarPopGestureType = TYNavigationPopGestureType_FullScreen;

// 禁用手势
self.ty_topBarPopGestureType = TYNavigationPopGestureType_Disable;
````

#### 设置状态栏

````objective-c
// 导入头文件
#import "UIViewController+TYNavigation.h"

// self 即当前 vc

self.ty_topBarStatusBarHidden = NO;
self.ty_topBarStatusBarStyle = UIStatusBarStyleLightContent;
````

> self.ty_naviBarxxx 的使用方法与 self.ty_topBarxxx 的使用方法完全一致，唯一区别在于影响范围



### 更多用法

参考 [TYNavigationController Example](https://github.com/TuyaInc/TYNavigationController/tree/master/Example)