let card1 = Card(Color: Color.diamonds, Value: Value.king)
let card2 = Card(Color: Color.hearts, Value: Value.queen)
let card3 = Card(Color: Color.spades, Value: Value.king)

print(card1)
print(card2)
print(card3)

print(String("s").isEqual(card2))
print(card2.isEqual(card2))

print(card1 == card2)
print(card2 == card3)
