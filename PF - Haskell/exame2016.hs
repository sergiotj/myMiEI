module EXAME2016 where


intersperse :: a -> [a] -> [a]
intersperse _ [] = []
intersperse n (x:xs) = x:n:intersperse n xs

-- [[],[11],[11,21],[11,21,13]]
inits :: [a]->[[a]]
inits [] = [[]]
inits l = inits (init l) ++ [l]

type Aluno = (Numero,Nome,Classificacao)
type Numero = Int
type Nome = String
data Classificacao = Aprov Int | Rep | Faltou
data Turma = Vazia | Nodo Aluno Turma Turma

-- verifica se aluno com numero está inscrito
inscNum :: Numero -> Turma -> Bool
inscNum _ Vazia = False
inscNum num (Nodo (numero,nome,classi) esq dir) = if (num == numero) then True else if (num < numero) then inscNum num esq else inscNum num dir

aprovAv :: Turma -> Float
aprovAv Vazia = 0.0
aprovAv turma = aux 0.0 0.0 turma where
	aux nalunos aprovados Vazia = aprovados/nalunos
	aux nalunos aprovados (Nodo (numero,nome,Aprov x) esq dir) = (aux (nalunos+1.0) (aprovados+1.0) esq) + (aux (nalunos+1.0) (aprovados+1.0) dir)
	aux nalunos aprovados (Nodo (numero,nome,Rep) esq dir) = (aux (nalunos+1.0) aprovados esq) + (aux (nalunos+1.0) aprovados dir)
	aux nalunos aprovados (Nodo (numero,nome,Faltou) esq dir) = (aux (nalunos+1.0) aprovados esq) + (aux (nalunos+1.0) aprovados dir)


melhorNota :: Turma -> Maybe Int
melhorNota Vazia = Nothing
melhorNota turma = aux turma 0 where
	aux Vazia melhorNota = Nothing
	aux arvore melhorNota = if ((percorreArvore melhorNota arvore) /= 0) then Just (percorreArvore melhorNota arvore) else Nothing

-- existe maior que valor?
percorreArvore :: Int -> Turma -> Int
percorreArvore n Vazia = 0
percorreArvore n (Nodo (numero,nome,Aprov x) esq dir) = if (x > n) then x else percorreArvore n esq + percorreArvore n dir


-- sera entao [0,0,0,-5,0,2]
-- 2x à quinta, -5x ao cubo
type Polinomio = [Coeficiente]
type Coeficiente = Float

addPoli :: Polinomio -> Polinomio -> Polinomio
addPoli [] [] = []
addPoli x [] = x
addPoli [] y = y
addPoli (x:xs) (y:ys) = (x+y):addPoli xs ys

-- multiplicacao de polinomios
-- o x a multiplicar com o y e soma dos indices deles

--multPoli :: Polinomio -> Polinomio -> Polinomio
--multPoli x y = aux 0 0 x y [] where
--	aux :: Int -> Int -> Polinomio -> Polinomio -> Polinomio
--	aux _ _ [] [] final = final
--	aux _ _ x [] _ = x
--	aux _ _ [] y _ = y
--	aux ix iy (x:xs) (y:ys) final = (colocaPosicao (ix+iy) (x*y) final):aux ix+1 iy+1 xs ys final

-- funcao que o coloca... Recebe sitio e valor dele
--colocaPosicao :: Int -> Int -> Polinomio -> Polinomio
--colocaPosicao _ _ [] = []
--colocaPosicao sitio valor poli = aux 0 sitio valor poli where
--	aux sitioatual sitio valor (x:xs)
--			| (sitio == sitioatual && x == 0) = valor:aux sitioatual+1 sitio valor xs
--			| (sitio == sitioatual) = x+valor:aux sitioatual+1 sitio valor xs
--			| otherwise = x:aux sitioatual+1 sitio valor xs

