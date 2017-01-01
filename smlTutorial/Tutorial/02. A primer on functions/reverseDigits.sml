fun digits(number) = 
	if (number div 10) = 0 then 1 
	else 1 + digits(number div 10);

fun reverseDigitsAux(number, length) = 
	if length  = 0 then 0
	else (number mod 10) * length + reverseDigitsAux(number div 10, length div 10);

fun reverseDigits(number) = 
	reverseDigitsAux(number, round(Math.pow(10.0, real(digits(number) - 1))));