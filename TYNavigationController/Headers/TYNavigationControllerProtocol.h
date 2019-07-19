//
//  TYNavigationControllerProtocol.h
//  TYNavigationController
//
//  Created by TuyaInc on 2018/11/13.
//

#import <Foundation/Foundation.h>

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
- (void)ty_refreshSeparator;
- (void)ty_refreshPopGesture;
- (void)ty_refreshHitThrough;

@end
