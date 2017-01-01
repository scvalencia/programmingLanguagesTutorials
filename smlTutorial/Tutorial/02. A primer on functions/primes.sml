fun notDivisible(d, n) = 
	not(n mod d = 0);

fun test(a,b,c) = 
	if a <= b then 
		notDivisible(a, c) andalso test(a + 1, b, c)
	else notDivisible(b, c);

fun prime1(n) = n = 2 orelse test(2, n - 1, n);

fun nextPrimeAdd(add, n) = 
	if prime1(n + add) then n + add
	else nextPrimeAdd(add + 1, n);

fun nextPrime(n) = nextPrimeAdd(1, n);

fun nextPrimeA n = 
	if prime1(n + 1) then n + 1
	else nextPrimeA n + 1;

fun divides(k, n) = (n mod k = 0);

fun prime(n) = 
	let
		fun next(n, k, i) = 
			if n <= i then k
			else
				if divides(prime(i), k) then next(n, k + 1, 0)
				else next(n, k, i + 1)
	in
		if n = 0 then 2
		else next(n, prime(n - 1) + 1, 0)
	end;

fun primesList(i, n) =
	if i > n then []
	else if prime1(i) then i :: primesList(i+1, n)
	else primesList(i+1, n);

fun primes(n) = primesList(2, n);

fun len L = 
	if L = nil then 0
	else 1 + len (tl(L));

fun piFunction n = len(primes(n));