//
//  SecondViewController.swift
//  day05
//
//  Created by Dan Sclearov on 4/27/17.
//  Copyright © 2017 None. All rights reserved.
//

import UIKit
import MapKit
import CoreLocation

class SecondViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {

    @IBOutlet weak var myTableView: UITableView!
    
    var places = [
        ("Botanica", CLLocationCoordinate2D(latitude: 46.9736, longitude: 28.9018)),
        ("Academy", CLLocationCoordinate2D(latitude: 47.0399, longitude: 28.8247)),
        ("Buiucani", CLLocationCoordinate2D(latitude: 47.0348, longitude: 28.7944))
    ]
    
    override func viewDidLoad() {
        super.viewDidLoad()
        myTableView.delegate = self
        myTableView.dataSource = self
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return places.count
    }
    
    func tableView(_ tableView: UITableView, didDeselectRowAt indexPath: IndexPath) {
        (tabBarController?.viewControllers?[0] as! FirstViewController).myMapView.region = MKCoordinateRegion(center: places[indexPath.item].1, span: MKCoordinateSpan(latitudeDelta: CLLocationDegrees(0.0001), longitudeDelta: CLLocationDegrees(0.0001)))
        tabBarController?.selectedIndex = 0
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "cell", for: indexPath) as! MyTableViewCell
        
        cell.desc.text = places[indexPath.row].0
        
        return cell
    }
    
}

