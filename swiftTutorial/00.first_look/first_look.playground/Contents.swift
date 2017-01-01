//: Playground - noun: a place where people can play

import UIKit

var str = "Hello, playground"


var highScore = 1000
var firstName = "Sebastián"
var isValid = true

/*
* One can declare the type of a variable if desired
*/

var points : Int = 45
var money : Float = 3453.43534534
var seconds : Double = 353456453.23143254545

var flag : Bool = true
var name : String
var letter : Character = "g"

let daysPerWeek = 7 // A constant, not a variable
let interestRate : Float = 4.5

let IRR = 36441238098.543

print(firstName)

let city = "Bogotá"
let day = "Friday"
let temperature = 34

print("The temperature of \(city) on \(day) is \(temperature)")

var quantity = 17
var unitPrice = 45345.345

print("The amount is \(Double(quantity) * unitPrice)")

var number = 232

if number < 0 {
    print("We're dealing with a negative number")
} else if number == 0 {
    print("We're dealing with absence")
} else {
    print("A positive number it is")
}

let windSpeed = 5

switch windSpeed {
case 0:
    print("Hello: \(0)")
case 1:
    print("Hello: \(1)")
case 2:
    print("Hello: \(2)")
case 3:
    print("Hello: \(3)")
case 4:
    print("Hello: \(4)")
case 5:
    print("Hello: \(5)")
case 6:
    print("Hello: \(6)")
case 7:
    print("Hello: \(7)")
case 8:
    print("Hello: \(8)")
case 9:
    print("Hello: \(9)")
default:
    break
}

switch windSpeed {
case 0...3:
    print("It's very calm")
case 4...6:
    print("A little windy")
case 7...9:
    print("Blowing a gale")
case 310...12:
    print("Batten down the hatches!")
default:
    break
}

var summation = 0

for var i = 0; i <= 100; i++ {
    summation += i
}

summation
summation = 0

// Closed range operator
for number in 1...100 {
    summation += number
}

summation

summation = 0

// Half-open range operator
for number in 1..<100 {
    summation += number
}

summation

summation = 0
var i = 0
while i <= 100 {
    summation += i
    i += 1
}

summation

i = 0
summation = 0
repeat {
    i += 1
    summation += i
} while i < 100

summation

// By value, not by reference
func salute(name : String, age : Int = -1) {
    if age == -1 {
        print("Hello \(name)")
    } else {
        print("Hello \(name), your age is \(age)")
    }
}

salute("Matsumoto", age: 56)
salute("Dan")
salute("Bernard")

func inc(n : Int) -> Int {
    return n + 1
}

summation
summation = inc(summation)
summation

let daysInMonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
var colors = ["Red", "Green", "Blue"]

var flavours : [String]

flavours = ["Vanilla", "Chocolate", "Strawberry"]
flavours[0]
flavours.append("Coffe")

flavours += ["Neapolitan"]

flavours.insert("Coconut", atIndex: 0)

flavours.removeAtIndex(0)
flavours

flavours.count
flavours.isEmpty

for flavour in flavours {
    print(flavour)
}

var states : [String : String] = ["AZ" : "Arizona", "CA" : "California", "DE" : "Delaware"]

print(states["AZ"])
print(states["FL"])

states["FL"] = "Florida"
states

// Removes key, value pair

states["FL"] = nil
states


for (name, state) in states {
    print("\(name) : \(state)")
}

// A tuple is an easy way to group data together
var tuple = (7, 8, 6, 4, 6, 8)
var mtuple = ("Arabic", 45, "French", 45.56)

var stringg = "Tuple"
var num = 0

var tpl = (stringg, num)

for (name, state) in states { // We get a tuple for the iteration
    print("\(name) : \(state)")
}

func arity() -> (String, Int, String) {
    return ("Colombia", 1812, "Bogotá")
}

let result = arity()

result.0
result.1
result.2

func arity2() -> (country : String, year : Int, city : String) {
    return ("Colombia", 1812, "Bogotá")
}

let result2 = arity2()

result2.country
result2.year
result2.city

let (country, year, cty) = arity()

// OPTIONALS : we may have a value, but may be not

var temp : Int?

if temp != nil {
    print("The temperature is \(temp) degrees")
}

// Forced unwrapping
if temp != nil {
    print("The temperature is \(temp!) degrees")
}

temp = 45

if temp != nil {
    print("The temperature is \(temp) degrees")
}

// Forced unwrapping
if temp != nil {
    print("The temperature is \(temp!) degrees")
}

var dct = ["AZ" : "Arizona", "FL" : "Florida", "CA" : "California", "KY" : "Kentucky", "DE" : "Delaware"]

// Optional binding (if and let statement)

if let fullname = dct["TX"] {
    print("The state is \(fullname)") // No forced unwrapping is necessary
} else {
    print("No details found")
}

dct["TX"] = "Texas"

// Optional binding (if and let statement)

if let fullname = dct["TX"] {
    print("The state is \(fullname)") // No forced unwrapping is necessary
} else {
    print("No details found")
}

// ENUMS

enum SeatPreference {
    case Window
    case Middle
    case Aisle
    case NoPreference
}

func seatPreferenceString(variable : SeatPreference) -> String {
    
    var ans : String
    
    switch variable {
        case .Window:
            ans = "window"
        case .Middle:
            ans = "middle"
        case .Aisle:
            ans = "aisle"
        case .NoPreference:
            ans = "no preference"
    }
    
    return ans.uppercaseString
    
}

var mypreference1 : SeatPreference
var mypreference2 = SeatPreference.Window

mypreference1 = .Aisle

let userpreference = SeatPreference.Window

var preferenceString = seatPreferenceString(userpreference)
var prefix : String?

if preferenceString == seatPreferenceString(SeatPreference.Aisle) {
    prefix = "an"
} else {
    prefix = "a"
}

print("Please book me \(prefix!) \(preferenceString) seat")

// CLOSURE : Group some code into a reusable unit, that does not even need a name

func foo() {
    print("Hello Swift")
}

let myclosure = {
    print("Hello Swift")
}

func dontimes(n : Int, closure : () -> ()) {
    for _ in 1...n {
        closure()
    }
}

dontimes(5, closure: myclosure)

dontimes(5, closure: {
    print("Hello Swift")
})

var array : [Int] = [4, 9, 0, 12, 78, 3, 0 , -1, 4, -2, 8, 0, 12, -19, 3]

let cmp = { (frst : Int, scnd : Int) -> Bool in frst < scnd }
array.sort(cmp)

// CLASSES

public class Player {
    
    var name : String
    var score : Int
    
    init(name : String) {
        self.name = name
        self.score = 0
    }
    
    public func description() {
        print("Player \(self.name) has a score of \(self.score)")
    }
    
    private func increaseScore() {
        self.score += 1
    }
}

var player = Player(name : "Alan Doe")
player.description()