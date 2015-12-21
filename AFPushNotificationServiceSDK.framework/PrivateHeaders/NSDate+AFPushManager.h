//
//  NSDate+AFPushManager.h
//  
//
//  Created by Michael Wegner on 01.12.15.
//
//

#import <Foundation/Foundation.h>

@interface NSDate (AFPushManager)

+ (NSDateFormatter *) dateFormatter;
+ (NSString *) stringFromDate:(NSDate *)date;
- (NSString *) stringFromDate;

@end
