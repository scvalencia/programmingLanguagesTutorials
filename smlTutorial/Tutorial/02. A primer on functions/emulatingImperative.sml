(*
	Emulating GOTO
		program stuff(output);
			label
				F, G, H;
			var
				x, y, z : integer;
		begin
			x := 0; y := 0; z := 0;
			F:
				x := x + 1;
				goto G;
			G:
				if y < z then goto F
				else begin
					y := y + x;
					goto H;
				end;
			H:
				if z > 0 then begin
					z := z - x;
					goto F;
				end
		end.

	run goto.pas
*)

(* A function per label *)

fun
	F(x, y, z) = G(x + 1, y, z)
and
	G(x, y, z) = 
		if y < z then F(x, y, z)
		else H(x, y + x, z)
and
	H(x, y, z) = 
		if z > 0 then F(x, y, z - x)
		else (x, y, z)

(*
	Emulating While loop

		Theorem:

			The functional program:

				fun prog(x) = 
					let
						fun loop(y) = 
							if b(y) then loop(g(y))
							else y
					in
						h(loop(f(x)))
					end


			is equivalent to the imperative program:

				y := f(x);
				while b(y) do
					y := g(y);
				z := h(y)


			for all input for which the imperative program halts

			x : Input data
			y : Aux variables of the program
			z : Output variables
			f(x) : Initialisation of program variables
			g(y) : Body of the loop
			h(y) : Exit operation

		The program written in Pascal loop1, has as equivalent:
		
		program loop1(output);
		type
			sequence = array [0 .. 9] of real;
		var
			list : sequence;

		function sum(n : integer; seq : sequence) : real;
			var res : real; i : integer;
		begin
			res := 0.0; i := 0;
			while i <= n do begin
				res := res + seq[i];
				i := i + 1
			end;
			sum := res
		end;

		begin
			...
		end.

*)

(*
	x : n, seq
	y : res, i
	z : sum
	f(x) : (0.0, 1)
	g(y) : (res + seq(i), i + 1)
	h(y) : res
*)

fun index i seq = List.nth (seq, i - 1);

fun loop1(n, seq : real list) = 
	let
		fun loop(res, i) =
			if i <= n then loop(res + (index i seq), i + 1)
			else (res, i)
	in
		let
			val (res, i) = loop(0.0, 1)
		in
			res
		end
	end


(*
	Example: translate the following program from Pascal to SML

	program summation(output);

		function sumOfSumOfDigits(n : integer) : integer;
			var s, i, j : integer;
		begin
			s := 0; i := 1;
			for i := 1 to n do begin
				j := i;
				while j > 0 do begin
					s := s + j mod 10;
					j := j div 10;
				end
			end;
			sumOfSumOfDigits := s
		end;

	begin
		writeln(sumOfSumOfDigits(143))
	end.

	1. Translate the program into a complete while program

		function sumOfSumOfDigits2(n : integer) : integer;
			var s, i, j : integer;
		begin
			s := 0; i := 1; i := 1;
			while i <= n do begin
				j := i;
				while j > 0 do begin
					s := s + j mod 10;
					j := j div 10;
				end
			end;
			sumOfSumOfDigits := s
		end;

	2. Translate the inner loop:

		j := i;
		while j > 0 do begin
			s := s + j mod 10;
			j := j div 10;
		end

		x : s, i
		y : s, i
		z : s, j
		f(x) : s, i
		g(y) : (s + j mod 10, j div 10)
		h(y) : (s, i + 1)

		fun jloop(s, i) = 
			let
				fun loop(s, i) =
					if j > 0 then
						loop(s + j mod 10, j div 10)
					else
						(s, i)
			in
				let
					val (s, i, j) = loop(s, i, i)
				in
					(s, i + 1)
				end
			end

	3. Rewrite the Pascal function

		function sumOfSumOfDigits2(n : integer) : integer;
			var s, i, j : integer;
		begin
			s := 0; i := 1; i := 1;
			while i <= n do begin
				j := i;
				jloop(s, i)
			end;
			sumOfSumOfDigits := s
		end;

	4. Translate the other loop:

		s := 0; i := 1;
		while i <= n do begin
			j := i;
			jloop(s, i)
		end;
		sumOfSumOfDigits := s

		x : n
		y : s, i
		z : sumOfSumOfDigits
		f(x) : (0, 1, 1)
		g(y) : (jloop(s, i), i)
		h(y) : s

		fun sumOfSumOfDigits(n) =
			let
				fun iloop(s, i) = 
					if y <= n then iloop(jloop(s, i))
					else (s, i)
			in
				let
					val (s, i) = iloop(0, 1)
				in
					s
				end
			end

*)

fun sumOfSumOfDigits(n) =
	let
		fun = iloop(s, i) =
			let
				fun jloop(s, i) =
					let fun loop(s, i, j) = 
						if j > 0 then loop(s + j mod 10, i, j div 10)
						else (s, i, j)
					in 
						let 
							val (s, i, j) = loop(s, i, i)
						in 
							(s, i + 1)
						end
					end
			in
				if i <= n then iloop(jloop(s, i))
				else (s, i)
			end
	in
		let
			val (s, i) = iloop(0, 1)
		in
			s
		end
	end