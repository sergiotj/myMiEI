module EXAME2015 where

import Data.Function (on)
import Data.List (sortBy)

type TurmaL = [(Numero,Aluno)]
type Aluno = (Nome,Nota)
type Numero = Int
type Nome = String
type Nota = Float


-- lista ordenada por numero de aluno

exTurma :: TurmaL
exTurma = [(77730,("Sergio",15)),(77870,("Vitor",15)),(77871,("Ricardo",11)),(77872,("Fernando",5.3)),(77873,("Bruno",4.2)),(77874,("Diana",15))]

exAlunos :: [Aluno]
exAlunos = [("Sergio",9.6),("Vitor",10),("Ricardo",11)]

taxaAp :: TurmaL -> Float
taxaAp turma = aux 0 0 turma where
	aux aprovados nalunos [] = aprovados/nalunos
	aux aprovados nalunos ((_,(_,nota)):xs) = if (nota >= 9.5) then aux (aprovados+1) (nalunos+1) xs else aux (aprovados) (nalunos+1) xs


-- determina o nome dos n melhores alunos da turma
-- ordenar por nota...
--top :: Int -> TurmaL -> [String]

melhorNota :: TurmaL -> Float
melhorNota [] = 0
melhorNota turma = aux turma 0 where
	aux [] melhor = melhor
	aux ((_,(_,nota)):xs) melhor = if (nota > melhor) then aux xs nota else aux xs melhor

rMelhorNota :: TurmaL -> Float -> (Numero,Aluno)
rMelhorNota ((num,(nome,nota)):xs) n = if (nota == n) then (num,(nome,nota)) else rMelhorNota xs n

tiraMelhorNota :: TurmaL -> (Numero,Aluno) -> TurmaL
tiraMelhorNota [] _ = []
tiraMelhorNota ((num,(nome,nota)):xs) (num1,(nome1,nota1)) = if (num == num1 && nome == nome1 && nota == nota1) then tiraMelhorNota xs (num1,(nome1,nota1)) else
	(num,(nome,nota)):tiraMelhorNota xs (num1,(nome1,nota1))

retiraMelhorNota :: TurmaL -> TurmaL
retiraMelhorNota [] = []
retiraMelhorNota (x:xs) = (tiraMelhorNota (x:xs) (rMelhorNota (x:xs) melhorNota1)) where
	melhorNota1 = melhorNota (x:xs)

jJoin :: TurmaL -> TurmaL
jJoin [] = []
jJoin (x:xs) = (rMelhorNota (x:xs) melhorNota1):jJoin (retiraMelhorNota (x:xs)) where
	melhorNota1 = melhorNota (x:xs)

top :: Int -> TurmaL -> [String]
top n lista = aux n (jJoin lista) where
	aux 0 lista = []
	aux n ((num,(nome,nota)):xs) = nome:aux (n-1) xs