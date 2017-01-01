fun evn n = n mod 2 = 0;

fun foo_aux(lst, odd, even) = 
	if lst = [] then even - odd
	else
		let
		 	val head = hd(lst);
		 	val tail = tl(lst);
		 in
		 	if evn head then foo_aux(tail, odd, even + head)
		 	else foo_aux(tail, odd + head, even)
		 end

fun foo lst = 
	let
		fun aux(lst, odd, even) = 
			if lst = [] then even - odd
			else
				let
					val head = hd(lst);
					val tail = tl(lst);
				in
					if head mod 2 = 0 then 
						aux(tail, odd, even + head)
					else
						aux(tail, odd + head, even)
				end
	in
		aux(lst, 0, 0)
	end;

fun foo2 lst =
	let
		fun aux(lst, sum) =
			if lst = [] then sum
			else
				if hd(lst) mod 2 = 0 then
					aux(tl(lst), sum + hd(lst))
				else
					aux(tl(lst), sum - hd(lst))
	in
		aux(lst, 0)
	end