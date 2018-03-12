//
//  APIController.swift
//  day04
//
//  Created by Dan Sclearov on 4/21/17.
//  Copyright © 2017 None. All rights reserved.
//

import Foundation

class APIController {
    
    weak var delegate: APITwitterDelegate?
    let token: String
    
    init(delegate: APITwitterDelegate?, token: String) {
        self.delegate = delegate
        self.token = token
    }
    
    func performQuery(_ s: String) {
        if let info = URL(string: "https://api.twitter.com/1.1/search/tweets.json?q=\(s)&count=100&lang=fr&result_type=recent".addingPercentEncoding(withAllowedCharacters: CharacterSet.urlQueryAllowed)!) {
            var url = URLRequest(url: info)
            url.httpMethod = "GET"
            url.setValue("Bearer \(token)", forHTTPHeaderField: "Authorization")
            
            let task = URLSession.shared.dataTask(with: url) {
                (data, response, error) in
                if error != nil {
                    DispatchQueue.main.async {
                        self.delegate?.error(error as! NSError)
                    }
                }
                else if let d = data {
                    do {
                        var tweets: [Tweet] = []
                        if let resp: NSDictionary = try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers) as? NSDictionary {
                            if let statuses: [NSDictionary] = resp["statuses"] as? [NSDictionary] {
                                for status in statuses {
                                    let name = (status["user"] as? NSDictionary)?["name"] as? String
                                    let text = status["text"] as? String
                                    let date = status["created_at"] as? String
                                    if (name != nil) && (text != nil) && (date != nil) {
                                        let dateFormatter = DateFormatter()
                                        dateFormatter.dateFormat = "E MMM dd HH:mm:ss Z yyyy"
                                        if let date = dateFormatter.date(from: date!) {
                                            dateFormatter.dateFormat = "dd/MM/yyyy HH:mm"
                                            let newDate = dateFormatter.string(from: date)
                                            tweets.append(Tweet(name: name!, text: text!, date: newDate))
                                        }
                                    }
                                }
                                DispatchQueue.main.async {
                                    self.delegate?.treatTheTweets(tweets)
                                }
                            }
                        }
                    }
                    catch let err as NSError {
                        DispatchQueue.main.async {
                            self.delegate?.error(err)
                        }
                    }
                }
            }
            task.resume()
        }
    }
    
}
