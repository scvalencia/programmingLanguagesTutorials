program randomtest;

	const
		MAX_RANDOM = 9;
		TESTS = 10000;

	type
		sequence = array[0..TESTS] of integer;

	var
		seed, i : integer;
		list : sequence;
		flag : boolean;

	function random(var seed : integer) : integer;
		const
			MULTIPLIER = 25173;
			INCREMENT = 13849;
			MODULUS = 65536;
	begin
		random := seed;
		seed := (MULTIPLIER * seed + INCREMENT) mod MODULUS;
	end;

begin

	read(seed);

	for i := 0 to TESTS do
		list[i] := abs(random(seed) mod MAX_RANDOM);

	for i:= 0 to (TESTS - 7) do begin
		flag := list[i] = 1;
		flag := flag and (list[i + 2] = 2);
		flag := flag and (list[i + 3] = 3);
		flag := flag and (list[i + 4] = 4);
		flag := flag and (list[i + 5] = 5);
		flag := flag and (list[i + 6] = 6);
		flag := flag and (list[i + 7] = 7);
	end;

	writeln(flag);
	
end.
