import Data.List
import Control.Monad

swap (a, b) = (b, a)

solve d events = nubBy (\a b -> a == b || a == swap b) 
   [(a1, b1) | (a1, b1, t1) <- events, (a2, b2, t2) <- events,
    a1 == b2 , b1 == a2, t1 < t2, t2 - t1 <= d]

getEvent = do [name1, name2, t] <- fmap words getLine 
              return (name1, name2, read t)


printFriends (name1, name2, t) = putStrLn (name1 ++ " " ++ name2)

main = do [n, d] <- fmap (map read.words) getLine
                    events <- replicateM n getEvent

		    let friends = solve d events

		    putStrLn $ show $ length friends
		    sequence_ $ map printFriends friends
