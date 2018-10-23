//
//  DYNotificationTrack.h
//  ServiceExtention
//
//  Created by Idan Oshri on 23/11/2017.
//  Copyright © 2017 dynamicyield. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "DYLogger.h"

typedef enum {
    DY_IMP,
    DY_CLICK
} trackingType;

@interface DYNotificationTrack : NSObject

+(void)trackDelivered:(NSDictionary*)userInfo;
+(void)trackClicked:(NSDictionary*)userInfo;

@end
