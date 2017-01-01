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
	list[1] := 12.0;
	list[2] := 10.0;
	list[3] := 19.0;
	list[4] := 24.0;
	list[5] := 45.0;
	list[6] := 14.0;
	list[7] := 67.0;
	list[8] := 90.0;
	list[9] := 00.0;

	writeln(sum(3, list) : 5 : 2)
end.