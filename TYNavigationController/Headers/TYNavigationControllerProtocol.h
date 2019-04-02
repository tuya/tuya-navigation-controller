//
//  TYNavigationControllerProtocol.h
//  TYNavigationController
//
//  Created by TuyaInc on 2018/11/13.
//

#import <Foundation/Foundation.h>

#import "TYNavigationTypeDefine.h"

@class TYNavigationBarItem;

@protocol TYNavigationControllerProtocol <NSObject>

#pragma mark - Refresh
- (void)ty_refreshBackAndLeftItems;
- (void)ty_refreshCenterItem;
- (void)ty_refreshRightItem;

- (void)ty_refreshBarAlpha;
- (void)ty_refreshHidden;
- (void)ty_refreshTransform;
- (void)ty_refreshBlurAlpha;
- (void)ty_refreshBackground;
- (void)ty_refreshSeperator;
- (void)ty_refreshPopGesture;
- (void)ty_refreshHitThrough;

- (void)ty_refreshStatusBar;

@end
