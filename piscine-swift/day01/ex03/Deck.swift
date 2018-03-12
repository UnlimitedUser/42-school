import Foundation

class Deck: NSObject {
	static let allSpades = Value.allValue.map({
			return Card(Color: Color.spades, Value: $0)
			})
	static let allHearts = Value.allValue.map({
			return Card(Color: Color.hearts, Value: $0)
			})
	static let allClubs = Value.allValue.map({
			return Card(Color: Color.clubs, Value: $0)
			})
	static let allDiamonds = Value.allValue.map({
			return Card(Color: Color.diamonds, Value: $0)
			})
	static let allCards = allSpades + allHearts + allClubs + allDiamonds
}

extension Array {
	func shuffle() -> Array {
		var el = self
			for i in indices {
				let a = Int(arc4random_uniform(UInt32(el.count - i))) + i
					if a != i {
						swap(&el[a], &el[i])
					}
			}
		return el
	}
}
