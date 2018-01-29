# Installation guide

To add the Zingle.framework library to your XCode project, follow the steps below to install the framework using CocoaPods

1. First, install [CocoaPods](https://cocoapods.org/) if it isn't already

```bash
gem install cocoapods
```

2. Add the Zingle dependency to your [Podfile](https://guides.cocoapods.org/using/the-podfile.html)

```ruby
target 'YourApp' do
    pod 'Zingle'
end
```

3. Install the pod

```bash
pod install
```

4. Open the generated `.xcworkspace` file, and start using the framework in your code.

Objective-C:

```objc
#import <Zingle/Zingle.h>

[Zingle initWithSettings:[ZNGSettings settingsWithAppId:@"YOUR_APP_ID"] completionHandler:^(NSError * _Nullable error, NSDictionary * _Nullable userInfo) {
    // Your code after init is complete
}];
```

Swift:

```swift
Zingle.initWith(ZNGSettings(appId: "YOUR_APP_ID")) { (error: Error?, userInfo: [AnyHashable : Any]?) in
    // Your code after init is complete
}
```
