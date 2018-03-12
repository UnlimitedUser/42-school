//
//  ViewController.swift
//  day00
//
//  Created by Dan Sclearov on 4/17/17.
//  Copyright © 2017 None. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet weak var Label: UILabel!
    
    var op = ""
    var l = 0.0
    var r = 0.0
    var onp = false
    
    @IBAction func one(_ sender: UIButton) {
        if Label!.text! == "0" || onp {
            Label!.text! = sender.titleLabel!.text!
            if !onp {
                l = Double(Label!.text!)!
            }
            onp = false
        }
        else {
            Label!.text! += sender.titleLabel!.text!
        }
    }
    
    func ch(_ sum: Double) {
        var s = String(sum)
        if s.range(of:".0") != nil {
            s = s.substring(to: s.index(s.endIndex, offsetBy: -2))
        }
        Label!.text! = s
    }
    
    @IBAction func op(_ sender: UIButton) {
        if Label!.text! == "Error" {
            Label!.text! = "0"
        }
        r = Double(Label!.text!)!
        onp = true
        if sender.titleLabel!.text! == "=" {
            switch op {
            case "+":
                ch(l + r)
            case "-":
                ch(l - r)
            case "*":
                ch(l * r)
            case "/":
                if r != 0.0 {
                    ch(l / r)
                }
                else {
                    Label!.text! = "Error"
                }
            default:
                Label!.text! = "0"
            }
        }
        if Label!.text! != "Error" {
            l = Double(Label!.text!)!
        }
        else {
            l = 0
        }
        op = sender.titleLabel!.text!
    }
    
    @IBAction func neg(_ sender: UIButton) {
        if Label!.text![Label!.text!.startIndex] == "-" {
            Label!.text! = Label!.text!.substring(from: Label!.text!.index(Label!.text!.startIndex, offsetBy: 1))
        }
        else {
            Label!.text! = "-" + Label!.text!
        }
    }
    
    @IBAction func ac(_ sender: UIButton) {
        Label!.text! = "0"
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
}

