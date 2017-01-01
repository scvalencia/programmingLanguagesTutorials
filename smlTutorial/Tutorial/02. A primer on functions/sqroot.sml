fun sqroot(n) = 
	let
		fun search(a, b) = 
			if a + 1 = b then a
			else
				let 
					val c = (a + b) div 2
				in
					if c * c > n then search(a, c)
					else search(c, b)
				end
	in
		search(0, n + 1)
	end;

(* 
	The integer square root of n is the integer k
	such that k^2 <= n < (k + 1)^2
*)

fun increase(k, n) = 
	if (k + 1) * (k + 1) > n then k
	else k + 1;

fun introot n = 
	if n = 0 then n
	else increase(2 * introot(n div 4), n);