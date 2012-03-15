import Data.List
import Data.Char

main = do
	a <- fmap (map toLower) getLine
	let b = "aoyeui" 
	let c = [x| x <- a, not (elem x b)] 
	putStrLn $ "." ++ intersperse '.' c 
