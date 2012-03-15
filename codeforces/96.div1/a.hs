toBits 0 n = []
toBits i n = (n `mod` 2) : toBits (i-1) (n `div` 2) 

fromBits [] = 0
fromBits (h:t) = 2 * fromBits t + h

rev = fromBits . reverse . toBits 8

recover l = zipWith (-) (0:l) l

to256 = map (`mod` 256)

s l = to256 $ recover (map (rev.fromEnum) l)
main = interact $ unlines.map show.s.head.lines

