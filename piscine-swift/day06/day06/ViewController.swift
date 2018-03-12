//
//  ViewController.swift
//  day06
//
//  Created by Dan Sclearov on 4/27/17.
//  Copyright © 2017 None. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    let size = 100
    
    var gravityBehavior = UIGravityBehavior()
    var dynamicAnimator: UIDynamicAnimator!
    var collision = UICollisionBehavior()
    var dynamic = UIDynamicItemBehavior()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        dynamicAnimator = UIDynamicAnimator(referenceView: view)
        
        dynamic.allowsRotation = true
        dynamic.elasticity = 0.75
        
        gravityBehavior.magnitude = 0.5
        
        collision.translatesReferenceBoundsIntoBoundary = true
        
        dynamicAnimator.addBehavior(gravityBehavior)
        dynamicAnimator.addBehavior(collision)
        dynamicAnimator.addBehavior(dynamic)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
        
    }
    
    @IBAction func tapAction(_ sender: UITapGestureRecognizer) {
        print("tapped")
        let shape = Shape(frame: CGRect(x: CGFloat(sender.location(in: view).x - 50), y: CGFloat(sender.location(in: view).y - 50), width: 100, height: 100))
        
        collision.addItem(shape)
        dynamic.addItem(shape)
        gravityBehavior.addItem(shape)
        view.addSubview(shape)
    }
}

