>**Note**: This repository is inherited from the [previous Tuya GitHub repository](https://github.com/TuyaInc/TYNavigationController), which will be deprecated soon. It is recommended to use this new repository for Tuya SDK development. For steps about how to change the existing remote repository URL, see [Changing a remote's URL](https://docs.github.com/en/github/using-git/changing-a-remotes-url).

# Overview

[中文版](README_cn.md) | [English](README.md)

`TYNavigationController` is a self-developed navigation bar component of Tuya. We recommend that customers who have access to Tuya UI Bizbundle use `TYNavigationController` as the navigation bar component to unify the style in the application.

### Features

- Native visual experience and transition animations.
- Chain syntax.
- The item supports status control.
- Navigation bar background supports the color, image, and layer.
- Alpha gradient, blur gradient, and transform animation are available.
- Configure the global default style.
- The full-screen return gesture is available.
- Each view controller (VC) can keep its style, with no effect on the parent VC.
- A parent VC can provide the default style for a child VC, and a child VC can also overwrite the default style.

## Example

To run the example project, clone the repository, and run `pod install` from the Example directory.

For more information, see [TYNavigationController Example](https://github.com/tuya/tuya-navigation-controller/tree/main/Example).

## Installation

`TYNavigationController` can be installed through [CocoaPods](https://cocoapods.org). To install it, simply add the following line to your Podfile:

```ruby
source 'https://github.com/TuyaInc/TYPublicSpecs.git'

pod 'TYNavigationController'
```

## Author

TuyaInc, https://www.tuya.com

