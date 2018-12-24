//
//  NotificationService.swift
//  DYServiceExtension
//
//  Created by Idan Oshri on 18/12/2018.
//  Copyright © 2018 Dynamic Yield. All rights reserved.
//

import UserNotifications
import DYSDK

class NotificationService: UNNotificationServiceExtension {

    var dyService = DYNotificationService();
    var contentHandler: ((UNNotificationContent) -> Void)?
    var bestAttemptContent: UNMutableNotificationContent?

    override func didReceive(_ request: UNNotificationRequest, withContentHandler contentHandler: @escaping (UNNotificationContent) -> Void) {
        self.contentHandler = contentHandler
        bestAttemptContent = (request.content.mutableCopy() as? UNMutableNotificationContent)
        
       
        dyService.didReceive(request, withContentHandler: contentHandler);
    }
    
    override func serviceExtensionTimeWillExpire() {
        // Called just before the extension will be terminated by the system.
        // Use this as an opportunity to deliver your "best attempt" at modified content, otherwise the original push payload will be used.
        if let contentHandler = contentHandler, let bestAttemptContent =  bestAttemptContent {
            contentHandler(bestAttemptContent)
        }
    }

}
