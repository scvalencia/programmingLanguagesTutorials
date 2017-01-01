program histogramOfGrades(input, output);

	const
		LETTERS = 6;
		ROWS = 20;
		COLS = 36;
		STAR = '*';
		BLANK = ' ';
		LINE = '==================================================';

	type
		rowtype = packed array[1 .. ROWS] of char;

	var
		histogram : array[1 .. ROWS] of rowtype;
		allblank : rowtype;
		frequency : array[1 .. LETTERS] of 0..10000;
		percent : array[1 .. LETTERS] of real;
		letter : 1 .. LETTERS;
		row : 1 .. ROWS;
		col : 1 .. COLS;
		grades : 0 .. 60000;
		barheight, topofbar : 0 .. 21;

begin
	for col := 1 to COLS do
		allblank[col] := BLANK;

	{ Read frequencies and calculate total number of grades : 1 -> A, 2 -> B, .., 6 -> INC}
	grades := 0;
	writeln('Input data frequency: ');
	for letter := 1 to LETTERS do begin
		read(frequency[letter]);
		write(frequency[letter]);
		grades := grades + frequency[letter];
	end;

	for letter := 1 to LETTERS do begin
		percent[letter] := 100 * (frequency[letter] / grades);
		barheight := round(percent[letter] / 5);

		topofbar := 21 - barheight;
		for col := 6 * letter - 5 to 6 * letter - 1 do begin
			for row := 1 to topofbar - 1 do
				histogram[row, col] := BLANK;

			for row := topofbar to rows do
				histogram[row, col] := STAR;
		end;

		for row := 1 to rows do
			histogram[row, 6 * letter] := BLANK;
	end;

	writeln;
	writeln(line);
	writeln('			Letter grade distribution');
	writeln;

	for row := 1 to rows do
		if histogram[row] <> allblank then 
			writeln(histogram[row]);

	writeln(line);
	writeln('	A 	B 	C 	D 	F 	INC');
	writeln;
	writeln('Vertical scale:  1 line = 5%');
	writeln;

	write('percents: ');
	for letter := 1 to LETTERS do
		write(percent[letter] : 7:2);
	writeln;
	
end.