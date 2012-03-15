main = interact $ show.gao.map read.words
gao [0, 0] = 0;
gao [a, b] = gao[a `div` 3, b `div` 3] * 3 + (3 + b - a) `mod` 3
