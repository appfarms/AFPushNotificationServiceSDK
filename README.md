# iOS appfarms Push Service Library

## Changelog

### Version 0.0.17, 0.0.16

- Improved code stability
- Wrote README.md

## Introduction

appfarms Push Notification Service is a web based portal to send remote push notifications to your app and collect important statistical data regarding your push notifications. This library  is a drop-in static library that provides a simple way to integrate Urban Airship services into your iOS applications.

Features supported:

1. **Enable Push Notifications:** Enable remote push notifications for your mobile app. The library automatically registers the device token with the appfarms Push Notification Service so that you easily can send remote push notifications via the appfarms Push Notification Service web frontend.

2. **Analytics:** Developers can then use the appfarms Analytics reports to measure:
  1. The number of active users are using their applications.
  2. Adoption and usage of specific features.
  3. And many other useful metrics...

This document contains the following sections:

1. [Requirements](#requirements)
2. [Setup](#setup)
   1. [Setup with CocoaPods](#cocoapods)
   2. [Enable Push Notification](#enablepush)
   3. [Analytics](#analytics)
   4. [Custom Parameter](#customparameter)
3. [Documentation](#documentation)
4. [License](#licence)
5. [Contact](#contact)

<a id="requirements"></a>
## 1. Requirements

1. Xcode 7 or later
2. The SDK supports iOS 7.0 and later
3. You do need a valid account and subscription of appfarms Push Notification Service for full support of the SDK. For more information go to "[appfarms Push Notification Service](http://push.appfarms.com)"

<a id="setup"></a>
## 2. Setup

We recommend integration of library via [CocoaPods](http://cocoapods.org).

<a id="cocoapods"></a>
### 2.1 Setup with CocoaPods

[CocoaPods](http://cocoapods.org) is a dependency manager for Objective-C, which automates and simplifies the process of using 3rd-party libraries like HockeySDK in your projects. To learn how to setup CocoaPods for your project, visit the [official CocoaPods website](http://cocoapods.org/).

**Podfile**

```ruby
platform :ios, '8.0'

source 'https://github.com/CocoaPods/Specs.git'

target 'MyTarget' do
pod "AFPushNotificationServiceSDK"
end
```

<a id="enablepush"></a>
### 2.2 Enable Push Notification

**Objective-C**

1. Open your `AppDelegate.m` file.
2. Add the following line at the top of the file below your own `import` statements:
   ```objective-c
   #import "AFPushManager.h"
   ```
3. Add the following code to `-application:didFinishLaunchingWithOptions:`:
   ```objective-c
   NSString          * apiKey = @"6fe...068";          // Your private apiKey from https://push.appfarms.com
   AFPushEnvironment   env    = AFPushEnvironmentLive; // or `AFPushEnvironmentDebug` or `AFPushEnvironmentStaging`

   [AFPushManager configureWithApiKey:apiKey
                          environment:env
                       enableTracking:YES
                     autoTrackingMode:AFPushAutoTrackingModeOptIn];

   [AFPushManager handleLaunchOptions:launchOptions];

   // Register for remote notifications
   if ([application respondsToSelector:@selector(registerUserNotificationSettings:)])
   {
       UIUserNotificationSettings * settings = nil;
       settings = [UIUserNotificationSettings settingsForTypes:UIUserNotificationTypeBadge|UIUserNotificationTypeSound|UIUserNotificationTypeAlert categories:nil];
       [application registerUserNotificationSettings:settings];
   }
   else
   {
       [application registerForRemoteNotifications];
   }
   ```
4. Add the following delegate methods to your `AppDelegate.m`:
   ```objective-c
   - (void) application:(UIApplication *)application didRegisterUserNotificationSettings:(UIUserNotificationSettings *)notificationSettings
   {
       if (notificationSettings.types != UIUserNotificationTypeNone)
       {
           [application registerForRemoteNotifications];
       }
   }

   - (void) application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
   {
       [AFPushManager setDeviceToken:deviceToken];
   }

   - (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
   {
       [AFPushManager handlePush:userInfo];
   }
   ```

<a id="analytics"></a>
### 2.3 Analytics

TODO

<a id="documentation"></a>
## 4. Documentation

Our documentation can be found on [appfarms Push Notification Service](http://push.appfarms.com).

<a id="licence"></a>
## 5.License

Copyright 2015 - 2016 appfarms GmbH & Co KG. All rights reserved.

<a id="contact"></a>
## 8. Contact

If you have further questions or are running into trouble that cannot be resolved by any of the steps here, feel free to open a Github issue here or contact us at [support@appfarms.com](mailto:support@appfarms.com)
