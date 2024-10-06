--1
-- foo [1,2,3] [4,5,6,7,8] = [1:foo ys xs]
-- foo [4,5,6,7,8] [2,3] = [1,4:foo ys xs]
-- foo [2,3] [5,6,7,8] = [1,4,2:foo ys xs]
-- foo [5,6,7,8] [3] = [1,4,2,5:foo ys xs]
-- foo [3] [6,7,8] = [1,4,2,5,3:foo ys xs]
-- foo [6,7,8] [] = [1,4,2,5,3,6,7,8]

--2
ocorrencias _ [] _ = 0
ocorrencias n (x:xs) c | n == x = ocorrencias n (xs) c+1
                       | otherwise = ocorrencias n (xs) c

--3
todos [] = True
todos (x:xs) | x == True = todos xs
             | otherwise = False

--4
restante _ [] = []
restante n (x:xs) | n <= x = x : restante n xs
                  | n >= x = restante n xs

--5
inverteDuplas [] = []
inverteDuplas ((x,y): xs) = (y,x) : inverteDuplas xs
