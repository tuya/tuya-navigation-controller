Pod::Spec.new do |s|
  s.name             = 'TYNavigationController'

  s.version          = '1.0.0'

  s.summary          = 'Navigation Controller Powered By TuyaInc'
  s.homepage         = 'https://github.com/TuyaInc/TYNavigationController.git'
  s.author           = { 'TuyaInc' => 'https://www.tuya.com' }
  s.license          = 'None'
  s.source           = { :git => 'https://github.com/TuyaInc/TYNavigationController.git', :tag => s.version.to_s }

  s.ios.deployment_target = '9.0'

  s.frameworks = 'UIKit'

  s.source_files = 'TYNavigationController/Headers/**/*'
  s.vendored_library = 'TYNavigationController/*.a'
  s.resources = ['TYNavigationController/Assets/*.{png,xib,plist,xcassets,bundle}']

  s.dependency 'TYUIKit'

end
