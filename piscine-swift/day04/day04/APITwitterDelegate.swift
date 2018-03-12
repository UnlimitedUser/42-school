//
//  APITwitterDelegate.swift
//  day04
//
//  Created by Dan Sclearov on 4/21/17.
//  Copyright © 2017 None. All rights reserved.
//

import Foundation

protocol APITwitterDelegate: class {
    
    func treatTheTweets(_ tweets: [Tweet])
    func error(_ error: NSError)
    
}
