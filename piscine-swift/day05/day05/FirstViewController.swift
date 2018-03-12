//
//  FirstViewController.swift
//  day05
//
//  Created by Dan Sclearov on 4/27/17.
//  Copyright © 2017 None. All rights reserved.
//

import UIKit
import MapKit
import CoreLocation

class FirstViewController: UIViewController, MKMapViewDelegate, CLLocationManagerDelegate {
    
    @IBOutlet weak var myMapView: MKMapView!
    
    var locationManager = CLLocationManager()
    
    var places = [
        ("Botanica", CLLocationCoordinate2D(latitude: 46.9736, longitude: 28.9018)),
        ("Academy", CLLocationCoordinate2D(latitude: 47.0399, longitude: 28.8247)),
        ("Buiucani", CLLocationCoordinate2D(latitude: 47.0348, longitude: 28.7944))
    ]
    
    override func viewDidLoad() {
        super.viewDidLoad()
        locationManager.requestWhenInUseAuthorization()
        locationManager.delegate = self
        myMapView.delegate = self
        locationManager.desiredAccuracy = kCLLocationAccuracyBest
        locationManager.startUpdatingLocation()
        let annotation = MKPointAnnotation()
        annotation.coordinate = CLLocationCoordinate2D(latitude: 47.039985, longitude: 28.824664)
        annotation.title = "42"
        annotation.subtitle = "Ecole"
        myMapView.region = MKCoordinateRegion(center: CLLocationCoordinate2D(latitude: 47.039985, longitude: 28.824664), span: MKCoordinateSpan(latitudeDelta: CLLocationDegrees(0.0001), longitudeDelta: CLLocationDegrees(0.0001)))
        for place in places {
            let annotation = MKPointAnnotation()
            annotation.coordinate = place.1
            annotation.title = "42"
            annotation.subtitle = "Some place"
            (tabBarController?.viewControllers?[0] as! FirstViewController).myMapView.addAnnotation(annotation)
        }
        myMapView.addAnnotation(annotation)
        // Do any additional setup after loading the view, typically from a nib.
    }

    func mapView(_ mapView: MKMapView, viewFor annotation: MKAnnotation) -> MKAnnotationView? {
        guard !(annotation is MKUserLocation) else { return nil }
        
        let identifier = "com.domain.app.something"
        var annotationView = mapView.dequeueReusableAnnotationView(withIdentifier: "em hz") as? MKPinAnnotationView
        if annotationView == nil {
            annotationView = MKPinAnnotationView(annotation: annotation, reuseIdentifier: identifier)
            if annotation.subtitle! == "Some place" {
                annotationView?.pinTintColor = UIColor.green
            }
            annotationView?.canShowCallout = true
        } else {
            annotationView?.annotation = annotation
        }
        
        return annotationView
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func buttonClick(_ sender: UIButton) {
        myMapView.region = MKCoordinateRegion(center: CLLocationCoordinate2D(latitude: 47.039985, longitude: 28.824664), span: MKCoordinateSpan(latitudeDelta: CLLocationDegrees(0.0001), longitudeDelta: CLLocationDegrees(0.0001)))
    }
    
    @IBAction func segControlAction(_ sender: UISegmentedControl) {
        switch (sender.selectedSegmentIndex) {
        case 0:
            myMapView.mapType = .standard
        case 1:
            myMapView.mapType = .satellite
        case 2:
            myMapView.mapType = .hybrid
        default:
            break
        }
    }
    
}

