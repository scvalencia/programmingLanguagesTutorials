program listUnion(input, output);

	const
		MAX_SIZE = 100;
		MAX_NUM = 127;
		MIN_NUM = -128;

	type
		vector = array[0..MAX_SIZE] of integer;

	var
		list1, list2 : vector;
		freq : array[MIN_NUM..MAX_NUM] of integer;

		size1, size2, counter, num : integer;


	procedure inputlist(var list : vector; var size : integer);
		var
			i, current : integer;
	begin

		for i := 0 to MAX_SIZE do
			list[i] := 0;

		read(size);

		for i := 0 to (size - 1) do begin
			read(current);
			list[i] := current;
			freq[current] := succ(freq[current])
		end;
		
	end;

begin

	inputlist(list1, size1);
	inputlist(list2, size2);

	for counter := 0 to (size1 - 1) do begin
		num := list1[counter];
		if freq[num] > 0 then begin
			write(num, ' ');
			freq[num] := 0;
		end;
	end;

	for counter := 0 to (size2 - 1) do begin
		num := list2[counter];
		if freq[num] > 0 then
			write(num, ' ');
	end;
	
	writeln;
end.
