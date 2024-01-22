//
//  FavoriteStorageServiceWrapper.m
//  Books
//
//  Created by Matheus dos Reis de Jesus on 21/01/24.
//

#import <Foundation/Foundation.h>
#import "Storage/Favorites/FavoriteStorageService.h"
#import "FavoriteStorageServiceWrapper.h"

@interface FavoriteStorageServiceWrapper () {
    Storage::FavoriteStorageService* service;
}

@end

@implementation FavoriteStorageServiceWrapper

static FavoriteStorageServiceWrapper* sharedInstance = nil;

-(instancetype)init {
    self = [super init];

    if(!self) return nil;
    
    NSString* baseDir = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,
    NSUserDomainMask, YES)[0];
    NSString* databasePath = [[NSString alloc] initWithString: [baseDir
                                                               stringByAppendingPathComponent:@"books.sqlite"]];

    service = new Storage::FavoriteStorageService([databasePath UTF8String]);
    return self;
}

-(instancetype)initWithPath:(NSString*)path {
    self = [super init];

    if(!self) return nil;

    NSString* databasePath = [[NSString alloc] initWithString: [path stringByAppendingPathComponent:@"books.sqlite"]];

    service = new Storage::FavoriteStorageService([databasePath UTF8String]);

    return self;
}

+ (instancetype)shared {
    @synchronized([FavoriteStorageServiceWrapper class]) {
        if (!sharedInstance)
            sharedInstance = [[self alloc] init];
        return sharedInstance;
    }
    return nil;
}

- (NSArray<NSString*>*)getAllFavorites {
    std::vector<std::string> response = service->getAllFavorites();

    NSMutableArray<NSString*>* favorites = [[NSMutableArray alloc] init];
    for(int i = 0; i < response.size(); i++) {
        [favorites addObject: [NSString stringWithUTF8String: response[i].c_str()]];
    }

    return favorites;
}

- (bool)removeAllFavorites {
    return service->removeAllFavorites();
}

- (bool)getFavoriteWithId:(NSString *)id {
    std::string parsedId = [id UTF8String];
    return service->isFavorite(parsedId);
}

- (bool)removeFavoriteWithId:(NSString *)id {
    std::string parsedId = [id UTF8String];
    return service->removeFavorite(parsedId);
}

- (bool)saveFavoriteWithId:(NSString *)id {
    std::string parsedId = [id UTF8String];
    return service->saveFavorite(parsedId);
}

@end
