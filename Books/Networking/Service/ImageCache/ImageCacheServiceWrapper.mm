//
//  ImageCacheService.m
//  Books
//
//  Created by Matheus dos Reis de Jesus on 21/01/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ImageCacheServiceWrapper.h"
#import "Networking/ImageCacheService/ImageCacheService.h"

@interface ImageCacheServiceWrapper () {
    Networking::ImageCacheService* service;
}

@end

@implementation ImageCacheServiceWrapper

static ImageCacheServiceWrapper* sharedInstance = nil;

-(instancetype)init {
    self = [ImageCacheServiceWrapper alloc];

    if(!self) {
        return nil;
    }

    Networking::NetworkProvider* provider = new Networking::NetworkProvider("");
    self->service = new Networking::ImageCacheService(provider);

    return self;
}

+ (instancetype)shared {
    @synchronized([ImageCacheServiceWrapper class]) {
        if (!sharedInstance)
            sharedInstance = [[self alloc] init];
        return sharedInstance;
    }
    return nil;
}

- (void)fetchImageWithUrl:(NSString *)url completion:(void (^)(UIImage*))block {
    std::string imageUrl = [url UTF8String];

    dispatch_async(dispatch_get_global_queue(0,0), ^{

        std::string result = self->service->getValue(imageUrl);

        NSData* data = [NSData dataWithBytes: result.data()
                                      length: result.length()];

        UIImage* image = [UIImage imageWithData:data];

        dispatch_async(dispatch_get_main_queue(), ^{
            block(image);
        });
    });
}

@end
