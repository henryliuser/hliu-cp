open Printf
open Scanf
module LL = Int64
let ( !! )  x  = LL.to_int x
let ( ++ ) x y = LL.add x y
let ( -- ) x y = LL.sub x y
let ( ** ) x y = LL.mul x y
let ( // ) x y = LL.div x y
let ( %% ) x y = LL.rem x y
let ( >> ) x y = (LL.compare x y) > 0
let ( << ) x y = (LL.compare x y) < 0
let ( == ) x y = (LL.compare x y) = 0
let rd_int _ = bscanf Scanning.stdin " %d " (fun x -> x)
let rd_ll _ = bscanf Scanning.stdin " %Ld " (fun x -> x)
let rd_arr n = Array.init n rd_ll

let solve n a = 
  Array.sort LL.compare a;
  let dx = 
    if n = 1 then a.(0)
    else a.(n-1) -- a.(n-2) in

  if dx >> 1L then "NO" else "YES"

let () =
  let t = read_int () in
  for i=1 to t do
    let n = rd_int () in
    let a = rd_arr n in
    printf "%s\n" (solve n a)
  done;
