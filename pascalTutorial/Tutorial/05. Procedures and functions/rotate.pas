program rotate(input, output);

	const
		MAX_SIZE = 1000;

	type
		sequence = array[0..MAX_SIZE] of integer;

	var
		original, result : sequence;
		size, shift, i : integer;

	procedure inputlist;
		var
			i: integer;
	begin
		write('n: '); read(size);
		writeln;
		for i := 0 to (size - 1) do begin
			write('INPUT[', i, ']: ');
			read(original[i]);
		end;
	end;

	procedure rotatespace;
		var
			i, current, newpos : integer;
	begin
		for i := 0 to (size - 1) do begin
			current := original[i];
			if i <= shift then begin
				newpos := abs(i - shift + 1);
				result[size - newpos] := current; 
			end else begin
				newpos := i - shift;
				result[newpos] := current
			end;
		end;

	end;

begin
	inputlist;

	writeln;
	write('shift: '); read(shift);

	rotatespace;

	for i := 0 to (size - 1) do
		write(result[i], ' ');

	writeln;

end.