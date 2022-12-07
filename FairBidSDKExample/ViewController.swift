//
//  ViewController.swift
//  FairBidSDKExample
//
//  Created by Kai-ping Tseng on 06.12.22.
//

import UIKit
import FairBidSDK

class ViewController: UIViewController {
    
    private let rewardedPlacementID = "197406"
    private let bannerPlacementID = "197407"
    
    @IBOutlet weak var rewardButton: UIButton!
    @IBOutlet weak var requestButton: UIButton!
    @IBOutlet weak var bannerView: UIView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        FYBBanner.delegate = self
        FYBRewarded.delegate = self
    }
    
    @IBAction func bannerButtonDidTap(_ sender: Any) {
        fetchingInProgress()
        let bannerOptions = FYBBannerOptions(placementId: bannerPlacementID, size: .smart)
        FYBBanner.show(in: bannerView, options: bannerOptions)
    }
    
    @IBAction func rewardButtonDidTap(_ sender: Any) {
        FYBRewarded.show(rewardedPlacementID)
    }

    @IBAction func requestButtonDidTap(_ sender: Any) {
        fetchingInProgress()
        FYBRewarded.request(rewardedPlacementID)
    }
    
    func fetchingInProgress() {
        requestButton.setTitleColor(.clear, for: .normal)
        requestButton.isEnabled = false
    }
    
    func adIsAvailable() {
        rewardButton.isEnabled = true
        requestButton.setTitleColor(.white, for: .normal)
        requestButton.isEnabled = false
    }
    
    func adDismissed() {
        requestButton.setTitleColor(.white, for: .normal)
        requestButton.isEnabled = true
        rewardButton.isEnabled = false
    }
}

extension ViewController: FYBRewardedDelegate {
    
    func rewardedIsAvailable(_ placementId: String) {
        adIsAvailable()
    }
    
    func rewardedDidDismiss(_ placementId: String) {
        adDismissed()
    }
    
}

extension ViewController: FYBBannerDelegate {
    func bannerDidLoad(_ banner: FYBBannerAdView) {
        adIsAvailable()
    }
}
