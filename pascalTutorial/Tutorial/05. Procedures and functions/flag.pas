program printFlag(output);
	
	const
		NROFROWS = 17;
		NROFCOLS = 48;
		STAR = '*';
		BLANK = ' ';

	type
		rType = 1 .. NROFROWS;
		cType = 1 .. NROFCOLS;
		tType = array[1 .. NROFROWS, 1 .. NROFCOLS] of char;

	var
		row : rType;
		col, startcol, stopcol : cType;
		flag : tType;

	procedure printTable(tbl : tType);
		var
			r : rType;
			c : cType;
	begin
		for r := 1 to NROFROWS do begin
			for c := 1 to NROFCOLS do
				write(tbl[r, c]);
			writeln;
		end;		
	end;

begin

	{ Start with a block of stars }
	for row := 1 to NROFROWS do
		for col := 1 to NROFCOLS do
			flag[row, col] := STAR;

	{ Superimpose a block of blanks in the middle leaving a border of stars }
	for row := 3 to NROFROWS - 2 do
		for col := 4 to NROFCOLS - 3 do
			flag[row, col] := BLANK;

	{ Diagonal bar from upper left to lower right }
	startcol := 4;
	for row := 3 to NROFROWS - 2 do begin
		for col := startcol to startcol + 5 do
			flag[row, col] := STAR;
		startcol := startcol + 3;
	end;

	{ Diagonal bar from upper right to lower left }
	stopcol := NROFCOLS - 3;
	for row := 3 to NROFROWS - 2 do begin
		for col := stopcol - 5 to stopcol do
			flag[row, col] := STAR;
		stopcol := stopcol - 3;
	end;	

	printTable(flag);
end.