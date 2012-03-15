import Data.List
main = interact $ show. gao. head. words
gao x = sum . map (cal. length) . group $ x
cal x = x `div` 5 + if (x `mod` 5 == 0) then 0 else 1 

