program smallestreg(input, output);

	const
		MAX_NUM_REGS = 1000;
		SIZE_OF_CODE = 5;

	type
		numregsindex = 0..MAX_NUM_REGS;
		codeindex = 0..SIZE_OF_CODE;
		codes = packed array[codeindex] of char;

	var
		numofrecords, i, ties : integer;
		current, currentcode : codes;
		minimum, currentscore : real;
		regcodes : array[numregsindex] of codes;
		regscores : array[numregsindex] of real;

	procedure readlist;
		var i, j : integer;
	begin
		write('Number of registers: '); read(numofrecords);

		for i := 0 to (numofrecords - 1) do begin
			write('Code of employee: ');
			for j := 0 to SIZE_OF_CODE do
				read(current[j]);				
			regcodes[i] := current; 
			write('ERA of employee: '); read(regscores[i]);
		end;
	end;

	function getbestregister() : real;
		var 
			i : integer;
			minimum, currentscore : real;
	begin
		minimum := 99999.00;
		for i := 0 to (numofrecords - 1) do begin
			currentscore := regscores[i];
			if currentscore < minimum then
				minimum := currentscore;
		end;

		getbestregister := minimum;

	end;

begin
	readlist;
	minimum := getbestregister();
	ties := 0;
	writeln('Out of ', numofrecords, ' employees:');
	writeln('The best ERA is ', minimum:2:2);

	for i := 0 to (numofrecords - 1) do begin
		currentscore := regscores[i];
		currentcode := regcodes[i];

		if currentscore = minimum then begin
			ties := ties + 1;
			if ties = 1 then
				writeln('Employee number ', currentcode, '.')
			else
				writeln('and employee number ', currentcode, '.');
		end;

	end; 
end.