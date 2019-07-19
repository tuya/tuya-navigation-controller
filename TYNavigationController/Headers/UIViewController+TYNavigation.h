//
//  UIViewController+TYNavigation.h
//  TYNavigationController
//
//  Created by TuyaInc on 2018/11/13.
//

#import <UIKit/UIKit.h>

#import "TYNavigationControllerProtocol.h"

#import "UIViewController+TYStatusBar.h"

#import "TYNavigationTopBarProtocol.h"
#import "TYNavigationCallbackProtocol.h"
#import "TYNavigationPresentProtocol.h"

@protocol TYNavigationNaviBarProtocol;

/*
 zh^
 所有以 ty_topBar 开头的属性 <TYNavigationTopBarProtocol>
 均表示 仅对当前页面产生影响，对后续push出来的页面的navi 无影响
 
 所有以 ty_naviBar 开头的属性 <TYNavigationNaviBarProtocol>
 均表示 在多层级页面中持续生效，对后续push出来的页面的navi 有影响
 如果需要使用，请自己引入头文件 TYNavigationNaviBarProtocol.h
 
 !!! 请不要重写属性的Accessor方法，否则将导致数据不准确
 zh$

 en^
 prefix ty_topBarxxx means this method/property only effect on current view controller, all ty_topBarxxx method/property are in <TYNavigationTopBarProtocol>
 
 prefix ty_naviBarxxx means this method/property will effect on current view controller and the view controller that pushed by current view controller, all ty_naviBarxxx method/property are in <TYNavigationNaviBarProtocol>
 if you need ty_naviBarxxx, you have to import header file TYNavigationNaviBarProtocol.h
 
 !!! Don't override any accessor method
 en$
 */
@interface UIViewController (TYNavigation)

@property (nonatomic, strong, readonly) __kindof UINavigationController<TYNavigationControllerProtocol> *navigationController;

@end




