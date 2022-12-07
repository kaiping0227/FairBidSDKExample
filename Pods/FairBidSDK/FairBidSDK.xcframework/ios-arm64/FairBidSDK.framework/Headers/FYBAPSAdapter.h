//
//
// Copyright (c) 2022 Fyber. All rights reserved.
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol FYBAPSSlotLoader <NSObject>

@optional

- (void)loadAPSBannerSlot:(NSString *)slotUUID width:(NSInteger)width height:(NSInteger)height;

- (void)loadAPSInterstitialSlot:(NSString *)slotUUID;

- (void)loadAPSRewardedSlot:(NSString *)slotUUID;

@end

@interface FYBAPSAdapter : NSObject

@property (nonatomic, strong, nullable) id<FYBAPSSlotLoader> slotLoader;

- (void)setBidInfo:(nonnull NSString*)bidInfo encodedPricePoint:(nonnull NSString*)encodedPricePoint slotUUID:(nonnull NSString*)slotUUID;

@end

NS_ASSUME_NONNULL_END
