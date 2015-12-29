//
//  AFTrackingProtocol.h
//  AFPushNotificationServiceSDK
//
//  Created by Daniel Kuhnke on 28.12.15.
//  Copyright © 2015 appfarms GmbH & Co. KG. All rights reserved.
//

@protocol AFTrackingProtocol <NSObject>

@optional
- (BOOL) ignoreInTrackings; // If not implemented: Default is NO
- (NSString *) trackingTitle;

@end