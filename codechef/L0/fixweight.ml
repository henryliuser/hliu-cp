(* https://www.codechef.com/COOK139B/problems/FIXWEIGHT *)
(* just brute force *)
open Printf
open Scanf 
module LL = Int64
let rd_ll () = bscanf Scanning.stdin " %Ld " (fun x -> x)

let (&) x = LL.of_int x
let ( + ) x y = LL.add x y
let ( - ) x y = LL.sub x y
let ( * ) x y = LL.mul x y
let ( / ) x y = LL.div x y
let ( % ) x y = x - ( y * (x / y) ) 

let solve n x = 
  let rec go i = 
    if i > n then false
    else if (x % i) <> 0L then go (i+1L)
    else 
      let q = x / i in
      if q <= (n-i+1L) then true
      else go (i+1L)
  in 
  if (go 1L) then "YES" else "NO"

let () =
  let t = read_int () in
  for i=1 to t do 
    let n = rd_ll () in 
    let x = rd_ll () in
    printf "%s\n" (solve n x)
  done;



