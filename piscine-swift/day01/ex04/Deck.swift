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
		var cards = allCards
		var discards: [Card] = []
		var outs: [Card] = []

		init(sorted: Bool) {
			if !sorted {
				cards = cards.shuffle()
			}
			super.init()
		}

	override var description: String {
		return "\(cards)"
	}

	func draw() -> Card {
		outs.append(cards.first!)
			return cards.removeFirst()
	}

	func fold(c: Card) {
		if outs.contains(c) {
			discards.append(c)
				outs = outs.filter { $0 != c }
		}
	}
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
