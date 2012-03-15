main = interact (lucky.read) 
lucky x 
	| all (`elem` "47") . show $ x = "YES" 
	| any ((=="YES").lucky) $ [y | y <- [1..x-1], mod x y == 0] = "YES"
	| otherwise = "NO"
