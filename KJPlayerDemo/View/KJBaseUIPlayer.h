//
//  KJBaseUIPlayer.h
//  KJPlayerDemo
//
//  Created by 杨科军 on 2021/2/16.
//  Copyright © 2021 杨科军. All rights reserved.
//  https://github.com/yangKJ/KJPlayerDemo
//  播放器UI协议

#import "KJBasePlayerView.h"
#import "KJPlayerType.h"
#import "KJPlayerLoadingLayer.h"
#import "KJPlayerHintTextLayer.h"

@protocol KJBaseUIPlayer <NSObject>
@required
/* 播放器载体 */
@property (nonatomic,strong) KJBasePlayerView *playerView;
/* 占位图 */
@property (nonatomic,strong) UIImage *placeholder;
/* 加载动画层 */
@property (nonatomic,strong,readonly) KJPlayerLoadingLayer *loadingLayer;
/* 文本提示框 */
@property (nonatomic,strong,readonly) KJPlayerHintTextLayer *hintTextLayer;
/* 背景颜色，默认黑色 */
@property (nonatomic,assign) CGColorRef background;
/* 视频显示模式，默认KJPlayerVideoGravityResizeAspect */
@property (nonatomic,assign) KJPlayerVideoGravity videoGravity;
/* 获取视频尺寸大小 */
@property (nonatomic,copy,readwrite) void (^kVideoSize)(CGSize size);
/* 提示文字面板属性，默认最大宽度250px */
@property (nonatomic,copy,readonly) void (^kVideoHintTextProperty)(CGFloat maxWidth, UIColor *background, UIColor *textColor, UIFont *font);
/* 获取当前截屏 */
@property (nonatomic,copy,readonly) void (^kVideoTimeScreenshots)(void(^)(UIImage *image));

#pragma mark - method
/* 圆圈加载动画 */
- (void)kj_startAnimation;
/* 停止动画 */
- (void)kj_stopAnimation;
/* 列表上播放绑定tableView */
- (void)kj_bindTableView:(UITableView*)tableView indexPath:(NSIndexPath*)indexPath;
/* 支持富文本提示的文本框，零秒表示不自动消失 */
- (void)kj_displayHintText:(id)text;
- (void)kj_displayHintText:(id)text max:(float)max;
- (void)kj_displayHintText:(id)text position:(id)position;
- (void)kj_displayHintText:(id)text time:(NSTimeInterval)time;
- (void)kj_displayHintText:(id)text time:(NSTimeInterval)time position:(id)position;
- (void)kj_displayHintText:(id)text time:(NSTimeInterval)time max:(float)max position:(id)position;
/* 隐藏提示文字 */
- (void)kj_hideHintText;

@end

// UI公共ivar
#define PLAYER_COMMON_UI_PROPERTY \
@synthesize loadingLayer = _loadingLayer;\
@synthesize hintTextLayer = _hintTextLayer;\
@synthesize playerView = _playerView;\
@synthesize placeholder = _placeholder;\
@synthesize background = _background;\
@synthesize videoGravity = _videoGravity;\
@synthesize kVideoTimeScreenshots = _kVideoTimeScreenshots;\
@synthesize kVideoSize = _kVideoSize;\
@dynamic kVideoHintTextProperty;\
