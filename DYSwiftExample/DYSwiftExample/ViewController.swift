//
//  ViewController.swift
//  DYSwiftExample
//
//  Created by Idan Oshri on 16/10/2018.
//  Copyright © 2018 Idan Oshri. All rights reserved.
//


import UIKit
import DYSDK


class ViewController: UIViewController,DYDelegateProtocol,DYRecommendationsDelegate {

    let DY_SECRET_KEY : String = YOUR_SECTION_SECRET_KEY
    let DY_WIDGET_ID : String = YOUR_WIDGET_ID
    let DY_CONTEXT : DYPageContext = DYPageContext.init();

    override func viewDidLoad() {
        super.viewDidLoad()

        //Init DYSDK
        DYApi.getInstance().setSecretKey(DY_SECRET_KEY);
        DYApi.getInstance().setDelegate(self);
        
        DY_CONTEXT.type = DY_TYPE_HOMEPAGE;
        

    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated);
        DYApi.getInstance().pageView("HomePage", context: DY_CONTEXT);
    }
    
    //DY ready delegate Method
    func experimentsReady(with state: ExperimentsState) {
        
        
        
        if (state == DY_READY_LOCAL_CACHE){
            //first call from local cache
            DYApi.getInstance().sendRecommendationRequest(DY_WIDGET_ID, with: DY_CONTEXT, itemsIDsOnly: false, andDelegate: self);
        }
        
        if (state == DY_READY_AND_UPDATED){
            //update the data if necessary
            DYApi.getInstance().sendRecommendationRequest(DY_WIDGET_ID, with: DY_CONTEXT, itemsIDsOnly: false, andDelegate: self);
        }
        
        if (state == DY_READY_NO_UPDATE_NEEDED){
            
        }
    }
    
    //DY Recom delegate method
    func onRecommendationResult(_ recommendations: [Any]?, forWidgetID widgetID: String) {
        print(String(format: "WidgetID %@ returned with data: %@", widgetID, recommendations?.description ?? "No data"));
    }
    
    //report results to DY
    func reportRecomItemRealImpression(skus : [String]) {
        DYApi.getInstance().trackRecomItemsRealImpression(DY_WIDGET_ID, andItemID: skus);
    }

    func reportRecomItemClicked(sku : String) {
        DYApi.getInstance().trackRecomItemClick(DY_WIDGET_ID, andItemID: sku);
    }
    
}

