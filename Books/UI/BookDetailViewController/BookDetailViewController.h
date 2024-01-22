//
//  BookDetailViewController.h
//  Books
//
//  Created by Matheus dos Reis de Jesus on 21/01/24.
//

#ifndef BookDetailViewController_h
#define BookDetailViewController_h

#import "UIKit/UIKit.h"
#import "BookModel.h"

@interface BookDetailViewController : UIViewController {
    BookModel* book;
}

- (void)setModel:(BookModel*)model;

@end

#endif /* BookDetailViewController_h */
