//
//  TYNavigationBarStatusProtocol.h
//  TYNavigationController
//
//  Created by TuyaInc on 2018/12/1.
//

#import <Foundation/Foundation.h>

#import "TYNavigationBarItem.h"

/**
 TYNavigationBar当前的一些状态量
 请勿直接修改！！！
 */
@protocol TYNavigationBarStatusProtocol <NSObject>

#pragma mark - NaviItem
@property (nonatomic, readonly) BOOL ty_currentNaviEnableBackItem;
@property (nonatomic, copy, readonly) TYNavigationBarItem *ty_currentNaviBackItem;
@property (nonatomic, copy, readonly) TYNavigationBarItem *ty_currentNaviCenterItem;
@property (nonatomic, copy, readonly) NSArray<TYNavigationBarItem *> *ty_currentNaviLeftItems;
@property (nonatomic, copy, readonly) NSArray<TYNavigationBarItem *> *ty_currentNaviRightItems;

#pragma mark - NaviStyle
@property (nonatomic, readonly) BOOL ty_currentNaviHidden;
@property (nonatomic, readonly) CGFloat ty_currentNaviAlpha;
@property (nonatomic, readonly) CGFloat ty_currentNaviBlurAlpha;
@property (nonatomic, readonly) CGFloat ty_currentNaviBackgroundAlpha;
@property (nonatomic, readonly) CGAffineTransform ty_currentNaviTransform;
@property (nonatomic, readonly) UIColor *ty_currentNaviBackgroundColor;
@property (nonatomic, readonly) UIImage *ty_currentNaviBackgroundImage;
@property (nonatomic, readonly) UIColor *ty_currentNaviSeperatorColor;

@end
