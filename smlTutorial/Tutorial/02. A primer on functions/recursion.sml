fun fact1 n = if n < 2 then 1 else n * fact1 (n-1);

fun fact2 0 = 1
  | fact2 n = n * fact2 (n-1); 

fun fact3 n = if n = 0 then 1 else fact3(n+1) div (n+1)

fun facti(n,p) = if n = 0 then p 
				 else facti(n-1, n * p);

(* Recursive power function *)
fun power(x, 0) = 1.0
  | power(x, n) = x * power(x, n - 1);

fun pow2(x,k) : real = if k = 1 then x
					   else 
					      if k mod 2 = 0 then pow2(x*x, k div 2)
					   	  else x * pow2(x*x, k div 2);

fun f n = if n < 2 then n else n + f(n-1);

fun sum(m,n) = if n = 0 then m else (m + n) + sum(m,n-1);

fun fib(n) = if n < 2 then n else fib(n-1) + fib(n-2);

fun gcd(m,n) = if m = 0 then n else gcd(n mod m, m);

fun reverse(L) = 
	if L = nil then nil
	else reverse(tl(L)) @ [hd(L)];

fun len L = 
	if L = nil then 0
	else 1 + len (tl(L));

fun evens(L) = (* Tell how many even numbers are on a list *)
 	if L = nil then 0 
 	else
 		if hd(L) mod 2 = 0 then 1 + evens(tl(L))
 		else 0 + evens(tl(L));

fun factorial n  : IntInf.int =
      if n=0 then 1 else n * factorial(n - 1);

(* To generate a list [0....n] ==> 
 * List.tabulate(n, fn x => x+j), where j is the shift
 * ammount
 *)

fun pe1 L = 
	if L = nil (* Project Euler problem 1 *)
	then 0
	else if hd(L) mod 3 = 0 orelse hd(L) mod 5 = 0
		then hd(L) + pe1(tl(L))
		else pe1(tl(L));

(* val a = List.tabulate(1000, fn x => x);
 * pe1 a --> val it = 233168 : int *)

fun binomialCoeff (n, k) = 
	if k = 0 orelse k = n orelse n < k then 1
	else binomialCoeff(n-1, k-1) + binomialCoeff(n-1, k);

fun stringPow(s,n) = if n = 1 then s
	else s^stringPow(s,n-1); 

fun isIthChar(str, i, ch) = String.sub(str,i) = ch;

fun occFromIth(str, i, ch) = 
	if i >= size(str) then 0
	else if isIthChar(str, i, ch) then 
		1 + occFromIth(str, i + 1, ch)
	else occFromIth(str, i + 1, ch);

fun occInString(str, ch) = occFromIth(str, 0, ch);


fun zeroes n = if n = 0 then []
	else 0 :: zeroes(n - 1); 

fun lst(a,b) = if b <= a then []
	else a :: lst(a + 1, b); 

fun range n = lst(0, n);

fun bin(n : IntInf.int, k) : IntInf.int = 
	if k = 0 orelse k = n then 1
	else
		let
			val right = bin(n - 1, k - 1)
			val left = bin(n - 1, k)
		in
			right + left
		end;

fun stringPower(str, n) = 
	if n < 2 then str
	else str ^ stringPower(str, n - 1);

(* Hansen's book *)

fun notDivisible(a, b) = (b mod a <> 0); 

fun test(a, b, c) = 
	if a <= b then
		notDivisible(a, c) andalso test(a + 1, b, c)
	else
		notDivisible(b, c);

fun prime(n) = n = 2 orelse test(2, n - 1, n);

fun nextPrime(n) = 
	if prime(n + 1) then n + 1
	else nextPrime(n + 1);

fun primes(a, b) =
	if a <= b then
		let
			val next = nextPrime(a)
		in
			if prime(a) then a :: primes(next, b)
			else next :: primes(next, b)
		end		
	else [];

fun primesUpTo(n) = primes(2, n);

fun newGCD(a, b) =
	if a = b then a 
	else if a mod 2 = 0 andalso b mod 2 = 0
		then 2 * newGCD(a div 2, b div 2)
	else if a mod 2 = 0 andalso b mod 2 <> 0
		then newGCD(a div 2, b)
	else newGCD(((b - 1) div 2) - ((a - 1) div 2), a);

fun reverse L =
	if L = nil then nil
	else reverse(tl(L)) @ [hd(L)]

