(* 3.2.1 Write the following recursive functions *)

fun fact n =
	if n < 2 then 1
	else n * fact (n - 1);

fun cycle lst =
	if lst = nil then nil
	else tl(lst) @ [hd(lst)]

fun cycleN lst i =
	let
		fun aux(lst, j, acum) = 
			if j = acum then lst
			else aux(cycle lst, j + 1, acum)
	in
		aux(lst, 0, i)
	end

fun duplicate lst = 
	if lst = nil then nil
	else
		let
			val head = hd(lst)
		in
			head :: head :: duplicate(tl(lst))
		end

fun length(lst) = 
	if lst = nil then 0
	else 1 + length(tl(lst))

fun pow x i =
	if i = 0 then 1
	else x * pow x (i - 1)

fun max(lst : real list) = 
	let
		fun aux(lst, current) =
			if lst = nil then current
			else if hd(lst) > current then
				aux(tl(lst), hd(lst))
			else
				aux(tl(lst), current)
	in
		aux(lst, hd(lst))
	end

(* 3.2.2 Explain type inference in the function *)

fun foo(a, b, c, d) = 
	if a = b then c + 1 
	else if a > b then c
	else b + d

(* 
	(type(1) = int) => (type(c + 1) = int)
	=> type(c) = int => type(b + d) = int
	=> type(b) = type(d) = int
	type(a = b) = bool and type(b) = int => type(a) = int

	type(a, b, c, d) = int

	type foo = int * int * int * int -> int
*)