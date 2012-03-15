gao '>' = 8
gao '<' = 9
gao '+' = 10
gao '-' = 11
gao '.' = 12
gao ',' = 13
gao '[' = 14
gao ']' = 15

main = interact $ show.foldl (\acc x -> ((gao x) + acc * 16) `mod` 1000003) 0.head.words 

