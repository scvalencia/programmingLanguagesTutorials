val whole : Int = 11
val fractional : Double = 1.4

val boolean : Boolean = true

val name : String = "Donald Knuth"

val lines : String = """Triple quotes let
|you have many lines
|in your string
""".stripMargin.replaceAll("\n", " ")

val five : Int = 5
val funny : String = "ABC1234"
val fivePointFour : Double = 5.4
val verdad : Boolean = true
//val wrong : Boolean = "maybe"
//val wrong2 : Int = 5.4
val right : Double = 15

val c = {
	val a = 2
	val c = 4
	a + c
}

val e = println(5)
val f = {}

val feetPerMile = 5280
val yardPerMile = feetPerMile / 3.0
val weird = 2000 / yardPerMile
val miles = (weird * yardPerMile) / feetPerMile