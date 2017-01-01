(*
	We need to structure data, tuples allow to have a fixed number of different types.

	Pairs:
		Syntax: (e1, e2)
		Evaluation:
			Eval(e1) -> v1
			Eval(e2) -> v2
			Result is (V1, V2)
		Type checking:
			t(e1) = t1 /\ t(e2) = t2 => t((e1, e2)) = t1 * t2

		if a = (e1, e2) => (#1 a) = e1 /\ (#2 b) = e2
		a should be a pair, and type checking works similiarly
*)

fun swap(pr : int * bool) = 
	(#2 pr, #1 pr)

fun sum_two_pairs(pr1 : int * int, pr2 : int * int) =
	(#1 pr1) + (#2 pr2) + (#1 pr2) + (#2 pr2)

fun div_mod(x : int, y : int) =
	(x div y, x mod y)

fun sort_pair(pr : int * int) = 
	if (#1 pr) < (#2 pr) then pr
	else (#2 pr, #1 pr)