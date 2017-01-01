(* fileName : functions.sml 
 * creator : scvalencia *)

(* This function takes a char and converts it to upper *)
fun upper c = chr(ord(c) - 32);

(* This funtion takes a real and returns the are of the circle
 * with this real as radius *)
fun radiusCircle r = Math.pi * r * r;

(* Recursive calculation of power *)
fun pow(b : int, e : int) = 
	if e = 0 then 1
 	else pow(b, e - 1) * b;

(* Cube of a real number *)
fun cube n:real = n * n * n;

(* Bigger component of a tuple int * int * int *)
fun max3(a:int, b, c) = 
	if a > b then 
		if a > c then a else c
	else
		if b > c then b else c;

(* Smallest component of a tuple int * int * int *)
fun min3(a:int, b, c) = 
	if a < b then
		if c < a then c else a
	else
		if b < c then b else c;

(* Returns the third ellement of a list *)
fun third lst = hd(tl(tl(lst)));

(* Reverse of a tuple of length 3 *)
fun reverse3 a =  tl(tl(a)) @ [hd(tl(a))] @ [hd(a)];

(* Returns the third character of a string *)
fun thirdLetter str = third(explode(str));

(* Cycle a list one Ullamn [a,b,...,z] -> [b,c,...,z,a] *)
fun cycleOne lst = tl(lst) @ [hd lst];

(* Given three numbers return a tuple of the largest and least *)
fun max a b = if a > b then a else b;

fun min a b = if a < b then a else b;

fun extrema a b c = 
	if max a b = a then
		if max a c = a then 
			if max c b = b then (a,c)
			else (a,b)
		else
			if max c b = c then (c, b)
			else (c, a)
	else
		if max b c = b then 
			if max a c = a then (b, c)
			else (b, a)
		else (c,a);

fun minMax a b c = (min3(a,b,c), max3(a,b,c));

(* Determines which date (h, min, TIME) comes after *)
fun firstH ((a,b,t),(c:int,d:int,p:string)) = 
	if t = p then
		if a < c then (c,d,p) else (a,b,t)
	else
		if t < p then (c,d,p) else (a,b,t);

(* Different implementations of recursive fact *)

(* Trivial functions *)

fun h (x,y) = Math.sqrt (x*x + y*y); (* Hypothenuse *)

fun nameAge(name, age) = name ^ " is " ^ 
						 Int.toString age ^ " years old";

fun append l n = l @ [n];

fun even n = n mod 2 = 0;

fun odd n = n mod 2 = 1;

fun digitval digitchar = chr(ord(#"0") + digitchar);

fun to_capital ch = chr(ord(ch) - 32);

fun isdigit n = (ord(n) >= 48) andalso (ord(n) < 58);

fun islowercase n = (ord(n) >= 97) andalso (ord(n) <= 122);

fun isuppercase n = (ord(n) >= 65) andalso (ord(n) <= 90);

fun isalpha n = islowercase n orelse isuppercase n;

fun count_evens(n : int) =
	let
		fun aux(n : int, m : int) =
			if n = 0 then m
			else
				if n mod 2 = 0 then aux(n - 1, m + 1)
				else aux(n - 1, m)
	in
		aux(n, 0)
	end
