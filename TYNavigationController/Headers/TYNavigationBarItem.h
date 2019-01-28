//
//  TYNavigationBarItem.h
//  TYNavigationController
//
//  Created by TuyaInc on 2018/11/13.
//

#import <Foundation/Foundation.h>

#import "TYNavigationBarItemMaker.h"

@interface TYNavigationBarItem : NSObject <NSCopying>

@property (nonatomic, strong) UIView *customView;

@property (nonatomic, strong) UIBarButtonItem *uiBarItem;

@property (nonatomic) UIControlState status;    /**< Only Normal、Highlighted、Selected、Disabled are available */

@property (nonatomic, strong) UIFont *titleFont;

@property (nonatomic, copy) NSString *normalTitle;
@property (nonatomic, copy) NSDictionary<NSAttributedStringKey, id> *normalTitleAttribute;
@property (nonatomic, copy) NSString *selectTitle;
@property (nonatomic, copy) NSDictionary<NSAttributedStringKey, id> *selectTitleAttribute;
@property (nonatomic, copy) NSString *disableTitle;
@property (nonatomic, copy) NSDictionary<NSAttributedStringKey, id> *disableTitleAttribute;

@property (nonatomic, strong) UIImage *normalImage;
@property (nonatomic, strong) UIImage *selectImage;
@property (nonatomic, strong) UIImage *disableImage;
@property (nonatomic) UIImageRenderingMode renderingMode;   /**< Original模式下，normalTintColor仅对文字生效 */

@property (nonatomic, strong) UIColor *normalBackgroundColor;
@property (nonatomic, strong) UIColor *selectBackgroundColor;
@property (nonatomic, strong) UIColor *disableBackgroundColor;

@property (nonatomic, strong) UIImage *normalBackgroundImage;
@property (nonatomic, strong) UIImage *selectBackgroundImage;
@property (nonatomic, strong) UIImage *disableBackgroundImage;

@property (nonatomic, strong) UIColor *normalTintColor;
@property (nonatomic, strong) UIColor *selectTintColor;
@property (nonatomic, strong) UIColor *disableTintColor;

@property (nonatomic) CGFloat alpha;

@property (nonatomic) CGSize size;  /**< w/h 为 0/CGFLOAT_MAX 则自动计算 */

@property (nonatomic) UIEdgeInsets titleInsets;     /**< 参考UIButton.titleEdgeInsets */
@property (nonatomic) UIEdgeInsets imageInsets;     /**< 参考UIButton.imageEdgeInsets */
@property (nonatomic) UIEdgeInsets contentInsets;   /**< 参考UIButton.contentEdgeInsets */

@property (nonatomic) CGFloat leftEdge;
@property (nonatomic) CGFloat rightEdge;
@property (nonatomic) CGFloat verticalOffset; // 暂不支持   Not Available

@property (nonatomic) BOOL userInteractionEnabled;     /**< 是否可以点击 Default: YES */
@property (nonatomic) UIEdgeInsets hitExtend;   /**< 点击区域扩展 正向外 负向内 */

@property (nonatomic, weak) id target;
@property (nonatomic) SEL action;

@property (nonatomic, readonly) BOOL isEraserItem;

@property (nonatomic) NSInteger tag;

@property (nonatomic, copy) NSString *accessibilityIdentifier;


+ (instancetype)itemWithTitle:(NSString *)title;
+ (instancetype)itemWithImage:(UIImage *)image;
+ (instancetype)itemWithCustomView:(UIView *)customView;
+ (instancetype)itemWithUIBarButtonItem:(UIBarButtonItem *)uiBarItem;
+ (instancetype)itemWithMaker:(void(^)(TYNavigationBarItemMaker *maker))block;

/**
 空白项，可以用来移除tab上已有item
 empty item, use to remove an item on navi
 */
+ (instancetype)eraserItem;

@end
