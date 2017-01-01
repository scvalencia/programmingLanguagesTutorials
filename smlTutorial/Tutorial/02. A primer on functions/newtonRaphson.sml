(* 
	Solves the equation f(x) = 0; for example:
	a - x^2 = 0.

	To compute sqrt(a), choose a positive approximation x_{0},
	the next approximation is (a/x + x)/2, until it converges.
*)

fun findroot (a, x, acc) =
	let
		val nextx = (a/x + x) / 2.0
	in
		if abs(x - nextx) < acc * x then nextx
		else findroot(a, nextx, acc)
	end

fun sqrtroot(a : real) = findroot(a, 1.0, 1.0E~10)

fun sqroot(a : real) =
	let
		val acc = 1.0E~10
		fun newtonRaphson x = 
			let
				val next = (a/x + x) / 2.0
			in
				if abs(x - next) < acc * x then next
				else newtonRaphson next
			end
	in
		newtonRaphson 1.0
	end