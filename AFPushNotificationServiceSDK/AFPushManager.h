//
//  AFPushManager.h
//  AFPushNotificationServiceSDK
//
//  Created by Daniel Kuhnke on 19.11.15.
//  Copyright © 2015 appfarms GmbH & Co. KG. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "AFTrackingProtocol.h"

typedef NS_ENUM(NSUInteger, AFPushEnvironment)
{
    AFPushEnvironmentLive    = 1, // Use this for App-Store-Distribution or In-House-Distribution (Distribution-Push-Certificate)
    AFPushEnvironmentStaging = 2, // Use this for Ad-Hoc-Distribution or Preview-Distribution (Distribution-Push-Certificate)
    AFPushEnvironmentDebug   = 3  // Use this if you're debugging or developing with Xcode (Development-Push-Certificate)
};

typedef NS_ENUM(NSUInteger, AFPushLogLevel)
{
    AFPushLogLevelNone,    // Don't show anything in log
    AFPushLogLevelError,   // Show errors in log
    AFPushLogLevelWarning, // Show errors and warnings in log
    AFPushLogLevelInfo,    // Show errors, warnings and infos in log
    AFPushLogLevelDebug    // Show a lot of debugging infos in log
};

typedef NS_ENUM(NSUInteger, AFPushTrackTransmissionInterval)
{
    AFPushTrackTransmissionIntervalNormal            = 300, // Transmit tracking data every 5 minutes
    AFPushTrackTransmissionIntervalFrequently        = 60,  // Transmit tracking data every minute
    AFPushTrackTransmissionIntervalExtremeFrequently = 10,  // Transmit tracking data every 10 seconds
    AFPushTrackTransmissionIntervalInfrequently      = 600  // Transmit tracking data every 10 minutes
};

typedef NS_ENUM(NSUInteger, AFPushAutoTrackingMode)
{
    AFPushAutoTrackingModeOptIn, // Every UIViewController will be recognized that implements at least `afTrackingTitle` from AFTrackingProtocol
    AFPushAutoTrackingModeAll,   // Every UIViewController will be recognized
    AFPushAutoTrackingModeNone   // No UIViewController will be tracked automatically
};

@interface AFPushManager : NSObject

/**
 @abstract Setup a shared instance of AFPushManager

 @discussion Call this from `appplication:didFinishLaunchingWithOptions:`.

 @param apiKey The apiKey you received from https://push.appfarms.com on app settings page
 @param environment The environment you want the manager to work with
 @param enableTracking
 */
+ (void) configureWithApiKey:(NSString *)apiKey environment:(AFPushEnvironment)environment enableTracking:(BOOL)enableTracking autoTrackingMode:(AFPushAutoTrackingMode)autoTrackingMode;

/**
 @abstract Set the logLevel to see log
 
 @discussion Default is AFPushLogLevelError
 
 @param logLevel A logLevel of type AFPushLogLevel
 */
+ (void) setLogLevel:(AFPushLogLevel)logLevel;

/**
 @abstract Adjust the frequency of tranmitting data to database

 @discussion Default is AFPushTrackTransmissionIntervalNormal

 @param trackTransmissionInterval A trackTransmissionInterval of type AFPushTrackTransmissionInterval
 */
+ (void) setTrackTransmissionInterval:(AFPushTrackTransmissionInterval)trackTransmissionInterval;

/**
 @abstract Register device with deviceToken to receive push notifications from https://push.appfarms.com

 @discussion Call this from `application:didRegisterForRemoteNotificationsWithDeviceToken:`.
 
 @param deviceToken The deviceToken data you get in `application:didRegisterForRemoteNotificationsWithDeviceToken:`.
 */
+ (void) setDeviceToken:(NSData *)deviceToken;

/**
 @abstract Give feedback for receiceived push notification to AFPushManager

 @discussion Call this from `application:didReceiveRemoteNotification:`.

 @param userInfo The userInfo dictionary you get in `appplication:didReceiveRemoteNotification:`.
 */
+ (void) handlePush:(NSDictionary *)userInfo;

/**
 @abstract Give feedback for receiceived push notification to AFPushManager

 @discussion Call this from `appplication:didFinishLaunchingWithOptions:`.

 @param userInfo The userInfo dictionary you get in `appplication:didFinishLaunchingWithOptions:`.
 */
+ (void) handleLaunchOptions:(NSDictionary *)launchOptions;

/**
 @abstract Save additional tracking data to server

 @discussion Call this anywhere you want but after calling `configureWithApiKey:environment:enableTracking:`. This can e.g. save the age or the gender of the user...

 @param additionalTrackingInfo A dictionary that holds als the fields you defined on https://push.appfarms.com
 */
+ (void) setAdditionalTrackingInfo:(NSMutableDictionary *)additionalTrackingInfo;

/**
 @abstract Verify if current device is connected to internet
 */
+ (BOOL) hasInternetConnection;

+ (void) trackApplicationDidShowScreen:(NSString *)screen details:(NSString *)details;

+ (void) trackApplicationDidShowScreen:(NSString *)screen details:(NSString *)details startDate:(NSDate *)startDate endDate:(NSDate *)endDate;

@end
