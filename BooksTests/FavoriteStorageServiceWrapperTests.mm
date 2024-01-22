//
//  FavoriteStorageServiceWrapperTests.m
//  BooksTests
//
//  Created by Matheus dos Reis de Jesus on 18/01/24.
//

#import <XCTest/XCTest.h>
#import "Storage/Favorites/FavoriteStorageServiceWrapper.h"

@interface FavoriteStorageServiceWrapperTests : XCTestCase {
}
@end

@implementation FavoriteStorageServiceWrapperTests

static FavoriteStorageServiceWrapper* service;

+ (void)setUp {
    service = [[FavoriteStorageServiceWrapper alloc] initWithPath: NSTemporaryDirectory()];
}

- (void)testRetrieveNonExistingFavorite {

    XCTAssertFalse([service getFavoriteWithId:@"123"], @"Favorite not present");
    [service saveFavoriteWithId:@"123"];
    XCTAssertTrue([service getFavoriteWithId:@"123"], @"Favorite is present");
}

- (void)testSaveAndRetrieveFavorite {
    [service saveFavoriteWithId:@"456"];
    XCTAssertTrue([service getFavoriteWithId:@"456"], @"Favorite is present");
}

- (void)testSaveMultipleFavorites {
    [service saveFavoriteWithId:@"123"];
    [service saveFavoriteWithId:@"456"];
    [service saveFavoriteWithId:@"789"];
    XCTAssertEqual([[service getAllFavorites] count], 3, @"Favorite is present");
}

- (void)testSaveAndRemoveFavorite {
    [service saveFavoriteWithId:@"123"];
    XCTAssertTrue([service getFavoriteWithId:@"123"], @"Favorite is present");
    [service removeFavoriteWithId:@"123"];
    XCTAssertFalse([service getFavoriteWithId:@"123"], @"Favorite is not present");
}

- (void)tearDown {
    [service removeAllFavorites];
}

@end
