import Data.List
main = interact $ unwords.map show. gao. map read. tail. words
gao x = sort.reverse.ch.reverse.sort $ x
ch (x:s) | x == 1 = 2:s | 1 > 0 = 1:s
