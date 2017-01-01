type hour = int * int * string

fun comesBefore(a : hour, b : hour) = 
	let
		val hour1 = #1(a);
		val hour2 = #1(b);
		val minute1 = #2(a);
		val minute2 = #2(b);
		val period1 = #3(a);
		val period2 = #3(b);
	in
		if period1 < period2 then a
		else if period2 < period2 then b
		else
			if hour1 < hour2 then a
			else if hour2 < hour1 then b
			else
				if minute1 < minute2 then a
				else bı
	end