import Data.Char
main = interact $ gao . head . lines
gao al@(x:xs) 
	| all (`elem` ['A'..'Z']) xs = map (\x->if isUpper x then toLower x else toUpper x) al 
	| otherwise = al
