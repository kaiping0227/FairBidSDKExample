//
//
// Copyright (c) 2020 Fyber. All rights reserved.
//
//

#ifndef FYBBannerOptions_h
#define FYBBannerOptions_h
#import <UIKit/UIKit.h>
#import <FairBidSDK/FYBBannerSize.h>

/**
 *  Locations where FairBid SDK can automatically place the banner.
 */
typedef NS_ENUM(NSUInteger, FYBBannerAdViewPosition) {
    /**
     *  Option for placing the banner at the top of the view.
     */
    FYBBannerAdViewPositionTop,
    /**
     *  Option for placing the banner at the bottom of the view.
     */
    FYBBannerAdViewPositionBottom
};


/**
 *  Options to present banners for a placement in a view controller.
 */
@interface FYBBannerOptions : NSObject

/**
 *  The view controller to present the ad from. 
 *
 *  This property is optional. If not set, it defaults to the root view controller of the application.
 *
 *  @note Setting this property doesn't change where the actual banner (a `UIView`) is placed. For Fyber banners, the width of this property will determine the width of a flexible-width banner.
 */
@property (nonatomic, weak, nullable) UIViewController *presentingViewController;

/**
 *  The identifier of the placement to be shown.
 */
@property (nonatomic, copy, nonnull) NSString *placementId;

/**
 *  The  position of the banner to be shown.
 */
@property (nonatomic, assign) FYBBannerAdViewPosition position;

/**
 *  The size of the banner to be shown.
 */
@property (nonatomic, assign) FYBBannerSize size;

NS_ASSUME_NONNULL_BEGIN

/**
 @deprecated Deprecated in v3.31.0.
 */
- (instancetype)init __attribute__((deprecated("Deprecated in v3.31.0")));

- (instancetype)initWithPlacementId:(NSString *)placementId;

- (instancetype)initWithPlacementId:(NSString *)placementId position:(FYBBannerAdViewPosition)position;

- (instancetype)initWithPlacementId:(NSString *)placementId size:(FYBBannerSize)size;

@end

NS_ASSUME_NONNULL_END

#endif
