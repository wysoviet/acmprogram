import Data.Char

solve [a, b] = 
	case compare a b of
		LT -> -1
		GT -> 1
		EQ -> 0
		
main = interact $ (show. solve. map (map toUpper).words)
