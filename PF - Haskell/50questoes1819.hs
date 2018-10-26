module CinqQ where

myEnumFromTo :: Int -> Int -> [Int]
myEnumFromTo x y = if (x <= y) then x : myEnumFromTo (x+1) y else []

myEnumFromThenTo :: Int -> Int -> Int -> [Int]
myEnumFromThenTo a b c = if (a <= c) then a : myEnumFromThenTo b (b + (b - a)) c else []

maisMais :: [a] -> [a] -> [a]
maisMais [] l = l
maisMais l [] = l
maisMais (x:xs) l = x : maisMais xs l

exclamaExclama :: [a] -> Int -> a
exclamaExclama (x:xs) n = if (n == 0) then x else exclamaExclama xs (n-1)

myInit :: [a] -> [a]
myInit [x] = []
myInit (x:xs) = x : myInit xs

myReverse :: [a] -> [a]
myReverse [] = []
myReverse l = (last l) : myReverse (myInit l)

myTake :: Int -> [a] -> [a]
myTake n [] = []
myTake n (x:xs) = if (n > 0) then x : myTake (n-1) xs else []

myDrop :: Int -> [a] -> [a]
myDrop n [] = []
myDrop n (x:xs) = if (n > 0) then myDrop (n-1) xs else x : myDrop n xs

myZip :: [a] -> [b] -> [(a,b)]
myZip [] _ = []
myZip _ [] = []
myZip (x:xs) (y:ys) = (x,y) : myZip xs ys

myElem :: Eq a => a -> [a] -> Bool
myElem n [] = False
myElem n (x:xs) = if (x == n) then True else myElem n xs

myReplicate :: Int -> a -> [a]
myReplicate 0 _ = []
myReplicate x n = n : myReplicate (x-1) n

myIntersperse :: a -> [a] -> [a]
myIntersperse _ [] = []
myIntersperse n [x] = [x]
myIntersperse n (x:xs) = x : n : myIntersperse n xs

-- falta group
myConcat :: [[a]] -> [a]
myConcat [] = []
myConcat (x:xs) = x ++ myConcat xs

--  inits [11,21,13] corresponde a [[],[11],[11,21],[11,21,13]].
inits :: [a] -> [[a]]
inits list = initsAux list [] where
    initsAux [] list = [list]
    initsAux (x:xs) list = list : initsAux xs (list ++ [x])

-- tails [1,2,3] corresponde a [[1,2,3],[2,3],[3],[]].
myTails :: [a] -> [[a]]
-- PORMENOR
myTails [] = [[]]
myTails (x:xs) = (x:xs) : myTails xs


isPrefixOf :: Eq a => [a] -> [a] -> Bool
isPrefixOf [] _ = True
isPrefixOf (px:pxs) (x:xs) = if (px == x) then isPrefixOf pxs xs else False

-- cagar na suffix

isSubsequenceOf :: Eq a => [a] -> [a] -> Bool
isSubsequenceOf _ [] = False
isSubsequenceOf [] _ = True
isSubsequenceOf (x:xs) (y:ys) = if (elem x ys) then isSubsequenceOf xs ys else isSubsequenceOf (x:xs) ys

elemIndices :: Eq a => a -> [a] -> [Int]
elemIndices n list = elemIndicesAux n list 0 where
    elemIndicesAux n [] ind = []
    elemIndicesAux n (x:xs) ind = if (x == n) then ind : elemIndicesAux n xs (ind + 1) else elemIndicesAux n xs (ind + 1)

temRepetidos :: Eq a => [a] -> Bool
temRepetidos [x] = False
temRepetidos [] = False
temRepetidos (x:y:xs) = if (x == y) then True else temRepetidos xs

nub :: Eq a => [a] -> [a]
nub list = nubAux list [] where
    nubAux [] new = new
    nubAux (x:xs) nList = if (elem x nList) then nubAux xs nList else nubAux xs (nList ++ [x])

delete :: Eq a => a -> [a] -> [a]
delete _ [] = []
delete n (x:xs) = if (n == x) then xs else x : delete n xs

barraBarra :: Eq a => [a] -> [a] -> [a]
barraBarra l [] = l
barraBarra [] _ = []
barraBarra (x:xs) (fx:fxs) = if (x == fx) then barraBarra xs fxs else x : barraBarra xs (fx:fxs)

union :: Eq a => [a] -> [a] -> [a]
union l [] = l
union l (x:xs) = if (elem x l == False) then union (l ++ [x]) xs else union l xs

-- elimina da primeira os que não estão na segunda
intersect :: Eq a => [a] -> [a] -> [a]
intersect [] l = []
intersect (x:xs) l = if (elem x l == False) then intersect l xs else x : intersect l xs

insert :: Ord a => a -> [a] -> [a]
insert n [] = [n]
insert n (x:xs) = if (x < n) then x : insert n xs else n : (x:xs)

myUnwords :: [String] -> String
myUnwords [] = []
myUnwords [x] = x
myUnwords (x:xs) = x ++ " " ++ myUnwords xs

myUnlines :: [String] -> String
myUnlines [] = []
myUnlines (x:xs) = x ++ "\n" ++ myUnlines xs

pMaior1 :: Ord a => [a] -> Int
pMaior1 list = pmaioraux list (head list) 0 0 where
               pmaioraux [] maior imaior iagora = imaior
               pmaioraux (x:xs) maior imaior iagora
                | x > maior = pmaioraux xs x iagora (iagora+1)
	            | otherwise = pmaioraux xs maior imaior (iagora+1)

algarismos :: [Char] -> [Char]
algarismos [] = []
algarismos (x:xs) = if (x >= '0' && x <= '9') then x : algarismos xs else algarismos xs

posImpares :: [a] -> [a]
posImpares [] = []
posImpares [x] = []
posImpares (x:y:xs) = y : posImpares xs

posPares :: [a] -> [a]
posPares [] = []
posPares [x] = [x]
posPares (x:y:xs) = x : posPares xs

isSorted :: Ord a => [a] -> Bool
isSorted [] = True
isSorted [x] = False
isSorted (x:y:xs) = if (x > y) then False else isSorted xs

-- Ordenar listas
inserirOrdem :: Ord a => a -> [a] -> [a]
inserirOrdem n [] = [n]
inserirOrdem n (x:xs) = if (x < n) then x : inserirOrdem n xs else n : (x:xs)

iSort :: Ord a => [a] -> [a]
iSort list = iSortAux list [] where
    iSortAux [] new = new
    iSortAux (x:xs) new = iSortAux xs (inserirOrdem x new)

-- falta a menor

elemMSet :: Eq a => a -> [(a,Int)] -> Bool
elemMSet _ [] = False
elemMSet n ((x,y):xs) = if (n == x) then True else elemMSet n xs

lengthMSet :: [(a,Int)] -> Int
lengthMSet [] = 0
lengthMSet ((x,y):xs) = y + lengthMSet xs

converteMSet :: [(a,Int)] -> [a]
converteMSet [] = []
converteMSet ((x,y):xs) = if (y == 0) then converteMSet xs else x : converteMSet ((x,y-1):xs)

insereMSet :: Eq a => a -> [(a,Int)] -> [(a,Int)]
insereMSet n [] = []
insereMSet n ((x,y):xs) = if (x == n) then (x,y+1) : insereMSet n xs else (x,y) : insereMSet n xs

-- falta o remove e o constroi

partitionEithers :: [Either a b] -> ([a],[b])
partitionEithers list = eithersAux list ([],[]) where
    eithersAux [] new = new
    eithersAux (Left x:xs) (l,r) = eithersAux xs (x:l,r)
    eithersAux (Right x:xs) (l,r) =  eithersAux xs (l,x:r)

catMaybes :: [Maybe a] -> [a]
catMaybes [] = []
catMaybes (Just x:xs) = x : catMaybes xs
catMaybes (Nothing:xs) = catMaybes xs

data Movimento = Norte | Sul | Este | Oeste
                deriving Show

mover (x,y) Norte = (x,y+1)
mover (x,y) Sul = (x,y-1)
mover (x,y) Este = (x+1,y)
mover (x,y) Oeste = (x-1,y)

posicao :: (Int,Int) -> [Movimento] -> (Int,Int)
posicao (x,y) [] = (x,y)
posicao (x,y) (mov:xs) = posicao (mover (x,y) mov) xs

caminho :: (Int,Int) -> (Int,Int) -> [Movimento]
caminho ini fin = caminhoAux ini fin [] where
    caminhoAux (x0,y0) (x,y) new
            | x > x0 = caminhoAux (x0+1,y0) (x,y) (Este:new)
            | x < x0 = caminhoAux (x0-1,y0) (x,y) (Oeste:new)
            | y > y0 = caminhoAux (x0,y0+1) (x,y) (Norte:new)
            | y < y0 = caminhoAux (x0,y0-1) (x,y) (Sul:new)
            | (x0 == x && y == y0) = new
            | otherwise = caminhoAux (x0,y0) (x,y) new

vertical :: [Movimento] -> Bool
vertical (Oeste:xs) = False
vertical (Este:xs) = False
vertical [] = True
vertical (_:xs) = vertical xs

data Posicao = Pos Int Int
            deriving Show

distOrigem :: Posicao -> Int
distOrigem (Pos x y) = round(sqrt((fromIntegral(x)-0)^2+(fromIntegral(y)-0)^2))

maisCentral :: [Posicao] -> Posicao
maisCentral lista = centralAux lista (head(lista)) where
    centralAux [] cent = cent
    centralAux (x:xs) cent = if (distOrigem x < distOrigem (cent)) then centralAux xs x else centralAux xs cent

vizinhos :: Posicao -> [Posicao] -> [Posicao]
vizinhos _ [] = []
vizinhos (Pos mx my) ((Pos x y):xs) = if (x - mx == 1 || mx - x == 1 || y - my == 1 || my - y == 1) then (Pos x y) : vizinhos (Pos mx my) xs else vizinhos (Pos mx my) xs

mesmaOrdenada :: [Posicao] -> Bool
mesmaOrdenada [] = True
mesmaOrdenada [x] = True
mesmaOrdenada ((Pos x y):(Pos x1 y1):xs) = if (y == y1) then mesmaOrdenada xs else False

data Semaforo = Verde | Amarelo | Vermelho
            deriving Show

-- só pode encontrar um verde
interseccaoOK :: [Semaforo] -> Bool
interseccaoOK lista = interAux lista 0 where
    interAux [] flag = True
    interAux (Verde:xs) flag = if (flag == 1) then False else if (flag == 0) then interAux xs 1 else interAux xs flag
    interAux (_:xs) flag = interAux xs flag
