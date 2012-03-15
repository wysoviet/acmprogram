s t = replicate (2 * t) ' '

p _ [] = []
p l ('<':'/':r) = s (l - 1) ++ "</" ++ p (l - 1) r
p l ('<':r)     = s l ++ "<" ++ p (l + 1) r
p l ('>':r) 	= ">\n" ++ p l r
p l (x:r) 	= x:p l r

main = interact $ p 0
