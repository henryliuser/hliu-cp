(* code by @xsd (atcoder) *)
Scanf.scanf "%d %d" (fun n p ->
  let ( +@) a b = (a + b) mod p in
  let rec loop i con non =
      if i = n then con else
          let nxtcon = Array.make n 0 in
          let nxtnon = Array.make n 0 in
          let () =
              Array.iteri (fun i v ->
                  nxtcon.(i) <- nxtcon.(i) +@ v;
                  if i + 1 < n then nxtcon.(i + 1) <- nxtcon.(i + 1) +@ (3 * v);
                  if i + 2 < n then nxtnon.(i + 2) <- nxtnon.(i + 2) +@ (2 * v);
              ) con;
              Array.iteri (fun i v ->
                  nxtcon.(i) <- nxtcon.(i) +@ v;
                  if i + 1 < n then nxtnon.(i + 1) <- nxtnon.(i + 1) +@ v;
              ) non;
          in
          loop (i + 1) nxtcon nxtnon
  in
  let icon = Array.make n 0 in
  let inon = Array.make n 0 in
  icon.(0) <- 1;
  inon.(1) <- 1;
  let con = loop 1 icon inon in
  Array.iteri (fun i v -> if i > 0 then Printf.printf "%d " v) con
)