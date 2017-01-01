program packedsample(output);

	type
		index = 1 .. 10;
	var
		{
			The packed keyword, indicates to the compiler, that the characters in 
			the array, must be packed in memory as densely as posible, in order to save space
		}
		
		chain : packed array[index] of char;
		flag : boolean;
		current : char;
		i : integer;

begin
	i := 1;
	flag := true;
	while (i <= 10) and flag do begin
		read(current);
		chain[i] := current;
		flag := current <> ' ';
		i := succ(i);
	end;

	i := 1;
	while i <= 10 do begin
		write(chain[i]);
		i := succ(i);
	end;

	writeln;
	
end.