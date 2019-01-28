//
//  TYViewControllerNaviBarProtocol.h
//  TYNavigationController
//
//  Created by TuyaInc on 2018/11/21.
//

#import <Foundation/Foundation.h>

#import "TYNavigationBarItem.h"
#import "TYNavigationTypeDefine.h"

/*
 所有以 ty_naviBar 开头的属性 均表示 在多层级页面中持续生效，对后续push出来的页面的navi 有影响
 ty_naviBar means this method/property will effect on current view controller and the view controller that pushed by current view controller
 
 !!! 请不要重写属性的Accessor方法，否则将导致数据不准确
 !!! Don't override any accessor method
 */
@protocol TYViewControllerNaviBarProtocol <NSObject>

#pragma mark - NaviItem
@property (nonatomic) BOOL ty_naviBarEnableBackItem;     /**< 是否使用back/cancel按钮  影响：当前页面&push页面 */
@property (nonatomic, strong) TYNavigationBarItem *ty_naviBarBackItem;      /**< back/cancel按钮样式  影响：当前页面&push页面 */
@property (nonatomic, strong) TYNavigationBarItem *ty_naviBarLeftItem;      /**< left样式  影响：当前页面&push页面 */
@property (nonatomic, strong) TYNavigationBarItem *ty_naviBarCenterItem;    /**< center样式  影响：当前页面&push页面 */
@property (nonatomic, strong) TYNavigationBarItem *ty_naviBarRightItem;     /**< right样式  影响：当前页面&push页面 */

#pragma mark - NaviStyle
@property (nonatomic) BOOL ty_naviBarHidden;             /**< 隐藏导航栏  影响: 当前页面&push页面 */
@property (nonatomic) CGFloat ty_naviBarAlpha;           /**< 导航栏整体透明度  影响：当前页面&push页面 */
@property (nonatomic) CGFloat ty_naviBarBlurAlpha;      /**< 毛玻璃效果  影响：当前页面&push页面 */
@property (nonatomic) CGFloat ty_naviBarBackgroundAlpha;            /**< 背景透明度  影响：当前页面&push页面 */
@property (nonatomic) CGFloat ty_naviBarSeperatorAlpha;             /**< 分割线透明度  影响：当前页面&push页面 */
@property (nonatomic) CGAffineTransform ty_naviBarTransform;        /**< 导航栏transform  影响: 当前页面&push页面 */
@property (nonatomic, strong) UIColor *ty_naviBarBackgroundColor;   /**< 背景色  影响：当前页面&push页面 */
@property (nonatomic, strong) UIImage *ty_naviBarBackgroundImage;   /**< 背景图  影响：当前页面&push页面 */
@property (nonatomic, strong) UIColor *ty_naviBarSeperatorColor;    /**< 分割线颜色  影响：当前页面&push页面 */

#pragma mark - PopGesture
@property (nonatomic) TYNavigationPopGestureType ty_naviBarPopGestureType;   /**< 返回手势 影响: 当前页面&push页面 */
@property (nonatomic) BOOL ty_naviBarHitThrough; /**< 点击(背景时)是否可以贯穿navi  影响：当前页面&push页面 */

@end
