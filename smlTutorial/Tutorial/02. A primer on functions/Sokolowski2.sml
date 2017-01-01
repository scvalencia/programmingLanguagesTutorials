(* Exercise 3, How will the following program evaluate *)

fun f(n) =
		if n = 0 then 1
		else f(n - 1) + g(n - 1, n - 1)
and g(n, k) =
		if k = 0 then 0
		else f(n) + g(n, k - 1);

(* Exercise 6, Find an SML counterpart of the bubble sort *)

fun index i seq = List.nth (seq, i - 1);

fun split(lst, i) = 
	let
		fun auxSplit(lst, i, j) =
			if i = j then
				(List.take(lst, j - 1), List.drop(lst, j))
			else auxSplit(lst, i + 1, j)
	in 
		auxSplit(lst, 0, i)
	end

fun swap(lst, i, j) =
	let
		val a = index i lst
		val b = index j lst
		val aparts = split(lst, i)

	in
		let
			val first = (#1 aparts) @ [b] @ (#2 aparts)
			val bparts = split(first, j)
			val second = (#1 bparts) @ [a] @ (#2 bparts)

		in
			second
		end
		
	end

(*
fun innerLoop(lst, index) = 
	let
		fun loop(a, j) =
			if j <= i then 
				if (index j a) > (index (j + 1) a) then
					loop(swap(a, j, j + 1), j + 1)
				else
					loop(a, j + 1)
			else
				(a, j)
	in
		val (a, j) = loop(lst, 1)
	end
*)

fun bubble_select [] lessThan =[]
  | bubble_select [a] lessThan =[a]
  | bubble_select (a::b::xs) lessThan =
    if lessThan b a then b::(bubble_select(a::xs) lessThan) else a::(bubble_select(b::xs) lessThan)
 
 
 
fun bubblesort [] lessthan =[]
  | bubblesort (x::xs) lessthan =bubble_select (x::(bubblesort xs lessthan)) lessthan

(* sorted : int list -> bool
 * check if a list of ints is sorted *)
fun sorted []         = true
  | sorted [x]        = true
  | sorted (x::y::xs) = x < y andalso sorted (y::xs)
 
val sorted_test1 = sorted [1,2,3]
val sorted_test2 = not (sorted [2,1,3])
val sorted_test3 = not (sorted [2,3,1])
val sorted_test4 = sorted []
 
local
  (* bSort' : int list -> int list
   * sort a list of ints just a little *)
  fun bSort' [] = []
    | bSort' [x] = [x]
    | bSort' (x::y::xs) = case Int.compare (x,y) of
                               GREATER => y :: x :: xs
                             | EQUAL   => x :: y :: xs
                             | LESS    => x :: bSort' (y::xs)
 
  (* function for doing fix point iteration *)
  fun fix f x = if f x = x then x
                else fix f (f x)
in
  (* bSort : int list -> int list
     using bSort' and fix point interation, sort a list of ints *)
  fun bSort x = fix bSort' x
end
 
val bSort_test1 = bSort [5,3,4,2,1] = [1,2,3,4,5]

fun bubble [] = []
  | bubble [x] = [x]
  | bubble (x::y::rest) = 
    if x >= y then 
      bubble (y::(bubble (x::rest)))
    else 
      x::(bubble (y::rest))