//
//  TYNavigationController.h
//  TYNavigationController
//
//  Created by TuyaInc on 2018/11/5.
//

#import <UIKit/UIKit.h>

#import "TYNavigationControllerProtocol.h"
#import "TYNavigationBarAppearance.h"

@interface TYNavigationController : UINavigationController <TYNavigationControllerProtocol>

/**
 default is [TYNavigationBarAppearance shareAppearance]
 if you want to modify anything only for one navigation controller, you have to create one with [TYNavigationBarAppearance new]
 if you want to modify anything for all navigation controller, you need to call like [TYNavigationBarAppearance shareAppearance].xxx = xxx
 */
@property (nonatomic, strong) TYNavigationBarAppearance *naviApperance;

@end
