main = interact $ show.solve.read
solve x = minimum.map (gao).zip [1..x] $ repeat x
gao (a,b) | a == 1 = b - 1 | b `mod` a == 0 = 1000000 | 1>0 = b `div` a + gao (b `mod` a, a)
