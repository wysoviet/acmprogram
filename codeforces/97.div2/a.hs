import Data.List
main = interact $ unwords. map show. gao. map read. words
gao (n:s) = map snd. sort . map swap. zip [1..n] $ s 
swap (a, b) = (b, a)
