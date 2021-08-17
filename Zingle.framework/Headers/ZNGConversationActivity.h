//
//  ZNGConversationActivity.h
//  Zingle
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  @abstract An activity type indicating that a participant of the converation started typing a response
 */
extern NSString *const ZNGConversationActivityTypeTypingStart;

/**
 *  @abstract An activity type indicating that a participant of the converation stopped typing a response
 */
extern NSString *const ZNGConversationActivityTypeTypingStop;

/**
 *  @abstract An activity type indicating that a participant of the converation recently read the user message
 *
 *  This event type is triggered for the current user when the conversation is read on a different device. 
 */
extern NSString *const ZNGConversationActivityTypeConversationRead;

/**
 *  @abstract An activity type indicating that the current user was added to a conversation
 */
extern NSString *const ZNGConversationActivityTypeConversationAdded;

/**
 *  @abstract An activity type indicating that the current user was removed from a conversation
 */
extern NSString *const ZNGConversationActivityTypeConversationRemoved;

/**
 *  @abstract An activity type indicating that another user was added to a conversation that the current user is part of
 */
extern NSString *const ZNGConversationActivityTypeParticipantAdded;

/**
 *  @abstract An activity type indicating that another user was removed from a conversation that the current user is part of
 */
extern NSString *const ZNGConversationActivityTypeParticipantRemoved;

/**
 *  @abstract A key whose value is an NSString representing the business name.
 *
 *  @discussion This key is used in the ZNGConversationActivity data object.
 */
extern NSString *const ZNGConversationActivityDataNameKey;

/**
 *  @abstract A key whose value is an NSString representing the URL of the business avatar.
 *
 *  @discussion This key is used in the ZNGConversationActivity data object.
 */
extern NSString *const ZNGConversationActivityDataAvatarUrlKey;

@interface ZNGConversationActivity : NSObject

/**
 *  @abstract the role of who is performing the typing activity
 */
@property(readonly, nullable) NSString *role;

/**
 *  @abstract the type of activity that is being triggered. Could be either
 *   - ZNGConversationActivityTypeTypingStart
 *   - ZNGConversationActivityTypeTypingStop
 *   - ZNGConversationActivityTypeConversationRead
 *   - ZNGConversationActivityTypeConversationAdded
 *   - ZNGConversationActivityTypeConversationRemoved
 *   - ZNGConversationActivityTypeParticipantAdded
 *   - ZNGConversationActivityTypeParticipantRemoved
 */
@property(readonly) NSString *type;

/**
 *  @abstract additional data for this activity. Posible values are the business's 'name' and/or 'avatarUrl'
 */
@property(readonly, nullable) NSDictionary *data;

/**
 *  @abstract conversationId for activity. Can be nil
 */
@property(readonly, nullable) NSString *conversationId;

/**
 *  @abstract date when the business last read user messages for activities of type ZNGConversationActivityTypeConversationRead
 */
@property(readonly, nullable) NSDate *businessLastRead;

/**
 * @abstract The userId if available, null otherwise
 *
 * available for ZNGConversationActivityTypeParticipantAdded, ZNGConversationActivityTypeParticipantRemoved
 */
@property(readonly, nullable) NSString *userId;

@end
NS_ASSUME_NONNULL_END
