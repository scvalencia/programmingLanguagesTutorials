program matrix1(input, output);
	const
		SIZE = 3;
	type
		subscript = 1 .. SIZE;
		matrix = array[subscript, subscript] of integer;
	var
		a, b, c : matrix;

	procedure readMatrix(var m : matrix);
		var
			i, j : subscript;
	begin
		for i := 1 to SIZE do
			for j := 1 to SIZE do
				read(m[i, j])		
	end;

	procedure initUnitMatrix(var m : matrix);
		var
			i, j : subscript;
	begin
		for i := 1 to SIZE do
			for j := 1 to SIZE do
				if i = j then m[i, j] := 1
				else m[i, j] := 0;		
	end;

	procedure writeMatrix(var m : matrix);
		var
			i, j : subscript;
	begin
		for i := 1 to SIZE do begin
			for j := 1 to SIZE do
				write(m[i, j]:3, ' ');
			writeln();
		end		
	end;

	procedure addMatrices(var a, b, c : matrix);
		var
			i, j : subscript;
	begin
		for i := 1 to SIZE do
			for j := 1 to SIZE do
				c[i, j] := a[i, j] + b[i, j];		
	end;

	procedure substractMatrices(var a, b, c : matrix);
		var
			i, j : subscript;
	begin
		for i := 1 to SIZE do
			for j := 1 to SIZE do
				c[i, j] := a[i, j] - b[i, j];		
	end;

	procedure multiplytMatrices(var a, b, c : matrix);
		var
			i, j, k : subscript;
	begin
		for i := 1 to SIZE do
			for j := 1 to SIZE do begin
				c[i, j] := 0;
				for k := 1 to SIZE do
					c[i, j] := c[i, j] + a[i, k] * b[k, j]
			end	
	end;

begin

	readMatrix(a);
	writeln();
	readMatrix(b);
	writeln();
	addMatrices(a, b, c);
	writeMatrix(c);
	writeln();
	substractMatrices(a, b, c);
	writeMatrix(c);
	writeln();
	multiplytMatrices(a, b, c);
	writeMatrix(c);
	writeln();
	initUnitMatrix(b);
	multiplytMatrices(a, b, c);
	writeMatrix(a);
	writeMatrix(c);
	
end.