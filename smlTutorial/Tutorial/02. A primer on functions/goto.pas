program stuff(output);
	label
		F, G, H;
	var
		x, y, z : integer;
begin
	x := 0; y := 0; z := 0;
	F:
		x := x + 1;
		goto G;
	G:
		if y < z then goto F
		else begin
			y := y + x;
			goto H;
		end;
	H:
		if z > 0 then begin
			z := z - x;
			goto F;
		end;

	writeln('x = ', x);
	writeln('y = ', y);
	writeln('z = ', z);
end.