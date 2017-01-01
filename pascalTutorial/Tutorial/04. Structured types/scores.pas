PROGRAM SCORES(INPUT, OUTPUT);

	CONST 
		MAXENROLLMENT = 100;
		SIGNAL = 9999;

	VAR
		ENROLLMENT : 0 .. MAXENROLLMENT;
		I : 1 .. MAXENROLLMENT;
		OUTDATA : BOOLEAN;
		SUM, NEXTSCORE : REAL;
		SCORE : PACKED ARRAY[1 .. MAXENROLLMENT] OF REAL;

BEGIN

	ENROLLMENT := 0;

	OUTDATA := FALSE;
	WHILE (NOT OUTDATA) AND (ENROLLMENT < MAXENROLLMENT) DO BEGIN
		READ(NEXTSCORE);
		IF NEXTSCORE = SIGNAL THEN
			OUTDATA := NOT OUTDATA
		ELSE BEGIN
			WRITELN('Input data nextscore: ', nextscore : 7 : 2);
			ENROLLMENT := ENROLLMENT + 1;
			SCORE[ENROLLMENT] := NEXTSCORE
		END;
	END;

	IF NOT OUTDATA THEN BEGIN
		READ(NEXTSCORE);
		IF NEXTSCORE <> SIGNAL THEN BEGIN
			WRITELN('The input data consists of more than ', MAXENROLLMENT : 1, ' scores');
			WRITELN('Only the first ', MAXENROLLMENT : 1, ' have been used')
		END;
	END;

	SUM := 0;
	FOR I := 1 TO ENROLLMENT DO
		SUM := SUM + SCORE[I];

	WRITELN;
	WRITELN('There are ', ENROLLMENT : 1, ' test socres');
	WRITELN('Average test score = ', SUM / ENROLLMENT : 1 : 3)

END.