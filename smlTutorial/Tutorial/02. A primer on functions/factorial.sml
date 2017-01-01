fun numPower(a,b) = Math.exp(b * Math.ln(a));

fun numericalFactorial n = 
	Math.sqrt(2.0 * Math.pi) * numPower(n,n+0.5) * Math.exp(~n);

fun fact1 n = if n < 2 then 1 else n * fact1 (n-1);

fun fact2 0 = 1
  | fact2 n = n * fact2 (n-1); 

fun fact3 n = if n = 0 then 1 else fact3(n+1) div (n+1)

fun facti(n,p) = if n = 0 then p 
				 else facti(n-1, n * p);

fun factorial n  : IntInf.int =
      if n=0 then 1 else n * factorial(n - 1);