//
//  AFPushManager.h
//  AFPushNotificationServiceSDK
//
//  Created by Daniel Kuhnke on 19.11.15.
//  Copyright © 2015 appfarms GmbH & Co. KG. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, AFPushEnvironment)
{
    AFPushEnvironmentLive    = 1,
    AFPushEnvironmentStaging = 2,
    AFPushEnvironmentDebug   = 3
};

typedef NS_ENUM(NSUInteger, AFPushLogLevel)
{
    AFPushLogLevelNone,
    AFPushLogLevelError,
    AFPushLogLevelWarning,
    AFPushLogLevelInfo,
    AFPushLogLevelDebug
};

@interface AFPushManager : NSObject

+ (void) configureWithApiKey:(NSString *)apiKey andEnvironment:(AFPushEnvironment)environment;

+ (void) setLogLevel:(AFPushLogLevel)logLevel;

/**
 
 @discussion Call this from `application:didRegisterForRemoteNotificationsWithDeviceToken:`.
 
 @param deviceToken The deviceToken data you get in `application:didRegisterForRemoteNotificationsWithDeviceToken:`.
 */
+ (void) setDeviceToken:(NSData *)deviceToken;

/**
 @abstract A default handler for push notifications while the app is active that
 could be used to mimic the behavior of iOS push notifications while the app is backgrounded or not running.

 @discussion Call this from `application:didReceiveRemoteNotification:`.

 @param userInfo The userInfo dictionary you get in `appplication:didReceiveRemoteNotification:`.
 */
+ (void) handlePush:(NSDictionary *)userInfo;

/**
 @abstract A default handler for push notifications while the app was not active that
 could be used to mimic the behavior of iOS push notifications while the app is backgrounded or not running.

 @discussion Call this from `appplication:didFinishLaunchingWithOptions:`.

 @param userInfo The userInfo dictionary you get in `appplication:didFinishLaunchingWithOptions:`.
 */
+ (void) handleLaunchOptions:(NSDictionary *)launchOptions;

+ (void) setAdditionalTrackingInfo:(NSMutableDictionary *)additionalTrackingInfo;
+ (void) trackApplicationDidBecomeActive;
+ (void) trackApplicationDidEnterBackground;
+ (void) trackApplicationDidShowScreen:(NSString *)screen;

@end
