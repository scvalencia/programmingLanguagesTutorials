var selection : String = "One"
selection match {
	case "One" => println("It was one.")
	case "Two" => println("It was two.")
	case "Nut" => println("Does not even makes sense")
	case _ => println("Selection is something else")
}
