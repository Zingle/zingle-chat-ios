//
//  ZNGMessageAction.h
//  Zingle
//

#import <Foundation/Foundation.h>

/**
 *  @abstract Type for a link action.
 */
extern NSString* _Nonnull const ZNGMessageActionTypeLink;

/**
 *  @abstract Type for a webview action.
 */
extern NSString* _Nonnull const ZNGMessageActionTypeWebview;

/**
 *  @abstract Type for a buy action.
 */
extern NSString* _Nonnull const ZNGMessageActionTypeBuy;

/**
 *  @abstract Type for a postback action.
 */
extern NSString* _Nonnull const ZNGMessageActionTypePostback;

/**
 *  @abstract Type for a reply action
 */
extern NSString* _Nonnull const ZNGMessageActionTypeReply;

/**
 *  @abstract Type for a location request
 */
extern NSString* _Nonnull const ZNGMessageActionTypeLocationRequest;

/**
 *  @abstract Offered state for a buy message. The user has not yet completed the transaction.
 */
extern NSString* _Nonnull const ZNGMessageActionStateOffered;

/**
 *  @abstract Paid state for a buy message. The user has completed the transaction and payment was successful.
 */
extern NSString* _Nonnull const ZNGMessageActionStatePaid;

/**
 *  @abstract A full-sized webview
 */
extern NSString* _Nonnull const ZNGMessageActionWebviewSizeFull;

/**
 *  @abstract A tall-sized webview
 */
extern NSString* _Nonnull const ZNGMessageActionWebviewSizeTall;

/**
 *  @abstract A compact-sized webview
 */
extern NSString* _Nonnull const ZNGMessageActionWebviewSizeCompact;

/**
 *  @abstract An action associated to a particular ZNGMessage.
 *
 *  Actions are rendered as buttons in the Zingle conversation screen, and may be of type `ZNGMessageActionTypeLink`, `ZNGMessageActionTypeBuy` or `ZNGMessageActionTypePostback`.
 *
 *  @see ZNGMessage
 */
@interface ZNGMessageAction : NSObject

/**
 *  @abstract The unique identifier representing the action.
 */
@property(readonly, nullable) NSString* actionId;

/**
 *  @abstract The type of action.
 *
 *  @discussion Valid types include `ZNGMessageActionTypeLink` for regular actions, and `ZNGMessageActionTypeBuy` for buy actions.
 */
@property(nullable) NSString* type;

/**
 *  @abstract The text to display as a descriptor for the action.
 *
 *  @discussion May not be nil.
 */
@property(nullable) NSString* text;

/**
 *  @abstract The URI to navigate to if the user interacts with the action.
 *
 *  @discussion May not be nil if message is of type `ZNGMessageActionTypeLink` or `ZNGMessageActionTypeWebview`
 */
@property(nullable) NSURL* uri;

/**
 *  @abstract Fallback URI to use for action types not supported by the SDK. May be nil.
 */
@property(nullable) NSURL* fallback;

/**
 *  @abstract The size of a webview
 *
 *  @discussion May not be nil if message is of type `ZNGMessageActionTypeWebview`
 */
@property(nullable, copy) NSString* size;

/**
 *  @abstract Metadata associated with the action.
 *
 *  @discussion A flat dictionary of metadata set through the REST API. May be nil.
 */
@property(nullable) NSDictionary* metadata;

/**
 *  @abstract Icon to display with a reply
 *
 *  @discussion An icon to render next to the reply option
 */
@property(nullable) NSString* iconUrl;

/**
 *  @abstract The payload of actions with type ZNGMessageActionTypeReply or ZNGMessageActionTypePostback
 *
 *  @discussion The payload of actions with type ZNGMessageActionTypeReply or ZNGMessageActionTypePostback, if applicable. May be nil
 */
@property(nullable) NSString* payload;

#pragma mark - Buy actions

/**
 *  @abstract The purchase state of the action
 *
 *  @discussion This property is only non-nil for actions of type `ZNGMessageActionTypeBuy`. Valid states include `ZNGMessageActionStateOffered` and `ZNGMessageActionStatePaid`.
 */
@property(nullable) NSString* state;

/**
 *  @abstract The amount of money to charge for the action.
 *
 *  @discussion This property is only valid for actions of type `ZNGMessageActionTypeBuy`. For USD, this value is in cents.
 */
@property long amount;

/**
 *  @abstract The currency in which the `amount` is expressed.
 *
 *  @discussion This property is only valid for actions of type `ZNGMessageActionTypeBuy`.
 */
@property(nullable) NSString* currency;

@end
