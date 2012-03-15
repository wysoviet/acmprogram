main = interact $ unlines.solve. map read. words. head. tail. lines
solve x = [show . length . gao $ x, unwords.map show. gao $ x] 
gao x = map fst. filter (ismean s l.snd) . zip [1..] $ x
	where   s = foldl1 (+) x
		l = length x
ismean s l x = x * l == s


