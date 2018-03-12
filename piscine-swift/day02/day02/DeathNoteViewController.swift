//
//  DeathNoteViewController.swift
//  DeathNote
//
//  Created by luc Casimir on 05/10/2016.
//  Copyright © 2016 Piscine_Swift_42. All rights reserved.
//

import UIKit

class DeathNoteViewController: UIViewController, UITableViewDelegate, UITableViewDataSource{
    var tableVictim : [Victim] = []

    @IBOutlet var deathNoteTableView: UITableView!
 
    override func awakeFromNib() {
        self.tableVictim.append(Victim(name: "Somebody", date: Date(), death: "By Somebody"))
        self.tableVictim.append(Victim(name: "Person A", date: Date(), death: "Much beatiful"))
        self.tableVictim.append(Victim(name: "Person B", date: Date(), death: "Very fun"))
    }
    
    override func viewDidLoad() {
        deathNoteTableView.rowHeight = UITableViewAutomaticDimension
        deathNoteTableView.estimatedRowHeight = 140
    }
    
    override func viewWillAppear(_ animated: Bool) {
        deathNoteTableView.reloadData()
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.tableVictim.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "myCell") as? MyCell
        cell?.a = self.tableVictim[indexPath.row]
        return cell!
    }
    
    @IBAction override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "addSegue"{
            if let dst = segue.destination as? addDeathViewController{
                dst.title? = "Bonjour!"
            }
        }
    }
}
