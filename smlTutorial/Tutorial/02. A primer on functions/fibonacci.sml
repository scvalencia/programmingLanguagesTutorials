(* Fibonacci numbers *)

fun nextfib (prev, curr) = (curr, prev + curr);

fun fibpair(n) = 
	if n = 1 then (0,1) else nextfib(fibpair(n - 1));

fun itfib(n, prev, curr) = if n = 1 then curr (* iterative *)
						   else itfib(n-1, curr, prev+curr);

fun fibonacci n = itfib(n,0,1); (* iterative interface *)