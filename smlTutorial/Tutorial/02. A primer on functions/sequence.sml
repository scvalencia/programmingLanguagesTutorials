(*
	Computes the sequence
	Pn = 1 + sum(k = 1, n - 1, Pk)
*)

val seed = []

fun sequence(n, accum) =
	if n = 0 then 1
	else
		let
			val flag = n - 1
			val bound = accum + sequence(n - 1, accum)
		in
			sequence(flag, bound + accum)
		end