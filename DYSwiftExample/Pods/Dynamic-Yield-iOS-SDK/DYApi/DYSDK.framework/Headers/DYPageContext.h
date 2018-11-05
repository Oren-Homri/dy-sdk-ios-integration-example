//
//  DYPageContext.h
//  DYApi
//
//  Created by Idan Oshri on 12/01/2016.
//  Copyright © 2016 Dynamic Yield. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    DY_TYPE_HOMEPAGE,
    DY_TYPE_CATEGORY,
    DY_TYPE_PRODUCT,
    DY_TYPE_CART,
    DY_TYPE_POST,
    DY_TYPE_EMAIL,
    DY_TYPE_SEARCH,
    DY_TYPE_OTHER,
    
    
} contextType;

/*!
 *  A helper class storing the screen’s context attributes
 */

@interface DYPageContext : NSObject

@property (strong,nonatomic) NSString* language;
@property (strong,nonatomic) NSArray* data;
@property contextType type;

-(NSDictionary* _Nonnull)getAsDictinary;
-(NSString* _Nonnull)convertDYContextTypeToString;
-(contextType)convertStringToDYContextType:(NSString* _Nonnull)context;
@end
