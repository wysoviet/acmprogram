import Data.List
gao x d = length . filter (`elem` d).nub $ 
          [[f a, (f b) - (f a), (f (length x)) -(f b)]| a <- [1..length x], b <- [a..length x]]  
        where f m = sum.take m $ x
main = do 
        input <- fmap lines $ readFile "input.txt" 
        let [n,m] = map (read::String->Int).words.head $ input
        let a = map (map read.words).tail $ input
        let d = nub.permutations.last $ a 
        let b = map sum $ init a
        let c = map sum.transpose $ init a
        writeFile "output.txt" .show $  (gao b d) + (gao c d)
