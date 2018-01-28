module AP1314 where

data Tree a = Empty | Leaf a | Fork (Tree a) (Tree a)

a1 :: Num a => Tree a
a1 = Fork (Fork (Leaf 4)
		(Fork Empty (Leaf 13)))
	(Fork Empty
		(Fork (Leaf 5) Empty))

a2 :: Num a => Tree a
a2 = Fork (Fork (Leaf 4) (Leaf 13)) (Leaf 5)


ultimo :: Eq a => Tree a -> Maybe a
ultimo Empty = Nothing
ultimo (Leaf a) = Just a
ultimo (Fork esq dir) = if (ultimo dir == Nothing) then ultimo esq else ultimo dir


apaga :: Eq a => a -> Tree a -> Tree a
apaga n (Leaf a) = if (n == a) then Empty else (Leaf a)
apaga n (Fork esq dir) = Fork (apaga n esq) (apaga n dir)

type Album = (Titulo,Artista,Ano,[Musica])
type Musica = (Nome,Int) -- (nome da musica, duracao em segundos)
type Titulo = String
type Nome = String
type Artista = String
type Ano = Int

album1 :: Album
album1 = ("Mylo Xyloto", "Coldplay", 2011, [("Paradise",438),("Us Against the World",400),("Charlie Brown",445)])

album2 :: Album
album2 = ("X&Y", "Coldplay", 2005, [("What If",457),("White Shadows",528),("Fix You",454)])

album3 :: Album
album3 = ("The Bends", "Radiohead", 1995, [("High and Dry",416),("Fake Plastic Trees",450)])


doArtista :: [Album] -> Artista -> [(Titulo,Ano)]
doArtista [] _ = []
doArtista ((title,artist,year,_):xs) artista = if (artist == artista) then (title,year):(doArtista xs artista) else (doArtista xs artista)

conta :: [Artista] -> [Album] -> [(Artista,Int)]
conta [] [] = []
conta (x:xs) album = (x, (contaUmArtista x album)):conta xs album

contaUmArtista :: Artista -> [Album] -> Int
contaUmArtista _ [] = 0
contaUmArtista artista ((_,artist,_,_):xs) = if (artista == artist) then 1+(contaUmArtista artista xs) else (contaUmArtista artista xs)

maisAntigos :: [Album] -> [Album]
maisAntigos [] = []
maisAntigos album = aux album (anoMaisAntigo album) where
	aux [] _ = []
	aux ((title,artist,year,musica):xs) minYear = if (year == minYear) then (title,artist,year,musica):aux xs minYear else aux xs minYear

anoMaisAntigo :: [Album] -> Int
anoMaisAntigo ((title,artist,year,musica):xs) = aux ((title,artist,year,musica):xs) year where
	aux [] minYear = minYear
	aux ((title,artist,year,_):xs) minYear = if (year < minYear) then aux xs year else aux xs minYear

