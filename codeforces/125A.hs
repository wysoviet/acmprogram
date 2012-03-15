main = do
 	a <- fmap read getLine
	let b = div a 3 +  (if mod a 3 > 1 then 1 else 0)
	putStrLn $ show (div b 12) ++ " " ++ show (mod b 12)

