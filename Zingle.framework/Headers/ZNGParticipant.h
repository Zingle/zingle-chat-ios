//
//  ZNGParticipant.h
//  Zingle
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZNGParticipant : NSObject <NSSecureCoding>

/**
 * @abstract The unique identifier of the participant.
 */
@property (readonly) NSString *participantId;

/**
 * @abstract The assigned appUserId for this participant.
 */
@property (readonly) NSString *appUserId;

/**
 * @abstract The number of unread messages for this participant.
 */
@property NSNumber *unreadCount;

/**
 * @abstract The date this participant last read the conversation.
 */
@property NSDate *lastRead;

@end

NS_ASSUME_NONNULL_END
