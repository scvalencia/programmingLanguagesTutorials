fun
	take(L) = 
		if L = nil then nil
		else hd(L) :: skip(tl(L))

and
	skip(L) = 
		if L = nil then nil
		else take(tl(L))

fun foo L = (* Assumes length is divisible by 2 *)
	if L = nil then nil
	else
		let
			val odd = take(L)
			val evn = skip(L)
		in
			if odd <> nil andalso evn <> nil then
				hd(evn) :: hd(odd) :: foo(tl(tl(L)))
			else if odd <> nil andalso evn = nil then
				hd(odd) :: foo(tl(tl(L)))
			else
				hd(evn) :: foo(tl(tl(L)))
		end

fun 
	pos d = 
		neg(d - 2.0) + 1.0 / d

and
	neg d =
		if d > 0.0 then pos(d - 2.0) - 1.0 / d
		else 0.0

fun piValue(n) = 4.0 * pos(n);



