(* https://codeforces.com/problemset/problem/1658/B *)
(* choose a permutation for odds and choose one for evens *)
open Printf
open Scanf 
module LL = Int64
let (!) x = LL.of_int x
let ( ++ ) x y = LL.add x y
let ( -- ) x y = LL.sub x y
let ( ** ) x y = LL.mul x y
let ( // ) x y = LL.div x y
let ( %% ) x y = x -- ( y ** (x // y) )

let maxn = 1001
let q = 998244353L

let fac = Array.make maxn 1L;;
for i = 1 to maxn-1 do
    fac.(i) <- !i ** fac.(i-1) %% q
done

let solve n =
    if n mod 2 = 1 
        then 0L
    else
        let m = n/2 in
        fac.(m) ** fac.(m) %% q

let () =
    let t = read_int () in
    for i=1 to t do 
        let n = read_int () in 
        printf "%Ld\n" (solve n)
    done;


