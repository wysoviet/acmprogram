main = interact $ show.maximum.scanl1 (+).map (negate.foldl1 (-).map read.words).tail.lines

