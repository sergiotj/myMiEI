module PF where

-- teste 2011/2012

maxSumPair :: [(Int,Int)] -> (Int,Int)
maxSumPair list = aux list (head list) where
	aux [] (x,y) = (x,y)
	aux ((x1,y1):xs) (x2,y2) = if ((x1 + y1) > (x2 + y2)) then aux xs (x1,y1) else aux xs (x2,y2)


maxes :: [(Int,Int)] -> (Int,Int)
maxes list = aux list (fst (head list)) (snd (head list)) where
	aux [] x y = (x,y)
	aux ((x,y):xs) mx my
		| x > mx && y > my = aux xs x y
		| x > mx = aux xs x my
		| y > my = aux xs mx y
		| otherwise = aux xs mx my


data BTree a = Empty | Node a (BTree a) (BTree a)

procura :: (Eq a) => a -> (BTree a) -> Bool
procura n Empty = False
procura n (Node x esq dir) = if (n == x) then True else procura n esq || procura n dir

type Concorrentes = [(Int, String)] -- numero e nome
type Prova = [(Int, Float)] -- numero e tempo gasto


junta :: Concorrentes -> Prova -> [(Int,String,Float)]
junta [] [] = []
junta ((num1,nome):xs) ((num2, temp):ys) = if (num1 == num2) then (num1,nome,temp):junta xs ys else junta xs ys

concorrentesEx :: Concorrentes
concorrentesEx = [(1,"Ana"), (2,"Sergio")]

provaEx :: Prova
provaEx = [(1,3.5), (2,4.5)]


-- quantos atletas fizeram um tempo abaixo do valor

conta :: Float -> Prova -> Int
conta _ [] = 0
conta n ((x,y):xs) = if (y < n) then (conta n xs)+1 else conta n xs

-- teste 2012/2013
-- merge [1,3,4,5] [2,4,6] = [1,2,3,4,4,5,6]
merge:: Ord a => [a] -> [a] -> [a]
merge [] [] = []
merge list [] = list
merge [] list = list
merge (x:xs) (y:ys) = if (x < y) then x:merge xs (y:ys) else y:merge (x:xs) ys

-- triplos "abcdefghijl" = [(’a’,’b’,’c’),(’d’,’e’,’f’),(’g’,’h’,’i’)]
triplos :: [a] -> [(a,a,a)]
triplos [] = []
triplos [x,y] = []
triplos [x] = []
triplos (x:y:z:xs) = (x,y,z):triplos xs

type Filme = (Titulo,Realizador,[Actor],Ano,Duracao)
type Titulo = String
type Realizador = String
type Actor = String
type Ano = Int
type Duracao = Int

doActor :: Actor -> [Filme] -> [(Titulo,Ano)]
doActor _ [] = []
doActor actor ((title,_,actores,ano,_):xs) = if (pertenceLista actor actores) then (title,ano):doActor actor xs else doActor actor xs

pertenceLista :: Actor -> [Actor] -> Bool
pertenceLista _ [] = False
pertenceLista n (x:xs) = if (n == x) then True else pertenceLista n xs

exFilme :: [Filme]
exFilme = [("Shutter Island","Martin Scorsese",["Dicaprio"],2010,138),("O Lobo de Wall Street","Martin Scorsese",["Dicaprio","Jonah Hill"],2013,180)]

total :: [Titulo] -> [Filme] -> Int
total [] [] = 0
total [] l = 0
total (titulo:xs) ((title,_,_,_,dur):ys) = if (title == titulo) then (total xs ys)+dur else total xs ys


data LTree a = Leaf a | Fork (LTree a) (LTree a)
    deriving (Eq, Show)

select :: LTree a -> [Bool] -> (Maybe a)
select (Leaf x) [] = Just x
select (Leaf x) list = Nothing
select (Fork x y) [] = Nothing
select (Fork _ y) (True:xs) = select y xs
select (Fork x _) (False:xs) = select x xs

exTree :: Num a => LTree a
exTree = Fork
           (Fork (Leaf 3)
                 (Fork (Leaf 2) (Leaf 1)))
           (Fork (Leaf 4)
                 (Fork (Leaf 12)
                       (Fork (Leaf 10) (Leaf 5))))

-- procura a 1 = Just [False,True,True]
-- procura :: Eq a => LTree a -> a -> Maybe [Bool]


