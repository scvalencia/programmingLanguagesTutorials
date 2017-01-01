program printLists(input, output);
	const
		LISTS = 2;
		SIGNAL = 9999;
		MAXIMUM = 100;

	type
		range = 1 .. MAXIMUM;
		collection = packed array[range] of real;

	var
		i : range;
		a, b : collection;
		lengtha, lengthb : integer;

	procedure clearList(var list : collection);
		var
			i : range;
	begin
		for i := 1 to MAXIMUM do
			list[i] := 0;
	end;


	function readList(var list : collection) : range;
		var
			i : range;
			ans : integer;
			finished : boolean;
			flag : real;
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
		readList := ans;		
	end;

	function max(a, b : range) : range;
	begin
		if a > b then
			max := a
		else
			max := b
	end;

	procedure padding(var list : collection; size, bound : range);
		var
			i : range;
	begin
		for i := size + 1 to bound do
			list[i] := SIGNAL		
	end;

begin

	lengtha :=  readList(a);
	lengthb := readList(b);


	if lengtha > lengthb then
		padding(b, lengthb, lengtha)

	else
		padding(a, lengtha, lengthb);

	writeln;

	for i := 1 to max(lengtha, lengthb) do begin
		if a[i] = SIGNAL then
			writeln(' ' : 6, ' ', b[i] : 2 : 3)
		else if b[i] = SIGNAL then 
			writeln(a[i] : 2 : 3)
		else
			writeln(a[i] : 2 : 3, ' ', b[i] : 2 : 3)
	end	
end.