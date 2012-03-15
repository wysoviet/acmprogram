import Data.List
main = do 
	a <- getLine
	let b = length.filter (=='4') $ a
	let c = length.filter (=='7') $ a
	putStrLn $ if max b c == 0 
			then "-1"
			else if b >= c 
				then "4"
				else "7"
