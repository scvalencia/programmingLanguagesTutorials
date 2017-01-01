program shiftArray(input, output);

	const
		SIGNAL = 9999;
		MAXIMUM = 1000;

	type
		range = 1 .. MAXIMUM;
		collection = packed array[range] of integer;

	var
		i, size, shift : range;
		a, b : collection;
		aux : integer;

	procedure clearList(var list : collection);
		var
			i : range;
	begin
		for i := 1 to MAXIMUM do
			list[i] := 0;
	end;


	function readList(var list : collection; var shift : range) : range;
		var
			i : range;
			ans : integer;
			finished : boolean;
			flag : integer;
	begin

		writeln('Introduce the members of the list (input is processed until ', SIGNAL : 1, ' is reached.');
			finished := false;

		clearList(list);
		i := 1;
		ans := 0;

		while (not finished) and (i < MAXIMUM) do begin
			read(flag);
			if flag = SIGNAL then
				finished := not finished
			else begin
				list[i] := flag;
				i := i + 1;
				ans := ans + 1;
			end
		end;

		write('Introduce the shift: ');
		read(shift);

		readList := ans;		
	end;

	procedure printList(var lst : collection; s : range);
		var i : range;
	begin
		for i := 1 to s do
			write(lst[i], ' ');
		writeln;
	end;

begin

	size := readList(a, shift);

	for i := 1 to size do begin
		aux := abs(i + shift) mod size;
		if aux = 0 then
			b[i] := a[size]
		else
			b[i] := a[(i + shift) mod size]
	end;

	writeln;
	printList(b, size);
end.