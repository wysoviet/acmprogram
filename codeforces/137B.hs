import List
main = interact $ show. gao. map read. words
gao (n:xs) = n - (length. takeWhile (<=n). map head.group.sort $ xs)
