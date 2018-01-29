//
//  ZNGConversationActivity.h
//  Zingle
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  @abstract An activity type indicating that the appMaker started typing a response
 */
extern NSString const *ZNGConversationActivityTypeTypingStart;

/**
 *  @abstract An activity type indicating that the appMaker stopped typing a response
 */
extern NSString const *ZNGConversationActivityTypeTypingStop;

/**
 *  @abstract An activity type indicating that the appMaker recently read the user message
 */
extern NSString const *ZNGConversationActivityTypeConversationRead;

/**
 *  @abstract A key whose value is an NSString representing the appMaker name.
 *
 *  @discussion This key is used in the ZNGConversationActivity data object.
 */
extern NSString const *ZNGConversationActivityDataNameKey;

/**
 *  @abstract A key whose value is an NSString representing the URL of the appMaker avatar.
 *
 *  @discussion This key is used in the ZNGConversationActivity data object.
 */
extern NSString const *ZNGConversationActivityDataAvatarUrlKey;

@interface ZNGConversationActivity : NSObject

/**
 *  @abstract the role of who is performing the typing activity
 */
@property(readonly) NSString *role;

/**
 *  @abstract the type of activity that is being triggered. Could be either ZNGConversationActivityTypeTypingStart, ZNGConversationActivityTypeTypingStop or ZNGConversationActivityTypeConversationRead
 */
@property(readonly) NSString *type;

/**
 *  @abstract additional data for this activity. Posible values are the appMaker's 'name' and/or 'avatarUrl'
 */
@property(readonly, nullable) NSDictionary *data;

/**
 *  @abstract date when the appMaker last read user messages for activities of type ZNGConversationActivityTypeConversationRead
 */
@property(readonly, nullable) NSDate *appMakerLastRead;

@end
NS_ASSUME_NONNULL_END
