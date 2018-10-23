//
//  DYIdentify.h
//  DYApi
//
//  Created by Idan Oshri on 1/6/15.
//  Copyright (c) 2015 Dynamic Yield. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 * @header DYIdentify.h
 * @discussion A helper class to identify the user
 *
 */

@interface DYUserData : NSObject


/*!
 *  Allocate and init a new instance
 *
 *  @return DYIdentify instance
 */

+(DYUserData* _Nonnull)create;

/*!
 *  @brief The user's Email
 */
@property (strong,atomic) NSString* _Nullable email;


/*!
 * @brief generic CUID
 */

@property (strong,atomic) NSString* _Nullable cuid;

/*!
 * @brief generic CUID type
 */

@property (strong,atomic) NSString* _Nullable cuidType;

/*!
 * @brief user identifier
 */

@property (strong,atomic) NSString* _Nullable externalUserID;

-(NSDictionary* _Nonnull)getParamsAsDic;

@end
