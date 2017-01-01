program multiplicationTable(output);
	var
		table : array [1 .. 10, 1 .. 10] of integer;
		row, col :  1 .. 10;

begin
	for row := 1 to 10 do
		for col := 1 to 10 do
			table[row, col] := row * col;

	writeln;

	for row := 1 to 10 do begin
		for col := 1 to 10 do
			write(table[row, col] : 6);
		writeln;
	end;

	writeln;

end.