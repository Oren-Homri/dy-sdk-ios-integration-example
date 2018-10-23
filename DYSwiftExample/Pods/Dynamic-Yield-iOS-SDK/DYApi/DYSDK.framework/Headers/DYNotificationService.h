//
//  DYNotificationService.h
//  DYNotificationService
//
//  Created by Idan Oshri on 16/11/2017.
//  Copyright © 2017 Dynamic Yield. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>

@interface DYNotificationService : NSObject


- (void)didReceiveNotificationRequest:(UNNotificationRequest *_Nonnull)request withContentHandler:(void (^_Nonnull)(UNNotificationContent * _Nonnull))contentHandler API_AVAILABLE(ios(10.0));
@end
