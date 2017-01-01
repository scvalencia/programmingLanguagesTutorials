(*
	Any number of elements of the same type

	[] -> []
	[v1, ..., vn] : t(vi) list if vi = t forall i in [1 .. n]

	[v1, v2, ..., vn] =
		v1 :: v2 :: ... :: vn :: []
		v1 :: v2 :: ... :: vn :: nil

	If e1 -> v /\ e2 -> [v1, .., vn]
	e1 :: e3 -> [v, v1, ..., vn]
	if type restriction holds

	(::) : a' * a' list -> a' list

	Accesing lists:
		null e = true iff e -> []

		e -> [v1, v2, .., vn] =>
		hd e -> v1 if e <> [] /\
		tl e -> [v2, ..., vn]

		Theorem:

		if e -> [v1, ..., vn] and |e| > 0
		e = hd(e) :: tl(e)

		hd : 'a list -> 'a
		tl : 'a list -> 'a list
*)

val empty = []

val lst = [3, 4, 5]

val cons1 = 4 :: lst

val cons2 = [6] :: [[7, 5], [8, 9]]

(*
	List functions
*)

fun sum(xs : int list) =
	if xs = nil then 0
	else hd xs + sum(tl(xs))

fun product(xs : int list) = 
	if xs = nil then 1
	else hd xs * product(tl(xs))

fun countdown(x : int) =
	if x = 0 then []
	else x :: countdown(x - 1)

fun append(xs : int list, ys : int list) =
	if xs = [] then ys
	else (hd xs) :: append(tl(xs), ys)

fun sum_pair_list (xs : (int * int) list) = 
	if null xs then 0
	else #1 (hd xs) + #2 (hd xs) + sum_pair_list(tl(xs))

fun firsts(xs : (int * int) list) = 
	if xs = nil then []
	else #1 (hd(xs)) :: first(tl(xs))

fun seconds(xs : (int * int) list) = 
	if xs = nil then []
	else #2 (hd(xs)) :: seconds(tl(xs))

fun sum_pair_list2 (xs : (int * int) list) =
	(sum (firsts xs)) + (sum (seconds xs))

fun factorial n = 
	product (countdown n)

