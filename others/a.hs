partition n = part n n
  where part n k | n == 0    = [[]]
                 | otherwise = concat [(map (i:) (part (n-i) i)) | i<-[1..min k n]]

