//
//  KJPlayerTool.h
//  KJPlayerDemo
//
//  Created by 杨科军 on 2019/7/21.
//  Copyright © 2019 杨科军. All rights reserved.
//  播放器的相关工具

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface KJPlayerTool : NSObject

/// 判断是否含有视频轨道（判断视频是否可以正常播放）
+ (BOOL)kj_playerHaveTracksWithURL:(NSURL*)url;

/// 判断是否是URL
+ (BOOL)kj_playerIsURL:(NSURL*)url;

/// 判断URL地址是否可用
+ (void)kj_playerValidateUrl:(NSURL*)url CompletionHandler:(void(^)(BOOL success))completionHandler;

/// MD5加密
+ (NSString*)kj_playerMD5WithString:(NSString*)string;

/// 根据 URL 得到完整路径
+ (NSString*)kj_playerGetIntegrityPathWithUrl:(NSURL*)url;

/// 判断存放视频的文件夹是否存在，不存在则创建对应文件夹
+ (BOOL)kj_playerCreateFileDirectoriesWithPath:(NSString*)path;

// 获取视频第一帧图片和视频总时长
+ (NSArray*)kj_playerFristImageWithURL:(NSURL*)url;

@end

NS_ASSUME_NONNULL_END
