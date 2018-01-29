# Installation guide

To add the Zingle.framework library to your XCode project, follow the steps below to install the framework using CocoaPods

1. First, install [CocoaPods](https://cocoapods.org/) if it isn't already

```bash
gem install cocoapods
```

2. Copy the `Zingle.framework` and `Zingle.podspec` files somewhere in your project directory, for example in `vendor/Zingle`
3. Add the Zingle dependency to your [Podfile](https://guides.cocoapods.org/using/the-podfile.html), using a local `path` that points to the directory in step 2

```ruby
target 'YourApp' do
    pod 'Zingle', :path => 'vendor/Zingle'
end
```

4. Install the pod

```bash
pod install
```

5. Open the generated `.xcworkspace` file, and start using the framework in your code.

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
