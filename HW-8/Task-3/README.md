# Задача 3. Maze escape

Вие се намирате в лабиринт, от който трябва да се измъкнете възможно най-бързо. Лабиринтът е разделен на клетки (може да си го представим като матрица с N реда и М колони), всяка от които е или празна (‘.’) или е стена (‘#’). Все още не можете да минавате през стени и се налага да се придвижвате само през празните клетки, като преминаването от една клетка в друга отнема, точно 1 секунда.

Тъй като, това да излезете най-бързо от въпросният лабиринт, не би било твърде голямо предизвикателство, вие разполагате с отварачка на портали. Въпросната отварачка ви позволява да отворите портал, от клетката в която се намирате, до някоя от стените на лабиринта, до която имате пряка видимост. Тъй като това е все още ранен прототип, отварачката може да отваря портали само по права линия от текущото ви местоположение и самите портали стоят отворени само 1 секунда (т.е ако не минете през портала, а отидете в друга празна клетка, порталът се затваря).

Намерете най-краткото време за което можете да излезете от лабиринта при дадени начална клетка и изход.

**Input Format**

На първият ред на входа се въвеждат N и М - броят редове и броят колони на матрицата. Следват N реда с по M символа от азбуката {‘.’, ‘#’, ‘S’, ‘F’}, където ‘S’ е началната клетка, а ‘F’ - изхода от лабиринта.

**Constraints**

0 < N, M <= 1 000

В 50% от тестовете 0 <= N, M <= 100.

**Output Format**

Изведете едно число - минималното време за достигане на изхода от лабиринта. Ако изходът е недостижим, изведете -1.

**Sample Input 0**
```
7 16
################
##S.....#....###
#####...#......#
#.#.....#..#####
#..............#
##.####....#.F.#
################
```

**Sample Output 0**
```
6
```

**Explanation 0**

image

**Sample Input 1**
```
5 5
#####
#S#.#
#.#.#
#.#F#
#####
```

**Sample Output 1**
```
-1
```