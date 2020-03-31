msort :: (Ord a) => [a] -> [a]  --merge sort in haskell
msort [] = [] --empty list is sorted
msort [x] = [x] --list of one element is sorted
msort xs = let (as, bs) = splitAt (length xs `quot` 2) xs -- this takes the list and splits into two, calls msort on both halves
               in merge (msort as) (msort bs) -- merges the results together using 'merge' as seen below
merge [] ys = ys --merging an empty list with a list just gives u the list
merge xs [] = xs --merging a list with empty list gives u original list
merge (x:xs) (y:ys) = if x <= y --this takes the smaller number of the first elements in the list then merge is called recursively until fully merged
                      then x : merge xs (y:ys)
                      else y : merge (x:xs) ys

main = print(msort[4, 65, 2, -31, 0, 99, 2, 83, 782, 1])