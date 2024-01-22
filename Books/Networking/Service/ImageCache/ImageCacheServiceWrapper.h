//
//  ImageCacheService.h
//  Books
//
//  Created by Matheus dos Reis de Jesus on 21/01/24.
//

#ifndef ImageCacheServiceWrapper_h
#define ImageCacheServiceWrapper_h

#import <UIKit/UIKit.h>

@interface ImageCacheServiceWrapper: NSObject

+ (instancetype)shared;

- (void)fetchImageWithUrl:(NSString*)url completion:(void (^)(UIImage*))block;

@end

#endif /* ImageCacheServiceWrapper_h */
