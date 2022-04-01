open Printf
open Scanf
let rd_int _ = bscanf Scanning.stdin " %d " (fun x -> x)
let rd_str _ = bscanf Scanning.stdin " %s " (fun x -> x)
let rd_mat n = Array.init n rd_str

let diag i j n = (i - j + n) mod n
let c2i ch = int_of_char ch - int_of_char '0'
let solve n mat = 
  let s = ref 0 in
  let cnt = Array.init n (fun _ -> 0) in
  for i=0 to n-1 do
    for j=0 to n-1 do
      let d = diag i j n in 
      let c = cnt.(d) in 
      let x = c2i mat.(i).[j] in
      cnt.(d) <- (c + x);
      s := !s + x;
    done;
  done;
  let best = (Array.fold_right max cnt 0) in
  let offD = !s - best in
    n - best + offD

let () =
  let t = rd_int () in
  for i=1 to t do
    let n = rd_int () in
    let mat = rd_mat n in
    printf "%d\n" (solve n mat)
  done;