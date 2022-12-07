//
//  AppDelegate.swift
//  FairBidSDKExample
//
//  Created by Kai-ping Tseng on 06.12.22.
//

import UIKit
import FairBidSDK

@main
class AppDelegate: UIResponder, UIApplicationDelegate {

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        let options = FYBStartOptions()
        options.autoRequestingEnabled = false
        options.logLevel = .verbose

        FairBid.start(withAppId: "109613", options: options)
        return true
    }

}
