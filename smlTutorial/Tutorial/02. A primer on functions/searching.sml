fun find [] target pos = pos
  | find (x::xs) target pos = 
  		if x = target then pos 
   		else find xs target (pos + 1);

fun search lst target =                                                
 	let 
 	    val pos = length lst
        val res = find lst target 1
    in
 	    if res > pos then ~1 else res
	end;

fun linearSearch lst trgt = 
	let
	 	val found : int = search lst trgt
	in
	 	if found = ~1 then false else true
	end;

fun isSorted [] = true
  | isSorted (x::[]) = true 
  | isSorted (x::xs) = x < hd xs andalso isSorted xs;

fun binSearchAux(lst, target, min, max) = 
	if max < min then ~1 
	else
		let
			val midpoint = (fn (min, max) => (max + ((min - max) div 2)))
			val mid = midpoint(min, max)
			val mid_itm = List.nth(lst, mid)
		in
			if mid_itm > target then binSearchAux(lst, target, min, (mid - 1))
			else if mid_itm < target then binSearchAux(lst, target, (mid + 1), max)
			else mid
		end;

fun binSearch lst key = 
	if not (isSorted lst) then ~1 (* should raise an error, listNotSoted error *)
	else
		let
			val min =  List.nth(lst, 0)
			val len = length lst
			val max =  List.nth(lst, len - 1)
		in
			if key < min orelse key > max then ~1 (* outOf bounds error *)
			else binSearchAux(lst, key, 0, length lst)
		end;