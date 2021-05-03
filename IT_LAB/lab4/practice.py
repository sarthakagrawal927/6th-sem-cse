class Person:
    "This is new class, this is comment"
    age = 10

    def __init__(self, name):
        self.name = name
        self._age = 0

    def greet(self):
        print('hello from {name}'.format(name=self.name))


print(Person.age)
print(Person.greet)

harry = Person('harry')
harry.greet()  # equates to Person.greet(harry)
