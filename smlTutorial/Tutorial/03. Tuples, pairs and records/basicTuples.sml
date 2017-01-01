(*
	A tuple is a generalized pair, while a pair has 2 elements, a tuple can have
	as many elements as you want. The syntax, the evaluation, and the type checking
	works in a similar fashion.

	(e1, e2, .., en)
	t1 * t2 * ... * tn
	#1 e, ..., #n e 
*)

(* int * (bool * int) *)
val x1 = (7, (true, 9))

(* bool *)
val x2 = #1 (#2 x1)

(* bool * int*)
val x3 = (#2 x1)

(* (int * int) * ((int * int) * (int * int)) *)
val x4 = ((3, 5), ((4, 8), (0, 0)))

(*
	val x = (3, (4, (5, 6)))
	val y = (#2 x, (#1 x, #2 (#2 x)))
		-> (#2 x, (#1 x, #2 (4, (5, 6))))
		-> (#2 x, (#1 x, (5, 6))) 
		-> (#2 x, (3, (5, 6)))
		-> ((4, (5, 6)), (3, (5, 6)))
	val ans = (#2 y, 4)
		-> ((3, (5, 6)), 4)
*)