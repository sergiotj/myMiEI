module TESTE2010 where

type Candidato = String
type Boletim = [Candidato] -- lista de nomes que consta nos boletins de voto
type Votacao = [Candidato] -- cada ocorrencia de um candidato representa um voto
type Escrutinio = [(Candidato,Int)]

ex1Votacao :: Votacao
ex1Votacao = ["Guterres","Passos Coelho","Antonio Costa","Guterres","Antonio Costa","Passos Coelho","Antonio Costa","Guterres","Passos Coelho","Antonio Costa","Guterres","Jeronimo de Sousa"]

ex1Boletim :: Boletim
ex1Boletim = ["Guterres","Antonio Costa","Passos Coelho","Jeronimo de Sousa"]

-- numero de votos de um candidato
votos :: Candidato -> Votacao -> Int
votos _ [] = 0
votos cand (x:xs) = if (x == cand) then 1+(votos cand xs) else votos cand xs

-- votos em cada um
contagem :: Boletim -> Votacao -> Escrutinio
contagem [] [] = []
contagem [] _ = []
contagem (x:xs) votacao = (x,(votos x votacao)):contagem xs votacao


nVotos :: Escrutinio -> Int
nVotos [] = 0
nVotos ((x,y):xs) = y+(nVotos xs)


-- estatistica -> percentagem de cada um
estatistica :: Escrutinio -> [(Candidato,Float)]
estatistica [] = []
estatistica escrutinio = aux escrutinio (fromIntegral (nVotos escrutinio)) where
	aux [] _ = []
	aux ((x,y):xs) totalVotos = (x,(fromIntegral y/totalVotos)*100):aux xs totalVotos

data Questionario a = Resultado a | Questao String (Questionario a) (Questionario a)

-- sim vai para a esquerda, nao para a direita

resp :: [Bool] -> Questionario a -> Maybe a
resp [] _ = Nothing
resp _ (Resultado a) = Just a
resp (x:xs) (Questao n esq dir) = if (x) then resp xs esq else resp xs dir

