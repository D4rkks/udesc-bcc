import Data.Char (toLower)
--1
pertence n [] = False
pertence n (x:xs) | n == x = True
                  | otherwise = pertence n xs
--2
intersecao [] [] = []
intersecao [] _ = []
intersecao (x:xs) (y:ys) | pertence x (y:ys) = x:intersecao xs (y:ys)
                         | otherwise = intersecao xs (y:ys)
--3
inverso [] = []
inverso (x:xs) = inverso xs ++ [x]

--4
nPrimeiros _ [] = []
nPrimeiros n (x:xs) | n > 0 = x : nPrimeiros (n-1) xs
                    | otherwise = []

nUltimos _ [] = []
nUltimos n (x:xs) | n > 0 = (inverso (nPrimeiros n (inverso (x:xs))))
                  | otherwise = []

--5
soma2 [] _ = []
soma2 _ [] = []
soma2 (x:xs) (y:ys) = x + y : soma2 xs ys

--6
pot2 0 = []
pot2 n = pot2 (n-1) ++ [2^n]

--7
intercalacao [] [] = []
intercalacao [x] [] = [x]
intercalacao [] [y] = [y]
intercalacao (x:xs) (y:ys) | x < y = x : intercalacao xs (y:ys)
                           | x > y = y : intercalacao (x:xs) ys
                           | x == y = x : intercalacao xs ys
                           | otherwise = []
--8
menor [x] = x
menor (x:xs) | x < menor xs = x
             | otherwise = menor xs

--9
removerElem _ [] = []
removerElem n (x:xs) | n == x = xs 
                     | otherwise = x : removerElem n xs

--10
ordenar [] = []
ordenar (x:xs) = menor (x:xs) : ordenar (removerElem (menor (x:xs)) (x:xs))

--11
insereOrd _ [] = []
insereOrd n (x:xs) | n < x = n : (x:xs)
                   | n == x = (x:xs)
                   | n > x = x: insereOrd n xs

--12
enesimo n (x:xs) | n == 1 = (x:xs)!!(0)
                 | otherwise = (x:xs)!!(n-1)

--13
repetir x y | x > 0 = y: repetir (x-1) y
                 | otherwise = []
--14
removeTab [] = []
removeTab (x:xs) | x == '\t' = ' ' : removeTab xs
                 | otherwise = x: removeTab xs

--15
minusculas [] = []
minusculas (x:xs) = map toLower(x:xs)

--16
inversoDupla [] = []
inversoDupla ((x,y):xs) = (y,x) : inversoDupla xs

--17
simetrico [] = []
simetrico((x,y):xs) | x == y = True: simetrico xs
                    | x /= y = False: simetrico xs

--18
numString :: Int -> String
numString n = show n

--19
stringNum :: String -> Int
stringNum (x) = read (x)

--20
decBin n | n == 0 = "0"
         | n == 1 = "1"
         | n /= 0 && n /= 1 = decBin (div n 2) ++ show (mod n 2)

--21
binDec2 [] = 0
binDec2 (x:xs) = 2^(length (xs)) * x + binDec2 (xs)

eachCharBin [] = []
eachCharBin (x:xs) | x == '1' = 1 : eachCharBin xs
                   | x == '0' = 0 : eachCharBin xs

binDec x = binDec2 (eachCharBin x)

--22
--trocoCafe x y | organizarValor (x-y) 0

organizarValor x y | y-x >= 50 = (50) : organizarValor x (y-50)
                  | y-x >= 20 = (20) : organizarValor x (y-20)
                  | y-x >= 10 = (10) : organizarValor x (y-10)
                  | y-x >= 5 = (5) : organizarValor x (y-5)
                  | otherwise = []

contador [] _ = []
contador (x:xs) y | pertence x xs = contador xs (y+1)
                  | otherwise = (x,(y+1)):contador xs 0

trocoCafe x y = contador (organizarValor x y) 0
