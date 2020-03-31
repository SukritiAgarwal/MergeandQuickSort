--Assignment 1 - Quick sort in Haskell
--Sukriti Agarwal

qsort :: (Ord a) => [a] -> [a]  --Quick sort a list in Haskell
--an empty list is an already sorted list
qsort [] = [] 

--Pivot is the head for quick sort
qsort (p:xs) =  

--call qsort on list of elements smaller than pivot element and also on list larger than element
    let left = qsort [a | a <- xs, a <= p] --Smaller or equal to pivot on the left
        right = qsort [a | a <- xs, a > p] --Greater than pivot on the right

--take head of list to be pivot and concatenate between (list thats smaller than pivot) and (list thats bigger than pivot)
    in  left ++ [p] ++ right 

main = print(qsort[4, 65, 2, -31, 0, 99, 2, 83, 782, 1])