(* 2.19 *)

fun newGCD(a, b) =
	if a = b then a 
	else if a mod 2 = 0 andalso b mod 2 = 0
		then 2 * newGCD(a div 2, b div 2)
	else if a mod 2 = 0 andalso b mod 2 <> 0
		then newGCD(a div 2, b)
	else newGCD(((b - 1) div 2) - ((a - 1) div 2), a);

(* 2.21 *)

fun introotpair n =
	if n<4 then (1,n-1)
	else 
		let 
			val (e,re) = introotpair(n div 4)
        	val ri = 4*re + n mod 4    (*remainder if root=2*k*)
        	val rj = ri - (4*e + 1)    (*remainder if root=2*k+1*)
    	in
    		if rj<0 then (2*e, ri)  else (2*e+1, rj)
    	end;

(* 2.22 *)

val a = 6
val b = 8

val (a, b) = (b, a)

(* 2.23 *)

fun
	P n = 1 + sumup (n - 1)
and
	sumup k = 
		if k < 1 then 0
		else
			P k + sumup(k - 1)
