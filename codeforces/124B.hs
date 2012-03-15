import Data.List

main = do
	getLine	
	interact (minimum.map (\x->((maximum x) - (minimum x))).transpose.map ((map read).permutations).words) 

