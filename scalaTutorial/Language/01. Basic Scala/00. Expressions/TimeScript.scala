print("Enter the number of seconds: ")
val totalSeconds = dereadInt
val displaySeconds = totalSeconds % 60

val totalMinutes = totalSeconds / 60
val displayMinutes = totalMinutes % 60

val displayHours = totalMinutes / 60

val sec = displaySeconds.toString
val min = displayMinutes.toString

val finalStrign = displayHours + ":"+("0"*(2 - min.length)) + min + ":" + ("0"*(2-sec.length))+sec
println(finalStrign)