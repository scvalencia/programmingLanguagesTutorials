program contingencies(input, output);

	const
		NUM_WIDTH = 4;
		BLANK = ' ';

	type
		letter = 'a' .. 'z';

	var
		freqTable : array[letter, letter] of integer;
		across, down : letter;
		thischar, prevchar : char;

begin
	for across := 'a' to 'z' do
		for down := 'a' to 'z' do
			freqTable[across, down] := 0;

	prevchar := BLANK;

	while not eof do begin
		read(thischar);

		if (thischar in ['a' .. 'z']) or (prevchar in ['a' .. 'z']) then begin
			freqTable[thischar, prevchar] := succ(freqTable[thischar, prevchar]);
		end;

	end;

	writeln;

	write(BLANK : 2);

	for down := 'a' to 'z' do
		write(BLANK : NUM_WIDTH - 1, down);
	writeln; writeln;

	for across := 'a' to 'z' do begin
		write(BLANK, across);
		for down := 'a' to 'z' do
			write(freqTable[across, down] : NUM_WIDTH);
		writeln;
	end
end.