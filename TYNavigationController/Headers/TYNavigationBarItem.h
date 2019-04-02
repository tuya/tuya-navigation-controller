//
//  TYNavigationBarItem.h
//  TYNavigationController
//
//  Created by TuyaInc on 2018/11/13.
//

#import <Foundation/Foundation.h>

#import "TYNavigationBarItemMaker.h"

@interface TYNavigationBarItem : NSObject <NSCopying, UIAccessibilityIdentification>

@property (nonatomic, strong) UIView *customView;

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

@property (nonatomic) CGSize size;  /**< w or h = 0 or CGFLOAT_MAX means automatic */

/**
 Available After TuyaSmart 3.9.0+
 */
@property (nonatomic) NSLineBreakMode titleBreakMode;
/**
 Available After TuyaSmart 3.9.0+
 */
@property (nonatomic) UIViewContentMode imageContentMode;
/**
 Available After TuyaSmart 3.9.0+
 */
@property (nonatomic) BOOL clipToBounds;


@property (nonatomic) UIEdgeInsets titleInsets;     /**< reference to UIButton.titleEdgeInsets */
@property (nonatomic) UIEdgeInsets imageInsets;     /**< reference to UIButton.imageEdgeInsets */
@property (nonatomic) UIEdgeInsets contentInsets;   /**< reference to UIButton.contentEdgeInsets */

@property (nonatomic) CGFloat leftEdge;         /**< distance to left item or screen */
@property (nonatomic) CGFloat rightEdge;        /**< distance to right item or screen */
@property (nonatomic) UIOffset offset;

@property (nonatomic) BOOL userInteractionEnabled;      /**< Default: YES */
@property (nonatomic) UIEdgeInsets hitExtend;           /**< point inside area extend */

@property (nonatomic, weak) id target;      /**< tap action target, callback [navi.topVC ty_navixxxItemAction] if nil */
@property (nonatomic) SEL action;           /**< tap action sel, callback [navi.topVC ty_navixxxItemAction] if nil */

@property (nonatomic, readonly) BOOL isEraserItem;

@property (nonatomic) NSInteger tag;


+ (instancetype)itemWithTitle:(NSString *)title;
+ (instancetype)itemWithImage:(UIImage *)image;
+ (instancetype)itemWithCustomView:(UIView *)customView;
+ (instancetype)itemWithUIBarButtonItem:(UIBarButtonItem *)uiBarItem;
+ (instancetype)itemWithMaker:(void(^)(TYNavigationBarItemMaker *maker))block;

/**
 zh*
 空白项，可以用来完全移除tab上已有的item
 zh$
 
 en*
 empty item, use to remove an item on navi completely
 en&
 */
+ (instancetype)eraserItem;

@end



@interface TYNavigationBarItem ()

/**
 | -12pt- <
 */
+ (instancetype)backItem;

/**
 | -16pt- Cancel
 */
+ (instancetype)cancelItem;

/**
 navigation title item
 userInteractionEnabled = NO
 */
+ (instancetype)centerItem:(NSString *)title;

@end
