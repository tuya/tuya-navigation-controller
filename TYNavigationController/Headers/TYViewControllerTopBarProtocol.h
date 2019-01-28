//
//  TYViewControllerTopBarProtocol.h
//  TYNavigationController
//
//  Created by TuyaInc on 2018/11/21.
//

#import <Foundation/Foundation.h>

#import "TYNavigationBarItem.h"
#import "TYNavigationTypeDefine.h"

/*
 所有以 ty_topBar 开头的属性 均表示 仅对当前页面产生影响，对后续push出来的页面的navi 无影响
 ty_topBar means this method/property only effect on current view controller
 
 !!! 请不要重写属性的Accessor方法，否则将导致数据不准确
 !!! Don't override any accessor method
 */
@protocol TYViewControllerTopBarProtocol <NSObject>

#pragma mark - NaviItem
@property (nonatomic) BOOL ty_topBarEnableBackItem;     /**< 是否使用back/cancel按钮  影响：当前页面 */
@property (nonatomic, strong) TYNavigationBarItem *ty_topBarBackItem;   /**< back/cancel按钮样式  影响：当前页面 */
@property (nonatomic, strong) TYNavigationBarItem *ty_topBarLeftItem;   /**< left样式  影响：当前页面 */
@property (nonatomic, strong) TYNavigationBarItem *ty_topBarCenterItem; /**< center样式  影响：当前页面 */
@property (nonatomic, strong) TYNavigationBarItem *ty_topBarRightItem;  /**< right样式  影响：当前页面 */

#pragma mark - NaviStyle
@property (nonatomic) BOOL ty_topBarHidden;             /**< 隐藏导航栏  影响: 当前页面 */
@property (nonatomic) CGFloat ty_topBarAlpha;           /**< 导航栏整体透明度  影响：当前页面 */
@property (nonatomic) CGFloat ty_topBarBlurAlpha;       /**< 毛玻璃效果  影响：当前页面 */
@property (nonatomic) CGFloat ty_topBarBackgroundAlpha;             /**< 背景透明度  影响：当前页面 */
@property (nonatomic) CGFloat ty_topBarSeperatorAlpha;              /**< 分割线透明度  影响：当前页面 */
@property (nonatomic) CGAffineTransform ty_topBarTransform;         /**< 导航栏transform  影响: 当前页面 */
@property (nonatomic, strong) UIColor *ty_topBarBackgroundColor;    /**< 背景色  影响：当前页面 */
@property (nonatomic, strong) UIImage *ty_topBarBackgroundImage;    /**< 背景图  影响：当前页面 */
@property (nonatomic, strong) UIColor *ty_topBarSeperatorColor;     /**< 分割线颜色  影响：当前页面 */

#pragma mark - PopGesture
@property (nonatomic) TYNavigationPopGestureType ty_topBarPopGestureType;   /**< 返回手势 影响: 当前页面 */
@property (nonatomic) BOOL ty_topBarHitThrough; /**< 点击(背景时)是否可以贯穿navi [default: NO]  影响：当前页面 */

@end
