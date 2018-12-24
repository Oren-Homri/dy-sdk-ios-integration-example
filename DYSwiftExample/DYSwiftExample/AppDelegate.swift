//
//  AppDelegate.swift
//  DYSwiftExample
//
//  Created by Idan Oshri on 04/11/2018.
//  Copyright © 2018 Dynamic Yield. All rights reserved.
//

import UIKit
import DYSDK

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {
    
    var window: UIWindow?
    let DY_SECRET_KEY : String = "b6df3017865af94dc9408580"
    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        DYApi.getInstance().setSecretKey(DY_SECRET_KEY);
        let remoteNotif = launchOptions?[UIApplication.LaunchOptionsKey.remoteNotification] as? [String: Any]
        if remoteNotif != nil {
            DYNotificationTrack.trackClicked(remoteNotif);
        }
        
        return true
    }
    
    func application(_ app: UIApplication, open url: URL, options: [UIApplication.OpenURLOptionsKey : Any] = [:]) -> Bool {
        print("DYSwiftExample openURL: " + url.description);
        
        return true;
    }
    
    func application(_ application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
        DYApi.getInstance().setPushNotificationID(deviceToken);
    }
    
    func application(_ application: UIApplication, didReceiveRemoteNotification userInfo: [AnyHashable : Any], fetchCompletionHandler completionHandler: @escaping (UIBackgroundFetchResult) -> Void) {
        DYNotificationTrack.application(application, didReceiveRemoteNotification: userInfo, fetchCompletionHandler: completionHandler);
    }
    
    func application(_ application: UIApplication, didReceiveRemoteNotification userInfo: [AnyHashable : Any]) {        
        DYNotificationTrack.application(application, didReceiveRemoteNotification: userInfo, fetchCompletionHandler: nil);
    }
    
}

