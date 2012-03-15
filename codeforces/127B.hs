import Data.List

main = do
	getLine
	a <- fmap (map (read::String->Int) . words) getLine 
	print $ (flip div 2) .sum . map ((flip div 2).length) . group . sort $ a
