program removeDuplicates(input, output);

	const
		MAX_SIZE = 100;
		MAX_NUM = 127;
		MIN_NUM = -128;

	var
		list : array[0..MAX_SIZE] of integer;
		freq : array[MIN_NUM..MAX_NUM] of integer;

		size, counter, num : integer;


	procedure main();
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
	main();

	for counter := 0 to (size - 1) do begin
		num := list[counter];
		if freq[num] = 1 then
			write(num, ' ');
	end;
	
	writeln;
end.
