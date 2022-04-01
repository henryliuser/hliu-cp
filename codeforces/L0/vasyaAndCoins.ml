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

let solve x y =
  if x = 0L then 1L
  else x+2L*y+1L

let () =
  let t = read_int () in
  for i=1 to t do
    let n = rd_ll () in
    let x = rd_ll () in
    printf "%Ld\n" (solve n x)
  done;