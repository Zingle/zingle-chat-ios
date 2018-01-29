//
//  Zingle.h
//  Zingle
//
//  version : 1.1.0

#import <Foundation/Foundation.h>
#import "ZNGConversation.h"
#import "ZNGSettings.h"
#import "ZNGUser.h"

NS_ASSUME_NONNULL_BEGIN
@protocol UNUserNotificationCenterDelegate;

#define ZINGLE_VERSION @"1.1.0"

FOUNDATION_EXPORT double ZingleVersionNumber;
FOUNDATION_EXPORT const unsigned char ZingleVersionString[];

/**
 *  @abstract User info dictionary key to determine the origin of a push notification.
 *
 *  @discussion Push notifications that originate from Zingle will have a non-nil value for this key.
 *
 *  `BOOL isZingleNotification = userInfo[ZNGPushNotificationIdentifier] != nil`
 */
extern NSString* const ZNGPushNotificationIdentifier;

/**
 *  @abstract User info dictionary key for an ZNGUser after a successful call to +login:jwt:completionHandler:
 *
 *  @see ZNGUser
 *  @see ZNGLoginDidCompleteNotification
 *  @see +login:jwt:completionHandler:
 */
extern NSString* const ZNGUserIdentifier;

/**
 *  @abstract User info dictionary key for an ZNGConversation after a successful call to +startConversationWithCompletionHandler:
 *
 *  @see ZNGConversation
 *  @see +startConversationWithCompletionHandler:
 */
extern NSString* const ZNGConversationIdentifier;

/**
 *  @abstract User info dictionary key to determine the error code of a failed operation. Possible operations that may include this value are +initWithSettings:completionHandler:, +login:jwt:completionHandler: and +logoutWithCompletionHandler:
 *
 *  @discussion Possible values include, but are not limited to, "unauthorized", "invalid_auth", "bad_request", "unhandled_error", "invalid_app" or an empty string for connectivity errors
 *
 *  @see ZNGInitializationDidFailNotification
 *  @see ZNGLoginDidFailNotification
 *  @see ZNGLogoutDidFailNotification
 *  @see +initWithSettings:completionHandler:
 *  @see +login:jwt:completionHandler:
 *  @see +logoutWithCompletionHandler:
 */
extern NSString* const ZNGErrorCodeIdentifier;

/**
 *  @abstract User info dictionary key to determine the error description of a failed operation. Possible operations that include this value are +initWithSettings:completionHandler:, +login:jwt:completionHandler: and +logoutWithCompletionHandler:
 *
 *  @see ZNGInitializationDidFailNotification
 *  @see ZNGLoginDidFailNotification
 *  @see ZNGLogoutDidFailNotification
 *  @see +initWithSettings:completionHandler:
 *  @see +login:jwt:completionHandler:
 *  @see +logoutWithCompletionHandler:
 */
extern NSString* const ZNGErrorDescriptionIdentifier;

/**
 *  @abstract Custom error domain identifier
 */
extern NSString* const ZNGErrorDomainIdentifier;

/**
 *  @abstract User info dictionary key to determine the HTTP status code of a failed operation. Possible operations that include this value are +initWithSettings:completionHandler:, +login:jwt:completionHandler: and +logoutWithCompletionHandler:
 *
 *  @discussion User info dictionary key to determine the HTTP status code of a failed operation
 *
 *  @see ZNGInitializationDidFailNotification
 *  @see ZNGLoginDidFailNotification
 *  @see ZNGLogoutDidFailNotification
 *  @see +initWithSettings:completionHandler:
 *  @see +login:jwt:completionHandler:
 *  @see +logoutWithCompletionHandler:
 */
extern NSString* const ZNGStatusCodeIdentifier;

/**
 *  @abstract Identifier for a Zingle user notification reply action.
 *
 *  @discussion Used as the identifier for a UIUserNotificationAction on iOS 9, and a UNTextInputNotificationAction on iOS 10 and above.
 */
extern NSString* const ZNGUserNotificationReplyActionIdentifier;

/**
 *  @abstract Identifier for a Zingle user notification category.
 *
 *  @discussion Used as the identifier for a UIUserNotificationCategory on iOS 9, and a UNNotificationCategory on iOS 10 and above.
 */
extern NSString* const ZNGUserNotificationReplyCategoryIdentifier;

/**
 *  @abstract Notification that fires when initialization completes successfully
 *
 *  @discussion This notification is fired each time a call to +initWithSettings:completionHandler: completes with a non-error status code.
 *
 *  @see +initWithSettings:completionHandler:
 */
extern NSString* const ZNGInitializationDidCompleteNotification;

/**
 *  @abstract Notification that fires when initialization fails
 *
 *  @discussion This notification is fired each time a call to +initWithSettings:completionHandler: fails.
 *
 *  You may use this notification to know if initialization failed due to an invalid app ID, invalid JWT, or connectivity errors by inspecting the `userInfo` dictionary included with it.
 *
 *  @see ZNGErrorCodeIdentifier
 *  @see ZNGErrorDescriptionIdentifier
 *  @see ZNGStatusCodeIdentifier
 */
extern NSString* const ZNGInitializationDidFailNotification;

/**
 *  @abstract Notification that fires when +login:jwt:completionHandler: completes successfully
 *
 *  @discussion This notification is fired each time a call to +login:jwt:completionHandler: completes with a non-error status code.
 *
 *  @see +login:jwt:completionHandler:
 *  @see ZNGUserIdentifier
 */
extern NSString* const ZNGLoginDidCompleteNotification;

/**
 *  @abstract Notification that fires when +login:jwt:completionHandler: fails
 *
 *  @discussion This notification is fired each time a call to +login:jwt:completionHandler: fails.
 *
 *  You may use this notification to know if a call to +login:jwt:completionHandler: failed due to an invalid JWT, or connectivity errors by inspecting the `userInfo` dictionary included with it.
 *
 *  @see ZNGErrorCodeIdentifier
 *  @see ZNGErrorDescriptionIdentifier
 *  @see ZNGStatusCodeIdentifier
 */
extern NSString* const ZNGLoginDidFailNotification;

/**
 *  @abstract Notification that fires when +logoutWithCompletionHandler: completes successfully
 *
 *  @discussion This notification is fired each time a call to +logoutWithCompletionHandler: completes with a non-error status code.
 *
 *  @see +logoutWithCompletionHandler:
 */
extern NSString* const ZNGLogoutDidCompleteNotification;

/**
 *  @abstract Notification that fires when a call to +logoutWithCompletionHandler: fails
 *
 *  @discussion This notification is fired when a call to +logoutWithCompletionHandler: fails
 *
 *  @see ZNGErrorCodeIdentifier
 *  @see ZNGErrorDescriptionIdentifier
 *  @see ZNGStatusCodeIdentifier
 */
extern NSString* const ZNGLogoutDidFailNotification;

/**
 *  @abstract The core class used for interacting with Zingle. Provides methods to initialize, configure, and interact with the library.
 */
@interface Zingle : NSObject

/**
 *  @abstract Initialize the Zingle SDK with the provided settings.
 *
 *  @discussion This may only be called once (preferably, in application:didFinishLaunchingWithOptions:).
 *
 *  Use +settings to retrieve and modify the given settings object.
 *
 *  @see ZNGSettings
 *
 *  @param settings The settings to use.
 *  @param handler An optional block to evaluate the result of the operation
 */
+(void)initWithSettings:(ZNGSettings*)settings completionHandler:(nullable void(^)(NSError * _Nullable error, NSDictionary * _Nullable userInfo))handler;

/**
 *  @abstract Accessor method for the sdk settings.
 *
 *  @discussion Use this object to update settings at run time.
 *
 *  Note: Some settings may only be configured at init time. See the ZNGSettings class reference for more information.
 *
 *  @see ZNGSettings
 *
 *  @return Settings object passed in +initWithSettings:completionHandler:, or nil if +initWithSettings:completionHandler: hasn't been called yet.
 */
+(nullable ZNGSettings*)settings;

/**
 *  @abstract Presents the Zingle conversation screen.
 *
 *  @discussion Uses the top-most view controller of the `UIApplicationDelegate` as the presenting view controller.
 *
 *  +initWithSettings:completionHandler: must have been called prior to calling this method.
 */
+(void)show;

/**
 *  @abstract Dismisses the Zingle conversation, if shown.
 *
 *  @discussion Note: If a view controller was created and presented using `newConversationViewController`, calling this method will have no effect.
 *
 *  +initWithSettings:completionHandler: must have been called prior to calling this method.
 */
+(void)close;

/**
 *  @abstract Destroys the Zingle SDK
 *
 *  @discussion Zingle is automatically terminated when the application exits. This method does not need to be called manually
 *
 */
+(void)destroy;

/**
 *  @abstract Presents the Zingle conversation screen, using the given view controller as presenting view controller.
 *
 *  @discussion In most cases, it is better to use +show. If you need more fine-grained control over which view controller is used as presenting view controller, use this method instead.
 *
 *  +initWithSettings:completionHandler: must have been called prior to calling this method.
 */
+(void)showConversationFromViewController:(UIViewController*)viewController;

/**
 *  @abstract Creates and returns a Zingle conversation view controller.
 *
 *  @discussion You may use this view controller to embed the conversation in a navigation controller, to change the modal presentation style, or display it in any way you choose.
 *
 *  A view controller created in this way is tied to the current user's conversation at creation time. If the current user changes (i.e. by calling +login:jwt:completionHandler: or +logoutWithCompletionHandler:), the view controller is invalidated and must be recreated for the new user.
 *
 *  Note: It is the responsibility of the caller to show, hide, and maintain a reference to this view controller. Calling `close` will not dismiss a view controller created in this way.
 *
 *  @return A new instance of the Zingle conversation view controller class. Returns nil if +initWithSettings:completionHandler: hasn't been called
 */
+(nullable UIViewController*)newConversationViewController;

/**
 *  @abstract Sets the current user's first and last name to be used as a display name when sending messages.
 *
 *  @discussion This is a shortcut for -setFirstName and -setLastName on `[ZNGUser currentUser]`
 *
 *  @see ZNGUser
 *
 *  @param firstName The first name of the user
 *  @param lastName The last name of the user
 */
+(void)setUserFirstName:(nullable NSString*)firstName lastName:(nullable NSString*)lastName;

/**
 *  @abstract Accessor method for the current conversation.
 *
 *  @see ZNGConversation
 *
 *  @return Current conversation, or nil if +initWithSettings:completionHandler: hasn't been called yet.
 */
+(nullable ZNGConversation*)conversation;

/**
 *  @abstract Logs in a new Zingle user.
 *
 *  @discussion You can either use this method to transition from logged out state to logged in, or to switch the currently logged in user to a different one.
 *
 *  User login state is persisted across app launches. You must call +logoutWithCompletionHandler: to reset to anonymous mode.
 *
 *  +initWithSettings:completionHandler: must have been called prior to calling this method.
 *
 *  You may not call login while the conversation screen is shown. Doing so will result in a no-op.
 *
 *  @param userId The distinct id of the user to login. Must not be nil.
 *  @param jwt jwt used to prove the origin of the login request. Must not be nil.
 */
+(void)login:(NSString*)userId jwt:(NSString*)jwt completionHandler:(nullable void(^)(NSError * _Nullable error, NSDictionary * _Nullable userInfo))handler;

/**
 *  @abstract Logs out the current user.
 *
 *  @discussion Calling this method while already in anonymous state has no effect.
 *
 *  You may not call logout while the conversation screen is shown. Doing so will result in a no-op.
 */
+(void)logoutWithCompletionHandler:(nullable void(^)( NSError * _Nullable error, NSDictionary * _Nullable userInfo))completionHandler;

/**
 *  @abstract Force-start a conversation for the current user
 *
 *  @discussion Creates a user and conversation on the server, allowing the business to reach out proactively to the user via the public API.
 *
 *  It is strongly recommended to only call this method in the case where a message is likely to be sent.
 *
 *  This method is called automatically when starting a conversation via the -sendMessage: or -sendImage:withProgress:completion: methods, or when a user sends a message via the conversation view controller.
 *
 *  If a conversation already exists for the current user, this call is a no-op.
 */
+(void)startConversationWithCompletionHandler:(nullable void(^)(NSError * _Nullable error, NSDictionary * _Nullable userInfo))completionHandler;

/**
 *  @abstract Set the push notification token for this device.
 *
 *  @discussion This method is called automatically if ZNGSettings.enableAppDelegateSwizzling is set to YES.
 *
 *  @see ZNGSettings
 */
+(void)setPushToken:(NSData*)token;

/**
 *  @abstract Handle an incoming push notification.
 *
 *  @discussion Call this method in your -application:didReceiveRemoteNotification: or -application:didReceiveRemoteNotification:fetchCompletionHandler: callback, passing the userInfo dictionary.
 *
 *  If the push notification did not originate from Zingle, this is a no-op.
 *
 *  This method is called automatically if ZNGSettings.enableAppDelegateSwizzling is set to YES.
 *
 *  @see ZNGSettings
 */
+(void)handlePushNotification:(NSDictionary*)userInfo;

/**
 *  @abstract An object conforming to UNUserNotificationCenterDelegate protocol, used to handle notifications on iOS 10 and above.
 *
 *  @discussion Implements both methods of UNUserNotificationCenterDelegate.
 *
 *  By default this object will automatically be set as the UNUserNotificationCenter delegate at init time. Zingle will maintain a reference to your app's existing delegate (if applicable), and automatically forward any calls for notifications that did not originate from Zingle.
 *
 *  To disable automatic overriding, you must set ZNGSettings.enableUserNotificationCenterDelegateOverride to NO before calling +initWithSettings:completionHandler:. If you choose to do so, you must manually forward any relevant calls from your own delegate object. To check the origin of a notification, see the documentation for ZNGPushNotificationIdentifier. For example:
 *
 *  -(void)userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions))completionHandler
 *  {
 *    if(notification.request.content.userInfo[ZNGPushNotificationIdentifier] != nil){
 *      [[Zingle userNotificationCenterDelegate] userNotificationCenter:center willPresentNotification:notification withCompletionHandler:completionHandler];
 *      return;
 *    }
 *  }
 *
 *  -(void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void (^)())completionHandler
 *  {
 *    if(response.notification.request.content.userInfo[ZNGPushNotificationIdentifier] != nil){
 *      [[Zingle userNotificationCenterDelegate] userNotificationCenter:center didReceiveNotificationResponse:response withCompletionHandler:completionHandler];
 *      return;
 *    }
 *  }
 *
 *  @see ZNGSettings
 *
 *  @return An object conforming to UNUserNotificationCenterDelegate protocol, or nil if +initWithSettings:completionHandler: hasn't been called yet.
 */
+(nullable id<UNUserNotificationCenterDelegate>)userNotificationCenterDelegate;

/**
 *  @abstract Handle the user input from a reply type notification action.
 *
 *  @discussion Call this method in your -application:handleActionWithIdentifier:forRemoteNotification:withResponseInfo:completionHandler:, passing the action identifier, responseInfo dictionary, and completionHandler callback.
 *
 *  This method will post a message on behalf of the user, with the contents of their inline reply. When the message upload completes (either in success or failure), the completion handler will be called.
 *
 *  If the action identifier does not match ZNGUserNotificationReplyActionIdentifier, the completion handler will be called immediately and the notification will be ignored.
 *
 *  This method is called automatically if ZNGSettings.enableAppDelegateSwizzling is set to YES.
 *
 *  @see ZNGSettings
 */
+(void)handleUserNotificationActionWithIdentifier:(NSString *)identifier withResponseInfo:(NSDictionary *)responseInfo completionHandler:(void (^)(void))completionHandler;

/**
 *  @abstract A set of categories used for handling and displaying Zingle user notification actions.
 *
 *  @discussion On iOS 8, returns an empty set.
 *  On iOS 9, returns a set of UIUserNotificationCategory objects, to be used with `UIUserNotificationSettings` +settingsForTypes:categories:
 *  On iOS 10, returns a set of UNNotificationCategory objects, to be used with `UNUserNotificationCenter` -setNotificationCategories:
 *
 *  Categories are registered automatically if ZNGSettings.requestPushPermissionOnFirstMessage is set to YES. If automatic registration is disabled, you must make sure to include the Zingle categories in your calls to the above mentioned methods.
 *
 *  @see ZNGSettings
 */
+(NSSet*)userNotificationCategories;

@end
NS_ASSUME_NONNULL_END
