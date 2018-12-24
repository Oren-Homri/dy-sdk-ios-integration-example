//
//  NotificationViewController.swift
//  DYContentExtension
//
//  Created by Idan Oshri on 18/12/2018.
//  Copyright © 2018 Dynamic Yield. All rights reserved.
//

import UIKit
import UserNotifications
import UserNotificationsUI
import DYSDK


class NotificationViewController: UIViewController, UNNotificationContentExtension {

    var dyContent = DYNotificationContent();
    @IBOutlet var label: UILabel?
    
    override func viewDidLoad() {
        super.viewDidLoad()

    }
    
    func didReceive(_ notification: UNNotification) {
        dyContent.didReceive(notification, with: self.view);
    }

    func didReceive(_ response: UNNotificationResponse, completionHandler completion: @escaping (UNNotificationContentExtensionResponseOption) -> Void) {
        dyContent.didReceive(response, completionHandler: completion);
    }    
    
}
