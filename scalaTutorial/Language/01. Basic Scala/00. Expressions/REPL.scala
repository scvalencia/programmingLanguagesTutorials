Welcome to Scala version 2.11.1 (Java HotSpot(TM) 64-Bit Server VM, Java 1.8.0_05).
Type in expressions to have them evaluated.
Type :help for more information.

scala> 5
res0: Int = 5

scala> 5.6
res1: Double = 5.6

scala> println("Niklaus Wirth")
Niklaus Wirth

scala> 5+6
res3: Int = 11

scala> 5 .+(6)
res4: Int = 11

scala> 5 % 2
res5: Int = 1

scala> 5.0 / 2.0
res6: Double = 2.5

scala> 5.0 / 2
res7: Double = 2.5

scala> 5.6.toInt
res8: Int = 5

scala> 5.6 toInt
warning: there were 1 feature warning(s); re-run with -feature for details
res9: Int = 5

scala> 5.6.toInt
res10: Int = 5

scala> true
res11: Boolean = true

scala> false
res12: Boolean = false

scala> 'a'
res13: Char = a

scala> 'a'.toInt
res14: Int = 97

scala> 'a' + 1
res15: Int = 98

scala> 98.toChar
res16: Char = b

scala> ('a' + 1).toChar
res17: Char = b

scala> "Scala is a programming language"
res18: String = Scala is a programming language

scala> "Scala is a programming language" + "."
res19: String = Scala is a programming language.

scala> "Scala is a programming language" + 123
res20: String = Scala is a programming language123

scala> 123 + "abc"
res21: String = 123abc

scala> "abc" * 6
res22: String = abcabcabcabcabcabc

scala> (5,6,7)
res23: (Int, Int, Int) = (5,6,7)

scala> ("Book", 6)
res24: (String, Int) = (Book,6)

scala> (5.9, 4.9, 5, "Hi", 'a')
res25: (Double, Double, Int, String, Char) = (5.9,4.9,5,Hi,a)

scala> 6 -> 4
res26: (Int, Int) = (6,4)

scala> 6 -> 4 -> 5
res27: ((Int, Int), Int) = ((6,4),5)

scala> (6 -> 4 -> 5)._1
res28: (Int, Int) = (6,4)

scala> (6 -> 4 -> 5)._2
res29: Int = 5

scala> (6 -> 4 -> 5)._0
<console>:8: error: value _0 is not a member of ((Int, Int), Int)
              (6 -> 4 -> 5)._0
                            ^

scala> 53.toBinaryString
res31: String = 110101

scala> (-53).toBinaryString
res32: String = 11111111111111111111111111001011

scala> (-53L).toBinaryString
res33: String = 1111111111111111111111111111111111111111111111111111111111001011

scala> (53L).toBinaryString
res34: String = 110101

scala> 53.toOctalString
res35: String = 65

scala> 0x65.toBinaryString
res36: String = 1100101

scala> 0x65
res37: Int = 101

scala> 101.toHexadecimalStrign
<console>:8: error: value toHexadecimalStrign is not a member of Int
              101.toHexadecimalStrign
                  ^

scala> 101.toHexStrign
<console>:8: error: value toHexStrign is not a member of Int
              101.toHexStrign
                  ^

scala> math.sqrt(9)
res40: Double = 3.0

scala> math.sqrt(69)
res41: Double = 8.306623862918075

scala> mapth.Pi
<console>:8: error: not found: value mapth
              mapth.Pi
              ^

scala> mapth.pi 
<console>:8: error: not found: value mapth
              mapth.pi
              ^

scala> math.pi
<console>:8: error: object pi is not a member of package math
              math.pi
                   ^

scala> math.Pi
res45: Double = 3.141592653589793

scala> val age : Int = 5
age: Int = 5

scala> val age = 5
age: Int = 5

scala> Loading /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/examples/TimeScript.scala...
totalSeconds: Int = 123456
displaySeconds: Int = 36
totalMinutes: Int = 2057
displayMinutes: Int = 17
displayHours: Int = 34
sec: String = 36
min: String = 17
finalStrign: String = 34:17
<console>:11: error: value unary_+ is not a member of String
              + ":" + ("0"*(2-sec.length))+sec
              ^
34:17

scala> Loading /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/examples/TimeScript.scala...
totalSeconds: Int = 123456
displaySeconds: Int = 36
totalMinutes: Int = 2057
displayMinutes: Int = 17
displayHours: Int = 34
sec: String = 36
min: String = 17
finalStrign: String = 34:17:36
34:17:36

scala> Loading /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/examples/TimeScript.scala...
Enter the number of seconds: warning: there were 1 deprecation warning(s); re-run with -deprecation for details
java.lang.NumberFormatException: For input string: ":load /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/examples/TimeScript.scala"
  at java.lang.NumberFormatException.forInputString(NumberFormatException.java:65)
  at java.lang.Integer.parseInt(Integer.java:580)
  at java.lang.Integer.parseInt(Integer.java:615)
  at scala.collection.immutable.StringLike$class.toInt(StringLike.scala:241)
  at scala.collection.immutable.StringOps.toInt(StringOps.scala:30)
  at scala.io.StdIn$class.readInt(StdIn.scala:110)
  at scala.io.StdIn$.readInt(StdIn.scala:229)
  at scala.DeprecatedPredef$class.readInt(Predef.scala:435)
  at scala.Predef$.readInt(Predef.scala:70)
  ... 54 elided
displaySeconds: Int = 36
totalMinutes: Int = 2057
displayMinutes: Int = 17
displayHours: Int = 34
sec: String = 36
min: String = 17
finalStrign: String = 34:17:36
34:17:36

scala> Loading /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/examples/TimeScript.scala...
Enter the number of seconds: warning: there were 1 deprecation warning(s); re-run with -deprecation for details
34534
totalSeconds: Int = 34534
displaySeconds: Int = 34
totalMinutes: Int = 575
displayMinutes: Int = 35
displayHours: Int = 9
sec: String = 34
min: String = 35
finalStrign: String = 9:35:34
9:35:34

scala> Loading /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/examples/TimeScript.scala...
Enter the number of seconds: warning: there were 1 deprecation warning(s); re-run with -deprecation for details
34534
totalSeconds: Int = 34534
displaySeconds: Int = 34
totalMinutes: Int = 575
displayMinutes: Int = 35
displayHours: Int = 9
sec: String = 34
min: String = 35
finalStrign: String = 9:35:34
9:35:34

scala> Loading /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/examples/TimeScript.scala...
Enter the number of seconds: warning: there were 1 deprecation warning(s); re-run with -deprecation for details
dfgfd
java.lang.NumberFormatException: For input string: "dfgfd"
  at java.lang.NumberFormatException.forInputString(NumberFormatException.java:65)
  at java.lang.Integer.parseInt(Integer.java:580)
  at java.lang.Integer.parseInt(Integer.java:615)
  at scala.collection.immutable.StringLike$class.toInt(StringLike.scala:241)
  at scala.collection.immutable.StringOps.toInt(StringOps.scala:30)
  at scala.io.StdIn$class.readInt(StdIn.scala:110)
  at scala.io.StdIn$.readInt(StdIn.scala:229)
  at scala.DeprecatedConsole.readInt(Console.scala:177)
  ... 54 elided
displaySeconds: Int = 34
totalMinutes: Int = 575
displayMinutes: Int = 35
displayHours: Int = 9
sec: String = 34
min: String = 35
finalStrign: String = 9:35:34
9:35:34

scala> 34534
res57: Int = 34534

scala> def scale = 5
scale: Int

scala> scale
res58: Int = 5

scala> val a = 17
a: Int = 17

scala> print a
<console>:8: error: missing arguments for method print in object Predef;
follow this method with `_' if you want to treat it as a partially applied function
              print a
              ^

scala> print(a)
17
scala> a = 20
<console>:8: error: reassignment to val
       a = 20
         ^

scala> val a = 20
a: Int = 20

scala> Loading /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/examples/BasicTypes.scala...
whole: Int = 11
fractional: Double = 1.4
boolean: Boolean = true
<console>:7: error: not found: type Strign
       val name : Strign = "Donald Knuth"
                  ^
lines: String =
"Triple quotes let
you have many lines
in your string
"

scala> Loading /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/examples/BasicTypes.scala...
whole: Int = 11
fractional: Double = 1.4
boolean: Boolean = true
name: String = Donald Knuth
lines: String =
"Triple quotes let
you have many lines
in your string
"

scala> Loading /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/examples/BasicTypes.scala...
whole: Int = 11
fractional: Double = 1.4
boolean: Boolean = true
name: String = Donald Knuth
lines: String =
"Triple quotes let
you have many lines
in your string
"
five: Int = 5
funny: String = ABC1234
fivePointFour: Double = 5.4
verdad: Boolean = true
<console>:7: error: type mismatch;
 found   : String("maybe")
 required: Boolean
       val wrong : Boolean = "maybe"
                             ^
<console>:7: error: type mismatch;
 found   : Double(5.4)
 required: Int
       val wrong2 : Int = 5.4
                          ^
wrong3: Double = 15.0

scala> Loading /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/examples/BasicTypes.scala...
whole: Int = 11
fractional: Double = 1.4
boolean: Boolean = true
name: String = Donald Knuth
lines: String =
"Triple quotes let
you have many lines
in your string
"
five: Int = 5
funny: String = ABC1234
fivePointFour: Double = 5.4
verdad: Boolean = true
<console>:7: error: type mismatch;
 found   : String("maybe")
 required: Boolean
       val wrong : Boolean = "maybe"
                             ^
<console>:7: error: type mismatch;
 found   : Double(5.4)
 required: Int
       val wrong2 : Int = 5.4
                          ^
right: Double = 15.0

scala> Loading /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/examples/BasicTypes.scala...
whole: Int = 11
fractional: Double = 1.4
boolean: Boolean = true
name: String = Donald Knuth
lines: String =
"Triple quotes let
|you have many lines
|in your string
"
five: Int = 5
funny: String = ABC1234
fivePointFour: Double = 5.4
verdad: Boolean = true
<console>:7: error: type mismatch;
 found   : String("maybe")
 required: Boolean
       val wrong : Boolean = "maybe"
                             ^
<console>:7: error: type mismatch;
 found   : Double(5.4)
 required: Int
       val wrong2 : Int = 5.4
                          ^
right: Double = 15.0

scala> Loading /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/examples/BasicTypes.scala...
whole: Int = 11
fractional: Double = 1.4
boolean: Boolean = true
name: String = Donald Knuth
lines: String = "Triple quotes let you have many lines in your string "
five: Int = 5
funny: String = ABC1234
fivePointFour: Double = 5.4
verdad: Boolean = true
<console>:7: error: type mismatch;
 found   : String("maybe")
 required: Boolean
       val wrong : Boolean = "maybe"
                             ^
<console>:7: error: type mismatch;
 found   : Double(5.4)
 required: Int
       val wrong2 : Int = 5.4
                          ^
right: Double = 15.0

scala> Loading /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/examples/BasicTypes.scala...
whole: Int = 11
fractional: Double = 1.4
boolean: Boolean = true
name: String = Donald Knuth
lines: String = "Triple quotes let you have many lines in your string "
five: Int = 5
funny: String = ABC1234
fivePointFour: Double = 5.4
verdad: Boolean = true
right: Double = 15.0
c: Int = 6

scala> Loading /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/examples/BasicTypes.scala...
whole: Int = 11
fractional: Double = 1.4
boolean: Boolean = true
name: String = Donald Knuth
lines: String = "Triple quotes let you have many lines in your string "
five: Int = 5
funny: String = ABC1234
fivePointFour: Double = 5.4
verdad: Boolean = true
right: Double = 15.0
c: Int = 6

scala> Loading /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/examples/BasicTypes.scala...
whole: Int = 11
fractional: Double = 1.4
boolean: Boolean = true
name: String = Donald Knuth
lines: String = "Triple quotes let you have many lines in your string "
five: Int = 5
funny: String = ABC1234
fivePointFour: Double = 5.4
verdad: Boolean = true
right: Double = 15.0
c: Int = 6
5
e: Unit = ()

scala> {}

scala> val f = {}
f: Unit = ()

scala> Loading /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/examples/BasicTypes.scala...
whole: Int = 11
fractional: Double = 1.4
boolean: Boolean = true
name: String = Donald Knuth
lines: String = "Triple quotes let you have many lines in your string "
five: Int = 5
funny: String = ABC1234
fivePointFour: Double = 5.4
verdad: Boolean = true
right: Double = 15.0
c: Int = 6
5
e: Unit = ()
f: Unit = ()
feetPerMile: Int = 5280
yardPerMile: Double = 1760.0

scala> Loading /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/examples/BasicTypes.scala...
whole: Int = 11
fractional: Double = 1.4
boolean: Boolean = true
name: String = Donald Knuth
lines: String = "Triple quotes let you have many lines in your string "
five: Int = 5
funny: String = ABC1234
fivePointFour: Double = 5.4
verdad: Boolean = true
right: Double = 15.0
c: Int = 6
5
e: Unit = ()
f: Unit = ()
feetPerMile: Int = 5280
yardPerMile: Double = 1760.0
weird: Double = 1.1363636363636365
miles: Double = 0.37878787878787884

scala> Loading /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/BasicExpressions.scala...
Hello Wolrd!
res63: (Int, Int) = (6,4)
res64: ((Int, Int), Int) = ((6,4),5)
radius: Int
<console>:9: error: not found: value pi
              (2 * pi) * radius
                   ^

scala> Loading /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/BasicExpressions.scala...
Hello Wolrd!
res69: (Int, Int) = (6,4)
res70: ((Int, Int), Int) = ((6,4),5)
pi: Double
radius: Int
res73: Double = 62.83185307179586

scala> Loading /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/BasicExpressions.scala...
Hello Wolrd!
res75: (Int, Int) = (6,4)
res76: ((Int, Int), Int) = ((6,4),5)
pi: Double
radius: Int
res79: Double = 62.83185307179586
incomes: Int = 1000000
money: Double = 1270000.0

scala> Loading /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/BasicExpressions.scala...
Hello Wolrd!
res83: (Int, Int) = (6,4)
res84: ((Int, Int), Int) = ((6,4),5)
pi: Double
radius: Int
res87: Double = 62.83185307179586
incomes: Int = 1000000
money: Double = 1270000.0
str: String = Niklaus Wirth
NIKLAUS WIRTH

scala> Loading /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/BasicExpressions.scala...
Hello Wolrd!
res92: (Int, Int) = (6,4)
res93: ((Int, Int), Int) = ((6,4),5)
pi: Double
radius: Int
res96: Double = 62.83185307179586
incomes: Int = 1000000
money: Double = 1270000.0
str: String = Niklaus Wirth
NIKLAUS WIRTH
Niklaus Wirth

scala> Loading /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/BasicExpressions.scala...
Hello Wolrd!
res102: (Int, Int) = (6,4)
res103: ((Int, Int), Int) = ((6,4),5)
pi: Double
radius: Int
res106: Double = 62.83185307179586
incomes: Int = 1000000
money: Double = 1270000.0
str: String = Niklaus Wirth
NIKLAUS WIRTH
Niklaus Wirth
Nikl

scala> Loading /Users/scvalencia/Documents/Programming/Scala/scalaTutorial/Language/01. Basic Scala/00. Expressions/BasicExpressions.scala...
Hello Wolrd!
res113: (Int, Int) = (6,4)
res114: ((Int, Int), Int) = ((6,4),5)
pi: Double
radius: Int
res117: Double = 62.83185307179586
incomes: Int = 1000000
money: Double = 1270000.0
str: String = Niklaus Wirth
NIKLAUS WIRTH
Niklaus Wirth
Nikl
res123: String = NiKlaus Wirth

scala> 8