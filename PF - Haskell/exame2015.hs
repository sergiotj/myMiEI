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
exTurma = [(77730,("Sergio",9.6)),(77870,("Vitor",10)),(77871,("Ricardo",11)),(77872,("Fernando",5.3)),(77873,("Bruno",4.2)),(77874,("Sara",15))]

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

rMelhorNota :: TurmaL -> Float -> TurmaL
rMelhorNota ((num,(nome,nota)):xs) n = if (nota == n) then (num,(nome,nota)) else rMelhorNota xs n

tiraMelhorNota :: TurmaL -> TurmaL -> TurmaL
tiraMelhorNota [] _ = []
tiraMelhorNota ((num,(nome,nota)):xs) (num1,(nome1,nota1):ys) = if (num == num1 && nome == nome1 && nota == nota1) then tiraMelhorNota xs else (num,(nome,nota)):tiraMelhorNota xs

join1 :: TurmaL -> TurmaL
join1 [] = []
join1 (x:xs) = (tiraMelhorNota (x:xs) (rMelhorNota (x:xs) (melhorNota (x:xs)))):join1 xs

