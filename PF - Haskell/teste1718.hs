module Teste1718 where


-- inserir ordenadamente um elemento numa lista
insert :: Ord a => a -> [a] -> [a]
insert _ [] = []
insert n (x:xs) = if (n > x) then x:insert n xs else n:(x:xs)


catMaybes :: [Maybe a] -> [a]
catMaybes [] = []
catMaybes ((Just x):xs) = x: catMaybes xs
catMaybes ((Nothing):xs) = catMaybes xs

sortOn :: Ord b => (a -> b) -> [a] -> [a]
sortOn f [] = []
sortOn f (x:xs) = insertAux x f (sortOn f xs)


insertAux :: Ord b => a -> (a -> b) -> [a] -> [a]
insertAux a _ [] = [a]
insertAux n f (x:xs) = if (f n > f x) then x:(insertAux n f xs) else n:(x:xs)

amplitude :: [Int] -> Int
amplitude lista = amplitudeAux (head lista) 0 lista where
    amplitudeAux min max [] = (max - min)
    amplitudeAux min max (x:xs) | x < min = amplitudeAux x max xs
                                | x > max = amplitudeAux min x xs
                                | otherwise = amplitudeAux min max xs 

-- parte :: [Int] -> ([Int],[Int])

data Imagem = Quadrado Int
        | Mover (Int,Int) Imagem
        | Juntar [Imagem]

ex :: Imagem
ex = Mover (5,5) (Juntar [Mover (0,1) (Quadrado 5),Quadrado 4,Mover (4,3) (Quadrado 2)])

conta :: Imagem -> Int
conta (Quadrado x) = 1
conta (Mover (x1,x2) (Quadrado x)) = (conta (Quadrado x))+1
conta (Juntar (Quadrado x:xs)) = (conta (Quadrado x))+1


data SReais = AA Double Double | FF Double Double
			| AF Double Double | FA Double Double
			| Uniao SReais SReais

ex1 :: SReais
ex1 = Uniao (Uniao (AA 4.2 5.5) (AF 3.1 7.0)) (FF (-12.3) 30.0)

pertence :: Double-> SReais -> Bool
pertence n (Uniao (AA x w) (FF z y)) =  if (n > x && n <= x) then True else False
pertence n (Uniao (AA x w) (AF z y)) =  if (n > x && n <= x) then True else False
pertence n (Uniao (AA x w) (FA z y)) =  if (n > x && n < x) then True else False
pertence n (Uniao (FF x w) (AF z y)) =  if (n >= x && n <= x) then True else False
pertence n (Uniao (FF x w) (FA z y)) =  if (n >= x && n < x) then True else False
pertence n (Uniao (AF x w) (FA z y)) =  if (n > x && n < x) then True else False