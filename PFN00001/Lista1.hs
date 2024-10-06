--1
ehTriangulo x y z = x + y > z && y + z > x && x + z > y

--2
tipoTriangulo x y z | x == y && y == z = "equilatero"
                    | x == y && y /= z || x == z && z /= y || x /= y && y == z = "isoceles"
                    | x /= y && y /= z = "escaleno"

--3
triangulo a b c | not (ehTriangulo a b c) = "Nao e um trianguko"
                | a == b && b == c = "equilatero"
                | a == b && b /= c || a == c && c /= b || a /= b && b == c = "isoceles"
                | a /= b && b /= c = "escaleno"
--4
somaPares 0 = 0
somaPares n | mod n 2 == 1 = somaPares (n-1)
            | n > 1 = n + somaPares(n-2)

--5
somaPot2m m 0 = m
somaPot2m m n | n /= 0 = 2^n * m + somaPot2m m (n-1)

--6
primo n | n == 2 || n == 3 || n == 5 || n == 7 = True
        | rem n 2 /= 0 && rem n 3 /= 0 && rem n 5 /= 0 && rem n 7 /= 0 = True
        | otherwise = False


--7
seriePi n | n == 1 = 4/1
          | mod n 2 == 0 = seriePi(n-1)
          | mod (div n 2) 2 == 0 = seriePi(n-2) + (4/fromIntegral n)
          | mod (div n 2) 2 == 1 = seriePi(n-2) - (4/fromIntegral n) 
