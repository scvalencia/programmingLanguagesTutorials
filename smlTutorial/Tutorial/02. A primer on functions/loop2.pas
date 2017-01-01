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
		sumOfSumOfDigits2 := s
	end;

begin
	writeln(sumOfSumOfDigits(14))
end.