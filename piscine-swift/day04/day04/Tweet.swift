//
//  tweet.swift
//  day04
//
//  Created by Dan Sclearov on 4/21/17.
//  Copyright © 2017 None. All rights reserved.
//

import Foundation

struct Tweet: CustomStringConvertible {
    
    let name: String
    let text: String
    let date: String
    
    var description: String {
        return "\(text), by \(name)"
    }
    
}
