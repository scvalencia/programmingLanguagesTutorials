(* Using lazy evaluation, we avoid division by zero exception *)
fun lazy n = 
	if n < 6 then 3
	else 1 div n;

(* We can trace lazy, and eager evaluation in this expression *)		

fun silly(x, y) = 
	if x then true
	else y;

fun forall(n, f) =
	if n = 0 then true
	else forall(n - 1, f) andalso f(n)

fun f(n) = n < 3;

(* Different results due to imperative constructs *)

val e = true;
val x = ref(e);
fun w1 n = !x:
fun w2 n = (x := false; n);
w1(w2(n));