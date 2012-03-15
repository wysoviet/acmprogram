main = interact gao
gao x = if any (`elem` "HQ9") x then "YES" else "NO"
