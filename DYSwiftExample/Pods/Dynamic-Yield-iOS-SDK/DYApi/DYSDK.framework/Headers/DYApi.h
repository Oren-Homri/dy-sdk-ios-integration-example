//
//  DYApi.h
//  DYApi
//
//  Created by Idan Oshri on 14/D/14.
//  Copyright (c) 2014 Dynamic Yield. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DYUserData.h"
#import "DYDelegate.h"
#import <UIKit/UIKit.h>
#import "DYPageContext.h"
#import <UserNotifications/UserNotifications.h>
#import <UserNotificationsUI/UserNotificationsUI.h>
#import <MobileCoreServices/MobileCoreServices.h>

/*!
 * @header DYApi.h
 * @discussion Dynamic Yield API
 *
 */

@interface DYApi : NSObject

/*!
 *  Main method, gets the shared instance of the SDK
 *
 *  @return DYApi shared instance
 */
+(DYApi* _Nonnull)getInstance ;

/*!
 *  Set an delegate object to receive notifications from DYApi
 *
 *  @param delegate - The delegate object
 *
 *  @return Yes if the object is OK
 */
-(BOOL)setDelegate:(id<DYDelegateProtocol> _Nonnull)delegate;

/*!
 *  A flag to toggle the use of the european server
 *
 *  @param on - YES/NO
 *
 */

-(void)setUseEuropeanServer:(BOOL)on;

/*!
 *  Sets the identifier in order to log the data
 *
 *  @param secret - String key, can be created in the Admin screen
 *
 *  @return Yes if the secret is not nil or empty
 */
-(BOOL)setSecretKey:(NSString* _Nonnull)secret;

/*!
 *  Help identify the user in a cross platform world
 *
 *  @param userAttributes - DYIdentify type,
 *  Holds the basic identifiers
 *
 *  @return Yes if the identifiers is not nil or empty
 */
-(BOOL)identifyUser:(DYUserData* _Nonnull)userAttributes;

/*!
 *  Sends an event to the database.
 *
 *  @param name  -f unique event name
 *  @param props - a key/value properties to add to the event
 *
 *  @return Yes if the name and props is not nil or empty
 */

-(BOOL)trackEvent:(NSString* _Nonnull)name prop:(NSDictionary* _Nullable)props;

/*!
 *  sends a page view event to the database.
 *
 *  @param uniqueID - unique identifier of the page
 *  @param name - display name of the page
 *  @param section - the section that hold the page - can be nil
 *  @param DYContext - optional page context
 
 *  @return Yes if the uniqueID and name is not nil or empty
 */

-(BOOL)pageView:(NSString* _Nonnull)uniqueID name:(NSString* _Nonnull)name section:(NSString* _Nullable)section context:(DYPageContext* _Nullable)DYContext;

/*!
 *  sends a page view event to the database.
 *
 *  @param uniqueID - unique identifier of the page
 *  @param DYContext - optional page context
 
 *  @return Yes if the uniqueID and name is not nil or empty
 */

-(BOOL)pageView:(NSString* _Nonnull)uniqueID context:(DYPageContext* _Nullable)DYContext;

/*!
 *  returns the audiences that the user belongs to
 *
 *  @return Array of Audiences OR Null if no audience available
 */
-(NSArray* _Nullable)getUserAudiences;

/*!
 *
 *  Returns the value assigned to a variable name specified
 *
 * @param varName - The name of the variable as maintained in the Dynamic Yield Admin Console
 * @param defaultValue - The value that should be assigned to the variable in case no value is returned
 *
 * @return the value of the smartVariable
 */

-(id _Nonnull)getSmartVariable:(NSString* _Nonnull)varName defaultValue:(id _Nullable)defaultValue;

/*!
 *  Selects an HTML variation from the defined smart object and then assigns it
 * to the defined webview container; returns YES if the input parameters are valid. If
 * parameter fallBackURL is maintained, the HTML content will be assigned in case no
 * variation is returned from the Dynamic Yield server.
 * Use delegate <delegate name> to respond to no returned results manually.
 *
 *  @param webView    the webView to load
 *  @param smartObjID The smartObjectID
 *
 *  @return Yes if the params are not nil or empty
 */


-(BOOL)loadWebView:(UIWebView* _Nullable)webView withSmartObject:(id _Nonnull)smartObjID fallbackURL:(NSURL* _Nullable)fallBackURL;

/*!
 *  Selects an Image template variation from the defined smart object and then assigns it
 * to the defined imageview container; returns YES if the input parameters are valid. If
 * parameter fallBackURL is maintained, the URL content will be assigned in case no
 * variation is returned from the Dynamic Yield server.
 * Use delegate <delegate name> to respond to no returned results manually.
 *
 *  @param imageView    the imageView to load
 *  @param smartObjID The smartObjectID
 *
 *  @return Yes if the params are not nil or empty
 */

-(BOOL)loadImageView:(UIImageView* _Nullable)imageView withSmartObject:(id _Nonnull)smartObjID fallbackURL:(NSURL* _Nullable)fallBackURL;


-(NSDictionary* _Nullable)getSmartObjectData:(id _Nonnull)smartObjectID;

/*!
 *  Get the recommended items for a given widget id in a specified context. The results are returned via the delegate.
 *
 *  @param widgetID - The recommendation widget ID as maintained in the Dynamic Yield admin console
 *  @param context - The current screen’s context
 *  @param itemsIDsOnly - Used to request only the recommended item’s identifiers (without additional item metadata).
 *  @param rcomDelegate - A delegate that receives the results and handles the recommended items presentation
 *
 *  @return Yes if the params are not nil or empty
 */

-(BOOL)sendRecommendationRequest:(NSString* _Nonnull)widgetID withContext:(DYPageContext* _Nonnull)context itemsIDsOnly:(BOOL)itemsIDsOnly andDelegate:(id<DYRecommendationsDelegate> _Nonnull)rcomDelegate;


-(BOOL)sendRecommendationRequest:(NSString* _Nonnull)widgetID withContext:(DYPageContext* _Nonnull)context itemsIDsOnly:(BOOL)itemsIDsOnly pageNumber:(int)pageNumber pageSize:(int)pageSize andDelegate:(id<DYRecommendationsDelegate> _Nonnull)rcomDelegate;


/*!
 *  Sets the current user’s affinity attributes with key value pairs where the keys are product attributes and the value are the attribute value. 
 *
 *  @param affinities - Key value pairs where the keys are product attributes and the value are the attribute values
 *
 *  @return Yes if the params are not nil or empty
 */

-(BOOL)setRecommendationAffinities:(NSDictionary* _Nonnull)affinities;


/*!
 *  Reports a list of recommended items real impressions (i.e. were visible to user) within a given recommendation widget to the Dynamic Yield server.
 *
 *  @param widgetID - The recommendation widget ID used for receiving the recommendations items presented to the user
 *  @param itemIDs - An array of identifiers of recommendation items presented to the user
 *
 *  @return Yes if the params are not nil or empty
 */
-(BOOL)TrackRecomItemsRealImpression:(NSString* _Nonnull)widgetID andItemID:(NSArray* _Nonnull)itemIDs;

/*!
 *  Reports the identifier of a recommended item tapped by the user within a given recommendation widget to the Dynamic Yield server. Returns YES if the input parameters are valid.
 *
 *  @param widgetID - The recommendation widget ID used for receiving the recommendations items presented to the user
 *  @param itemID - The identifier of a recommendation items tapped by the user
 *
 *  @return Yes if the params are not nil or empty
 */

-(BOOL)TrackRecomItemClick:(NSString* _Nonnull)widgetID andItemID:(NSString* _Nonnull)itemID;


/*!
 *  Sets the Evaluator value
 *
 *  @param evaluatorID - the ID (not display name) of the evaluator
 *  @param params - the value of the evaluator
 *
 *  @return Yes if evaluatorID is not nil or empty
 */

-(BOOL)setEvaluator:(NSString* _Nonnull)evaluatorID forParams:(NSArray* _Nonnull)params;

/*!
 *  Sets the Evaluator value
 *
 *  @param evaluatorID - the ID (not display name) of the evaluator
 *  @param params - the value of the evaluator
 *  @param save - Yes to save evaluator between sessions, No otherwise
 *
 *  @return Yes if evaluatorID is not nil or empty
 */
-(BOOL)setEvaluator:(NSString* _Nonnull)evaluatorID forParams:(NSArray* _Nonnull)params saveBetweenSessions:(BOOL)save;

/*!
 *  Sets the Evaluator value
 *
 *  @param evaluatorID - the ID (not display name) of the evaluator
 *  @param params - the value of the evaluator
 *  @param save - Yes to save evaluator between sessions, No otherwise
 *  @param completionHandler - Code to be excuted when the evaluator is set
 *
 *  @return Yes if evaluatorID is not nil or empty
 */
-(BOOL)setEvaluator:(NSString* _Nonnull)evaluatorID forParams:(NSArray* _Nonnull)params saveBetweenSessions:(BOOL)save completion:(void(^)(void))completionHandler;


/*!
 * Activates developer mode enabling advanced
 * logging and debugging of the content and flow
 *
 * @param enable - True/False to show logs
 */

-(void)enableDeveloperLogs:(BOOL)enable;

-(NSDictionary* _Nullable)getUserAffinityProfile:(BOOL)normalizedScores;

-(NSString* _Nullable)getDYID;

//DYNotification

-(void)registerForPushNotifications;

-(BOOL)setPushNotificationID:(NSData* _Nonnull)pushID;

-(BOOL)subscribeToPushNotifications;

-(BOOL)unsubscribeFromPushNotifications;

///

-(BOOL)getProductActivityData:(NSArray* _Nonnull)skus timeframe:(NSArray* _Nullable)time includeProductInterest:(NSString* _Nullable)interest includeProductData:(BOOL)includeData andDelegate:(id<DYProductActivityDataDelegate> _Nonnull)delegate;

-(void)consentOptout;
-(void)consentOptin;

@end
