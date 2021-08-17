# Installation guide

To add the Zingle.framework library to your XCode project, follow the steps below to install the framework using CocoaPods

1. First, install [CocoaPods](https://cocoapods.org/) if it isn't already

```bash
gem install cocoapods
```

2. Copy the `Zingle.xcframework` and `Zingle.podspec` files somewhere in your project directory, for example in `vendor/Zingle`
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

5. Open the generated `.xcworkspace` file and add the following keys to your app's Info.plist file (replacing the values if desired):

```xml
<key>NSPhotoLibraryUsageDescription</key>
<string>${PRODUCT_NAME} will read your photo library to gather additional information</string>
<key>NSPhotoLibraryAddUsageDescription</key>
<string>${PRODUCT_NAME} will write to your photo library to gather additional information</string>
<key>NSCameraUsageDescription</key>
<string>${PRODUCT_NAME} will use your camera to gather additional information</string>
```

6. Start using the framework in your code.

Objective-C:

```objc
#import <Zingle/Zingle.h>

[Zingle initWithSettings:[ZNGSettings settingsWithIntegrationId:@"YOUR_INTEGRATION_ID"] completionHandler:^(NSError * _Nullable error, NSDictionary * _Nullable userInfo) {
    // Your code after init is complete
}];
```

Swift:

```swift
Zingle.initWith(ZNGSettings(integrationId: "YOUR_INTEGRATION_ID")) { (error: Error?, userInfo: [AnyHashable : Any]?) in
    // Your code after init is complete
}
```


# Documentation
Detailed documentation is available in the docset contained in this repository

# Customizing Colors
The style of the conversation user interface can be controlled through two techniques:

* Using the `UIAppearance` proxy of `UINavigationBar` to style the navigation bar’s color and appearance.
* The `ZNGSettings` class provides access to the status bar and the color of the message bubbles and its text.

Suppose you wanted the conversation UI to have a black navigation bar and red message bubbles with white text. First, you’d use `UINavigationBar`’s appearance proxy to set up the navigation bar. Then, you’d use `ZNGSettings` to finish styling the UI:

Objective-C:
```
ZNGSettings* settings = [ZNGSettings settingsWithIntegrationId:@"YOUR_INTEGRATION_ID"];
settings.conversationAccentColor = [UIColor redColor];
settings.userMessageTextColor = [UIColor whiteColor];
settings.conversationStatusBarStyle = UIStatusBarStyleLightContent;

[[UINavigationBar appearance] setBarTintColor:[UIColor blackColor]];
[[UINavigationBar appearance] setTintColor:[UIColor redColor]];
[[UINavigationBar appearance] setTitleTextAttributes:@{ NSForegroundColorAttributeName : [UIColor redColor] }];
```

Swift:
```
var settings = ZNGSettings(integrationId: "YOUR_INTEGRATION_ID")
settings.conversationAccentColor = UIColor.redColor();
settings.userMessageTextColor = UIColor.whiteColor();
settings.conversationStatusBarStyle = UIStatusBarStyle.LightContent;

UINavigationBar.appearance().barTintColor = UIColor.blackColor()
UINavigationBar.appearance().tintColor = UIColor.redColor()
UINavigationBar.appearance().titleTextAttributes = [ NSForegroundColorAttributeName : UIColor.redColor()]
Menu items
The iOS SDK features a tappable menu icon that allows the user to send various message
```

# Customizing Strings
The strings used in the SDK interface can be customized by creating an empty strings file in your XCode project called ZingleLocalizable.strings and specifying overrides in that file.  Strings are references by their original value:
```
/* Nav bar button, action sheet cancel button */
"Cancel" = "...";

/* Conversation title */
"Messages" = "...";

/* Conversation header. Uses CFBundleDisplayName */
"This is the start of your conversation with the %@ team. We'll stay in touch to help you get the most out of your app.\nFeel free to leave us a message about anything that’s on your mind. We’ll get back to your questions, suggestions or anything else as soon as we can." = "...";

/* Conversation header when there are previous messages */
"Show more..." = "...";

/* Conversation header when fetching previous messages */
"Retrieving history..." = "...";

/* Error message shown in conversation view */
"No Internet connection" = "...";

/* Error message shown in conversation view */
"Could not connect to server" = "...";

/* Error message shown in conversation view */
"An error occurred while processing your action. Please try again." = "...";

/* Error message shown in conversation view */
"Reconnecting..." = "...";

/* Error message shown in conversation view */
"Invalid file" = "...";

/* Error message shown in conversation view */
"A virus was detected in your file and it has been rejected" = "...";

/* Error message shown in conversation view. Parameter represents the max file size formatted by NSByteCountFormatter */
"Max file size limit exceeded %@." = "...";

/* Fallback used by the in app notification when no message author name is found */
"%@ Team" = "...";

/* Conversation send button */
"Send" = "...";

/* Conversation text input place holder */
"Type a message..." = "...";

/* Conversation nav bar left button */
"Done" = "...";

/* Failure text for chat messages that fail to upload */
"Message not delivered. Tap to retry." = "...";

/* Status text for chat messages */
"Sending..." = "...";

/* Status text for sent chat messages */
"Delivered" = "...";

/* Status text for chat messages seen by the appMaker */
"Seen" = "...";

/* Timestamp text for recent messages */
"Just now" = "...";

/* Timestamp text for messages in the last hour */
"%.0fm ago" = "...";

/* Timestamp text for messages in the last day */
"%.0fh ago" = "...";

/* Timestamp text for messages in the last week */
"%.0fd ago" = "...";

/* Action sheet button label */
"Take Photo" = "...";

/* Action sheet button label */
"Photo & Video Library" = "...";

/* Action sheet button label */
"Use Last Photo Taken" = "...";

/* Action sheet button label */
"Share Location" = "...";

/* Photo confirmation alert title */
"Confirm Photo" = "...";

/* Action sheet button label */
"Resend" = "...";

/* Action sheet button label */
"View Image" = "...";

/* Error displayed in message bubble if image failed to download */
"Tap to reload image" = "...";

/* Error displayed as message if location sending fails */
"Could not send location" = "...";

/* Error title when user selects "use latest photo", but no photos exist */
"No Photos Found" = "...";

/* Error description when user selects "use latest photo", but no photos exist */
"Your photo library seems to be empty." = "...";

/* Error title when user attempts to upload a photo but Photos access is denied */
"Can't Access Photos" = "...";

/* Error description when user attempts to upload a photo but Photos access is denied */
"Make sure to allow photos access for this app in your privacy settings." = "...";

/* Error title when user attempts to take a photo but camera access is denied */
"Can't Access Camera" = "...";

/* Error description when user attempts to take a photo but camera access is denied */
"Make sure to allow camera access for this app in your privacy settings." = "...";

/* Generic error title when user attempts to upload an image and it fails for an unknown reason */
"Can't Retrieve Photo" = "...";

/* Generic error description when user attempts to upload an image and it fails for an unknown reason */
"Please try again or select a new photo." = "...";

/* Error title when user attempts to send the current location but location access is denied */
"Can't Access Location" = "...";

/* Error description when user attempts to send the current location but location access is denied */
"Make sure to allow location access for this app in your privacy settings." = "...";

/* UIAlertView button title to link to Settings app */
"Settings" = "...";

/* UIAlertView button title to dismiss */
"Dismiss" = "...";

/* Title for payment button */
"Pay Now" = "...";

/* Title for message action when payment completed */
"Payment Completed" = "...";

/*
 Instructions for entering credit card info. Parameters are as follows:
 1. Amount (e.g. 50.45)
 2. Currency (e.g. USD)
 3. App name (Uses CFBundleDisplayName)
*/
"Enter your credit card to send $%@ %@ securely to %@" = "...";

/* Error text when payment fails */
"An error occurred while processing the card. Please try again or use a different card." = "...";

/* Button label for saved credit card view */
"Change Credit Card" = "...";

/*
 Information label for saved credit card view. Parameters are as follows:
 1. Amount (e.g. 50.45)
 2. Currency (e.g. USD)
 3. App name (Uses CFBundleDisplayName)
 */
"You're about to send $%@ %@ securely to %@" = "...";

/* Title for user notification action */
"Reply" = "...";

/* Date format used for message grouping headers on the conversation screen */
"MMMM d, h:mm a" = "MMMM d, h:mm a";

/* Date format used for message timestamps on the conversation screen */
"hh:mm a" = "hh:mm a";

/* Error message when the content of a webview fails to load */
"Failed to open the page" = "...";
```
