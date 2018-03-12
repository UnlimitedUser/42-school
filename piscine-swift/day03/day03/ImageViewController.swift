//
//  ImageViewController.swift
//  day03
//
//  Created by Dan Sclearov on 4/20/17.
//  Copyright © 2017 None. All rights reserved.
//

import UIKit

class ImageViewController: UIViewController, UIScrollViewDelegate {

    var imageView: UIImageView?
    var image: UIImage?
    @IBOutlet weak var scrollView: UIScrollView!
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.imageView = UIImageView(image: self.image)
        scrollView.addSubview(self.imageView!)
        scrollView?.contentSize = (self.imageView?.frame.size)!
        scrollView.minimumZoomScale = 0.1
        scrollView.maximumZoomScale = 100.0
        scrollView.delegate = self
        // Do any additional setup after loading the view.
    }
    
//    override func viewDidLayoutSubviews() {
//        scrollView?.minimumZoomScale = scrollView.bounds.width / (self.imageView?.bounds.width)!
//    }
//    
    func viewForZooming(in scrollView: UIScrollView) -> UIView? {
        return imageView
    }
    
    
    
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
