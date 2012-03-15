gao[[n,k],xs] = show.sum.map (\x -> if x < (3*k) then x `mod` k else x - (3*k)) $  xs
main = readFile "input.txt" >>= writeFile "output.txt" . gao . map (map read. words) . lines
