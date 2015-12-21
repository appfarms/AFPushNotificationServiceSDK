//
//  AFTrackingEntry.h
//
//
//  Created by Michael Wegner on 01.12.15.
//
//

#import <Foundation/Foundation.h>

@interface AFTrackingEntry : NSObject

@property (nonatomic, assign) BOOL transmitted;

+ (id)entryForDidBecomeActive;
+ (id)entryForDidEnterBackground;
+ (id)entryForDidShowScreen:(NSString *)screen customParams:(NSDictionary *)params;
+ (id)entryForAction:(NSString *)action customParams:(NSDictionary *)params;

- (NSDictionary *)transmissionDictionary;

@end
