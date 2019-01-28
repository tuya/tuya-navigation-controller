//
//  TYNavigationBarItem+Sugar.h
//  TYNavigationController
//
//  Created by TuyaInc on 2018/12/1.
//

#import "TYNavigationBarItem.h"

@interface TYNavigationBarItem (Sugar)

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
