fun max lst = 
	let
		fun max_aux(lst, flag, counter) = 
			if lst = [] then (flag, counter)
			else if hd(lst) > flag then
				max_aux(tl(lst), hd(lst), counter + 1)
			else
				max_aux(tl(lst), flag, counter + 1)
	in
		max_aux(lst, hd(lst), 0)
	end

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
			if lst = nil then []
			else second
		end
		
	end

(* Buggy selection sort *)
fun selection_sort(lst) = 
	if lst = nil then nil
	else
		let
			val tail = tl(lst)
			val maximum = max lst
			val index = #2 maximum
			val value = #1 maximum
		in
			if lst = nil then nil
			else
				value :: selection_sort(swap(tail, 1, index))

		end
