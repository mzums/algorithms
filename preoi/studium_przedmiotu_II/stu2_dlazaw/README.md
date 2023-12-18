Program kompilujemy komendą:
g++ twoj_program.cpp stu2lib.cc -o twoj_program
A następnie wykonujemy:
./twoj_program < test.in

Testy mają nastepujący format:
- w pierwszej linii liczby n i q, oznaczające długość ciągu i ilość zapytań
- w kolejnych q liniach:
   * 0 a b, jeśli zamieniamy miejscami liczby na pozycjach a i b
   * 1 a b, jeśli pytamy się o wynik na przedziale [a,b]

Testy przykładowe znajdują się w folderze in.
