Program kompilujemy komendą:
g++ twoj_program.cpp sejlib.cc -o twoj_program
A następnie wykonujemy:
./twoj_program < test.in

Testy mają nastepujący format:
- w pierszej linii znajduje się liczba całkowita n, oznaczająca ilość posłów
- w drugiej linii znajduje się ciąg n liczb 0-1, gdzie 0 oznacza posła prawdomównego, a 1 - marionetkę
- w trzeciej linii znajdują się początkowe długości nosów wszystkich posłów

Testy przykładowe znajdują się w folderze in.
