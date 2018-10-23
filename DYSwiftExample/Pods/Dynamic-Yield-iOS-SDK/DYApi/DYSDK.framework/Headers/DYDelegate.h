//
//  DYDelegate.h
//  DYApi
//
//  Created by Idan Oshri on 2/24/15.
//  Copyright (c) 2015 Dynamic Yield. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#include <AvailabilityMacros.h>


typedef enum {
    DY_NOT_READY, //experiments are not ready to use
    DY_READY_LOCAL_CACHE, //experiments loaded from local cache
    DY_READY_AND_UPDATED, //experiments has been updated from the server and ready to use
    DY_READY_NO_UPDATE_NEEDED //experiments loaded from local cache and no more update is needed
} ExperimentsState;


typedef enum {
    DY_NOT_INITIALIZED,//no server call has been made
    DY_INIT_CALLED,// a server call has been sent
    DY_SECTION_INACTIVE,//the section is not active or the secret key is wrong
    DY_INIT_FAILED,// the server can't responde or an error has been received
    DY_INIT_OK// the server call succeeded
    
} InitReply;

/*!
 * @header DYDelegateProtocol.h
 * @discussion Dynamic Yield API's Delegate Object
 *
 */


@protocol DYDelegateProtocol <NSObject>

@optional

/*!
 *  Called after the server responded the init request
 *
 *  @param initStatus - the server result
 */
-(void)onInitReply:(InitReply)initStatus;


/*!
 *  Called when the experiments has been updated and ready to use
 *  DEPRECATED - use "experimentsReadyWithState:" instead.
 */

-(void)experimentsUpdatedAndReady;

/*!
 *  Called when the experiments has been updated and ready to use,
 *  with more explained state
 *  @param state - the experiments state
 *
 */
-(void)experimentsReadyWithState:(ExperimentsState)state;


/*!
 *  Called with the result of running a smart object experiments
 *
 *  @param smartObjID the smart object ID
 *  @param html       the HTML that returned (may be null)
 *  @param View       the View to load on 
 */

-(void)smartObject:(NSString* _Nonnull)smartObjID returned:(NSString* _Nonnull)html on:(UIView* _Nullable)View;



/*!
 *  This method is called after an Overlay or Custom Action has been triggered and a variation has
 * been selected by Dynamic Yield.  For Custom Actions the implementation of the method should
 * include the desired app manipulation based on the JSON data returned.  For Overlays where
 * ‘shouldDYRender’ was set to ‘false’, this method allows manipulation and 
 * custom rendering 8 based on the HTML data returned by Dynamic Yield.
 
 *  @param smartActionID - The Smart Action ID as maintained in the Dynamic Yield Admin Console
 *  @param smartActionData - The variation data as maintained in the Dynamic Yield Admin Console;
 * this can be either the Messaging Overlay HTML or the Custom Action JSON.
 */

-(void)onSmartAction:(NSString* _Nonnull)smartActionID returned:(NSDictionary* _Nonnull)smartActionData;

/*!
 *  This method is called just before the HTML Overlay content is rendered
 *  by Dynamic Yield and allows preventing its rendering.  The default value is ‘true’.
 *
 *  @param smartActionID - The Smart Action ID as maintained in the Dynamic Yield Admin Console
 */
 
-(BOOL)shouldDYRender:(NSString* _Nonnull)smartActionID;


@end



@protocol DYRecommendationsDelegate <NSObject>


/*!
 *  A delegate method called with the return of the recommendation results. This is where the rendering logic of the returned recommended items should take place. 
 *  The input parameter is an array of JSON objects, each item in the returned array includes the available metadata for every recommendation item.
 *
 *  @param recommendations - recommendations results from the server
 */

@required
-(void)onRecommendationResult:(NSArray* _Nullable)recommendations forWidgetID:(NSString* _Nonnull)widgetID;

@optional
-(void)onRecommendationResult:(NSArray* _Nullable)recommendations;

@end

@protocol DYProductActivityDataDelegate <NSObject>

/*!
 *  A delegate method called with the return of the product activity results.
 *  The input parameter is an array of JSON objects.
 *
 *  @param results - product activity results from the server
 */
-(void)onProductActivityDataResults:(NSDictionary* _Nullable)results;

@end
