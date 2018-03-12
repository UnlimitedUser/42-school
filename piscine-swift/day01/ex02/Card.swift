import Foundation

class Card: NSObject {
	var color: Color
	var value: Value

	init(Color c: Color, Value v: Value) {
		color = c
		value = v
	}

	override var description: String {
		return "\(color) of \(value)"
	}

	override func isEqual(_ object: Any?) -> Bool {
		if let o = object as? Card {
			return (o.color == self.color && o.value == self.value)
		}
		return false
	}

	static func ==(lsh: Card, rsh: Card) -> Bool {
		return (lsh.color == rsh.color && lsh.value == rsh.value)
	}
}
