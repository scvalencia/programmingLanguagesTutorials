(* This function tells if an int list, is sorted *)
fun isSorted [] = true
  | isSorted (x::[]) = true 
  | isSorted (x::xs) = x < hd xs andalso isSorted xs;


(* This function serves as auxiliar for the main binSearch algorithm *)
fun binSearchAux(lst, target, min, max) = 
	if max < min then ~1 (* Base case *)
	else
		let
			val midpoint = (fn (min, max) => (max + ((min - max) div 2)))
			val mid = midpoint(min, max)
			val mid_itm = List.nth(lst, mid)
		in
			if mid_itm > target then 
				binSearchAux(lst, target, min, (mid - 1))
			else if mid_itm < target then 
				binSearchAux(lst, target, (mid + 1), max)
			else mid (* Base case *)
		end;


(* Main binary search function, this should be used no others *)
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

(* A function to tell whether or not, a value is present in a list *)
fun contains [] _ = false
  | contains (x::xs) key = binSearch (x::xs) key <> ~1;