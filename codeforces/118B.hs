import Data.List
f n = [0..n] ++ [n - 1, n - 2 .. 0]
g n x = (replicate (2 *( n - x)) ' ') ++ (intersperse ' ' $ concatMap show $ f x)
main = interact $ unlines.(\n -> map (g n) (f n)).read
