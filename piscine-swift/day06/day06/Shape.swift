//
//  Shape.swift
//  day06
//
//  Created by Dan Sclearov on 4/27/17.
//  Copyright © 2017 None. All rights reserved.
//

import UIKit

class Shape: UIView {
    
    private func randomColor() -> UIColor {
        switch arc4random() % 6 + 1 {
        case 1:
            return UIColor.black
        case 2:
            return UIColor.cyan
        case 3:
            return UIColor.blue
        case 4:
            return UIColor.red
        case 5:
            return UIColor.green
        case 6:
            return UIColor.purple
        default:
            return UIColor.red
        }
    }
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        self.backgroundColor = randomColor()
        self.layer.cornerRadius = CGFloat((arc4random() % 2 == 0) ? 0 : 50)
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    /*
    // Only override draw() if you perform custom drawing.
    // An empty implementation adversely affects performance during animation.
    override func draw(_ rect: CGRect) {
        // Drawing code
    }
    */
    
    override var collisionBoundsType: UIDynamicItemCollisionBoundsType {
//        if circle {
            return .ellipse
//        }
//        return .rectangle
    }

}
