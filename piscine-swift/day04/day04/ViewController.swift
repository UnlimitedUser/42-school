//
//  ViewController.swift
//  day04
//
//  Created by Dan Sclearov on 4/21/17.
//  Copyright © 2017 None. All rights reserved.
//

import UIKit

class ViewController: UIViewController, APITwitterDelegate, UITableViewDataSource, UISearchBarDelegate {

    @IBOutlet weak var searchBar: UISearchBar!
    @IBOutlet weak var tweetTableView: UITableView!
    
    var tweets: [Tweet] = []
    var token: String = ""
    
    override func viewDidLoad() {
        super.viewDidLoad()
        searchBar.delegate = self
        searchBar.text = "ecole 42"
        tweetTableView.dataSource = self
        
        let CONSUMER_KEY = "CNdxhjOiAfm5UgYSsk1smEIj4"
        let CONSUMER_SECRET = "VTplJy449iEQzWDyoCmUjzY1rNHJF73Ti15Mcvtf7BRqIKsAcY"
        let BEARER = (("\(CONSUMER_KEY):\(CONSUMER_SECRET)").data(using: String.Encoding.utf8))!.base64EncodedString(options: NSData.Base64EncodingOptions(rawValue: 0))
        
        let url = URL(string: "https://api.twitter.com/oauth2/token")
        var request = URLRequest(url: url!)
        request.httpMethod = "POST"
        request.setValue("Basic \(BEARER)", forHTTPHeaderField: "Authorization")
        request.setValue("application/x-www-form-urlencoded;charset=UTF-8", forHTTPHeaderField: "Content-Type")
        request.httpBody = "grant_type=client_credentials".data(using: String.Encoding.utf8)
        let task = URLSession.shared.dataTask(with: request) {
            (data, response, error) in
            if let err = error {
                print(err)
            }
            else if let d = data {
                do {
                    if let resp: NSDictionary = try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers) as? NSDictionary {
                        if let token = resp["access_token"] {
                            self.token = token as! String
                            let controller = APIController(delegate: self, token: self.token)
                            controller.performQuery(self.searchBar.text!)
                        }
                    }
                }
                catch (let err) {
                    print(err)
                }
            }
        }
        task.resume()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func error(_ error: NSError) {
        print("error")
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return tweets.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tweetTableView.dequeueReusableCell(withIdentifier: "cell", for: indexPath) as! TweetTableViewCell
        self.tweetTableView.rowHeight = UITableViewAutomaticDimension
        self.tweetTableView.estimatedRowHeight = 80
        self.tweetTableView.setNeedsLayout()
        self.tweetTableView.contentInset = UIEdgeInsetsMake(0, 0, 120, 0)
        

        cell.name.text = tweets[indexPath.row].name
        cell.date.text = tweets[indexPath.row].date
        cell.desc.text = tweets[indexPath.row].text
        
        return cell
    }
    
    func treatTheTweets(_ tweets: [Tweet]) {
        self.tweets = tweets
        tweetTableView.reloadData()
    }
    
    func searchBarSearchButtonClicked(_ searchBar: UISearchBar) {
        if searchBar.text != nil {
            let controller = APIController(delegate: self, token: token)
            controller.performQuery(searchBar.text!)
        }
    }

}

