potencia n = [x^2 | x <- [0,1..n]]
primo n =  if length (fatores n ) == 2 then True else False
fatores n = [ f | f <- [1..n], mod n f == 0]

{-Um versão recursiva da função sem 
a utilização da função interna sum poderia 
ser assim:-}
soma [] = 0
--soma lista = head(lista) + soma (tail lista)
soma (a:x) = a + soma x
