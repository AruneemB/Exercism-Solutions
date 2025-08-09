type nucleotide = A | C | G | T

let hamming_distance (s1 : nucleotide list) (s2 : nucleotide list) : (int, string) result =
  let rec aux l1 l2 count =
    match (l1, l2) with
    | ([], []) -> Ok count
    | (x1::t1, x2::t2) ->
        let count' = if x1 = x2 then count else count + 1 in
        aux t1 t2 count'
    | _ -> Error "strands must be of equal length"
  in
  aux s1 s2 0
