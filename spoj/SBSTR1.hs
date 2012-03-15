import Data.List
main = interact $ unlines.map (gao.words).lines
gao [a, b] | b `isInfixOf` a = "1" | 1 > 0 = "0"
