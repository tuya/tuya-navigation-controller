//
//  UIViewController+TYNavigation.h
//  TYNavigationController
//
//  Created by TuyaInc on 2018/11/13.
//

#import <UIKit/UIKit.h>

#import "TYNavigationControllerProtocol.h"
//#import "TYNavigationBarStatusProtocol.h"

#import "TYViewControllerTopBarProtocol.h"
#import "TYViewControllerNaviCallbackProtocol.h"

#import "TYNavigationBarItem+Sugar.h"

@protocol TYViewControllerNaviBarProtocol;

/*
 所有以 ty_topBar 开头的属性 <TYViewControllerTopBarProtocol>
 均表示 仅对当前页面产生影响，对后续push出来的页面的navi 无影响

 ty_topBar means this method/property only effect on current view controller
 
 所有以 ty_naviBar 开头的属性 <TYViewControllerNaviBarProtocol>
 均表示 在多层级页面中持续生效，对后续push出来的页面的navi 有影响
 
 ty_naviBar means this method/property will effect on current view controller and the view controller that pushed by current view controller
 
 !!! 请不要重写属性的Accessor方法，否则将导致数据不准确
 !!! Don't override any accessor method
 */
@interface UIViewController (TYNavigation) <TYViewControllerTopBarProtocol, TYViewControllerNaviBarProtocol, TYViewControllerNaviCallbackProtocol>

@property (nonatomic, strong, readonly) __kindof UINavigationController<TYNavigationControllerProtocol> *navigationController;

@end
