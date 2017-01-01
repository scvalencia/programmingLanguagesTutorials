fun index i seq = List.nth (seq, i - 1);

fun sum(n, seq) = 
	if n = 0 then 0.0
	else
		sum(n - 1, seq) + index n seq

fun sumOfSumOfDigits(n) = 
	let
		fun sumOfDigits(i) = 
			if i = 0 then 0
			else (i mod 10) + sumOfSumOfDigits(i div 10)
	in
		if n= 0 then 0
		else sumOfSumOfDigits(n - 1) + sumOfDigits(n)
	end

val a = sumOfSumOfDigits(14)