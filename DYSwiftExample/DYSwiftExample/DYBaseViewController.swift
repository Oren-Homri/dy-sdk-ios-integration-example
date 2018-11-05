//
//  DYBaseViewController.swift
//  DYSwiftExample
//
//  Created by Idan Oshri on 04/11/2018.
//  Copyright © 2018 Dynamic Yield. All rights reserved.
//

import UIKit
import DYSDK
import SVProgressHUD

class DYBaseViewController: UIViewController,DYDelegateProtocol {
    
    let DY_CONTEXT : DYPageContext = DYPageContext.init();
    var mPageName = "";
    let mBlackView : UIView = UIView(frame: UIScreen.main.bounds);
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated);
        
        SVProgressHUD.show();
        
        mBlackView.backgroundColor = UIColor.black;
        mBlackView.alpha = 0.5;
        
        self.view.window!.addSubview(mBlackView);
        
        DYApi.getInstance().setDelegate(self);
        DYApi.getInstance().pageView(mPageName, context: DY_CONTEXT);
    }
    
    func experimentsReady(with state: ExperimentsState) {
        SVProgressHUD.dismiss();
        DispatchQueue.main.async() {
            self.mBlackView.removeFromSuperview();
        }
    }
    
    
}
