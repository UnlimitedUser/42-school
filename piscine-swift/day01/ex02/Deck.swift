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
