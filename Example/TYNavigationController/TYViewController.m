//
//  TYViewController.m
//  TYUIKit
//
//  Created by TuyaInc on 01/02/2019.
//  Copyright (c) 2018 panyfun. All rights reserved.
//

#import "TYViewController.h"

#import "UIViewController+TYNavigation.h"

#import "TYUIKit.h"

@interface TYViewController ()

@property (weak, nonatomic) IBOutlet UISwitch *dynamicAlphaSwitch;
@property (weak, nonatomic) IBOutlet UISwitch *dynamicBlurSwitch;
@property (weak, nonatomic) IBOutlet UISwitch *followSwitch;
@property (weak, nonatomic) IBOutlet UISwitch *useImageSwitch;

@end

@implementation TYViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.tableView.separatorColor = [UIColor clearColor];
    self.view.backgroundColor = [UIColor whiteColor];
    self.tableView.contentInset = UIEdgeInsetsMake(0, 0, 120, 0);
    
    self.ty_topBarBackgroundColor = [UIColor yellowColor];
    self.ty_topBarSeparatorColor = [UIColor yellowColor];
    
    self.title = [NSString stringWithFormat:@"%lu", (unsigned long)self.navigationController.viewControllers.count];
    
    TYNavigationBarItem *rightItem = [TYNavigationBarItem itemWithTitle:@"Push"];
    self.ty_topBarRightItems = @[rightItem];

    if (self.navigationController.viewControllers.count > 1) {        TYNavigationBarItem *leftItem = [TYNavigationBarItem itemWithTitle:@"Pop"];
        self.ty_topBarLeftItems = @[leftItem];
    }
    
    if (self.navigationController.viewControllers.count == 3) {
        self.ty_topBarBackItem = [TYNavigationBarItem backItem];
        self.ty_topBarBackItem.normalTitle = @"Back";
    } else if (self.navigationController.viewControllers.count == 4) {
        self.ty_topBarBackItem = [TYNavigationBarItem itemWithMaker:^(TYNavigationBarItemMaker *maker) {
            maker.normalTitle(@"Back");
            maker.normalTintColor([UIColor purpleColor]);
        }];
    } else {
        // Use default style
    }
}

- (void)ty_naviRightItemAction:(TYNavigationBarItem *)item {
    UIStoryboard *mainStoryboard = [UIStoryboard storyboardWithName:@"Main" bundle:[NSBundle mainBundle]];
    TYViewController *vc = [mainStoryboard instantiateViewControllerWithIdentifier:@"MainViewController"];
    [self.navigationController pushViewController:vc animated:YES];
}

- (void)ty_naviLeftItemAction:(TYNavigationBarItem *)item {
    if ([item.normalTitle isEqualToString:@"Pop"]) {
        NSLog(@"Pop Tap Action");
        [self.navigationController popViewControllerAnimated:YES];
    }
}

#pragma mark - Private
- (void)refreshBackgroundWithColor:(UIColor *)color {
    if (_useImageSwitch.isOn) {
        self.ty_topBarBackgroundColor = [UIColor whiteColor];
        CAGradientLayer *layer = [CAGradientLayer new];
        layer.frame = CGRectMake(0, 0, TY_ScreenWidth(), TY_NaviBarHeight());
        layer.colors = @[(id)[UIColor whiteColor].CGColor, (id)color.CGColor];
        layer.startPoint = CGPointMake(0, 1);
        layer.endPoint = CGPointMake(1, 0);
        UIImage *img = [UIImage ty_imageWithLayer:layer];
        [UIView animateWithDuration:0.6 animations:^{
            self.ty_topBarBackgroundImage = img;
//            self.ty_topBarBackgroundLayer = layer;
        }];
    } else {
        self.ty_topBarBackgroundImage = nil;
        self.ty_topBarBackgroundLayer = nil;
        [UIView animateWithDuration:0.6 animations:^{
            self.ty_topBarBackgroundColor = color;
        }];
    }
}

#pragma mark - IBAction
- (IBAction)backgroundColorSegmentAction:(UISegmentedControl *)sender {
    UIColor *color = @[[UIColor yellowColor], [UIColor orangeColor], [UIColor redColor], [UIColor greenColor], [UIColor clearColor]][sender.selectedSegmentIndex];
    [self refreshBackgroundWithColor:color];
}

- (IBAction)blurSliderAction:(UISlider *)sender {
    self.ty_topBarBlurAlpha = sender.value;
}

- (IBAction)backgroundAlphaSliderAction:(UISlider *)sender {
    self.ty_topBarBackgroundAlpha = sender.value;
}

- (IBAction)separatorColorSegmentAction:(UISegmentedControl *)sender {
    UIColor *color = @[[UIColor yellowColor], [UIColor orangeColor], [UIColor redColor], [UIColor greenColor], [UIColor clearColor]][sender.selectedSegmentIndex];
    [UIView animateWithDuration:0.4 animations:^{
        self.ty_topBarSeparatorColor = color;
    }];
}

- (IBAction)pushTapAction:(id)sender {
    [self ty_naviRightItemAction:nil];
}

- (IBAction)hiddenSwitchAction:(UISwitch *)sender {
    [UIView animateWithDuration:0.5 animations:^{
        self.ty_topBarHidden = sender.isOn;
    }];
}

- (IBAction)separatorSwitchAction:(UISwitch *)sender {
    [UIView animateWithDuration:0.4 animations:^{
        self.ty_topBarSeparatorAlpha = sender.isOn ? 1 : 0;
    }];
}

- (IBAction)rightItemSwitchAction:(UISwitch *)sender {
    self.ty_topBarRightItem.status = sender.isOn ? UIControlStateNormal : UIControlStateDisabled;
}


- (void)scrollViewDidScroll:(UIScrollView *)scrollView {
    CGFloat offset = scrollView.contentOffset.y;
    if (_dynamicAlphaSwitch.isOn) {
        CGFloat alpha = MIN(1, MAX(0, 1 - (offset + 64) / (135 + 64)));
        NSLog(@"offsetY = %f navi alpha = %f", offset, alpha);
        self.ty_topBarAlpha = alpha;
    }
    
    if (_dynamicBlurSwitch.isOn) {
        // Background alpha should < 1
        CGFloat alpha = MIN(1, MAX(0, (offset - 5) / (70 - 5)));
        NSLog(@"offsetY = %f blur alpha = %f", offset, alpha);
        self.ty_topBarBlurAlpha = alpha;
    }
    
    if (_followSwitch.isOn) {
        CGFloat y = MAX(-self.navigationController.navigationBar.frame.size.height-20, MIN(0, -(offset + 64)));
        self.ty_topBarTransform = CGAffineTransformMakeTranslation(0, y);
    }
    
}

@end
