(* This is a comment. This is an exploration
 ** on expression *)

(* val <id> = <expression> *)
val x = 34; (* so 34 is an int, x is an int *)
(* static enviroment: x : int *)
(* dyanmic enviroment: x -> 34 *)
val y = 17;
(* static enviroment: x : int, y : int *)
(* dyanmic enviroment: x -> 34, y -> 17 *)
val z = (x + y) + (y + 2);
(* static enviroment: x : int, y : int, z : int *)
(* dyanmic enviroment: x -> 34, y -> 17, z -> 70 *)
val q = z + 1;
(* static enviroment: x : int, y : int, z : int, q : int *)
(* dyanmic enviroment: x -> 34, y -> 17, z -> 70, q -> 71 *)




