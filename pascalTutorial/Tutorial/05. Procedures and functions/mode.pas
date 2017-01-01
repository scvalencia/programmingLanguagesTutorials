program mode(input, output);

	const
		MAX_SIZE = 100;
		MAX_NUM = 127;
		MIN_NUM = -128;

	var
		list : array[0..MAX_SIZE] of integer;
		freq : array[MIN_NUM..MAX_NUM] of integer;

		size, counter, num, cmax, cmode : integer;

	function max(a, b, md : integer) : integer;
	begin
		if a > b then
			max := a
		else begin
			max := b;
			cmode := md;
		end;
	end;

	procedure inputlist();
		var
			i, current : integer;
	begin

		for i := MIN_NUM to MAX_NUM do
			freq[i] := 0;

		read(size);

		for i := 0 to (size - 1) do begin
			read(current);
			list[i] := current;
			freq[current] := succ(freq[current])
		end;
		
	end;

begin
	inputlist;

	for counter := 0 to (size - 1) do begin
		num := list[counter];
		if freq[num] > 0 then begin
			cmax := max(cmax, freq[num], num);
		end;
	end;

	writeln(cmode);
end.