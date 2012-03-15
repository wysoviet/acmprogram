solve ["front","1"] = "L"
solve ["front","2"] = "R"
solve ["back", "1"] = "R"
solve ["back", "2"] = "L"

main = readFile "input.txt" >>= writeFile "output.txt" . solve . words 
