var s = Deck(sorted: false)

print("description:", s.description)

var card1 = s.draw()

print("\n\ndraw:", card1)

print("description:", s.description)

print("\n\ndraw:", s.draw())

print("description:", s.description)

print("\n\ndraw:", s.draw())

print("description:", s.description)

s.fold(c: card1)

print("\n\nfolded card:", card1)

print("description:", s.description)
