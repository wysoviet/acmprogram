solve [[n,k],xs] = show.fst.head.dropWhile ((==0).snd). drop (k-1).cycle.zip [1..n] $ xs
main = readFile "input.txt" >>= writeFile "output.txt".solve.map(map read.words).lines
