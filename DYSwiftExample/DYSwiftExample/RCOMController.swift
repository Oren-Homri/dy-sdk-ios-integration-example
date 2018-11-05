//
//  SecondViewController.swift
//  DYSwiftExample
//
//  Created by Idan Oshri on 04/11/2018.
//  Copyright © 2018 Dynamic Yield. All rights reserved.
//

import UIKit
import DYSDK
import BButton

class RCOMController: DYBaseViewController,DYRecommendationsDelegate,UIScrollViewDelegate {
    
    
    @IBOutlet weak var mScrollView: UIScrollView!
    @IBOutlet weak var mTextView: UITextView!
    
    let DY_WIDGET_ID : String = "39593"
    var mImageWidth : CGFloat = 0;
    var mRcomData : [Any]? = nil;
    
    var mItemReported : Array<Bool> = [];
    
    @IBOutlet weak var mloadRcomButton: BButton!
    
    
    @IBAction func rcomButtonClicked(_ sender: Any) {
        
        //Requesting RCOM data
        DYApi.getInstance().sendRecommendationRequest(DY_WIDGET_ID, with: DY_CONTEXT, itemsIDsOnly: false, andDelegate: self);
        
    }
    
    func onRecommendationResult(_ recommendations: [Any]?, forWidgetID widgetID: String) {
        
        mRcomData = recommendations;
        mItemReported = Array<Bool>.init(repeating: false, count: mRcomData!.count);
        DispatchQueue.main.async() {
            
            self.mTextView.text = recommendations?.description;
            
            for i in 0 ..< recommendations!.count {
                if let item = recommendations![i] as? [String: Any] {
                    if let itemData = item["item"] as? [String: Any] {
                        let imageView = UIImageView()
                        let x = self.mImageWidth * CGFloat(i)
                        imageView.frame = CGRect(x: x, y: 0, width: self.mImageWidth, height: self.mScrollView.frame.height*0.9);
                        imageView.contentMode = .scaleAspectFit
                        
                        let tapGestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(self.imageTapped(tapGestureRecognizer:)))
                        imageView.isUserInteractionEnabled = true
                        imageView.addGestureRecognizer(tapGestureRecognizer)
                        imageView.tag = i;
                        
                        let url = itemData["image_url"] as? String;
                        self.downloadImage(from: URL(string: url!)!, imageView:imageView );
                        self.mScrollView.contentSize.width = self.mImageWidth * CGFloat(i + 1)
                        self.mScrollView.addSubview(imageView)
                    }
                }
            }
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        mImageWidth = self.mScrollView.frame.width/1.5;
        
        mloadRcomButton.setStyle(BButtonStyle.bootstrapV3);
        mloadRcomButton.setType(BButtonType.facebook);
        
        mScrollView.delegate = self;
        DY_CONTEXT.type = DY_TYPE_HOMEPAGE;
        mPageName = "rcom";
    }
    
    func scrollViewDidScroll(_ scrollView: UIScrollView) {
        
        var sku : String = "";
        var index : Int = 0;
        
        if (scrollView.contentOffset.x >= (scrollView.contentSize.width - scrollView.frame.size.width)){
            index = (mRcomData?.count)! - 1;
        } else {
            let rol_x = scrollView.contentOffset.x;
            index = Int(rol_x/mImageWidth);
        }
        
        if (!mItemReported[index]){
            sku = ((mRcomData![index] as? [String: Any])!["item"] as? [String: Any])!["sku"]! as! String
            
            //Tracking RCOM widget real impression
            DYApi.getInstance().trackRecomItemsRealImpression(DY_WIDGET_ID, andItemID:[sku]);
            mItemReported[index] = true;
        }
        
    }
    
    @objc func imageTapped(tapGestureRecognizer: UITapGestureRecognizer)
    {
        if let item = mRcomData![tapGestureRecognizer.view?.tag ?? 0] as? [String: Any] {
            if let itemData = item["item"] as? [String: Any] {
                let sku = itemData["sku"] as! String;
                
                //Tracking RCOM widget click
                DYApi.getInstance().trackRecomItemClick(DY_WIDGET_ID, andItemID: sku)
            }
        }
    }
    
    func downloadImage(from url: URL,imageView: UIImageView) {
        
        getData(from: url) { data, response, error in
            guard let data = data, error == nil else {
                print("error");
                return;
            }
            print(response?.suggestedFilename ?? url.lastPathComponent)
            
            DispatchQueue.main.async() {
                imageView.image = UIImage(data: data)
            }
        }
    }
    
    func getData(from url: URL, completion: @escaping (Data?, URLResponse?, Error?) -> ()) {
        URLSession.shared.dataTask(with: url, completionHandler: completion).resume()
    }
    
    
}

