//
//  FavoriteStorageServiceWrapper.h
//  Books
//
//  Created by Matheus dos Reis de Jesus on 21/01/24.
//

#ifndef FavoriteStorageServiceWrapper_h
#define FavoriteStorageServiceWrapper_h

@interface FavoriteStorageServiceWrapper: NSObject

+ (instancetype)shared;

-(instancetype)init;
-(instancetype)initWithPath:(NSString*)path;
-(NSArray<NSString*>*)getAllFavorites;
-(bool)saveFavoriteWithId:(NSString*)id;
-(bool)removeFavoriteWithId:(NSString*)id;
-(bool)getFavoriteWithId:(NSString*)id;
-(bool)removeAllFavorites;

@end

#endif /* FavoriteStorageServiceWrapper_h */
