//
//  FirstViewController.swift
//  DYSwiftExample
//
//  Created by Idan Oshri on 04/11/2018.
//  Copyright © 2018 Dynamic Yield. All rights reserved.
//

import UIKit
import BButton
import DYSDK

class DynamicContentController: DYBaseViewController {

    @IBOutlet weak var mImageButton: BButton!
    @IBOutlet weak var mWebButton: BButton!
    @IBOutlet weak var mImageView: UIImageView!
    @IBOutlet weak var mWebView: UIWebView!
    
    override func viewDidLoad() {
        super.viewDidLoad()

        DY_CONTEXT.type = DY_TYPE_HOMEPAGE;
        mPageName = "dynamicContent";

        mImageButton.setStyle(BButtonStyle.bootstrapV3);
        mImageButton.setType(BButtonType.facebook);

        mWebButton.setStyle(BButtonStyle.bootstrapV2);
        mWebButton.setType(BButtonType.facebook);

    }

    
   @IBAction func loadSmartObjectToImageView(_ sender: Any){
        DYApi.getInstance().load(mImageView, withSmartObject: "imageContent", fallbackURL:URL(string: "https://www.gstatic.com/webp/gallery/1.jpg"));
    }
    

    @IBAction func loadSmartObjectToWebView(_ sender: Any){
        DYApi.getInstance().load(mWebView, withSmartObject: "htmlContent", fallbackURL:URL(string: "https://www.gstatic.com/webp/gallery/1.jpg"));
    }
    
    

    
}

