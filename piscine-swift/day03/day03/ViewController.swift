//
//  ViewController.swift
//  day03
//
//  Created by Dan Sclearov on 4/20/17.
//  Copyright © 2017 None. All rights reserved.
//

import UIKit

class ViewController:  UIViewController, UICollectionViewDataSource, UICollectionViewDelegate {

    let reuseIdentifier = "cell" // also enter this string as the cell identifier in the storyboard
    var items: [String] = ["https://4.bp.blogspot.com/-k8IX2Mkf0Jo/U4ze2gNn7CI/AAAAAAAA7xg/iKxa6bYITDs/s0/HOT+Balloon+Trip_Ultra+HD.jpg", "https://s-media-cache-ak0.pinimg.com/originals/7e/80/01/7e80012f3e7abc6ae3744559788a3666.jpg", "https://4.bp.blogspot.com/-lYq2CzKT12k/VVR_atacIWI/AAAAAAABiwk/ZDXJa9dhUh8/s0/Convict_Lake_Autumn_View_uhd.jpg", "https://4.bp.blogspot.com/-BMmgkIkfTOM/UsF-F9q2qhI/AAAAAAAAcBc/x_waaNRX4co/s0/Winter+landscapes+from+Tirol+Ultra+HD.jpg","https://4.bp.blogspot.com/-k8IX2Mkf0Jo/U4ze2gNn7CI/AAAAAAAA7xg/iKxa6bYITDs/s0/HOT+Balloon+Trip_Ultra+HD.jpg", "https://s-media-cache-ak0.pinimg.com/originals/7e/80/01/7e80012f3e7abc6ae3744559788a3666.jpg"]
    
    // MARK: - UICollectionViewDataSource protocol
    
    // tell the collection view how many cells to make
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return self.items.count
    }

    // make a cell for each cell index path
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        
        // get a reference to our storyboard cell
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: reuseIdentifier, for: indexPath as IndexPath) as! MyCollectionViewCell
        
        // Use the outlet in our custom class to get a reference to the UILabel in the cell
        UIApplication.shared.isNetworkActivityIndicatorVisible = true
        cell.activity.startAnimating()
        URLSession.shared.dataTask(with: NSURL(string: items[indexPath.item])! as URL, completionHandler: { (data, response, error) -> Void in
            
            if error != nil {
                let alert = UIAlertController(title: "Error", message: "Image could not be loaded", preferredStyle: UIAlertControllerStyle.alert)
                alert.addAction(UIAlertAction(title: "Ok", style: UIAlertActionStyle.default, handler: nil))
                self.present(alert, animated: true, completion: nil)
                return
            }
            DispatchQueue.main.async(execute: { () -> Void in
                let image = UIImage(data: data!)
                cell.activity.stopAnimating()
                UIApplication.shared.isNetworkActivityIndicatorVisible = false
                cell.image.image = image
            })
            
        }).resume()
        
        return cell
    }
    
    // MARK: - UICollectionViewDelegate protocol
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        // handle tap events
        print("You selected cell #\(indexPath.item)!")
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "segue" {
            if let destination = segue.destination as? ImageViewController {
                destination.image = (sender as! MyCollectionViewCell).image.image!
            }
        }
    }

}
