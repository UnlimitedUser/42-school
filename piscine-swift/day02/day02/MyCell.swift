//
//  MyCell.swift
//  DeathNote
//
//  Created by luc Casimir on 06/10/2016.
//  Copyright © 2016 Piscine_Swift_42. All rights reserved.
//

import UIKit

class MyCell: UITableViewCell {
    @IBOutlet var dateLabel: UILabel!
    @IBOutlet var nameLabel: UILabel!
    @IBOutlet var descriptionLabel: UILabel!
    
    
    var a: Victim? {
        didSet {
            if let v = a {
                let date = DateFormatter()
                date.dateStyle = .medium
                nameLabel?.text = v.name
                dateLabel?.text = date.string(from: v.date as Date)
                descriptionLabel?.text = v.death
            }
        }
    }
}
