//
//  DYNotificationContent.h
//  DYSDK
//
//  Created by Idan Oshri on 16/11/2017.
//  Copyright © 2017 dynamicyield. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "iCarousel.h"

#import <AVKit/AVKit.h>
#import <UserNotifications/UserNotifications.h>
#import <UserNotificationsUI/UserNotificationsUI.h>
#import <MobileCoreServices/MobileCoreServices.h>
//#import "DYApi.h"

typedef enum {
    DY_NO_NOTIF,
    DY_IMAGE_NOTIF,
    DY_CAROUSEL_NOTIF
    
    
} DYNotificationType;

@interface DYNotificationContent : NSObject <iCarouselDelegate,iCarouselDataSource>


@property (nonatomic, strong) IBOutlet UIView* view;

@property (nonatomic, strong) IBOutlet iCarousel *carousel;
@property (nonatomic, strong) NSArray * carouselData;
@property (nonatomic, strong) NSMutableDictionary * imagesCache;

@property (nonatomic, strong) NSDictionary* notificationData;
@property DYNotificationType notifiationType;


-(void)didReceiveNotification:(UNNotification *)notification withView:(UIView*)view API_AVAILABLE(ios(10.0));
- (void)didReceiveNotificationResponse:(UNNotificationResponse *)response completionHandler:(void (^)(UNNotificationContentExtensionResponseOption option))completion  API_AVAILABLE(ios(10.0));
@end

